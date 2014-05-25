#include "motorselector.h"
#include "ui_motorselector.h"

MotorSelector::MotorSelector(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MotorSelector),
	position(this),
	springDamper(this),
	velocity(this)
{
	ui->setupUi(this);
}

MotorSelector::~MotorSelector()
{
	delete ui;
}

void MotorSelector::on_comboBox_currentIndexChanged(int index)
{
	switch(index)
	{		
	case 1:
		ui->toolButton->setMenu(&position);
		break;
		
	case 2:
		ui->toolButton->setMenu(&springDamper);
		break;
		
	case 3:
		ui->toolButton->setMenu(&velocity);
		break;
		
	default:
		ui->toolButton->setMenu(0);
		break;
	}
}

void MotorSelector::setMotor(const hkpConstraintMotor* motor)
{
	if(!motor)
		ui->comboBox->setCurrentIndex(0);
	else if(position.parseMotor(motor))
		ui->comboBox->setCurrentIndex(1);
	else if(springDamper.parseMotor(motor))
		ui->comboBox->setCurrentIndex(2);
	else if(velocity.parseMotor(motor))
		ui->comboBox->setCurrentIndex(3);
	ui->comboBox->setCurrentText(ui->comboBox->itemText(ui->comboBox->currentIndex()));
}

hkpConstraintMotor* MotorSelector::getMotor()
{
	switch(ui->comboBox->currentIndex())
	{		
	case 1:
		return position.getMotor();
		
	case 2:
		return springDamper.getMotor();
		
	case 3:
		return velocity.getMotor();
		
	default:
		return 0;
	}
}
