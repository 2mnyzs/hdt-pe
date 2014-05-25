#ifndef SHAPESETTERBASE_H
#define SHAPESETTERBASE_H

#include <QWidget>

#include "havokhelper.h"

class ShapeSetterBase : public QWidget
{
	Q_OBJECT
public:
	explicit ShapeSetterBase(QWidget *parent = 0);
	virtual ~ShapeSetterBase(){}
	
	virtual const hkpShape* getShape() = 0;
	virtual bool parseShape(const hkpShape*) = 0;
	
signals:
	
public slots:
	
};

#endif // SHAPESETTERBASE_H
