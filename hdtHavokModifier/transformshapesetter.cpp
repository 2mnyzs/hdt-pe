#include "transformshapesetter.h"
#include "ui_transformshapesetter.h"

TransformShapeSetter::TransformShapeSetter(QWidget *parent) :
	ShapeSetterBase(parent),
	ui(new Ui::TransformShapeSetter)
{
	ui->setupUi(this);
	ui->widgetShape->setShape(new hkpSphereShape(1));
	ui->widgetTranslation->setVector(hkVector4::getZero());
	ui->widgetRotation->setRotation(hkQuaternion::getIdentity());
	ui->widgetScaling->setVector(hkVector4(1,1,1));
}

TransformShapeSetter::~TransformShapeSetter()
{
	delete ui;
}

#include <QMessageBox>

const hkpShape* TransformShapeSetter::getShape()
{
	hkVector4 t;
	ui->widgetTranslation->getVector(t);
	hkQsTransform qs;
	ui->widgetTranslation->getVector(qs.m_translation);
	ui->widgetRotation->getRotation(qs.m_rotation);
	ui->widgetScaling->getVector(qs.m_scale);
	auto shape = dynamic_cast<const hkpConvexShape*>(ui->widgetShape->getShape());
	if(!shape)
	{
		QMessageBox::warning(this, "Unsupport Shape",
							 "hkpConvexTransformShape only support:\n"
							 "hkpSphereShape\n"
							 "hkpCylinderShape\n"
							 "hkpTriangleShape\n"
							 "hkpCapsuleShape\n"
							 "hkpBoxShape\n"
							 "hkpConvexVerticesShape",
							 QMessageBox::Ok, QMessageBox::Ok);
		return 0;
	}
	return new hkpConvexTransformShape(shape, qs);
}

bool TransformShapeSetter::parseShape(const hkpShape *s)
{
	auto shape = dynamic_cast<const hkpConvexTransformShape*>(s);
	if(!shape) return false;
	ui->widgetTranslation->setVector(shape->getQsTransform().getTranslation());
	ui->widgetRotation->setRotation(shape->getQsTransform().getRotation());
	ui->widgetScaling->setVector(shape->getQsTransform().getScale());
	ui->widgetShape->setShape(shape->getChildShape());
	return true;
}
