#ifndef DIALOGRIGIDBODY_H
#define DIALOGRIGIDBODY_H

#include <QDialog>

#include "havokhelper.h"

namespace Ui {
	class DialogRigidBody;
}

class DialogRigidBody : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogRigidBody(hkpRigidBody* rb, QWidget *parent = 0);
	~DialogRigidBody();
	
	void accept();
	
	hkpRigidBody* rigidbody;

public slots:
	void on_widgetMassProperties_buttonAutoFill(float);
	
private:
	Ui::DialogRigidBody *ui;
};

#endif // DIALOGRIGIDBODY_H
