#include "shapeselector.h"
#include "ui_shapeselector.h"

ShapeSelector::ShapeSelector(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ShapeSelector)
{
	ui->setupUi(this);
	shape = 0;
}

ShapeSelector::~ShapeSelector()
{
	delete ui;
}

void ShapeSelector::setShape(const hkpShape *s)
{
	if(shape) shape->removeReference();
	shape = s;
	shape->addReference();
	auto shapeClass = getHavokClass(shape);
	ui->pushButton->setText(tr(shapeClass->getName()));
}

const hkpShape* ShapeSelector::getShape()
{
	return shape;
}

#include "dialogshapesetter.h"
#include <QMessageBox>

void ShapeSelector::on_pushButton_clicked()
{
	DialogShapeSetter dialog(this);
	if(!dialog.setShape(shape))
	{
		QString text = ui->pushButton->text();
		text += " is not support by the editor\n";
		text += "if continue, the shape will be replaced and cannot roll back.\n";
		text += "continue?";
		if(QMessageBox::warning(this, "Warning", text, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
			return;
	}
	dialog.show();
	if(dialog.exec())
		setShape(dialog.shape);
}
