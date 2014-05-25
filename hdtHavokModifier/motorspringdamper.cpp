#include "motorspringdamper.h"
#include "ui_motorspringdamper.h"

MotorSpringDamper::MotorSpringDamper(QWidget *parent) :
	MotorBase(parent),
	ui(new Ui::MotorSpringDamper)
{
	ui->setupUi(this);
}

MotorSpringDamper::~MotorSpringDamper()
{
	delete ui;
}

bool MotorSpringDamper::parseMotor(const hkpConstraintMotor* m)
{
	auto motor = dynamic_cast<const hkpSpringDamperConstraintMotor*>(m);
	if(!motor) return false;
	ui->spinBoxConstant->setValue(motor->m_springConstant);
	ui->spinBoxDamping->setValue(motor->m_springDamping);
	return true;
}

hkpConstraintMotor* MotorSpringDamper::getMotor()
{
	auto motor = new hkpSpringDamperConstraintMotor;
	motor->m_springConstant = ui->spinBoxConstant->value();
	motor->m_springDamping = ui->spinBoxDamping->value();
	return motor;
}
