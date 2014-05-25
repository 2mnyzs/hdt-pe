#include "matrix33setter.h"
#include "ui_matrix33setter.h"

Matrix33Setter::Matrix33Setter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Matrix33Setter)
{
	ui->setupUi(this);
	
	isSymmetric = false;
}

Matrix33Setter::~Matrix33Setter()
{
	delete ui;
}

void Matrix33Setter::getMatrix(hkMatrix3 &matrix)
{
	float _00 = ui->doubleSpinBox->value();
	float _01 = ui->doubleSpinBox_2->value();
	float _02 = ui->doubleSpinBox_3->value();
	float _10 = ui->doubleSpinBox_4->value();
	float _11 = ui->doubleSpinBox_5->value();
	float _12 = ui->doubleSpinBox_6->value();
	float _20 = ui->doubleSpinBox_7->value();
	float _21 = ui->doubleSpinBox_8->value();
	float _22 = ui->doubleSpinBox_9->value();
	
	matrix(0, 0) = _00;
	matrix(0, 1) = _01;
	matrix(0, 2) = _02;
	matrix(1, 0) = _10;
	matrix(1, 1) = _11;
	matrix(1, 2) = _12;
	matrix(2, 0) = _20;
	matrix(2, 1) = _21;
	matrix(2, 2) = _22;
}

void Matrix33Setter::setMatrix(const hkMatrix3 &matrix)
{
	ui->doubleSpinBox->setValue(matrix(0, 0));
	ui->doubleSpinBox_2->setValue(matrix(0, 1));
	ui->doubleSpinBox_3->setValue(matrix(0, 2));
	ui->doubleSpinBox_4->setValue(matrix(1, 0));
	ui->doubleSpinBox_5->setValue(matrix(1, 1));
	ui->doubleSpinBox_6->setValue(matrix(1, 2));
	ui->doubleSpinBox_7->setValue(matrix(2, 0));
	ui->doubleSpinBox_8->setValue(matrix(2, 1));
	ui->doubleSpinBox_9->setValue(matrix(2, 2));
}

void Matrix33Setter::setPrecision(int precision)
{
	ui->doubleSpinBox->setDecimals(precision);
	ui->doubleSpinBox_2->setDecimals(precision);
	ui->doubleSpinBox_3->setDecimals(precision);
	ui->doubleSpinBox_4->setDecimals(precision);
	ui->doubleSpinBox_5->setDecimals(precision);
	ui->doubleSpinBox_6->setDecimals(precision);
	ui->doubleSpinBox_7->setDecimals(precision);
	ui->doubleSpinBox_8->setDecimals(precision);
	ui->doubleSpinBox_9->setDecimals(precision);
}

void Matrix33Setter::setMinLimit(float min)
{
	ui->doubleSpinBox->setMinimum(min);
	ui->doubleSpinBox_2->setMinimum(min);
	ui->doubleSpinBox_3->setMinimum(min);
	ui->doubleSpinBox_4->setMinimum(min);
	ui->doubleSpinBox_5->setMinimum(min);
	ui->doubleSpinBox_6->setMinimum(min);
	ui->doubleSpinBox_7->setMinimum(min);
	ui->doubleSpinBox_8->setMinimum(min);
	ui->doubleSpinBox_9->setMinimum(min);
}

void Matrix33Setter::setMaxLimit(float max)
{
	ui->doubleSpinBox->setMaximum(max);
	ui->doubleSpinBox_2->setMaximum(max);
	ui->doubleSpinBox_3->setMaximum(max);
	ui->doubleSpinBox_4->setMaximum(max);
	ui->doubleSpinBox_5->setMaximum(max);
	ui->doubleSpinBox_6->setMaximum(max);
	ui->doubleSpinBox_7->setMaximum(max);
	ui->doubleSpinBox_8->setMaximum(max);
	ui->doubleSpinBox_9->setMaximum(max);
}

void Matrix33Setter::getSymmetricMatrix(hkSymmetricMatrix3 &matrix)
{
	hkMatrix3 m;
	getMatrix(m);
	matrix.setFromSymmetricMatrix(m);
}

void Matrix33Setter::setSymmetricMatrix(const hkSymmetricMatrix3 &matrix)
{
	hkMatrix3 m;
	matrix.getMatrix(m);
	setMatrix(m);
}

void Matrix33Setter::on_doubleSpinBox_4_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_2->setValue(ui->doubleSpinBox_4->value());
}

void Matrix33Setter::on_doubleSpinBox_2_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_4->setValue(ui->doubleSpinBox_2->value());
}

void Matrix33Setter::on_doubleSpinBox_3_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_7->setValue(ui->doubleSpinBox_3->value());
}

void Matrix33Setter::on_doubleSpinBox_7_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_3->setValue(ui->doubleSpinBox_7->value());
}

void Matrix33Setter::on_doubleSpinBox_6_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_8->setValue(ui->doubleSpinBox_8->value());
}

void Matrix33Setter::on_doubleSpinBox_8_editingFinished()
{
	if(isSymmetric)
		ui->doubleSpinBox_6->setValue(ui->doubleSpinBox_6->value());
}
