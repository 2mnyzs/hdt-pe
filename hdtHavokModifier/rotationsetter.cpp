#include "rotationsetter.h"
#include "ui_rotationsetter.h"

RotationSetter::RotationSetter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RotationSetter)
{
	ui->setupUi(this);
	
	rot.setIdentity();
	updateText();
}

RotationSetter::~RotationSetter()
{
	
}

void RotationSetter::setRotation(const hkQuaternion& q)
{
	rot = q;
	rot.normalize();
	updateText();
}

void RotationSetter::setRotation(const hkRotation& m)
{
	rot.setAndNormalize(m);
	updateText();
}

void RotationSetter::getRotation(hkQuaternion& q)
{
	q = rot;
}

void RotationSetter::getRotation(hkRotation& m)
{
	m.set(rot);
}

#include "dialogrotation.h"
void RotationSetter::on_pushButton_clicked()
{
	DialogRotation dialog(this);
	dialog.setRotation(rot);
	dialog.show();
	if(dialog.exec())
		dialog.getRotation(rot);
	updateText();
}

void RotationSetter::updateText()
{
	float x, y, z;
	getEularZYX(rot, z, y, x);
	QString text = "Z: ";
	text += QString().setNum(z);
	text += ", Y: ";
	text += QString().setNum(y);
	text += ", X: ";
	text += QString().setNum(x);
	ui->pushButton->setText(text);
}
