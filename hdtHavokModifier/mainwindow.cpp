#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonLoad()
{
	QString dir = ui->lineEditCurrentFile->text();
	QString path = QFileDialog::getOpenFileName(this, tr("Open Havok Serialized File"), dir, tr("Havok Serialized File(*.hkx *.xml)"));
	if(path.isEmpty()) return;
	
	auto newSystem = loadPhysicsSystem((wchar_t*)path.data());
	if(!newSystem)
	{
		QString content = tr("Cannot open file \"");
		content += path;
		content += tr("\"");
		QMessageBox::critical(this, tr("Loading failed"), content, QMessageBox::Ok, QMessageBox::Ok);
	}
	else
	{
		for(auto i : rigidbodies) i->removeReference();
		for(auto i : constraints) i->removeReference();
		rigidbodies.clear();
		constraints.clear();

		ui->lineEditCurrentFile->setText(path);
		for(auto& i : newSystem->getRigidBodies()) rigidbodies.push_back(i);
		for(auto& i : newSystem->getConstraints()) constraints.push_back(i);
		for(auto i : rigidbodies) i->addReference();
		for(auto i : constraints) i->addReference();
		newSystem->removeReference();
		fillTableRigidBodies();
		fillTableConstraints();
	}
}

void MainWindow::onButtonSave()
{
	QString dir = ui->lineEditCurrentFile->text();
	QString path = QFileDialog::getSaveFileName(this, tr("Save Havok Serialized File"), dir, tr("Text Package Files(*.xml);;Binary Package Files(*.hkx)"));
	if(path.isEmpty()) return;
	
	hkArray<char> buf;
	hkSerializeUtil::SaveOptions options;
	if(path.endsWith(tr(".xml")))
	{
		options.setWithMask(1, hkSerializeUtil::SAVE_TEXT_FORMAT);
		options.setWithMask(1, hkSerializeUtil::SAVE_TEXT_NUMBERS);
	}
	
	auto system = new hkpPhysicsSystem;
	for(auto& i : rigidbodies)
		system->addRigidBody(i);
	for(auto& i : constraints)
		system->addConstraint(i);
	
	hkSerializeUtil::savePackfile(system, system->staticClass(), hkOstream(buf).getStreamWriter(), hkPackfileWriter::Options(), 0, options);
	std::ofstream fout((wchar_t*)path.data());
	fout.write(&buf[0], buf.getSize());
	fout.close();
	ui->lineEditCurrentFile->setText(path);
}

void MainWindow::fillTableRigidBodies()
{
	ui->tableRigidBodies->clearContents();
	ui->tableRigidBodies->setRowCount(rigidbodies.size());
	for(int i=0; i<rigidbodies.size(); ++i)
		updateRigidBody(i);
}

void MainWindow::fillTableConstraints()
{
	ui->tableConstraints->clearContents();
	ui->tableConstraints->setRowCount(constraints.size());
	for(int i=0; i<constraints.size(); ++i)
		updateConstraint(i);
}

void MainWindow::updateRigidBody(int idx)
{
	auto rb = rigidbodies[idx];
	ui->tableRigidBodies->setItem(idx, 0, new QTableWidgetItem(tr(rb->getName())));
	auto enumClass = hkpMotionClass.getDeclaredEnumByName("MotionType");
	ui->tableRigidBodies->setItem(idx, 1, new QTableWidgetItem(tr(enumClass->getItem(rb->getMotionType()).getName())));
	auto shape = rb->getCollidable()->getShape();
	auto shapeClass = getHavokClass(shape);
	ui->tableRigidBodies->setItem(idx, 2, new QTableWidgetItem(tr(shapeClass->getName())));
}

void MainWindow::updateConstraint(int idx)
{
	auto instance = constraints[idx];
	ui->tableConstraints->setItem(idx, 0, new QTableWidgetItem(tr(getHavokClass(instance->getData())->getName())));
	QString rbs;
	if(instance->getType() == instance->TYPE_CHAIN)
	{
		auto chain = (hkpConstraintChainInstance*)instance;
		for(int i=0; i<chain->m_chainedEntities.getSize(); ++i)
			rbs += tr(chain->m_chainedEntities[i]->getName()) + tr(";");
	}
	else rbs = tr(instance->getEntityA()->getName()) + tr(";") + tr(instance->getEntityB()->getName()) + tr(";");
	ui->tableConstraints->setItem(idx, 1, new QTableWidgetItem(rbs));
}

#include "dialogrigidbody.h"

void MainWindow::onModifyRigidBody(int row, int)
{
	auto dialog = new DialogRigidBody(rigidbodies[row], this);
	dialog->show();
	dialog->exec();
	
	if(dialog->rigidbody != rigidbodies[row])
	{
		auto oldBody = rigidbodies[row];
		auto body = dialog->rigidbody;
		rigidbodies[row] = dialog->rigidbody;
		rigidbodies[row]->addReference();
		for(auto& instance : constraints)
		{
			if(instance->getType() == instance->TYPE_CHAIN)
			{
				auto chain = (hkpConstraintChainInstance*)instance;
				for(int i=0; i<chain->m_chainedEntities.getSize(); ++i)
				{
					if(chain->m_chainedEntities[i] == oldBody)
					{
						oldBody->removeReference();
						chain->m_chainedEntities[i] = body;
						body->addReference();
					}
				}
			}
			else if(instance->getEntityA() == oldBody || instance->getEntityB() == oldBody)
				instance->replaceEntity(oldBody, body);
		}
		oldBody->removeReference();
	}
	
	updateRigidBody(row);
	for(int i=0; i<constraints.size(); ++i)
		updateConstraint(i);
	
	delete dialog;
}

#include "dialogconstraint.h"
void MainWindow::onModifyConstraint(int row, int)
{
	DialogConstraint dialog(rigidbodies, this);
	if(dialog.setConstraint(constraints[row]))
	{
		dialog.show();
		if(dialog.exec())
		{
			constraints[row]->removeReference();
			constraints[row] = dialog.constraint;
			constraints[row]->addReference();
			updateConstraint(row);
		}
	}
}

void MainWindow::on_buttonAddBody_clicked()
{
	DialogRigidBody dialog(0, this);
	dialog.show();
	
	if(dialog.exec())
	{
		dialog.rigidbody->addReference();
		rigidbodies.push_back(dialog.rigidbody);
		ui->tableRigidBodies->setRowCount(rigidbodies.size());
		updateRigidBody(rigidbodies.size()-1);
		ui->tableRigidBodies->setCurrentCell(rigidbodies.size()-1, 0);
		ui->tableRigidBodies->scrollToBottom();
	}
}


void MainWindow::on_buttonRemoveBody_clicked()
{
	int idx = ui->tableRigidBodies->currentRow();
	if(idx < 0) return;
	
	auto oldBody = rigidbodies[idx];
	for(int i=0; i<constraints.size(); )
	{
		bool shouldRemove = false;
		if(constraints[i]->getType() == hkpConstraintInstance::TYPE_CHAIN)
		{
			auto chain = (hkpConstraintChainInstance*)constraints[i];
			for(int i=0; i<chain->m_chainedEntities.getSize(); ++i)
				shouldRemove |= chain->m_chainedEntities[i] == oldBody;
		}
		else shouldRemove = constraints[i]->getEntityA() == oldBody || constraints[i]->getEntityB() == oldBody;
		if(shouldRemove)
		{
			constraints[i]->removeReference();
			constraints.erase(constraints.begin()+i);
		}
		else ++i;
	}
	oldBody->removeReference();
	rigidbodies.erase(rigidbodies.begin()+idx);
	ui->tableRigidBodies->removeRow(idx);
	fillTableConstraints();
}

void MainWindow::on_buttonAddConstraint_clicked()
{
	if(rigidbodies.size() < 2) return;
	DialogConstraint dialog(rigidbodies, this);
	dialog.show();
	if(dialog.exec())
	{
		dialog.constraint->addReference();
		constraints.push_back(dialog.constraint);
		ui->tableConstraints->setRowCount(constraints.size());
		updateConstraint(constraints.size()-1);
		ui->tableConstraints->setCurrentCell(constraints.size()-1, 0);
		ui->tableConstraints->scrollToBottom();
	}
}

void MainWindow::on_buttonRemoveConstraint_clicked()
{
    int idx = ui->tableConstraints->currentRow();
	if(idx < 0) return;
	constraints[idx]->removeReference();
	constraints.erase(constraints.begin()+idx);
	ui->tableConstraints->removeRow(idx);
}
