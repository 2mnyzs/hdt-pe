#include "sphereshapesetter.h"
#include "ui_sphereshapesetter.h"

SphereShapeSetter::SphereShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::SphereShapeSetter)
{
	ui->setupUi(this);
}

SphereShapeSetter::~SphereShapeSetter()
{
	delete ui;
}

const hkpShape* SphereShapeSetter::getShape()
{
	return new hkpSphereShape(ui->doubleSpinBox->value());
}

bool SphereShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpSphereShape*>(s);
	if(!shape) return false;
	ui->doubleSpinBox->setValue(shape->getRadius());
	return true;
}
