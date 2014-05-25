#include "motorlimitedforce.h"
#include "ui_motorlimitedforce.h"

MotorLimitedForce::MotorLimitedForce(QWidget *parent) :
	MotorBase(parent),
	ui(new Ui::MotorLimitedForce)
{
	ui->setupUi(this);
}

MotorLimitedForce::~MotorLimitedForce()
{
	delete ui;
}

bool MotorLimitedForce::parseMotor(const hkpConstraintMotor* m)
{
	auto motor = dynamic_cast<const hkpLimitedForceConstraintMotor*>(m);
	if(!motor) return false;
	ui->spinBoxMin->setValue(motor->m_minForce);
	ui->spinBoxMax->setValue(motor->m_maxForce);
}

hkpConstraintMotor* MotorLimitedForce::getMotor()
{
	auto motor = new hkpLimitedForceConstraintMotor;
	float min = ui->spinBoxMin->value();
	float max = ui->spinBoxMax->value();
	min = min > max ? max - 1e-6 : min;
	motor->setMinMaxForces(min, max);
	return motor;
}
