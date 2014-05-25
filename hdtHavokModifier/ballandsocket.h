#ifndef BALLANDSOCKET_H
#define BALLANDSOCKET_H

#include <QWidget>
#include "constraintbase.h"

namespace Ui {
	class BallAndSocket;
}

class BallAndSocket : public ConstraintBase
{
	Q_OBJECT
	
public:
	explicit BallAndSocket(QWidget *parent = 0);
	~BallAndSocket();
	
	virtual hkpConstraintData* getConstraint();
	virtual int parseConstraint(const hkpConstraintData*);
	
private:
	Ui::BallAndSocket *ui;
};

#endif // BALLANDSOCKET_H
