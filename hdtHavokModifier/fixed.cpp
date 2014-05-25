#include "fixed.h"
#include "ui_fixed.h"

Fixed::Fixed(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Fixed)
{
	ui->setupUi(this);
}

Fixed::~Fixed()
{
	delete ui;
}

hkpConstraintData* Fixed::getConstraint()
{
	hkTransform pivotA, pivotB;
	ui->widgetPivotA->getVector(pivotA.getTranslation());
	ui->widgetPivotB->getVector(pivotB.getTranslation());
	ui->widgetBasisA->getRotation(pivotA.getRotation());
	ui->widgetBasisB->getRotation(pivotB.getRotation());
	auto data = new hkpFixedConstraintData;
	data->setInBodySpace(pivotA, pivotB);
	
	return data;
}

int Fixed::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpFixedConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
		
	return true;
}
