#ifndef BUTTONROTATION_H
#define BUTTONROTATION_H

#include <QPushButton>
#include "havokhelper.h"

namespace Ui {
	class RotationSetter;
}

class RotationSetter : public QWidget
{
	Q_OBJECT
public:
	explicit RotationSetter(QWidget *parent = 0);
	~RotationSetter();

	void setRotation(const hkQuaternion& q);
	void setRotation(const hkRotation& m);
	void getRotation(hkQuaternion& q);
	void getRotation(hkRotation& m);
	
signals:
		
private slots:
	void on_pushButton_clicked();
	
private:
	hkQuaternion rot;
	Ui::RotationSetter* ui;
	
	void updateText();
};
#endif // BUTTONROTATION_H
