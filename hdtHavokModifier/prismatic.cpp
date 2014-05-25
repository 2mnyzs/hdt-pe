#include "prismatic.h"
#include "ui_prismatic.h"

Prismatic::Prismatic(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Prismatic)
{
	ui->setupUi(this);
}

Prismatic::~Prismatic()
{
	delete ui;
}

hkpConstraintData* Prismatic::getConstraint()
{
	auto data = new hkpPrismaticConstraintData;
	ui->widgetPivotA->getVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->getVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->getRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->getRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	data->setMinLinearLimit(ui->spinBoxMin->value());
	data->setMaxLinearLimit(ui->spinBoxMax->value());
	data->setMaxFrictionForce(ui->spinBoxFriction->value());
	data->setMotor(ui->widgetMotor->getMotor());
	data->setMotorTargetPosition(ui->spinBoxMotorTarget->value());
	
	return data;
}

int Prismatic::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpPrismaticConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	ui->spinBoxMin->setValue(data->getMinLinearLimit());
	ui->spinBoxMax->setValue(data->getMaxLinearLimit());
	ui->spinBoxFriction->setValue(data->getMaxFrictionForce());
	ui->widgetMotor->setMotor(data->getMotor());
	ui->spinBoxMotorTarget->setValue(data->m_atoms.m_motor.m_targetPosition);
	
	return true;
}
