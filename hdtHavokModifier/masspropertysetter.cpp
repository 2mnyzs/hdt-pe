#include "masspropertysetter.h"
#include "ui_masspropertysetter.h"

MassPropertySetter::MassPropertySetter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MassPropertySetter)
{
	ui->setupUi(this);
}

MassPropertySetter::~MassPropertySetter()
{
	delete ui;
}

void MassPropertySetter::onButtonSimplify()
{
	hkMatrix3 matrix;
	ui->widgetInertia->getMatrix(matrix);
	hkInertiaTensorComputer::simplifyInertiaTensorToOrientedParticle(matrix);
	ui->widgetInertia->setMatrix(matrix);
}

void MassPropertySetter::getMassProperties(hkMassProperties &m)
{
	m.m_mass = ui->spinBoxMass->value();
	ui->widgetCOM->getVector(m.m_centerOfMass);
	ui->widgetInertia->getMatrix(m.m_inertiaTensor);
}

void MassPropertySetter::setMassProperties(const hkMassProperties &m)
{
	ui->spinBoxMass->setValue(m.m_mass);
	ui->widgetCOM->setVector(m.m_centerOfMass);
	ui->widgetInertia->setMatrix(m.m_inertiaTensor);
}

void MassPropertySetter::onButtonAutoFill()
{
	emit buttonAutoFill(ui->spinBoxMass->value());
}
