#include "linearclearance.h"
#include "ui_linearclearance.h"

LinearClearance::LinearClearance(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::LinearClearance)
{
	ui->setupUi(this);
}

LinearClearance::~LinearClearance()
{
	delete ui;
}

hkpConstraintData* LinearClearance::getConstraint()
{
	hkVector4 limMin, limMax;
	ui->widgetMin->getVector(limMin);
	ui->widgetMax->getVector(limMax);
	
	auto type = (hkpLinearClearanceConstraintData::Type)ui->comboBox->currentIndex();
	auto data = new hkpLinearClearanceConstraintData;
	switch(type)
	{
	case hkpLinearClearanceConstraintData::PRISMATIC:
		data->m_atoms.m_ang.m_firstConstrainedAxis = 0;
		data->m_atoms.m_ang.m_numConstrainedAxes = 3;
		break;
		
	case hkpLinearClearanceConstraintData::HINGE:
		data->m_atoms.m_ang.m_firstConstrainedAxis = 1;
		data->m_atoms.m_ang.m_numConstrainedAxes = 2;
		break;
		
	default:
		data->m_atoms.m_ang.m_firstConstrainedAxis = 3;
		data->m_atoms.m_ang.m_numConstrainedAxes = 0;
		break;
	}
	ui->widgetPivotA->getVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->getVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->getRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->getRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	
	data->setMaxFrictionForce(ui->spinBoxFriction->value());
	data->setLimits(limMin.getComponent<0>(), limMax.getComponent(0),
					limMin.getComponent<1>(), limMax.getComponent(1),
					limMin.getComponent<2>(), limMax.getComponent(2));
	data->setMotor(ui->widgetMotor->getMotor());
	data->setMotorTargetPosition(ui->spinBoxMotorTarget->value());
	return data;
}

int LinearClearance::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpLinearClearanceConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	
	hkVector4 limMin, limMax;
	limMin.setComponent<0>(data->m_atoms.m_linLimit0.m_min);
	limMin.setComponent<1>(data->m_atoms.m_linLimit1.m_min);
	limMin.setComponent<2>(data->m_atoms.m_linLimit2.m_min);
	limMax.setComponent<0>(data->m_atoms.m_linLimit0.m_max);
	limMax.setComponent<1>(data->m_atoms.m_linLimit1.m_max);
	limMax.setComponent<2>(data->m_atoms.m_linLimit2.m_max);
	ui->widgetMin->setVector(limMin);
	ui->widgetMax->setVector(limMax);
	
	if(data->m_atoms.m_ang.m_firstConstrainedAxis==1 && data->m_atoms.m_ang.m_numConstrainedAxes>=2)
		ui->comboBox->setCurrentIndex(1);
	else if(!data->m_atoms.m_ang.m_firstConstrainedAxis && data->m_atoms.m_ang.m_numConstrainedAxes>=3)
		ui->comboBox->setCurrentIndex(0);
	else ui->comboBox->setCurrentIndex(2);
	
	ui->spinBoxFriction->setValue(data->getMaxFrictionForce());
	ui->widgetMotor->setMotor(data->getMotor());
	ui->spinBoxMotorTarget->setValue(data->m_atoms.m_motor.m_targetPosition);
	
	return true;
}
