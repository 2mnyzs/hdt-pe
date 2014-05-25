#include "chainpowered.h"
#include "ui_chainpowered.h"

ChainPowered::ChainPowered(QWidget *parent) :
	ChainBase(parent),
	ui(new Ui::ChainPowered)
{
	ui->setupUi(this);
	chain = new hkpPoweredChainData;
	ui->pivotA->setPrecision(4);
	ui->pivotB->setPrecision(4);
}

ChainPowered::~ChainPowered()
{
	delete ui;
}

int ChainPowered::size()
{
	return chain->m_infos.getSize();
}

void ChainPowered::setSize(int size)
{
	hkpPoweredChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	info.m_aTc.setIdentity();
	info.m_bTc.setIdentity();
	info.m_motors[0] = info.m_motors[1] = info.m_motors[2] = 0;
	info.m_switchBodies = false;
	chain->m_infos.setSize(size, info);
}

void ChainPowered::apply(int idx)
{
	ui->pivotA->getVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->getVector(chain->m_infos[idx].m_pivotInB);
	ui->basisA->getRotation(chain->m_infos[idx].m_aTc);
	ui->basisB->getRotation(chain->m_infos[idx].m_aTc);
	if(chain->m_infos[idx].m_motors[0]) chain->m_infos[idx].m_motors[0]->removeReference();
	if(chain->m_infos[idx].m_motors[1]) chain->m_infos[idx].m_motors[1]->removeReference();
	if(chain->m_infos[idx].m_motors[2]) chain->m_infos[idx].m_motors[2]->removeReference();
	chain->m_infos[idx].m_motors[0] = ui->motorX->getMotor();
	chain->m_infos[idx].m_motors[1] = ui->motorY->getMotor();
	chain->m_infos[idx].m_motors[2] = ui->motorZ->getMotor();
	chain->m_infos[idx].m_switchBodies = ui->switchBodies->isChecked();
}

void ChainPowered::setIndex(int idx)
{
	ui->pivotA->setVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->setVector(chain->m_infos[idx].m_pivotInB);
	ui->basisA->setRotation(chain->m_infos[idx].m_aTc);
	ui->basisB->setRotation(chain->m_infos[idx].m_aTc);
	ui->motorX->setMotor(chain->m_infos[idx].m_motors[0]);
	ui->motorY->setMotor(chain->m_infos[idx].m_motors[1]);
	ui->motorZ->setMotor(chain->m_infos[idx].m_motors[2]);
	ui->switchBodies->setChecked(chain->m_infos[idx].m_switchBodies);
}

void ChainPowered::erase(int idx)
{
	chain->m_infos.removeAtAndCopy(idx);
}

void ChainPowered::insert(int idx)
{
	hkpPoweredChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	info.m_aTc.setIdentity();
	info.m_bTc.setIdentity();
	info.m_motors[0] = info.m_motors[1] = info.m_motors[2] = 0;
	info.m_switchBodies = false;
	chain->m_infos.insertAt(idx, info);
}

hkpConstraintChainData *ChainPowered::getChain()
{
	return chain;
}

bool ChainPowered::parseChain(const hkpConstraintChainData *data)
{
	auto cvt = dynamic_cast<const hkpPoweredChainData*>(data);
	if(!cvt) return false;
	chain->m_infos.clear();
	chain->m_infos.append(cvt->m_infos);
	return true;
}

void ChainPowered::getTauDamping(float &tau, float &damping)
{
	tau = chain->m_tau;
	damping = chain->m_damping;
}

void ChainPowered::setTauDamping(float tau, float damping)
{
	chain->m_tau = tau;
	chain->m_damping = damping;
}

