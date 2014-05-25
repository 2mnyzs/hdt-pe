#ifndef MATRIX33SETTER_H
#define MATRIX33SETTER_H

#include <QWidget>
#include "havokhelper.h"

namespace Ui {
	class Matrix33Setter;
}

class Matrix33Setter : public QWidget
{
	Q_OBJECT
	
public:
	explicit Matrix33Setter(QWidget *parent = 0);
	~Matrix33Setter();
	
	void getMatrix(hkMatrix3& matrix);
	void setMatrix(const hkMatrix3& matrix);
	
	void getSymmetricMatrix(hkSymmetricMatrix3& matrix);
	void setSymmetricMatrix(const hkSymmetricMatrix3& matrix);
	
	void setPrecision(int precision);
	void setMinLimit(float min);
	void setMaxLimit(float max);
		
	bool isSymmetric;
	
private slots:
	void on_doubleSpinBox_4_editingFinished();
	
	void on_doubleSpinBox_2_editingFinished();
	
	void on_doubleSpinBox_3_editingFinished();
	
	void on_doubleSpinBox_7_editingFinished();
	
	void on_doubleSpinBox_6_editingFinished();
	
	void on_doubleSpinBox_8_editingFinished();
	
private:
	
	Ui::Matrix33Setter *ui;
};

#endif // MATRIX33SETTER_H
