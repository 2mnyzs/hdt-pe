#ifndef LIMITEDFORCEMOTOR_H
#define LIMITEDFORCEMOTOR_H

#include <QDialog>
#include "motorbase.h"

namespace Ui {
	class MotorLimitedForce;
}

class MotorLimitedForce : public MotorBase
{
	Q_OBJECT
	
public:
	explicit MotorLimitedForce(QWidget *parent = 0);
	~MotorLimitedForce();
	
	virtual bool parseMotor(const hkpConstraintMotor* motor);
	virtual hkpConstraintMotor* getMotor();
	
private:
	Ui::MotorLimitedForce *ui;
};

#endif // LIMITEDFORCEMOTOR_H
