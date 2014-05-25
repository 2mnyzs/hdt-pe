#include "boxshapesetter.h"
#include "ui_boxshapesetter.h"

BoxShapeSetter::BoxShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::BoxShapeSetter)
{
	ui->setupUi(this);
	ui->widgetHalfExtents->setVector(hkVector4(1,1,1));
	ui->widgetHalfExtents->setLowLimit(hkVector4::getZero());
}

BoxShapeSetter::~BoxShapeSetter()
{
	delete ui;
}

const hkpShape *BoxShapeSetter::getShape()
{
	hkVector4 h;
	ui->widgetHalfExtents->getVector(h);
	return new hkpBoxShape(h, ui->spinBoxRadius->value());
}

bool BoxShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpBoxShape*>(s);
	if(!shape) return false;
	ui->widgetHalfExtents->setVector(shape->getHalfExtents());
	ui->spinBoxRadius->setValue(shape->getRadius());
	return true;
}
