#include "hingelimits.h"
#include "ui_hingelimits.h"

HingeLimits::HingeLimits(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::HingeLimits)
{
	ui->setupUi(this);
}

HingeLimits::~HingeLimits()
{
	delete ui;
}

void HingeLimits::on_radioDegree_toggled(bool checked)
{
	float k = checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD;
	ui->spinBoxMin->setValue(ui->spinBoxMin->value() * k);
	ui->spinBoxMax->setValue(ui->spinBoxMax->value() * k);
}

hkpConstraintData* HingeLimits::getConstraint()
{
	float k = ui->radioDegree->isChecked() ? HK_REAL_DEG_TO_RAD : 1;
	auto data = new hkpHingeLimitsData;
	ui->widgetBasisA->getRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->getRotation(data->m_atoms.m_rotations.m_rotationB);
	data->setMinAngularLimit(ui->spinBoxMin->value()*k);
	data->setMaxAngularLimit(ui->spinBoxMax->value()*k);
	return data;
}

int HingeLimits::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpHingeLimitsData*>(p);
	if(!data) return false;
	float k = ui->radioDegree->isChecked() ? HK_REAL_RAD_TO_DEG : 1;
	ui->widgetBasisA->setRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->setRotation(data->m_atoms.m_rotations.m_rotationB);
	ui->spinBoxMin->setValue(data->getMinAngularLimit() * k);
	ui->spinBoxMax->setValue(data->getMaxAngularLimit() * k);
	
	return true;
}
