#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Generic;
}

class Generic : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Generic(QWidget *parent = 0);
	~Generic();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Generic *ui;
};

#endif // GENERIC_H
