#include "collisionfiltersetter.h"
#include "ui_collisionfiltersetter.h"

CollisionFilterSetter::CollisionFilterSetter(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CollisionFilterSetter)
{
	ui->setupUi(this);
	
	boxes[0] = ui->checkBox_0;
	boxes[1] = ui->checkBox_1;
	boxes[2] = ui->checkBox_2;
	boxes[3] = ui->checkBox_3;
	boxes[4] = ui->checkBox_4;
	boxes[5] = ui->checkBox_5;
	boxes[6] = ui->checkBox_6;
	boxes[7] = ui->checkBox_7;
	boxes[8] = ui->checkBox_8;
	boxes[9] = ui->checkBox_9;
	boxes[10] = ui->checkBox_10;
	boxes[11] = ui->checkBox_11;
	boxes[12] = ui->checkBox_12;
	boxes[13] = ui->checkBox_13;
	boxes[14] = ui->checkBox_14;
	boxes[15] = ui->checkBox_15;
	boxes[16] = ui->checkBox_16;
	boxes[17] = ui->checkBox_17;
	boxes[18] = ui->checkBox_18;
	boxes[19] = ui->checkBox_19;
	boxes[20] = ui->checkBox_20;
	boxes[21] = ui->checkBox_21;
	boxes[22] = ui->checkBox_22;
	boxes[23] = ui->checkBox_23;
}

CollisionFilterSetter::~CollisionFilterSetter()
{
	delete ui;
}

void CollisionFilterSetter::setFilterInfo(int mask)
{
	int group = mask>>24;
	if(group>=24 || group<0) group = -1;
	ui->comboBox->setCurrentIndex(group+1);
	
	for(int i=0; i<24; ++i)
		boxes[i]->setChecked( group<0 ? 1 : mask&(1<<i) );
}

int CollisionFilterSetter::getFilterInfo()
{
	int group = ui->comboBox->currentIndex()-1;
	if(group>=24 || group<0) return -1;
	int mask = group << 24;
	for(int i=0; i<24; ++i)
		mask |= boxes[i]->isChecked() << i;
	return mask;
}
