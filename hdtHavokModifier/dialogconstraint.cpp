#include "dialogconstraint.h"
#include "ui_dialogconstraint.h"

DialogConstraint::DialogConstraint(const std::vector<hkpRigidBody *> &bodies, QWidget *parent) :
	QDialog(parent),
	bodies(bodies),
	ui(new Ui::DialogConstraint)
{
	ui->setupUi(this);
	setWindowTitle("Constraint");
	setWindowFlags(windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
	
	array[0] = &generic;
	array[1] = &ballAndSocket;
	array[2] = &cogWheel;
	array[3] = &deformableFixed;
	array[4] = &fixed;
	array[5] = &hinge;
	array[6] = &hingeLimits;
	array[7] = &limitedHinge;
	array[8] = &linearClearance;
	array[9] = &malleable;
	array[10] = &pointToPlane;
	array[11] = &prismatic;
	array[12] = &rackAndPinion;
	array[13] = &ragdoll;
	array[14] = &ragdollLimit;
	array[15] = &rotational;
	array[16] = &stiffSpring;
	array[17] = &wheel;
	
	ui->comboType->addItem("hkpGenericConstraintData");
	ui->comboType->addItem("hkpBallAndSocketConstraintData");
	ui->comboType->addItem("hkpCogWheelConstraintData");
	ui->comboType->addItem("hkpDeformableFixedConstraintData");
	ui->comboType->addItem("hkpFixedConstraintData");
	ui->comboType->addItem("hkpHingeConstraintData");
	ui->comboType->addItem("hkpHingeLimitsData");
	ui->comboType->addItem("hkpLimitedHingeConstraintData");
	ui->comboType->addItem("hkpLinearClearanceConstraintData");
	ui->comboType->addItem("hkpMalleableConstraintData");
	ui->comboType->addItem("hkpPointToPlaneConstraintData");
	ui->comboType->addItem("hkpPrismaticConstraintData");
	ui->comboType->addItem("hkpRackAndPinionConstraintData");
	ui->comboType->addItem("hkpRagdollConstraintData");
	ui->comboType->addItem("hkpRagdollLimitsData");
	ui->comboType->addItem("hkpRotationalConstraintData");
	ui->comboType->addItem("hkpStiffSpringConstraintData");
	ui->comboType->addItem("hkpWheelConstraintData");
	
	for(int i=0; i<bodies.size(); ++i)
	{
		ui->comboBodyA->addItem(bodies[i]->getName());
		ui->comboBodyB->addItem(bodies[i]->getName());
	}
	
	for(auto i : array) i->setVisible(false);
	for(auto i : array) ui->layoutData->addWidget(i);
	
	ui->comboType->setCurrentIndex(13);
	ui->comboType->setCurrentText(ui->comboType->itemText(ui->comboType->currentIndex()));
	on_comboType_currentIndexChanged(13);
	
	constraint = 0;
	currentChainBody = -1;
	
	chains[0] = &chainBallSocket;
	chains[1] = &chainPowered;
	chains[2] = &chainStiffSpring;
	currentChain = chains[0];
	for(auto i : chains) i->setVisible(false);
	for(auto i : chains) ui->layoutChainData->addWidget(i);
	ui->comboChainType->addItem("hkpBallSocketChainData");
	ui->comboChainType->addItem("hkpPoweredChainData");
	ui->comboChainType->addItem("hkpStiffSpringChainData");
	
	ui->comboChainType->setCurrentIndex(0);
	
	for(auto i : bodies) ui->comboChainBody->addItem(i->getName());
}

DialogConstraint::~DialogConstraint()
{
	if(constraint) constraint->removeReference();
	delete ui;
}

void DialogConstraint::on_comboType_currentIndexChanged(int index)
{
	for(auto i : array) i->setVisible(false);
	array[index]->setVisible(true);
}

#include <QMessageBox>
bool DialogConstraint::setConstraint(const hkpConstraintInstance* instance)
{
	int ret = 0;
	if(instance->getType() == hkpConstraintInstance::TYPE_CHAIN)
	{
		ui->tabWidget->setCurrentIndex(1);
		auto chain = (hkpConstraintChainInstance*)instance;
		chainBodies.clear();
		for(int i=0; i<chain->m_chainedEntities.getSize(); ++i)
		{
			chainBodies.pushBack(chain->m_chainedEntities[i]);
			ui->listWidget->addItem(chain->m_chainedEntities[i]->getName());
		}
		
		for(int i=0; i<3; ++i)
		{
			auto flag = chains[i]->parseChain(chain->getData());
			ret |= flag;
			if(flag > 0)
			{
				float tau, damping;
				chains[i]->getTauDamping(tau, damping);
				ui->chainTau->setValue(tau);
				ui->chainDamping->setValue(damping);
				ui->comboChainType->setCurrentIndex(i);
				return true;
			}
		}
	}
	else
	{
		ui->tabWidget->setCurrentIndex(0);
		int idxA = std::find(bodies.begin(), bodies.end(), instance->getRigidBodyA())-bodies.begin();
		int idxB = std::find(bodies.begin(), bodies.end(), instance->getRigidBodyB())-bodies.begin();
		ui->comboBodyA->setCurrentIndex(idxA);
		ui->comboBodyB->setCurrentIndex(idxB);
		for(int i=0; i<18; ++i)
		{
			auto flag = array[i]->parseConstraint(instance->getData());
			ret |= flag;
			if(flag > 0)
			{
				ui->comboType->setCurrentIndex(i);
				on_comboType_currentIndexChanged(i);
				return true;
			}
		}
	}
	
	if(!ret)
	{
		auto dataClass = getHavokClass(instance->getData());
		QString text = dataClass->getName();
		text += " is not support yet\n";
		text += "if continue, the constraint will be replaced.\n";
		text += "continue?";
		if(QMessageBox::warning(this, "Warning", text, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
			return true;
	}
	return false;
}

void DialogConstraint::accept()
{
	if(ui->tabWidget->currentIndex())
	{
		currentChain->setTauDamping(ui->chainTau->value(), ui->chainDamping->value());
		auto data = currentChain->getChain();
		if(!data->isValid())
			QMessageBox::warning(this, "Invalid Constraint", "Invalid constraint data.\nCheck if some values wrong.", QMessageBox::Ok, QMessageBox::Ok);
		else
		{
			auto instance = new hkpConstraintChainInstance(data);
			for(auto i : chainBodies)
				instance->addEntity(i);
			constraint = instance;
			QDialog::accept();
		}
	}
	else
	{
		auto data = array[ui->comboType->currentIndex()]->getConstraint();
		if(!data || !data->isValid())
			QMessageBox::warning(this, "Invalid Constraint", "Invalid constraint data.\nCheck if some values wrong.", QMessageBox::Ok, QMessageBox::Ok);
		else
		{
			int idxA = ui->comboBodyA->currentIndex();
			int idxB = ui->comboBodyB->currentIndex();
			constraint = new hkpConstraintInstance(bodies[idxA], bodies[idxB], data);
			QDialog::accept();
		}
	}
}

void DialogConstraint::on_comboChainType_currentIndexChanged(int index)
{
	if(currentChainBody >=0 && currentChainBody < currentChain->size())
		currentChain->apply(currentChainBody);
	currentChain->setVisible(false);
	currentChain = chains[index];
	currentChain->setSize(std::max(chainBodies.getSize()-1, 0));
	if(currentChainBody >=0 && currentChainBody < currentChain->size())
	{
		currentChain->setIndex(currentChainBody);
		currentChain->setVisible(true);
	}
}

void DialogConstraint::on_listWidget_currentRowChanged(int currentRow)
{
	if(currentChainBody >=0 && currentChainBody < currentChain->size())
		currentChain->apply(currentChainBody);
	currentChainBody = currentRow;
	if(currentChainBody >=0 && currentChainBody < currentChain->size())
	{
		currentChain->setIndex(currentChainBody);
		currentChain->setVisible(true);
	}
	else currentChain->setVisible(false);
}

void DialogConstraint::on_buttonAdd_clicked()
{
	auto body = bodies[ui->comboChainBody->currentIndex()];
	if(chainBodies.getSize())
		currentChain->insert(chainBodies.getSize()-1);
	chainBodies.pushBack(body);
	ui->listWidget->addItem(body->getName());
}

void DialogConstraint::on_buttonRemove_clicked()
{
    auto idx = ui->listWidget->currentIndex().row();
	if(idx < currentChain->size())
		currentChain->erase(idx);
	delete ui->listWidget->takeItem(idx);
	chainBodies.removeAtAndCopy(idx);
	ui->listWidget->setCurrentRow(std::min(idx, chainBodies.getSize()-1));
}

void DialogConstraint::on_buttonUp_clicked()
{
	auto idx = ui->listWidget->currentIndex().row();
	if(idx <= 0) return;
	std::swap(chainBodies[idx], chainBodies[idx-1]);
	ui->listWidget->item(idx)->setText(chainBodies[idx]->getName());
	ui->listWidget->item(idx-1)->setText(chainBodies[idx-1]->getName());
	ui->listWidget->setCurrentRow(idx-1);
}

void DialogConstraint::on_toolButton_clicked()
{
	auto idx = ui->listWidget->currentIndex().row();
	if(idx >= chainBodies.getSize()-1) return;
	std::swap(chainBodies[idx], chainBodies[idx+1]);
	ui->listWidget->item(idx)->setText(chainBodies[idx]->getName());
	ui->listWidget->item(idx+1)->setText(chainBodies[idx+1]->getName());
	ui->listWidget->setCurrentRow(idx+1);
}
