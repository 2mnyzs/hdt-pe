#ifndef STIFFSPRING_H
#define STIFFSPRING_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class StiffSpring;
}

class StiffSpring : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit StiffSpring(QWidget *parent = 0);
	~StiffSpring();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::StiffSpring *ui;
};

#endif // STIFFSPRING_H
