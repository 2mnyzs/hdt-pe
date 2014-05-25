#include "vec4setter.h"
#include "ui_vec4setter.h"

Vec4Setter::Vec4Setter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Vec4Setter)
{
	ui->setupUi(this);
	setVector(hkVector4::getZero());
}

Vec4Setter::~Vec4Setter()
{
	delete ui;
}

void Vec4Setter::getVector(hkVector4& vec)
{
	float x = ui->spinBoxX->value();
	float y = ui->spinBoxY->value();
	float z = ui->spinBoxZ->value();
	float w = ui->spinBoxW->value();
	vec.set(x, y, z, w);
}

void Vec4Setter::setVector(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	float w = vec.getComponent<3>();
	ui->spinBoxX->setValue(x);
	ui->spinBoxY->setValue(y);
	ui->spinBoxZ->setValue(z);
	ui->spinBoxW->setValue(w);
}

void Vec4Setter::setHighLimit(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	float w = vec.getComponent<3>();
	ui->spinBoxX->setMaximum(x);
	ui->spinBoxY->setMaximum(y);
	ui->spinBoxZ->setMaximum(z);
	ui->spinBoxW->setMaximum(w);
}

void Vec4Setter::setLowLimit(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	float w = vec.getComponent<3>();
	ui->spinBoxX->setMinimum(x);
	ui->spinBoxY->setMinimum(y);
	ui->spinBoxZ->setMinimum(z);
	ui->spinBoxW->setMinimum(w);
}

void Vec4Setter::setPrecision(int precision)
{
	ui->spinBoxX->setDecimals(precision);
	ui->spinBoxY->setDecimals(precision);
	ui->spinBoxZ->setDecimals(precision);
	ui->spinBoxW->setDecimals(precision);
}
