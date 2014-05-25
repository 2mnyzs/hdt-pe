#ifndef LINEARCLEARANCE_H
#define LINEARCLEARANCE_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class LinearClearance;
}

class LinearClearance : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit LinearClearance(QWidget *parent = 0);
	~LinearClearance();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::LinearClearance *ui;
};

#endif // LINEARCLEARANCE_H
