#ifndef ROTATIONAL_H
#define ROTATIONAL_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Rotational;
}

class Rotational : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Rotational(QWidget *parent = 0);
	~Rotational();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Rotational *ui;
};

#endif // ROTATIONAL_H
