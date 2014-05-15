#include "havok_helper.h"
#include "log.h"

#include <Common\Base\keycode.cxx>
#include <Common\Base\Config\hkProductFeatures.cxx>

void GetNiTransform(const NiTransform& in, hkQsTransform& out)
{
	GetNiTransform(in, out.m_translation, out.m_rotation);
	out.m_scale.set(in.scale, in.scale, in.scale);
}

void SetNiTransform(NiTransform& out, const hkQsTransform& in)
{
	float temp[4];
	SetNiTransform(out, in.m_translation, in.m_rotation);
	in.getScale().store4(temp);
	out.scale = temp[0];
}

void GetNiTransformScaled(const NiTransform& in, hkQsTransform& out)
{
	GetNiTransformScaled(in, out.m_translation, out.m_rotation);
	out.m_scale.set(in.scale, in.scale, in.scale);
}

void SetNiTransformScaled(NiTransform& out, const hkQsTransform& in)
{
	float temp[4];
	SetNiTransformScaled(out, in.m_translation, in.m_rotation);
	in.getScale().store4(temp);
	out.scale = temp[0];
}

void GetNiTransform(const NiTransform& in, hkTransform& out)
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	hkVector4 pos;
	hkRotation rot;
	hkVector4 col0(in.rot.data[0],in.rot.data[3],in.rot.data[6]);
	hkVector4 col1(in.rot.data[1],in.rot.data[4],in.rot.data[7]);
	hkVector4 col2(in.rot.data[2],in.rot.data[5],in.rot.data[8]);
	rot.setCols(col0, col1, col2);
	pos.set(in.pos.x, in.pos.y, in.pos.z);

	out.setRotation(rot);
	out.setTranslation(pos);
}

void SetNiTransform(NiTransform& out, const hkTransform& in)
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	float temp[4];
	hkVector4 mat[3];
	in.getRotation().getRows(mat[0], mat[1], mat[2]);
	mat[0].store3(out.rot.data);
	mat[1].store3(out.rot.data+3);
	mat[2].store3(out.rot.data+6);

	in.getTranslation().store4(temp);
	out.pos.x = temp[0];
	out.pos.y = temp[1];
	out.pos.z = temp[2];
}

void GetNiTransformScaled(const NiTransform& in, hkTransform& out)
{
	GetNiTransform(in, out);
	out.getTranslation().mul(scaleToHavok);
}

void SetNiTransformScaled(NiTransform& out, const hkTransform& in)
{
	SetNiTransform(out, in);
	out.pos.x *= scaleToSkyrim;
	out.pos.y *= scaleToSkyrim;
	out.pos.z *= scaleToSkyrim;
}

void GetNiTransform(const NiTransform& in, hkVector4& pos, hkQuaternion& q)
{
	hkTransform trans;
	GetNiTransform(in, trans);
	q.setAndNormalize(trans.getRotation());
	pos = trans.getTranslation();
}

void SetNiTransform(NiTransform& out, const hkVector4& pos, const hkQuaternion& q)
{
	hkTransform trans;
	hkVector4 axis;

	trans.getRotation().set(q);
	trans.setTranslation(pos);

	SetNiTransform(out, trans);
}

void GetNiTransformScaled(const NiTransform& in, hkVector4& pos, hkQuaternion& q)
{
	hkTransform trans;
	GetNiTransformScaled(in, trans);
	q.setAndNormalize(trans.getRotation());
	pos = trans.getTranslation();
}

void SetNiTransformScaled(NiTransform& out, const hkVector4& pos, const hkQuaternion& q)
{
	hkTransform trans;
	hkVector4 axis;
	
	trans.getRotation().set(q);
	trans.setTranslation(pos);

	SetNiTransformScaled(out, trans);
}

void ScaleMotorLinear(hkpConstraintMotor* motor, float scale)
{
	if(!motor) return;
	switch(motor->getType())
	{
	case hkpConstraintMotor::TYPE_POSITION:
		{
			auto m = (hkpPositionConstraintMotor*)motor;
			m->m_maxForce *= scale;
			m->m_minForce *= scale;
			m->m_constantRecoveryVelocity *= scale;
		}
		break;
		
	case hkpConstraintMotor::TYPE_SPRING_DAMPER:
		{
			auto m = (hkpSpringDamperConstraintMotor*)motor;
			m->m_maxForce *= scale;
			m->m_minForce *= scale;
		}
		break;
		
	case hkpConstraintMotor::TYPE_VELOCITY:
		{
			auto m = (hkpVelocityConstraintMotor*)motor;
			m->m_maxForce *= scale;
			m->m_minForce *= scale;
			m->m_velocityTarget *= scale;
		}
		break;

	default: break;
	}
}

void ScaleMotorAngular(hkpConstraintMotor* motor, float scale)
{
	if(!motor) return;
	switch(motor->getType())
	{
	case hkpConstraintMotor::TYPE_POSITION:
		{
			auto m = (hkpPositionConstraintMotor*)motor;
			m->m_maxForce *= scale*scale;	// torgue?
			m->m_minForce *= scale*scale;
		}
		break;
		
	case hkpConstraintMotor::TYPE_SPRING_DAMPER:
		{
			auto m = (hkpSpringDamperConstraintMotor*)motor;
			m->m_maxForce *= scale*scale;
			m->m_minForce *= scale*scale;
			m->m_springConstant *= scale*scale;	// ¦Á=T/I = (k¦¤¦Ø)/I  alpha£ºAngular acceleration£¬ k£ºspringConstant I£ºinertia, T: torgue
			m->m_springDamping *= scale*scale;	//	I is scaled by X^2 so we scale k by X^2 to keep alpha constant
		}
		break;
		
	case hkpConstraintMotor::TYPE_VELOCITY:
		{
			auto m = (hkpVelocityConstraintMotor*)motor;
			m->m_maxForce *= scale*scale;
			m->m_minForce *= scale*scale;
		}
		break;

	default: break;
	}
}

void ScaleConstraint(hkpConstraintData* data, float scaleA, float scaleB)
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	float scale = (scaleA+scaleB)*0.5;
	if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_BALL_SOCKET_CHAIN)
	{
		auto chain = (hkpBallSocketChainData*)data;
		for(int i=0; i<chain->m_infos.getSize(); ++i)
		{
			chain->m_infos[i].m_pivotInA.mul(scaleA);
			chain->m_infos[i].m_pivotInB.mul(scaleB);
		}
	}
	else if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_STIFF_SPRING_CHAIN)
	{
		auto chain = (hkpStiffSpringChainData*)data;
		for(int i=0; i<chain->m_infos.getSize(); ++i)
		{
			chain->m_infos[i].m_pivotInA.mul(scaleA);
			chain->m_infos[i].m_pivotInB.mul(scaleB);
			chain->m_infos[i].m_springLength *= (scaleA+scaleB)*0.5;
		}
	}
	else if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_POWERED_CHAIN)
	{
		auto chain = (hkpPoweredChainData*)data;
		for(int i=0; i<chain->m_infos.getSize(); ++i)
		{
			chain->m_infos[i].m_pivotInA.mul(scaleA);
			chain->m_infos[i].m_pivotInB.mul(scaleB);
			ScaleMotorAngular(chain->m_infos[i].m_motors[0], scale);
			ScaleMotorAngular(chain->m_infos[i].m_motors[1], scale);
			ScaleMotorAngular(chain->m_infos[i].m_motors[2], scale);
		}
	}
	else if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_BREAKABLE)
	{
		auto b = (hkpBreakableConstraintData*)data;
		ScaleConstraint(b->m_constraintData, scaleA, scaleB);
	}
	else if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_MALLEABLE)
	{
		auto b = (hkpMalleableConstraintData*)data;
		ScaleConstraint(b->getWrappedConstraintData(), scaleA, scaleB);
	}
	else if(data->getType() == hkpConstraintData::CONSTRAINT_TYPE_GENERIC)
	{
		auto list = ((hkpGenericConstraintData*)data)->getScheme();
		for(int i=0, j=0; i<list->m_commands.getSize(); ++i)
		{
			switch(list->m_commands[i])
			{
			case hkpGenericConstraintDataScheme::e_setPivotA:
				list->m_data[j].mul(scaleA);
				++j;
				break;

			case hkpGenericConstraintDataScheme::e_setPivotB:
				list->m_data[j].mul(scaleB);
				++j;
				break;

			case hkpGenericConstraintDataScheme::e_setLinearLimit:
				list->m_data[j].mul((scaleA+scaleB)*0.5);
				++i; ++j;
				break;
				
			case hkpGenericConstraintDataScheme::e_setLinearMotor:
				{
					int idx = list->m_data[j].getComponent(0);
					auto old = list->m_motors[idx];
					list->m_motors[idx] = old->clone();
					ScaleMotorLinear(list->m_motors[idx], scale);
					old->removeReference();
					++i; ++j;
					break;
				}

			case hkpGenericConstraintDataScheme::e_setAngularMotor:
				{
					int idx = list->m_data[j].getComponent(0);
					auto old = list->m_motors[idx];
					list->m_motors[idx] = old->clone();
					ScaleMotorAngular(list->m_motors[idx], scale);
					old->removeReference();
					++i; ++j;
					break;
				}
				break;

			case hkpGenericConstraintDataScheme::e_setAngularBasisA:
			case hkpGenericConstraintDataScheme::e_setAngularBasisB:
				j+=3;
				break;

			case hkpGenericConstraintDataScheme::e_setTwistLimit:
				++i;
			case hkpGenericConstraintDataScheme::e_setConeLimit:
			case hkpGenericConstraintDataScheme::e_setAngularLimit:
			case hkpGenericConstraintDataScheme::e_setAngularFriction:
			case hkpGenericConstraintDataScheme::e_setLinearDofA:
			case hkpGenericConstraintDataScheme::e_setLinearDofB:
			case hkpGenericConstraintDataScheme::e_setLinearDofW:
			case hkpGenericConstraintDataScheme::e_setLinearFriction:
				++i; ++j;
				break;
								
			case hkpGenericConstraintDataScheme::e_constrainLinearW:
			case hkpGenericConstraintDataScheme::e_constrainToAngularW:
				++i;
				break;

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
	}
	else
	{
		hkpConstraintData::ConstraintInfo info;
		data->getConstraintInfo(info);

		static const int nextAtom[] = {
			0,
			sizeof(hkpBridgeConstraintAtom),
			sizeof(hkpSetLocalTransformsConstraintAtom),
			sizeof(hkpSetLocalTranslationsConstraintAtom),
			sizeof(hkpSetLocalRotationsConstraintAtom),
			sizeof(hkpBallSocketConstraintAtom),
			sizeof(hkpStiffSpringConstraintAtom),
			sizeof(hkpLinConstraintAtom),
			sizeof(hkpLinSoftConstraintAtom),
			sizeof(hkpLinLimitConstraintAtom),
			sizeof(hkpLinFrictionConstraintAtom),
			sizeof(hkpLinMotorConstraintAtom),
			sizeof(hkp2dAngConstraintAtom),
			sizeof(hkpAngConstraintAtom),
			sizeof(hkpAngLimitConstraintAtom),
			sizeof(hkpTwistLimitConstraintAtom),
			sizeof(hkpConeLimitConstraintAtom),
			sizeof(hkpAngFrictionConstraintAtom),
			sizeof(hkpAngMotorConstraintAtom),
			sizeof(hkpRagdollMotorConstraintAtom),
			sizeof(hkpPulleyConstraintAtom),
			sizeof(hkpRackAndPinionConstraintAtom),
			sizeof(hkpCogWheelConstraintAtom),
			sizeof(hkpSetupStabilizationAtom),
			sizeof(hkp3dAngConstraintAtom),
			sizeof(hkpDeformableAngConstraintAtom),
			sizeof(hkpDeformableLinConstraintAtom),
			sizeof(hkpOverwritePivotConstraintAtom),
			sizeof(hkpSimpleContactConstraintAtom),
			sizeof(hkpSoftContactModifierConstraintAtom),
			sizeof(hkpMassChangerModifierConstraintAtom),
			sizeof(hkpViscousSurfaceModifierConstraintAtom),
			sizeof(hkpMovingSurfaceModifierConstraintAtom),
			sizeof(hkpIgnoreModifierConstraintAtom),
			sizeof(hkpCenterOfMassChangerModifierConstraintAtom),
		};
		for(auto atom = info.m_atoms; (UINT32)atom - (UINT32)info.m_atoms<info.m_sizeOfAllAtoms; )
		{
			if(atom->m_type == hkpConstraintAtom::TYPE_INVALID)
				break;
			else if(atom->m_type == hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS)
			{
				auto lct = (hkpSetLocalTransformsConstraintAtom*)atom;
				lct->m_transformA.getTranslation().mul(scaleA);
				lct->m_transformB.getTranslation().mul(scaleB);
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_SET_LOCAL_TRANSLATIONS)
			{
				auto lct = (hkpSetLocalTranslationsConstraintAtom*)atom;
				lct->m_translationA.mul(scaleA);
				lct->m_translationB.mul(scaleB);
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_STIFF_SPRING)
			{
				auto lct = (hkpStiffSpringConstraintAtom*)atom;
				lct->m_length *= scale;
				lct->m_maxLength *= scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_LIN_LIMIT)
			{
				auto lct = (hkpLinLimitConstraintAtom*)atom;
				lct->m_max *= scale;
				lct->m_min *= scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_LIN_MOTOR)
			{
				auto lct = (hkpLinMotorConstraintAtom*)atom;
				lct->m_targetPosition *= scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_LIN_FRICTION)
			{
				auto lct = (hkpLinFrictionConstraintAtom*)atom;
				lct->m_maxFrictionForce *= scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_DEFORMABLE_3D_LIN)
			{
				auto lct = (hkpDeformableLinConstraintAtom*)atom;
				lct->m_offset.mul(scale);
				lct->m_ultimateStrengthDiag.mul(scale);
				lct->m_ultimateStrengthOffDiag.mul(scale);
				lct->m_yieldStrengthDiag.mul(scale);
				lct->m_yieldStrengthOffDiag.mul(scale);
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_DEFORMABLE_3D_ANG)
			{
				auto lct = (hkpDeformableAngConstraintAtom*)atom;
				lct->m_ultimateStrengthDiag.mul(scale*scale);
				lct->m_ultimateStrengthOffDiag.mul(scale*scale);
				lct->m_yieldStrengthDiag.mul(scale*scale);
				lct->m_yieldStrengthOffDiag.mul(scale*scale);
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_ANG_FRICTION)
			{
				auto lct = (hkpAngFrictionConstraintAtom*)atom;
				lct->m_maxFrictionTorque *= scale*scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_RACK_AND_PINION)
			{
				auto lct = (hkpRackAndPinionConstraintAtom*)atom;
				lct->m_pinionRadiusOrScrewPitch *= scale;
				atom = lct->next();
			}
			else if(atom->m_type == hkpConstraintAtom::TYPE_COG_WHEEL)
			{
				auto lct = (hkpCogWheelConstraintAtom*)atom;
				lct->m_cogWheelRadiusA *= scaleA;
				lct->m_cogWheelRadiusB *= scaleB;
				atom = lct->next();
			}
			else atom = (hkpConstraintAtom*)((UINT8*)atom + nextAtom[atom->m_type]);
		}

		if(data->getType() == data->CONSTRAINT_TYPE_RAGDOLL)
		{
			auto d = (hkpRagdollConstraintData*)data;
			ScaleMotorAngular(d->getConeMotor(), scale);
			ScaleMotorAngular(d->getPlaneMotor(), scale);
			ScaleMotorAngular(d->getTwistMotor(), scale);
		}
		else if(data->getType() == data->CONSTRAINT_TYPE_HINGE)
		{
			auto d = (hkpLimitedHingeConstraintData*)data;
			ScaleMotorAngular(d->getMotor(), scale);
		}
		else if(data->getType() == data->CONSTRAINT_TYPE_PRISMATIC)
		{
			auto d = (hkpPrismaticConstraintData*)data;
			ScaleMotorLinear(d->getMotor(), scale);
		}
		else if(data->getType() == data->CONSTRAINT_TYPE_LINEAR_SLACK)
		{
			auto d = (hkpLinearClearanceConstraintData*)data;
			ScaleMotorLinear(d->getMotor(), scale);
		}
	}
}

void ScaleRigidBody(hkpRigidBody* rb, float scale)
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
	auto vec = rb->getCenterOfMassLocal();
	vec.mul(scale);
	rb->setCenterOfMassLocal(vec);
	rb->getCollidableRw()->m_allowedPenetrationDepth *= scale;
	vec = rb->getLinearVelocity();
	vec.mul(scale);
	rb->setLinearVelocity(vec);

	auto shape = rb->getCollidableRw()->getShape();
	shape = hkpShapeScalingUtility::scaleShapeSimd((hkpShape*)shape, scale);
	rb->setShape(shape);

	if(!rb->isFixedOrKeyframed())
	{
		hkMatrix3 inertia;
		rb->getInertiaLocal(inertia);
		hkVector4 scale4;
		scale4.setAll(scale*scale);
		inertia.setDiagonalMul(scale4, inertia);
		rb->setInertiaLocal(inertia);
	}
}

bool ScaleSystemWithNode(const hkArray<NiNode*>& bones, hkpPhysicsSystem* system, float defaultScale)
{
	auto& bodies = system->getRigidBodies();
	auto& constraints = system->getConstraints();
	
	std::unordered_map<hkpEntity*, float> mapScale;

	LogDebug("Scaling bodies...");
	for(int i=0; i<bodies.getSize(); ++i)
	{
		float scale;
		if(!bones[i])
		{
			LogWarning("Cannot bind bone : %s - bone doesn't exist", bodies[i]->getName());
			if(!IsDynamic(bodies[i]->getMotionType()))
			{
				LogError("Illegal hkx file : %s - Fixed/Keyframed body without binding!", bodies[i]->getName());
				return false;
			}
			scale = defaultScale;
		}
		else scale = bones[i]->m_worldTransform.scale;
		scale *= scaleToHavok;
		mapScale.insert(std::make_pair(bodies[i], scale));
		ScaleRigidBody(bodies[i], scale);
	}
	
	auto getScale = [&, defaultScale](hkpEntity* e)->float
	{
		auto idx = mapScale.find(e);
		if(idx == mapScale.end())
			return defaultScale;
		return idx->second;
	};

	LogDebug("Scaling constraints...");
	for(int i=0; i<constraints.getSize(); ++i)
		if(constraints[i]->getType() != hkpConstraintInstance::TYPE_CHAIN
		&& constraints[i]->getEntityA()->isFixedOrKeyframed()
		&& constraints[i]->getEntityB()->isFixedOrKeyframed())
				system->removeConstraint(i--);

	for(int i=0; i<constraints.getSize(); ++i)
	{
		if(constraints[i]->getType() == hkpConstraintInstance::TYPE_CHAIN)
		{
			auto chain = (hkpConstraintChainInstance*)constraints[i];
			float scale = getScale(chain->getEntityA());
			ScaleConstraint(chain->getDataRw(), scale, scale);
		}
		else
		{
			float scaleA = getScale(constraints[i]->getEntityA());
			float scaleB = getScale(constraints[i]->getEntityB());
			ScaleConstraint(constraints[i]->getDataRw(), scaleA, scaleB);
		}
	}

	LogDebug("Havok physics system attached...");
	hkpConstraintStabilizationUtil::stabilizePhysicsSystemInertias(system);
	return true;
}

hkUint32 MyGroupFilter::calcCollisionInfo(hkUint32 myGroup, hkUint32 noCollideWith)
{
	return (myGroup<<24) | (noCollideWith & 0x00FFFFFF);
}

bool MyGroupFilter::isFiltered(hkUint32 a, hkUint32 b)
{
	auto groupA = a>>24;
	auto mask = groupA >= 24 ? -1 : (1<<groupA);
	return b&mask;
}

bool MyGroupFilter::isCollisionEnabled(hkUint32 a, hkUint32 b)
{
	auto f0 = !isFiltered(a,b);
	auto f1 = !isFiltered(b,a);
	return f0 && f1;
}

hkBool MyGroupFilter::isCollisionEnabled( const hkpCollidable& a, const hkpCollidable& b ) const
{
	return isCollisionEnabled( a.getCollisionFilterInfo(), b.getCollisionFilterInfo() );
}

#include <Physics2012\Collide\Agent\hkpCollisionInput.h>

hkBool MyGroupFilter::isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& a, const hkpCdBody& b, const hkpShapeContainer& bCollection, hkpShapeKey bKey  ) const
{
	hkUint32 infoB = bCollection.getCollisionFilterInfo( bKey );
	// We need a corresponding filter info for 'a'. Whether we should get this from a parent/grandparent/etc... of 'a' in the case that
	// 'a' is part of a shape collection depends on how we decide to handle the 'collection vs collection' case.
	// Here we just assume that we do not have collections colliding against collections, and use the filter info of the root collidable of 'a'
	return isCollisionEnabled( a.getRootCollidable()->getCollisionFilterInfo(), infoB );
}

hkBool MyGroupFilter::isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const HK_SHAPE_CONTAINER& containerShapeA, const HK_SHAPE_CONTAINER& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB ) const
{
	hkUint32 infoA = containerShapeA.getCollisionFilterInfo( keyA );
	hkUint32 infoB = containerShapeB.getCollisionFilterInfo( keyB );
	return isCollisionEnabled( infoA, infoB );
}

hkBool MyGroupFilter::isCollisionEnabled( const hkpShapeRayCastInput& aInput, const hkpShapeContainer& bContainer, hkpShapeKey bKey ) const 
{
	hkUint32 infoB = bContainer.getCollisionFilterInfo( bKey );
	return isCollisionEnabled( aInput.m_filterInfo, infoB );
}

hkBool MyGroupFilter::isCollisionEnabled( const hkpWorldRayCastInput& aInput, const hkpCollidable& collidableB ) const
{
	return isCollisionEnabled( aInput.m_filterInfo, collidableB.getCollisionFilterInfo() );
}

hkpPhysicsSystem* LoadPhysicsFile(const char* path)
{
	BSResourceNiBinaryStream fileStream(path);
	if(!fileStream.IsValid())
	{
		LogError("Load \"%s\" error - file no exist", path);
		return nullptr;
	}

	int currRead;
	char buf[1000];
	std::vector<char> loaded;
	loaded.reserve(2000);
	while(true)
	{
		currRead = fileStream.Read(buf, sizeof(buf));
		loaded.resize(loaded.size()+currRead);
		memcpy(loaded.data() + loaded.size() - currRead, buf, currRead);
		if(currRead < sizeof(buf)) break;
	}

	hkSerializeUtil::ErrorDetails err;
	auto resource = hkSerializeUtil::load(loaded.data(), loaded.size(), &err);
	if(!resource)
	{
		LogError("Load \"%s\" error - ", err.defaultMessage.cString());
		return 0;
	}

	auto system = resource->getContents<hkpPhysicsSystem>();
	if(!system)
	{
		auto data = resource->getContents<hkpPhysicsData>();
		if(!data)
		{
			auto root = resource->getContents<hkRootLevelContainer>();
			if(root)
			{
				system = (hkpPhysicsSystem*)root->findObjectByType("hkpPhysicsSystem");
				if(!system)
				{
					data = (hkpPhysicsData*)root->findObjectByType("hkpPhysicsData");
					if(data && data->getPhysicsSystems().getSize())
					{
						system = data->getPhysicsSystems()[0];
						system->addReference();
					}
					if(data) data->removeReference();
				}
				delete root;
			}
		}
		else
		{
			system = data->getPhysicsSystems()[0];
			system->addReference();
			data->removeReference();
		}
	}
	if(!system)
		LogError("Couldn't find hkpPhysicsSystem in hkx file \"%s\"", path);
	else for(auto rb : system->getRigidBodies())
	{
		// correct dampings
		//v' = v*pow(1-damping, dt)
		//but in havok, v' = v*(1-dh*dt);(dh : damping havok)
		// so pow(1-damping, dt) = 1-dh*dt -> dh = (1-pow(1-d, dt))/dt
		rb->setLinearDamping( (1 - pow(1-rb->getLinearDamping(), TIME_TICK)) / TIME_TICK );
		rb->setAngularDamping( (1 - pow(1-rb->getAngularDamping(), TIME_TICK)) / TIME_TICK );
	}

	return system;
}
