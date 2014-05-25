#include "rotational.h"
#include "ui_rotational.h"

Rotational::Rotational(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Rotational)
{
	ui->setupUi(this);
}

Rotational::~Rotational()
{
	delete ui;
}

hkpConstraintData* Rotational::getConstraint()
{
	auto data = new hkpRotationalConstraintData;
	ui->widgetBasisA->getRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->getRotation(data->m_atoms.m_rotations.m_rotationB);
	
	return data;
}

int Rotational::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpRotationalConstraintData*>(p);
	if(!data) return false;
	ui->widgetBasisA->setRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->setRotation(data->m_atoms.m_rotations.m_rotationB);
	
	return true;
}
