#ifndef CYLINDERSHAPESETTER_H
#define CYLINDERSHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class CylinderShapeSetter;
}

class CylinderShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit CylinderShapeSetter(QWidget *parent = 0);
	~CylinderShapeSetter();
	
	virtual const hkpShape *getShape();
	virtual bool parseShape(const hkpShape*);
	
private:
	Ui::CylinderShapeSetter *ui;
};

#endif // CYLINDERSHAPESETTER_H
