#ifndef DIALOGSHAPESETTER_H
#define DIALOGSHAPESETTER_H

#include <QDialog>

namespace Ui {
	class DialogShapeSetter;
}

#include "boxshapesetter.h"
#include "capsuleshapesetter.h"
#include "cylindershapesetter.h"
#include "listshapesetter.h"
#include "sphereshapesetter.h"
#include "transformshapesetter.h"
#include "translatedshapesetter.h"
#include "triangleshapesetter.h"

class DialogShapeSetter : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogShapeSetter(QWidget *parent = 0);
	~DialogShapeSetter();
	
	bool setShape(const hkpShape* shape);
	const hkpShape* shape;
	
public slots:
	void accept();
	
private slots:
	void on_comboBox_currentIndexChanged(int index);
	
private:
	
	Ui::DialogShapeSetter *ui;
	
	BoxShapeSetter box;
	CapsuleShapeSetter capsule;
	CylinderShapeSetter cylinder;
	ListShapeSetter list;
	SphereShapeSetter sphere;
	TransformShapeSetter transformed;
	TranslatedShapeSetter translated;
	TriangleShapeSetter triangle;
	
	ShapeSetterBase* setters[8];
};

#endif // DIALOGSHAPESETTER_H
