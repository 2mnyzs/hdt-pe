#ifndef TRANSFORMSHAPESETTER_H
#define TRANSFORMSHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class TransformShapeSetter;
}

class TransformShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit TransformShapeSetter(QWidget *parent = 0);
	~TransformShapeSetter();
	
	virtual const hkpShape *getShape();
	virtual bool parseShape(const hkpShape*);
	
private:
	Ui::TransformShapeSetter *ui;
};

#endif // TRANSFORMSHAPESETTER_H
