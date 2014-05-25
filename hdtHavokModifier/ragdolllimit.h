#ifndef RAGDOLLLIMIT_H
#define RAGDOLLLIMIT_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class RagdollLimit;
}

class RagdollLimit : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit RagdollLimit(QWidget *parent = 0);
	~RagdollLimit();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_radioDegree_toggled(bool checked);
	
private:
	Ui::RagdollLimit *ui;
};

#endif // RAGDOLLLIMIT_H
