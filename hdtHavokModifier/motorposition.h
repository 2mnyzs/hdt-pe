#ifndef POSITIONMOTOR_H
#define POSITIONMOTOR_H

#include <QDialog>
#include "motorbase.h"

namespace Ui {
	class MotorPosition;
}

class MotorPosition : public MotorBase
{
	Q_OBJECT
	
public:
	explicit MotorPosition(QWidget *parent = 0);
	~MotorPosition();
	
	bool parseMotor(const hkpConstraintMotor *motor);
	hkpConstraintMotor *getMotor();
private:
	Ui::MotorPosition *ui;
	
	// MotorBase interface
};

#endif // POSITIONMOTOR_H
