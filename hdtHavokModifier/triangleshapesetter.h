#ifndef TRIANGLESHAPESETTER_H
#define TRIANGLESHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class TriangleShapeSetter;
}

class TriangleShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit TriangleShapeSetter(QWidget *parent = 0);
	~TriangleShapeSetter();
	
	virtual const hkpShape* getShape();
	virtual bool parseShape(const hkpShape*);
	
private:
	Ui::TriangleShapeSetter *ui;
};

#endif // TRIANGLESHAPE_H
