#ifndef MOTORSELECTOR_H
#define MOTORSELECTOR_H

#include <QWidget>
#include "havokhelper.h"

namespace Ui {
	class MotorSelector;
}

#include "motorposition.h"
#include "motorspringdamper.h"
#include "motorvelocity.h"

class MotorSelector : public QWidget
{
	Q_OBJECT
	
public:
	explicit MotorSelector(QWidget *parent = 0);
	~MotorSelector();
	
	void setMotor(const hkpConstraintMotor* motor);
	hkpConstraintMotor* getMotor();
	
private slots:	
	void on_comboBox_currentIndexChanged(int index);
	
private:
	
	Ui::MotorSelector *ui;
	
	MotorPosition position;
	MotorSpringDamper springDamper;
	MotorVelocity velocity;
};

#endif // MOTORSELECTOR_H
