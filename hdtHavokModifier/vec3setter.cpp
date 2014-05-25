#include "vec3setter.h"
#include "ui_vec3setter.h"

Vec3Setter::Vec3Setter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Vec3Setter)
{
	ui->setupUi(this);
	setVector(hkVector4::getZero());
}

Vec3Setter::~Vec3Setter()
{
	delete ui;
}

void Vec3Setter::getVector(hkVector4& vec)
{
	float x = ui->spinBoxX->value();
	float y = ui->spinBoxY->value();
	float z = ui->spinBoxZ->value();
	vec.set(x, y, z);
}

void Vec3Setter::setVector(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	ui->spinBoxX->setValue(x);
	ui->spinBoxY->setValue(y);
	ui->spinBoxZ->setValue(z);
}

void Vec3Setter::setHighLimit(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	ui->spinBoxX->setMaximum(x);
	ui->spinBoxY->setMaximum(y);
	ui->spinBoxZ->setMaximum(z);
}

void Vec3Setter::setLowLimit(const hkVector4& vec)
{
	float x = vec.getComponent<0>();
	float y = vec.getComponent<1>();
	float z = vec.getComponent<2>();
	ui->spinBoxX->setMinimum(x);
	ui->spinBoxY->setMinimum(y);
	ui->spinBoxZ->setMinimum(z);
}

void Vec3Setter::setPrecision(int precision)
{
	ui->spinBoxX->setDecimals(precision);
	ui->spinBoxY->setDecimals(precision);
	ui->spinBoxZ->setDecimals(precision);
}
