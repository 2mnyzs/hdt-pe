#include "wheel.h"
#include "ui_wheel.h"

Wheel::Wheel(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Wheel)
{
	ui->setupUi(this);
}

Wheel::~Wheel()
{
	delete ui;
}

hkpConstraintData* Wheel::getConstraint()
{
	auto data = new hkpWheelConstraintData;
	ui->widgetPivotA->getVector(data->m_atoms.m_suspensionBase.m_transformA.getTranslation());
	ui->widgetPivotB->getVector(data->m_atoms.m_suspensionBase.m_transformB.getTranslation());
	ui->widgetBasisA->getRotation(data->m_atoms.m_suspensionBase.m_transformA.getRotation());
	ui->widgetBasisB->getRotation(data->m_atoms.m_suspensionBase.m_transformB.getRotation());
	ui->widgetSteeringBasisB->getRotation(data->m_atoms.m_steeringBase.m_rotationB);
	data->m_atoms.m_steeringBase.m_rotationA.setMulInverseMul(data->m_atoms.m_suspensionBase.m_transformA.getRotation(), data->m_atoms.m_suspensionBase.m_transformB.getRotation());
	data->m_atoms.m_steeringBase.m_rotationA.mul(data->m_atoms.m_steeringBase.m_rotationB);
	data->setSuspensionDamping(ui->spinBoxDamping->value());
	data->setSuspensionStrength(ui->spinBoxStrength->value());
	data->setSuspensionMinLimit(ui->spinBoxMin->value());
	data->setSuspensionMaxLimit(ui->spinBoxMax->value());
	
	return data;
}

int Wheel::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpWheelConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_suspensionBase.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_suspensionBase.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_suspensionBase.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_suspensionBase.m_transformB.getRotation());
	ui->widgetSteeringBasisB->setRotation(data->m_atoms.m_steeringBase.m_rotationB);
	ui->spinBoxDamping->setValue(data->m_atoms.m_lin0Soft.m_damping);
	ui->spinBoxStrength->setValue(data->m_atoms.m_lin0Soft.m_tau);
	ui->spinBoxMin->setValue(data->m_atoms.m_lin0Limit.m_min);
	ui->spinBoxMax->setValue(data->m_atoms.m_lin0Limit.m_max);
	
	return true;
}
