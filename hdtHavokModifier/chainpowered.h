#ifndef CHAINPOWERED_H
#define CHAINPOWERED_H

#include <QWidget>
#include "chainbase.h"

namespace Ui {
	class ChainPowered;
}

class ChainPowered : public ChainBase
{
	Q_OBJECT
	
public:
	explicit ChainPowered(QWidget *parent = 0);
	~ChainPowered();
	
private:
	Ui::ChainPowered *ui;
	hkRefPtr<hkpPoweredChainData> chain;
	
	// ChainBase interface
public:
	int size();
	void setSize(int size);
	void apply(int idx);
	void setIndex(int idx);
	void erase(int idx);
	void insert(int idx);
	hkpConstraintChainData *getChain();
	bool parseChain(const hkpConstraintChainData *data);
	void getTauDamping(float& tau, float& damping);
	void setTauDamping(float tau, float damping);
};

#endif // CHAINPOWERED_H
