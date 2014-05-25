#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <QWidget>

#include "havokhelper.h"

class ChainBase : public QWidget
{
	Q_OBJECT
public:
	explicit ChainBase(QWidget *parent = 0);
	
	virtual int size() = 0;
	virtual void setSize(int size) = 0;
	virtual void apply(int idx) = 0;
	virtual void setIndex(int idx) = 0;
	virtual void erase(int idx) = 0;
	virtual void insert(int idx) = 0;
	
	virtual hkpConstraintChainData* getChain() = 0;
	virtual bool parseChain(const hkpConstraintChainData* data) = 0;
	
	virtual void getTauDamping(float& tau, float& damping) = 0;
	virtual void setTauDamping(float tau, float damping) = 0;
	
signals:
	
public slots:
	
};

#endif // CHAINBASE_H
