#ifndef RAGDOLL_H
#define RAGDOLL_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class Ragdoll;
}

class Ragdoll : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Ragdoll(QWidget *parent = 0);
	~Ragdoll();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_radioDegree_toggled(bool checked);
	
private:
	Ui::Ragdoll *ui;
};

#endif // RAGDOLL_H
