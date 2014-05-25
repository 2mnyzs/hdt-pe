#ifndef MOTORBASE_H
#define MOTORBASE_H

#include <QMenu>
#include "havokhelper.h"

class MotorBase : public QMenu
{
	Q_OBJECT
public:
	explicit MotorBase(QWidget *parent = 0);
	
	virtual bool parseMotor(const hkpConstraintMotor* motor) = 0;
	virtual hkpConstraintMotor* getMotor() = 0;
	
signals:
	
public slots:
	
};

#endif // MOTORBASE_H
