#include "ballandsocket.h"
#include "ui_ballandsocket.h"

BallAndSocket::BallAndSocket(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::BallAndSocket)
{
	ui->setupUi(this);
}

BallAndSocket::~BallAndSocket()
{
	delete ui;
}

hkpConstraintData* BallAndSocket::getConstraint()
{
	hkVector4 pivotA, pivotB;
	ui->widgetPivotA->getVector(pivotA);
	ui->widgetPivotB->getVector(pivotB);
	auto data = new hkpBallAndSocketConstraintData;
	data->setInBodySpace(pivotA, pivotB);
	return data;
}

int BallAndSocket::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpBallAndSocketConstraintData*>(p);
	if(!data) return false;
	ui->widgetPivotA->setVector(data->m_atoms.m_pivots.m_translationA);
	ui->widgetPivotB->setVector(data->m_atoms.m_pivots.m_translationB);
	return true;
}
