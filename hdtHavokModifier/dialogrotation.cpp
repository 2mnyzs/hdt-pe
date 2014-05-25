#include "dialogrotation.h"
#include "ui_dialogrotation.h"

DialogRotation::DialogRotation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogRotation)
{
	ui->setupUi(this);
	setWindowTitle("Rotation");
	setWindowFlags(windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
	currentIndex = ui->tabWidget->currentIndex();
	setRotation(hkQuaternion::getIdentity());
	
	ui->widgetMatrix->setPrecision(8);
	ui->widgetMatrix->setMinLimit(-1);
	ui->widgetMatrix->setMaxLimit(1);
	
	ui->widgetQuaternion->setLowLimit(hkVector4(-1,-1,-1,-1));
	ui->widgetQuaternion->setHighLimit(hkVector4(1,1,1,1));
	ui->widgetQuaternion->setPrecision(6);
	
	ui->widgetAxis->setLowLimit(hkVector4(-1,-1,-1,-1));
	ui->widgetAxis->setHighLimit(hkVector4(1,1,1,1));
	ui->widgetAxis->setPrecision(8);
}

DialogRotation::~DialogRotation()
{
	delete ui;
}

void DialogRotation::accept()
{
	updateRotation();
	QDialog::accept();
}

void DialogRotation::updateRotation()
{
	hkQuaternion q;
	hkRotation r;
	switch(currentIndex)
	{
	case 0:
		if(ui->radioEularDegree->isChecked())
		{
			float y = ui->spinBoxY->value();
			float p = ui->spinBoxP->value();
			float r = ui->spinBoxR->value();
			setEularZYX(q, r * HK_REAL_DEG_TO_RAD, p * HK_REAL_DEG_TO_RAD, y * HK_REAL_DEG_TO_RAD);
		}
		else setEularZYX(q, ui->spinBoxR->value(), ui->spinBoxP->value(), ui->spinBoxY->value());
		setRotation(q);
		break;
		
	case 1:
		if(!ui->spinBoxAngle->value())
			q.setIdentity();
		else
		{
			hkVector4 axis;
			ui->widgetAxis->getVector(axis);
			if(axis.allExactlyEqualZero<3>())
				q.setIdentity();
			else q.setAxisAngle(axis, ui->spinBoxAngle->value() * (ui->radioAxisAngleDegree->isChecked() ? HK_REAL_DEG_TO_RAD : 1));
		}
		setRotation(q);
		break;
		
	case 2:
		ui->widgetMatrix->getMatrix(r);
		r.renormalize();
		setRotation(r);
		break;
		
	default:
		ui->widgetQuaternion->getVector(q.m_vec);
		if(q.m_vec.allEqualZero<4>(1e-4f))
			q.setIdentity();
		q.normalize();
		setRotation(q);
		break;
	}
	
}

void DialogRotation::setRotation(const hkQuaternion & q)
{
	ui->widgetQuaternion->setVector(q.m_vec);
	hkRotation matrix;
	matrix.set(q);
	ui->widgetMatrix->setMatrix(matrix);
	if(q.hasValidAxis())
	{
		hkVector4 axis;
		q.getAxis(axis);
		ui->widgetAxis->setVector(axis);
		ui->spinBoxAngle->setValue(q.getAngle() * (ui->radioAxisAngleDegree->isChecked() ? HK_REAL_RAD_TO_DEG : 1));
	}
	else
	{
		ui->widgetAxis->setVector(hkVector4::getZero());
		ui->spinBoxAngle->setValue(0);
	}
	
	float y, p, r;
	getEularZYX(q, r, p, y);
	if(ui->radioEularDegree->isChecked())
	{
		y *= HK_REAL_RAD_TO_DEG;
		p *= HK_REAL_RAD_TO_DEG;
		r *= HK_REAL_RAD_TO_DEG;
	}
	
	ui->spinBoxR->setValue(r);
	ui->spinBoxP->setValue(p);
	ui->spinBoxY->setValue(y);
}

void DialogRotation::setRotation(const hkRotation & m)
{
	hkQuaternion q(m);
	ui->widgetQuaternion->setVector(q.m_vec);
	ui->widgetMatrix->setMatrix(m);
	if(q.hasValidAxis())
	{
		hkVector4 axis;
		q.getAxis(axis);
		ui->widgetAxis->setVector(axis);
		ui->spinBoxAngle->setValue(q.getAngle() * (ui->radioAxisAngleDegree->isChecked() ? HK_REAL_RAD_TO_DEG : 1));
	}
	else
	{
		ui->widgetAxis->setVector(hkVector4::getZero());
		ui->spinBoxAngle->setValue(0);
	}
	
	float y, p, r;
	getEularZYX(q, r, p, y);
	if(ui->radioEularDegree->isChecked())
	{
		y *= HK_REAL_RAD_TO_DEG;
		p *= HK_REAL_RAD_TO_DEG;
		r *= HK_REAL_RAD_TO_DEG;
	}
	
	ui->spinBoxR->setValue(r);
	ui->spinBoxP->setValue(p);
	ui->spinBoxY->setValue(y);
}

void DialogRotation::getRotation(hkQuaternion &q)
{
	ui->widgetQuaternion->getVector(q.m_vec);
}

void DialogRotation::getRotation(hkRotation &m)
{
	ui->widgetMatrix->getMatrix(m);
}

void DialogRotation::on_tabWidget_currentChanged(int index)
{
	updateRotation();
	currentIndex = index;
}


void DialogRotation::on_radioEularDegree_toggled(bool checked)
{
	ui->spinBoxR->setValue(ui->spinBoxR->value() * (checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD));
	ui->spinBoxP->setValue(ui->spinBoxP->value() * (checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD));
	ui->spinBoxY->setValue(ui->spinBoxY->value() * (checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD));
}

void DialogRotation::on_radioAxisAngleDegree_toggled(bool checked)
{
	ui->spinBoxAngle->setValue(ui->spinBoxAngle->value() * (checked ? HK_REAL_RAD_TO_DEG : HK_REAL_DEG_TO_RAD));
}
