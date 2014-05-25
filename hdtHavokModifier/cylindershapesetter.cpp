#include "cylindershapesetter.h"
#include "ui_cylindershapesetter.h"

CylinderShapeSetter::CylinderShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::CylinderShapeSetter)
{
	ui->setupUi(this);
	hkVector4 v1(1, 0, 0), v2(-1, 0, 0);
	ui->widgetVertex1->setVector(v1);
	ui->widgetVertex2->setVector(v2);
	ui->spinBoxRadius->setValue(1);
	ui->spinBoxMargin->setValue(0);
}

CylinderShapeSetter::~CylinderShapeSetter()
{
	delete ui;
}

const hkpShape* CylinderShapeSetter::getShape()
{
	hkVector4 v1, v2;
	ui->widgetVertex1->getVector(v1);
	ui->widgetVertex2->getVector(v2);
	return new hkpCylinderShape(v1, v2, ui->spinBoxRadius->value(), ui->spinBoxMargin->value());
}

bool CylinderShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpCylinderShape*>(s);
	if(!shape) return false;
	ui->widgetVertex1->setVector(shape->getVertex(0));
	ui->widgetVertex2->setVector(shape->getVertex(1));
	ui->spinBoxRadius->setValue(shape->getCylinderRadius());
	ui->spinBoxMargin->setValue(shape->getRadius());
	return true;
}
