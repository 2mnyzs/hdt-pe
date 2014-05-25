#ifndef SPHERESHAPESETTER_H
#define SPHERESHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class SphereShapeSetter;
}

class SphereShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit SphereShapeSetter(QWidget *parent = 0);
	~SphereShapeSetter();
	
	virtual const hkpShape *getShape();
	virtual bool parseShape(const hkpShape*);
		
private:
	Ui::SphereShapeSetter *ui;
};

#endif // SPHERESHAPESETTER_H
