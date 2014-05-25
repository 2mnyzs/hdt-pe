#include "limitedhinge.h"
#include "ui_limitedhinge.h"

LimitedHinge::LimitedHinge(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::LimitedHinge)
{
	ui->setupUi(this);
}

LimitedHinge::~LimitedHinge()
{
	delete ui;
}

void LimitedHinge::on_radioDegree_toggled(bool checked)
{
	float k = checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD;
	ui->spinBoxMin->setValue(ui->spinBoxMin->value() * k);
	ui->spinBoxMax->setValue(ui->spinBoxMax->value() * k);
}

hkpConstraintData* LimitedHinge::getConstraint()
{
	float k = ui->radioDegree->isChecked() ? HK_REAL_DEG_TO_RAD : 1;
	auto data = new hkpLimitedHingeConstraintData;
	ui->widgetPivotA->getVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->getVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->getRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->getRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	data->setMinAngularLimit(ui->spinBoxMin->value()*k);
	data->setMaxAngularLimit(ui->spinBoxMax->value()*k);
	data->setMotor(ui->widgetMotor->getMotor());
	data->setAngularLimitsTauFactor(ui->spinBoxTau->value());
	
	return data;
}

int LimitedHinge::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpLimitedHingeConstraintData*>(p);
	if(!data) return false;
	float k = ui->radioDegree->isChecked() ? HK_REAL_RAD_TO_DEG : 1;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	ui->spinBoxMin->setValue(data->getMinAngularLimit() * k);
	ui->spinBoxMax->setValue(data->getMaxAngularLimit() * k);
	ui->widgetMotor->setMotor(data->getMotor());
	ui->spinBoxTau->setValue(data->getAngularLimitsTauFactor());
	
	return true;
}
