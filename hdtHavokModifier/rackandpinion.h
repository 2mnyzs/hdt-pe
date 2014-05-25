#ifndef RACKANDPINION_H
#define RACKANDPINION_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class RackAndPinion;
}

class RackAndPinion : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit RackAndPinion(QWidget *parent = 0);
	~RackAndPinion();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_checkBoxScrew_toggled(bool checked);
	
private:
	Ui::RackAndPinion *ui;
};

#endif // RACKANDPINION_H
