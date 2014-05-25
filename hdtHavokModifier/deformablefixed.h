#ifndef DEFORMABLEFIXED_H
#define DEFORMABLEFIXED_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class DeformableFixed;
}

class DeformableFixed : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit DeformableFixed(QWidget *parent = 0);
	~DeformableFixed();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_radioDegree_toggled(bool checked);
	
private:
	Ui::DeformableFixed *ui;
};

#endif // DEFORMABLEFIXED_H
