#ifndef CONSTRAINTBASE_H
#define CONSTRAINTBASE_H

#include "havokhelper.h"
#include <QWidget>

class ConstraintBase : public QWidget
{
	Q_OBJECT
public:
	explicit ConstraintBase(QWidget *parent = 0);
	virtual ~ConstraintBase(){}
	
	virtual hkpConstraintData* getConstraint() = 0;
	virtual int parseConstraint(const hkpConstraintData*) = 0;
};

#endif // CONSTRAINTBASE_H
