#ifndef SPRINGDAMPERMOTOR_H
#define SPRINGDAMPERMOTOR_H

#include <QDialog>
#include "motorbase.h"

namespace Ui {
	class MotorSpringDamper;
}

class MotorSpringDamper : public MotorBase
{
	Q_OBJECT
	
public:
	explicit MotorSpringDamper(QWidget *parent = 0);
	~MotorSpringDamper();
	
	virtual bool parseMotor(const hkpConstraintMotor* motor);
	virtual hkpConstraintMotor* getMotor();
	
private:
	Ui::MotorSpringDamper *ui;
};

#endif // SPRINGDAMPERMOTOR_H
