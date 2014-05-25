#include "hinge.h"
#include "ui_hinge.h"

Hinge::Hinge(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Hinge)
{
	ui->setupUi(this);
}

Hinge::~Hinge()
{
	delete ui;
}

hkpConstraintData* Hinge::getConstraint()
{
	hkVector4 pivotA, pivotB, axisA, axisB;
	ui->widgetPivotA->getVector(pivotA);
	ui->widgetPivotB->getVector(pivotB);
	ui->widgetAxisA->getVector(axisA);
	ui->widgetAxisB->getVector(axisB);
	auto data = new hkpHingeConstraintData;
	data->setInBodySpace(pivotA, pivotB, axisA, axisB);
	
	return data;
}

int Hinge::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpHingeConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetAxisA->setVector(data->m_atoms.m_transforms.m_transformA.getRotation().getColumn(data->m_atoms.m_2dAng.m_freeRotationAxis));
	ui->widgetAxisB->setVector(data->m_atoms.m_transforms.m_transformB.getRotation().getColumn(data->m_atoms.m_2dAng.m_freeRotationAxis));
	
	return true;
}
