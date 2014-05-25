#ifndef TRANSLATEDSHAPESETTER_H
#define TRANSLATEDSHAPESETTER_H

#include <QWidget>
#include "shapesetterbase.h"

namespace Ui {
	class TranslatedShapeSetter;
}

class TranslatedShapeSetter : public ShapeSetterBase
{
	Q_OBJECT
	
public:
	explicit TranslatedShapeSetter(QWidget *parent = 0);
	~TranslatedShapeSetter();
	
	virtual const hkpShape *getShape();
	virtual bool parseShape(const hkpShape*);
	
private:
	Ui::TranslatedShapeSetter *ui;
};

#endif // TRANSLATEDSHAPESETTER_H
