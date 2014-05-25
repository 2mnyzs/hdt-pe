#ifndef FIXED_H
#define FIXED_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Fixed;
}

class Fixed : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Fixed(QWidget *parent = 0);
	~Fixed();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::Fixed *ui;
};

#endif // FIXED_H
