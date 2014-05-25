#ifndef COGWHEEL_H
#define COGWHEEL_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class CogWheel;
}

class CogWheel : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit CogWheel(QWidget *parent = 0);
	~CogWheel();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::CogWheel *ui;
};

#endif // COGWHEEL_H
