#ifndef WHEEL_H
#define WHEEL_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Wheel;
}

class Wheel : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Wheel(QWidget *parent = 0);
	~Wheel();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Wheel *ui;
};

#endif // WHEEL_H
