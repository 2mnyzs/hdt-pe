#include "translatedshapesetter.h"
#include "ui_translatedshapesetter.h"

TranslatedShapeSetter::TranslatedShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::TranslatedShapeSetter)
{
	ui->setupUi(this);
	ui->widgetShape->setShape(new hkpSphereShape(1));
}

TranslatedShapeSetter::~TranslatedShapeSetter()
{
	delete ui;
}

#include <QMessageBox>
const hkpShape* TranslatedShapeSetter::getShape()
{
	hkVector4 t;
	ui->widgetTranslation->getVector(t);
	auto shape = dynamic_cast<const hkpConvexShape*>(ui->widgetShape->getShape());
	if(!shape)
	{
		QMessageBox::warning(this, tr("Unsupport Shape"),
							 tr("hkpConvexTransformShape only support:\n"
								"hkpSphereShape\n"
								"hkpCylinderShape\n"
								"hkpTriangleShape\n"
								"hkpCapsuleShape\n"
								"hkpBoxShape\n"
								"hkpConvexVerticesShape"),
							 QMessageBox::Ok, QMessageBox::Ok);
		return 0;
	}
	return new hkpConvexTranslateShape(shape, t);
}

bool TranslatedShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpConvexTranslateShape*>(s);
	if(!shape) return false;
	ui->widgetTranslation->setVector(shape->getTranslation());
	ui->widgetShape->setShape(shape->getChildShape());
	return true;
}
