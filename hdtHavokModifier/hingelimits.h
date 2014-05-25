#ifndef HINGELIMITS_H
#define HINGELIMITS_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class HingeLimits;
}

class HingeLimits : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit HingeLimits(QWidget *parent = 0);
	~HingeLimits();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_radioDegree_toggled(bool checked);
	
private:
	Ui::HingeLimits *ui;
};

#endif // HINGELIMITS_H
