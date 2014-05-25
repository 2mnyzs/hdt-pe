#ifndef CHAINBALLSOCKET_H
#define CHAINBALLSOCKET_H

#include <QWidget>
#include "chainbase.h"

namespace Ui {
	class ChainBallSocket;
}

class ChainBallSocket : public ChainBase
{
	Q_OBJECT
	
public:
	explicit ChainBallSocket(QWidget *parent = 0);
	~ChainBallSocket();
	
private:
	Ui::ChainBallSocket *ui;
	hkRefPtr<hkpBallSocketChainData> chain;
	
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

#endif // CHAINBALLSOCKET_H
