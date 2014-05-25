#include "listshapesetter.h"
#include "ui_listshapesetter.h"

ListShapeSetter::ListShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::ListShapeSetter)
{
	ui->setupUi(this);
}

ListShapeSetter::~ListShapeSetter()
{
	for(int i=0; i<children.getSize(); ++i)
		children[i]->removeReference();
	delete ui;
}

#include "dialogshapesetter.h"
#include <QMessageBox>
void ListShapeSetter::on_listWidget_doubleClicked(const QModelIndex &index)
{
	DialogShapeSetter dialog(this);
	auto shape = children[index.row()];
	if(!dialog.setShape(shape))
	{
		QString text = ui->listWidget->item(index.row())->text();
		text += " is not support by the editor\n";
		text += "if continue, the shape will be replaced and cannot roll back.\n";
		text += "continue?";
		if(QMessageBox::warning(this, "Warning", text, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
			return;
	}
	dialog.show();
	if(dialog.exec())
	{
		shape->removeReference();
		children[index.row()] = dialog.shape;
		dialog.shape->addReference();
		auto shapeClass = getHavokClass(dialog.shape);
		ui->listWidget->item(index.row())->setText(shapeClass->getName());
	}
}

void ListShapeSetter::on_buttonAdd_clicked()
{
	children.pushBack(new hkpSphereShape(1));
	ui->listWidget->addItem("hkpSphereShape");
}

void ListShapeSetter::on_buttonRemove_clicked()
{
	auto idx = ui->listWidget->currentIndex().row();
	children[idx]->removeReference();
	children.removeAtAndCopy(idx);
    delete ui->listWidget->takeItem(idx);
}

#include <QMessageBox>
const hkpShape* ListShapeSetter::getShape()
{
	if(children.isEmpty())
	{
		QMessageBox::warning(this, "Warning", "You should add at least one child shape.", QMessageBox::Ok, QMessageBox::Ok);
		return 0;
	}
	return new hkpListShape(&children[0], children.getSize());
}

bool ListShapeSetter::parseShape(const hkpShape* s)
{
	auto shape = dynamic_cast<const hkpListShape*>(s);
	if(!shape) return false;
	
	ui->listWidget->clear();
	for(int i=0; i<children.getSize(); ++i)
		children[i]->removeReference();
	children.clear();
	
	hkpShapeBuffer buffer;
	for(hkpShapeKey key = shape->getFirstKey(); key!=HK_INVALID_SHAPE_KEY; key = shape->getNextKey(key))
	{
		auto child = shape->getChildShape(key, buffer);
		child->addReference();
		auto shapeClass = getHavokClass(child);
		ui->listWidget->addItem(new QListWidgetItem(shapeClass->getName()));
		children.pushBack(child);
	}
	return true;
}
