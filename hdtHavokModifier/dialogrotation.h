#ifndef DIALOGROTATION_H
#define DIALOGROTATION_H

#include <QDialog>

#include "havokhelper.h"

namespace Ui {
	class DialogRotation;
}

class DialogRotation : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogRotation(QWidget *parent = 0);
	~DialogRotation();
	
	void accept();
	
	void getRotation(hkRotation&);
	void getRotation(hkQuaternion&);
	void setRotation(const hkRotation&);
	void setRotation(const hkQuaternion&);
		
private slots:
	void on_tabWidget_currentChanged(int index);
		
	void on_radioEularDegree_toggled(bool checked);
	
	void on_radioAxisAngleDegree_toggled(bool checked);
	
private:
	int currentIndex;
	Ui::DialogRotation *ui;
	
	void updateRotation();
};

#endif // DIALOGROTATION_H
