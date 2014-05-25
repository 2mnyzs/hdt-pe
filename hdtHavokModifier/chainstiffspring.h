#ifndef CHAINSTIFFSPRING_H
#define CHAINSTIFFSPRING_H

#include <QWidget>
#include "chainbase.h"

namespace Ui {
	class ChainStiffSpring;
}

class ChainStiffSpring : public ChainBase
{
	Q_OBJECT
	
public:
	explicit ChainStiffSpring(QWidget *parent = 0);
	~ChainStiffSpring();
	
private:
	Ui::ChainStiffSpring *ui;
	hkRefPtr<hkpStiffSpringChainData> chain;
	
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

#endif // CHAINSTIFFSPRING_H
