#include "capsuleshapesetter.h"
#include "ui_capsuleshapesetter.h"

CapsuleShapeSetter::CapsuleShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::CapsuleShapeSetter)
{
	ui->setupUi(this);
	hkVector4 v1(1, 0, 0), v2(-1, 0, 0);
	ui->widgetVertex1->setVector(v1);
	ui->widgetVertex2->setVector(v2);
	ui->spinBoxRadius->setValue(1);
}

CapsuleShapeSetter::~CapsuleShapeSetter()
{
	delete ui;
}

const hkpShape *CapsuleShapeSetter::getShape()
{
	hkVector4 v1, v2;
	ui->widgetVertex1->getVector(v1);
	ui->widgetVertex2->getVector(v2);
	return new hkpCapsuleShape(v1, v2, ui->spinBoxRadius->value());
}

bool CapsuleShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpCapsuleShape*>(s);
	if(!shape) return false;
	ui->widgetVertex1->setVector(shape->getVertex(0));
	ui->widgetVertex2->setVector(shape->getVertex(1));
	ui->spinBoxRadius->setValue(shape->getRadius());
	return true;
}
