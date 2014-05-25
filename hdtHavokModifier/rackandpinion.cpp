#include "rackandpinion.h"
#include "ui_rackandpinion.h"

RackAndPinion::RackAndPinion(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::RackAndPinion)
{
	ui->setupUi(this);
}

RackAndPinion::~RackAndPinion()
{
	delete ui;
}

void RackAndPinion::on_checkBoxScrew_toggled(bool checked)
{
	if(checked)
		ui->labelRadius->setText(tr("Screw Pitch:"));
	else ui->labelRadius->setText(tr("Pinion Radius:"));
}

hkpConstraintData* RackAndPinion::getConstraint()
{
	auto data = new hkpRackAndPinionConstraintData;
	ui->widgetPivotA->getVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->getVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->getRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->getRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	data->m_atoms.m_rackAndPinion.m_isScrew = ui->checkBoxScrew->isChecked();
	data->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch = ui->spinBoxRadius->value();
	return data;
}

int RackAndPinion::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpRackAndPinionConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_transforms.m_transformA.getTranslation());
	ui->widgetPivotB->setVector(data->m_atoms.m_transforms.m_transformB.getTranslation());
	ui->widgetBasisA->setRotation(data->m_atoms.m_transforms.m_transformA.getRotation());
	ui->widgetBasisB->setRotation(data->m_atoms.m_transforms.m_transformB.getRotation());
	ui->checkBoxScrew->setChecked(data->m_atoms.m_rackAndPinion.m_isScrew);
	on_checkBoxScrew_toggled(data->m_atoms.m_rackAndPinion.m_isScrew);
	ui->spinBoxRadius->setValue(data->m_atoms.m_rackAndPinion.m_pinionRadiusOrScrewPitch);
	
	return true;
}
