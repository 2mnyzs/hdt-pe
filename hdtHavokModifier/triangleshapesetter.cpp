#include "triangleshapesetter.h"
#include "ui_triangleshapesetter.h"

TriangleShapeSetter::TriangleShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::TriangleShapeSetter)
{
	ui->setupUi(this);
}

TriangleShapeSetter::~TriangleShapeSetter()
{
	delete ui;
}

const hkpShape* TriangleShapeSetter::getShape()
{
	hkVector4 v1, v2, v3;
	ui->widgetV1->getVector(v1);
	ui->widgetV2->getVector(v2);
	ui->widgetV3->getVector(v3);
	return new hkpTriangleShape(v1, v2, v3, ui->spinBoxMargin->value());
}

bool TriangleShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpTriangleShape*>(s);
	if(!shape) return false;
	ui->widgetV1->setVector(shape->getVertex(0));
	ui->widgetV2->setVector(shape->getVertex(1));
	ui->widgetV3->setVector(shape->getVertex(2));
	ui->spinBoxMargin->setValue(shape->getRadius());
	return true;
}
