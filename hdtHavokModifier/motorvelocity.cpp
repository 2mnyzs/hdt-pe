#include "motorvelocity.h"
#include "ui_motorvelocity.h"

MotorVelocity::MotorVelocity(QWidget *parent) :
	MotorBase(parent),
	ui(new Ui::MotorVelocity)
{
	ui->setupUi(this);
}

MotorVelocity::~MotorVelocity()
{
	delete ui;
}

bool MotorVelocity::parseMotor(const hkpConstraintMotor* m)
{
	auto motor = dynamic_cast<const hkpVelocityConstraintMotor*>(m);
	if(!motor) return false;
	ui->spinBoxTau->setValue(motor->m_tau);
	ui->spinBoxTarget->setValue(motor->m_velocityTarget);
	ui->checkBox->setChecked(motor->m_useVelocityTargetFromConstraintTargets);
	return true;
}

hkpConstraintMotor* MotorVelocity::getMotor()
{
	auto motor = new hkpVelocityConstraintMotor;
	motor->m_tau = ui->spinBoxTau->value();
	motor->m_velocityTarget = ui->spinBoxTarget->value();
	motor->m_useVelocityTargetFromConstraintTargets = ui->checkBox->isChecked();
	return motor;
}
