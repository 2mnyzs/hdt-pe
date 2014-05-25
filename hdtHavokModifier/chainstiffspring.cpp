#include "chainstiffspring.h"
#include "ui_chainstiffspring.h"

ChainStiffSpring::ChainStiffSpring(QWidget *parent) :
	ChainBase(parent),
	ui(new Ui::ChainStiffSpring)
{
	ui->setupUi(this);
	chain = new hkpStiffSpringChainData;
	ui->pivotA->setPrecision(4);
	ui->pivotB->setPrecision(4);
}

ChainStiffSpring::~ChainStiffSpring()
{
	delete ui;
}

int ChainStiffSpring::size()
{
	return chain->m_infos.getSize();
}

void ChainStiffSpring::setSize(int size)
{
	hkpStiffSpringChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	info.m_springLength = 1;
	chain->m_infos.setSize(size, info);
}

void ChainStiffSpring::apply(int idx)
{
	ui->pivotA->getVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->getVector(chain->m_infos[idx].m_pivotInB);
	chain->m_infos[idx].m_springLength = ui->length->value();
}

void ChainStiffSpring::setIndex(int idx)
{
	ui->pivotA->setVector(chain->m_infos[idx].m_pivotInA);
	ui->pivotB->setVector(chain->m_infos[idx].m_pivotInB);
	ui->length->setValue(chain->m_infos[idx].m_springLength);
}

void ChainStiffSpring::erase(int idx)
{
	chain->m_infos.removeAtAndCopy(idx);
}

void ChainStiffSpring::insert(int idx)
{
	hkpStiffSpringChainData::ConstraintInfo info;
	info.m_pivotInA.setZero();
	info.m_pivotInB.setZero();
	info.m_springLength = 1;
	chain->m_infos.insertAt(idx, info);
}

hkpConstraintChainData *ChainStiffSpring::getChain()
{
	return chain;
}

bool ChainStiffSpring::parseChain(const hkpConstraintChainData *data)
{
	auto cvt = dynamic_cast<const hkpStiffSpringChainData*>(data);
	if(!cvt) return false;
	chain->m_infos.clear();
	chain->m_infos.append(cvt->m_infos);
	return true;
}

void ChainStiffSpring::getTauDamping(float &tau, float &damping)
{
	tau = chain->m_tau;
	damping = chain->m_damping;
}

void ChainStiffSpring::setTauDamping(float tau, float damping)
{
	chain->m_tau = tau;
	chain->m_damping = damping;
}


