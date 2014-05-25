#ifndef VELOCITYMOTOR_H
#define VELOCITYMOTOR_H

#include <QDialog>
#include "motorbase.h"

namespace Ui {
	class MotorVelocity;
}

class MotorVelocity : public MotorBase
{
	Q_OBJECT
	
public:
	explicit MotorVelocity(QWidget *parent = 0);
	~MotorVelocity();
	
	virtual bool parseMotor(const hkpConstraintMotor* motor);
	virtual hkpConstraintMotor* getMotor();
	
private:
	Ui::MotorVelocity *ui;
};

#endif // VELOCITYMOTOR_H
