#ifndef POINTTOPLANE_H
#define POINTTOPLANE_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class PointToPlane;
}

class PointToPlane : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit PointToPlane(QWidget *parent = 0);
	~PointToPlane();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::PointToPlane *ui;
};

#endif // POINTTOPLANE_H
