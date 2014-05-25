#ifndef MALLEABLE_H
#define MALLEABLE_H

#include <QWidget>

#include "fixed.h"
#include "rotational.h"
#include "stiffspring.h"

namespace Ui {
	class Malleable;
}

class Malleable : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit Malleable(QWidget *parent = 0);
	~Malleable();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private slots:
	void on_comboBoxChild_currentIndexChanged(int index);
	
private:
	Ui::Malleable *ui;
	
	Fixed fixed;
	Rotational rotational;
	StiffSpring stiffSpring;
	
	ConstraintBase* array[3];
};

#endif // MALLEABLE_H
