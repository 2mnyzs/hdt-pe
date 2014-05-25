#include "cogwheel.h"
#include "ui_cogwheel.h"

CogWheel::CogWheel(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::CogWheel)
{
	ui->setupUi(this);
}

CogWheel::~CogWheel()
{
	delete ui;
}

hkpConstraintData* CogWheel::getConstraint()
{
	hkVector4 pivotA, pivotB, axisA, axisB;
	ui->widgetPivotA->getVector(pivotA);
	ui->widgetPivotB->getVector(pivotB);
	ui->widgetAxisA->getVector(axisA);
	ui->widgetAxisB->getVector(axisB);
	auto data = new hkpCogWheelConstraintData;
	data->setInBodySpace(pivotA, axisA, ui->spinBoxRadiusA->value(), pivotB, axisB, ui->spinBoxRadiusB->value());
	return data;
}

int CogWheel::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpCogWheelConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetAxisA->setVector(data->m_atoms.m_transforms.m_transformA.getRotation().getColumn<0>());
	ui->widgetAxisB->setVector(data->m_atoms.m_transforms.m_transformB.getRotation().getColumn<0>());
	
	ui->spinBoxRadiusA->setValue(data->m_atoms.m_cogWheels.m_cogWheelRadiusA);
	ui->spinBoxRadiusB->setValue(data->m_atoms.m_cogWheels.m_cogWheelRadiusB);
	
	return true;
}
