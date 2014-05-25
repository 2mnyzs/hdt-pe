#ifndef DIALOGCONSTRAINT_H
#define DIALOGCONSTRAINT_H

#include <QDialog>

namespace Ui {
	class DialogConstraint;
}

#include "generic.h"
#include "ballandsocket.h"
#include "cogwheel.h"
#include "deformablefixed.h"
#include "fixed.h"
#include "hinge.h"
#include "hingelimits.h"
#include "limitedhinge.h"
#include "linearclearance.h"
#include "malleable.h"
#include "pointtoplane.h"
#include "prismatic.h"
#include "rackandpinion.h"
#include "ragdoll.h"
#include "ragdolllimit.h"
#include "rotational.h"
#include "stiffspring.h"
#include "wheel.h"

#include <vector>

#include "chainballsocket.h"
#include "chainpowered.h"
#include "chainstiffspring.h"

class DialogConstraint : public QDialog
{
	Q_OBJECT
	
public:
	explicit DialogConstraint(const std::vector<hkpRigidBody*>& bodies, QWidget *parent = 0);
	~DialogConstraint();
	
	bool setConstraint(const hkpConstraintInstance* instance);
	hkpConstraintInstance* constraint;
	
	void accept();
	
private slots:
	void on_comboType_currentIndexChanged(int index);
		
	void on_comboChainType_currentIndexChanged(int index);
	
	void on_listWidget_currentRowChanged(int currentRow);
	
	void on_buttonAdd_clicked();
	
	void on_buttonRemove_clicked();
	
	void on_buttonUp_clicked();
	
	void on_toolButton_clicked();
	
private:
	Ui::DialogConstraint *ui;
	
	Generic generic;
	BallAndSocket ballAndSocket;
	CogWheel cogWheel;
	DeformableFixed deformableFixed;
	Fixed fixed;
	Hinge hinge;
	HingeLimits hingeLimits;
	LimitedHinge limitedHinge;
	LinearClearance linearClearance;
	Malleable malleable;
	PointToPlane pointToPlane;
	Prismatic prismatic;
	RackAndPinion rackAndPinion;
	Ragdoll ragdoll;
	RagdollLimit ragdollLimit;
	Rotational rotational;
	StiffSpring stiffSpring;
	Wheel wheel;
	
	const std::vector<hkpRigidBody*>& bodies;
	
	ConstraintBase* array[18];
	
	ChainBallSocket chainBallSocket;
	ChainPowered chainPowered;
	ChainStiffSpring chainStiffSpring;
	ChainBase* chains[3];
	int currentChainBody;
	ChainBase* currentChain;
	hkArray<hkpEntity*> chainBodies;
};

#endif // DIALOGCONSTRAINT_H
