#include "ragdolllimit.h"
#include "ui_ragdolllimit.h"

RagdollLimit::RagdollLimit(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::RagdollLimit)
{
	ui->setupUi(this);
}

RagdollLimit::~RagdollLimit()
{
	delete ui;
}

void RagdollLimit::on_radioDegree_toggled(bool checked)
{
	float k = checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD;
	ui->spinBoxCone->setValue(ui->spinBoxCone->value() * k);
	ui->spinBoxPlaneMin->setValue(ui->spinBoxPlaneMin->value() * k);
	ui->spinBoxPlaneMax->setValue(ui->spinBoxPlaneMax->value() * k);
	ui->spinBoxTwistMin->setValue(ui->spinBoxTwistMin->value() * k);
	ui->spinBoxTwistMax->setValue(ui->spinBoxTwistMax->value() * k);
}

hkpConstraintData* RagdollLimit::getConstraint()
{
	float k = ui->radioDegree->isChecked() ? HK_REAL_DEG_TO_RAD : 1;
	auto data = new hkpRagdollLimitsData;
	ui->widgetBasisA->getRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->getRotation(data->m_atoms.m_rotations.m_rotationB);
	data->setConeAngularLimit(ui->spinBoxCone->value() * k);
	data->setPlaneMinAngularLimit(ui->spinBoxPlaneMin->value() * k);
	data->setPlaneMaxAngularLimit(ui->spinBoxPlaneMax->value() * k);
	data->setTwistMinAngularLimit(ui->spinBoxTwistMin->value() * k);
	data->setTwistMaxAngularLimit(ui->spinBoxTwistMax->value() * k);
	data->m_atoms.m_coneLimit.m_angularLimitsTauFactor = ui->spinBoxConeTau->value();
	data->m_atoms.m_planesLimit.m_angularLimitsTauFactor = ui->spinBoxPlaneTau->value();
	data->m_atoms.m_twistLimit.m_angularLimitsTauFactor = ui->spinBoxTwistTau->value();
	data->m_atoms.m_coneLimit.m_isEnabled = !!ui->spinBoxConeTau->value();
	data->m_atoms.m_planesLimit.m_isEnabled = !!ui->spinBoxPlaneTau->value();
	data->m_atoms.m_twistLimit.m_isEnabled = !!ui->spinBoxTwistTau->value();
		
	return data;
}

int RagdollLimit::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpRagdollLimitsData*>(p);
	if(!data) return false;
	float k = ui->radioDegree->isChecked() ? HK_REAL_RAD_TO_DEG : 1;
	ui->widgetBasisA->setRotation(data->m_atoms.m_rotations.m_rotationA);
	ui->widgetBasisB->setRotation(data->m_atoms.m_rotations.m_rotationB);
	ui->spinBoxCone->setValue(data->getConeAngularLimit() * k);
	ui->spinBoxPlaneMin->setValue(data->getPlaneMinAngularLimit() * k);
	ui->spinBoxPlaneMax->setValue(data->getPlaneMaxAngularLimit() * k);
	ui->spinBoxTwistMin->setValue(data->getTwistMinAngularLimit() * k);
	ui->spinBoxTwistMax->setValue(data->getTwistMaxAngularLimit() * k);
	ui->spinBoxConeTau->setValue(data->m_atoms.m_coneLimit.m_angularLimitsTauFactor);
	ui->spinBoxPlaneTau->setValue(data->m_atoms.m_planesLimit.m_angularLimitsTauFactor);
	ui->spinBoxTwistTau->setValue(data->m_atoms.m_twistLimit.m_angularLimitsTauFactor);
	
	if(!data->m_atoms.m_coneLimit.m_isEnabled) ui->spinBoxConeTau->setValue(0);
	if(!data->m_atoms.m_planesLimit.m_isEnabled) ui->spinBoxPlaneTau->setValue(0);
	if(!data->m_atoms.m_twistLimit.m_isEnabled) ui->spinBoxTwistTau->setValue(0);
	
	return true;
}

