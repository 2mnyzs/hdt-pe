#ifndef BOXSHAPESETTER_H
#define BOXSHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class BoxShapeSetter;
}

class BoxShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit BoxShapeSetter(QWidget *parent = 0);
	~BoxShapeSetter();
	
	virtual const hkpShape* getShape();
	virtual bool parseShape(const hkpShape *);
	
private:
	Ui::BoxShapeSetter *ui;
};

#endif // BOXSHAPESETTER_H
