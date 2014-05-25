#ifndef LIMITEDHINGE_H
#define LIMITEDHINGE_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class LimitedHinge;
}

class LimitedHinge : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit LimitedHinge(QWidget *parent = 0);
	~LimitedHinge();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_radioDegree_toggled(bool checked);
	
private:
	Ui::LimitedHinge *ui;
};

#endif // LIMITEDHINGE_H
