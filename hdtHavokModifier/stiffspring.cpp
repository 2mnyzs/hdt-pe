#include "stiffspring.h"
#include "ui_stiffspring.h"

StiffSpring::StiffSpring(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::StiffSpring)
{
	ui->setupUi(this);
}

StiffSpring::~StiffSpring()
{
	delete ui;
}

hkpConstraintData* StiffSpring::getConstraint()
{
	auto data = new hkpStiffSpringConstraintData;
	ui->widgetPivotA->getVector(data->m_atoms.m_pivots.m_translationA);
	ui->widgetPivotB->getVector(data->m_atoms.m_pivots.m_translationB);
	data->setSpringLength(ui->spinBoxMin->value(), ui->spinBoxMax->value());
	return data;
}

int StiffSpring::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpStiffSpringConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_pivots.m_translationA);
	ui->widgetPivotB->setVector(data->m_atoms.m_pivots.m_translationB);
	ui->spinBoxMin->setValue(data->m_atoms.m_spring.m_length);
	ui->spinBoxMax->setValue(data->m_atoms.m_spring.m_maxLength);
	
	return true;
}
