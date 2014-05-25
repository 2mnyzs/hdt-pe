#include "generic.h"
#include "ui_generic.h"

Generic::Generic(QWidget *parent) :
	ConstraintBase(parent),
	ui(new Ui::Generic)
{
	ui->setupUi(this);
}

Generic::~Generic()
{
	delete ui;
}

hkpConstraintData* Generic::getConstraint()
{
	auto data = new hkpGenericConstraintData;
	hkpConstraintConstructionKit kit;
	kit.begin(data);
	{
		hkVector4 pivotA, pivotB;
		ui->pivotA->getVector(pivotA);
		ui->pivotB->getVector(pivotB);
		kit.setPivotA(pivotA);
		kit.setPivotB(pivotB);
		
		hkRotation linearBasis;
		ui->linearBasisB->getRotation(linearBasis);
		kit.setLinearDofB(linearBasis.getColumn(0), 0);
		kit.setLinearDofB(linearBasis.getColumn(1), 1);
		kit.setLinearDofB(linearBasis.getColumn(2), 2);
		hkVector4 linMin, linMax;
		ui->linearMin->getVector(linMin);
		ui->linearMax->getVector(linMax);
		for(int i=0; i<3; ++i)
		{
			if(linMin(i)==linMax(i) && !linMin(i))
				kit.constrainLinearDof(i);
			else if(linMin(i)<=linMax(i))
				kit.setLinearLimit(i, linMin(i), linMax(i));
		}
		auto lMotorX = ui->linearMotorX->getMotor();
		auto lMotorY = ui->linearMotorY->getMotor();
		auto lMotorZ = ui->linearMotorZ->getMotor();
		if(lMotorX) kit.setLinearMotor(0, lMotorX);
		if(lMotorY) kit.setLinearMotor(1, lMotorY);
		if(lMotorZ) kit.setLinearMotor(2, lMotorZ);
		if(lMotorX) lMotorX->removeReference();
		if(lMotorY) lMotorY->removeReference();
		if(lMotorZ) lMotorZ->removeReference();
		
		hkRotation basisA, basisB;
		ui->angularBasisA->getRotation(basisA);
		ui->angularBasisB->getRotation(basisB);
		kit.setAngularBasisA(basisA);
		kit.setAngularBasisB(basisB);
		hkVector4 angMin, angMax;
		ui->angularMin->getVector(angMin);
		ui->angularMax->getVector(angMax);
		for(int i=0; i<3; ++i)
		{
			if(angMin(i)==angMax(i) && !angMin(i))
				kit.constrainToAngularDof(i);
			else if(angMin(i)<=angMax(i))
				kit.setAngularLimit(i, angMin(i), angMax(i));
		}
		auto aMotorX = ui->angularMotorX->getMotor();
		auto aMotorY = ui->angularMotorY->getMotor();
		auto aMotorZ = ui->angularMotorZ->getMotor();
		if(aMotorX) kit.setAngularMotor(0, aMotorX);
		if(aMotorY) kit.setAngularMotor(1, aMotorY);
		if(aMotorZ) kit.setAngularMotor(2, aMotorZ);
		if(aMotorX) aMotorX->removeReference();
		if(aMotorY) aMotorY->removeReference();
		if(aMotorZ) aMotorZ->removeReference();
		
		hkVector4 linFri, angFri;
		ui->linearFriction->getVector(linFri);
		ui->angularFriction->getVector(angFri);
		for(int i=0; i<3; ++i) if(linFri(i)) kit.setLinearFriction(i, linFri(i));
		for(int i=0; i<3; ++i) if(angFri(i)) kit.setAngularFriction(i, angFri(i));
	}
	kit.end();
	return data;
}

int Generic::parseConstraint(const hkpConstraintData *p)
{
	auto data = dynamic_cast<const hkpGenericConstraintData*>(p);
	if(!data) return false;
	auto list = ((hkpGenericConstraintData*)data)->getScheme();
	
	hkVector4 linMin(1,1,1), linMax(0,0,0), linFri(0,0,0), angMin(1,1,1), angMax(0,0,0), angFri(0,0,0);
	hkRotation angularBasisA, angularBasisB, linearBasis;
	angularBasisA.setIdentity();
	angularBasisB.setIdentity();
	
	for(int i=0, j=0; i<list->m_commands.getSize(); ++i)
	{
		switch(list->m_commands[i])
		{
		case hkpGenericConstraintDataScheme::e_setPivotA:
			ui->pivotA->setVector(list->m_data[j++]);
			break;
			
		case hkpGenericConstraintDataScheme::e_setPivotB:
			ui->pivotB->setVector(list->m_data[j++]);
			break;
			
		case hkpGenericConstraintDataScheme::e_setLinearLimit:
		{
			int idx = list->m_commands[++i];
			linMin(idx) = list->m_data[j](0);
			linMax(idx) = list->m_data[j](1);
			++j;
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setAngularLimit:
		{
			int idx = list->m_commands[++i];
			angMin(idx) = list->m_data[j](0);
			angMax(idx) = list->m_data[j](1);
			++j;
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setLinearMotor:
		{
			int idx = list->m_data[j++].getComponent(0);
			auto motor = list->m_motors[idx];
			switch(list->m_commands[++i])
			{
			case 0:
				ui->linearMotorX->setMotor(motor);
				break;
			case 1:
				ui->linearMotorY->setMotor(motor);
				break;
			case 2:
				ui->linearMotorZ->setMotor(motor);
				break;
			}
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setAngularMotor:
		{
			int idx = list->m_data[j++].getComponent(0);
			auto motor = list->m_motors[idx];
			switch(list->m_commands[++i])
			{
			case 0:
				ui->angularMotorX->setMotor(motor);
				break;
			case 1:
				ui->angularMotorY->setMotor(motor);
				break;
			case 2:
				ui->angularMotorZ->setMotor(motor);
				break;
			}
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setAngularBasisA:
		{
			angularBasisA.getColumn(0) = list->m_data[j++];
			angularBasisA.getColumn(1) = list->m_data[j++];
			angularBasisA.getColumn(2) = list->m_data[j++];
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setAngularBasisB:
		{
			angularBasisB.getColumn(0) = list->m_data[j++];
			angularBasisB.getColumn(1) = list->m_data[j++];
			angularBasisB.getColumn(2) = list->m_data[j++];
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setLinearDofA:
		case hkpGenericConstraintDataScheme::e_setLinearDofB:
		case hkpGenericConstraintDataScheme::e_setLinearDofW:
		{
			int idx = list->m_commands[++i];
			linearBasis.getColumn(idx) = list->m_data[j++];
			linearBasis.getColumn(idx).normalize3();
			break;
		}
		
		case hkpGenericConstraintDataScheme::e_setTwistLimit:
			++i;
		case hkpGenericConstraintDataScheme::e_setConeLimit:
			++i; ++j;
			break;
		case hkpGenericConstraintDataScheme::e_setAngularFriction:
		{
			int idx = list->m_commands[++i];
			linFri(idx) = list->m_data[j++](0);
			break;
		}
		case hkpGenericConstraintDataScheme::e_setLinearFriction:
		{
			int idx = list->m_commands[++i];
			angFri(idx) = list->m_data[j++](0);
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_constrainLinearW:
		{
			int idx = list->m_commands[++i];
			linMin(idx) = 0;
			linMax(idx) = 0;
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_constrainToAngularW:
		{
			int idx = list->m_commands[++i];
			angMin(idx) = 0;
			angMax(idx) = 0;
			break;
		}
			
		case hkpGenericConstraintDataScheme::e_setStrength:
			++j;
			break;
			
		case hkpGenericConstraintDataScheme::e_doConstraintModifier:
			i+=2;
			break;
			
		default:
			break;
		}
	}
	
	ui->linearMin->setVector(linMin);
	ui->linearMax->setVector(linMax);
	ui->angularMin->setVector(angMin);
	ui->angularMax->setVector(angMax);
	ui->linearBasisB->setRotation(linearBasis);
	ui->angularBasisA->setRotation(angularBasisA);
	ui->angularBasisB->setRotation(angularBasisB);
	ui->linearFriction->setVector(linFri);
	ui->angularFriction->setVector(angFri);
	
	return true;
}
