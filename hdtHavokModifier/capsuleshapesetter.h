#ifndef CAPSULESHAPESETTER_H
#define CAPSULESHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class CapsuleShapeSetter;
}

class CapsuleShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit CapsuleShapeSetter(QWidget *parent = 0);
	~CapsuleShapeSetter();
	
	virtual const hkpShape* getShape();
	virtual bool parseShape(const hkpShape*);
	
private:
	Ui::CapsuleShapeSetter *ui;
};

#endif // CAPSULESHAPESETTER_H
