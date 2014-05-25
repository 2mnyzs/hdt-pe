#ifndef HINGE_H
#define HINGE_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Hinge;
}

class Hinge : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Hinge(QWidget *parent = 0);
	~Hinge();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Hinge *ui;
};

#endif // HINGE_H
