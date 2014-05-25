#include "motorposition.h"
#include "ui_motorposition.h"

MotorPosition::MotorPosition(QWidget *parent) :
	MotorBase(parent),
	ui(new Ui::MotorPosition)
{
	ui->setupUi(this);
}

MotorPosition::~MotorPosition()
{
	delete ui;
}

bool MotorPosition::parseMotor(const hkpConstraintMotor* m)
{
	auto motor = dynamic_cast<const hkpPositionConstraintMotor*>(m);
	if(!motor) return false;
	ui->spinBoxTau->setValue(motor->m_tau);
	ui->spinBoxDamping->setValue(motor->m_damping);
	ui->spinBoxPV->setValue(motor->m_proportionalRecoveryVelocity);
	ui->spinBoxCV->setValue(motor->m_constantRecoveryVelocity);
	return true;
}

hkpConstraintMotor* MotorPosition::getMotor()
{
	auto motor = new hkpPositionConstraintMotor;
	motor->m_tau = ui->spinBoxTau->value();
	motor->m_damping = ui->spinBoxDamping->value();
	motor->m_proportionalRecoveryVelocity = ui->spinBoxPV->value();
	motor->m_constantRecoveryVelocity = ui->spinBoxCV->value();
	return motor;
}
