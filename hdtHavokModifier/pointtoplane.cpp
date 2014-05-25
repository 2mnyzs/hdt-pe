#include "pointtoplane.h"
#include "ui_pointtoplane.h"

PointToPlane::PointToPlane(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::PointToPlane)
{
	ui->setupUi(this);
}

PointToPlane::~PointToPlane()
{
	delete ui;
}

hkpConstraintData* PointToPlane::getConstraint()
{
	auto data = new hkpPointToPlaneConstraintData;
	hkVector4 pivotA, pivotB, normalB;
	ui->widgetPivotA->getVector(pivotA);
	ui->widgetPivotB->getVector(pivotB);
	ui->widgetNormalB->getVector(normalB);
	data->setInBodySpace(pivotA, pivotB, normalB);
	return data;
}

int PointToPlane::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpPointToPlaneConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetNormalB->setVector(data->m_atoms.m_transforms.m_transformB.getRotation().getColumn(data->m_atoms.m_lin.m_axisIndex));
	
	return true;
}
