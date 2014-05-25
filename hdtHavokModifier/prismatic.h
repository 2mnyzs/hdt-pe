#ifndef PRISMATIC_H
#define PRISMATIC_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Prismatic;
}

class Prismatic : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Prismatic(QWidget *parent = 0);
	~Prismatic();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Prismatic *ui;
};

#endif // PRISMATIC_H
