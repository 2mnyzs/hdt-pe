#include "chainballsocket.h"
#include "ui_chainballsocket.h"

ChainBallSocket::ChainBallSocket(QWidget *parent) :
	ChainBase(parent),
	ui(new Ui::ChainBallSocket)
{
	ui->setupUi(this);
	chain = new hkpBallSocketChainData;
	ui->pivotA->setPrecision(4);
	ui->pivotB->setPrecision(4);
}

ChainBallSocket::~ChainBallSocket()
{
	delete ui;
}

int ChainBallSocket::size()
{
	return chain->m_infos.getSize();
}

void ChainBallSocket::setSize(int size)
{
	hkpBallSocketChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	chain->m_infos.setSize(size, info);
}

void ChainBallSocket::apply(int idx)
{
	ui->pivotA->getVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->getVector(chain->m_infos[idx].m_pivotInB);
}

void ChainBallSocket::setIndex(int idx)
{
	ui->pivotA->setVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->setVector(chain->m_infos[idx].m_pivotInB);
}

void ChainBallSocket::erase(int idx)
{
	chain->m_infos.removeAtAndCopy(idx);
}

void ChainBallSocket::insert(int idx)
{
	hkpBallSocketChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	chain->m_infos.insertAt(idx, info);
}

hkpConstraintChainData *ChainBallSocket::getChain()
{
	return chain;
}

bool ChainBallSocket::parseChain(const hkpConstraintChainData *data)
{
	auto cvt = dynamic_cast<const hkpBallSocketChainData*>(data);
	if(!cvt) return false;
	chain->m_infos.clear();
	chain->m_infos.append(cvt->m_infos);
	return true;
}

void ChainBallSocket::getTauDamping(float &tau, float &damping)
{
	tau = chain->m_tau;
	damping = chain->m_damping;
}

void ChainBallSocket::setTauDamping(float tau, float damping)
{
	chain->m_tau = tau;
	chain->m_damping = damping;
}

