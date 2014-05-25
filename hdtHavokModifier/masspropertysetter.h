#ifndef MASSPROPERTYSETTER_H
#define MASSPROPERTYSETTER_H

#include <QWidget>

#include "havokhelper.h"

namespace Ui {
	class MassPropertySetter;
}

class MassPropertySetter : public QWidget
{
	Q_OBJECT
	
public:
	explicit MassPropertySetter(QWidget *parent = 0);
	~MassPropertySetter();
	
	void setMassProperties(const hkMassProperties& m);
	void getMassProperties(hkMassProperties& m);
	
public slots:
	void onButtonSimplify();
	void onButtonAutoFill();
	
signals:
	void buttonAutoFill(float mass);
		
private:
	Ui::MassPropertySetter *ui;
};

#endif // MASSPROPERTYSETTER_H
