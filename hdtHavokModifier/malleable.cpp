#include "malleable.h"
#include "ui_malleable.h"

Malleable::Malleable(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Malleable)
{
	ui->setupUi(this);
	
	array[0] = &fixed;
	array[1] = &rotational;
	array[2] = &stiffSpring;
	
	for(auto i : array) i->setVisible(false);
	for(auto i : array) ui->layoutChild->addWidget(i);
	
	ui->comboBoxChild->addItem("hkpFixedConstraintData");
	ui->comboBoxChild->addItem("hkpRotationalConstraintData");
	ui->comboBoxChild->addItem("hkpStiffSpringConstraintData");
	
	array[0]->setVisible(true);
	ui->comboBoxChild->setCurrentIndex(0);
	ui->comboBoxChild->setCurrentText(ui->comboBoxChild->itemText(0));
}

Malleable::~Malleable()
{
	delete ui;
}

hkpConstraintData* Malleable::getConstraint()
{
	auto child = array[ui->comboBoxChild->currentIndex()]->getConstraint();
	auto data = new hkpMalleableConstraintData((hkpConstraintData*)child);
	child->removeReference();
	data->setStrength(ui->spinBoxStrength->value());
	return data;
}

#include <QMessageBox>
int Malleable::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpMalleableConstraintData*>(p);
	if(!data) return false;
	auto child = data->getWrappedConstraintData();
	int ret = 0;
	for(int i=0; i<3; ++i)
	{
		auto flag = array[i]->parseConstraint(child);
		ret |= flag;
		if(flag > 0)
		{
			ui->comboBoxChild->setCurrentIndex(i);
			ui->comboBoxChild->setCurrentText(ui->comboBoxChild->itemText(i));
			on_comboBoxChild_currentIndexChanged(i);
		}
	}
	if(!ret)
	{
		auto childClass = getHavokClass(child);
		QString str = "hkpMalleableConstraint with child ";
		str += childClass->getName();
		str += " is not support yet.\n";
		str += "Continue?";
		if( QMessageBox::warning(this, "Constraint not support", str, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes )
			 return true;
		return -1;
	}
	
	return ret;
}

void Malleable::on_comboBoxChild_currentIndexChanged(int index)
{
	for(auto i : array) i->setVisible(0);
	array[index]->setVisible(1);
}
