#include "PhysObject.h"

CSystemObject::~CSystemObject()
{
	RemoveFromWorld();
	if(m_system)
		m_system->removeReference();

	for(auto i : m_bones)
		if(i) i->DecRef();
}

void SortAsTree(NiNode* skeleton, hkArray<NiNode*>& bones, hkArray<hkpRigidBody*>& rbs)
{
	std::vector<int> idx;
	std::vector<NiNode*> childlist;
	idx.resize(bones.getSize());
	for(int i=0; i<bones.getSize(); ++i)
		idx[i] = i;
	
	std::stable_sort(idx.begin(), idx.end(), [&](int a, int b)->bool
	{
		if(bones[a] == bones[b]) return false;
		return IsMyAncestor(bones[b], bones[a]);
	});

	hkArray<NiNode*> cbones;
	cbones.append(bones);

	hkArray<hkpRigidBody*> crbs;
	crbs.append(rbs);

	for(int i=0; i<idx.size(); ++i)
	{
		bones[i] = cbones[idx[i]];
		rbs[i] = crbs[idx[i]];
	}
}

bool CSystemObject::BindPhysicsInfo(hkpPhysicsSystem* system, NiNode* skeleton)
{
	auto& bodies = system->getRigidBodies();
	auto& constraints = system->getConstraints();
	m_bones.setSize(bodies.getSize());
	for(int i=0; i<bodies.getSize(); ++i)
	{
		m_bones[i] = ni_cast(skeleton->GetObjectByName(bodies[i]->getName()), NiNode);
		if(m_bones[i]) m_bones[i]->IncRef();
	}
	
	SortAsTree(skeleton, m_bones, (hkArray<hkpRigidBody*>&)bodies);
	
	for(int i=0; i<m_bones.getSize(); ++i)
	{
		if(bodies[i]->getMotionType() == hkpMotion::MOTION_FIXED)
			bodies[i]->setMotionType(hkpMotion::MOTION_KEYFRAMED);

		if(bodies[i]->getMotionType() == hkpMotion::MOTION_KEYFRAMED)
			for(int j=0; j<i; ++j)
			{
				if(bodies[j]->getMotionType() == hkpMotion::MOTION_KEYFRAMED)
					continue;

				if(IsMyAncestor(m_bones[i], m_bones[j]))
					bodies[j]->setMotionType(hkpMotion::MOTION_KEYFRAMED);
			}
	}

	if(!ScaleSystemWithNode(m_bones, system, skeleton->m_worldTransform.scale))
		return false;
	
	m_system = system;
	hkpConstraintStabilizationUtil::stabilizePhysicsSystemInertias(m_system);

	m_system->addReference();
	m_skeleton = skeleton;
	return true;
}

void CSystemObject::ReadFromWorld()
{
	auto& bodies = m_system->getRigidBodies();
	auto& constraints = m_system->getConstraints();
	
	for(int i=0; i<bodies.getSize(); ++i)
	{
		if(!m_bones[i]) continue;
		if(bodies[i]->isFixedOrKeyframed())	continue;
		hkTransform t = bodies[i]->getTransform();
		SetNiTransformScaled(m_bones[i]->m_worldTransform, t);
		UpdateLocalData(m_bones[i]);
	}
}

void CSystemObject::WriteToWorld(float invDeltaTime)
{
	auto& bodies = m_system->getRigidBodies();
	auto& constraints = m_system->getConstraints();
	
	hkVector4 pos;
	hkQuaternion rot;
	
	for(int i=0; i<bodies.getSize(); ++i)
	{
		if(!m_bones[i]) continue;
		if(!bodies[i]->isFixedOrKeyframed()) continue;

		GetNiTransformScaled(m_bones[i]->m_worldTransform, pos, rot);
		//bodies[i]->setPositionAndRotation(pos, rot);
		hkpKeyFrameUtility::applyHardKeyFrame(pos, rot, invDeltaTime, bodies[i]);
	}
}

void CSystemObject::AddToWorld(hkpWorld* pWorld)
{
	if(m_world == pWorld)
		return;

	if(m_world)
		RemoveFromWorld();
	
	auto& bodies = m_system->getRigidBodies();
	auto& constraints = m_system->getConstraints();

	for(int i=0; i<bodies.getSize(); ++i)
	{
		hkVector4 pos = hkVector4::getZero();
		hkQuaternion rot = hkQuaternion::getIdentity();
		if(m_bones[i])
			GetNiTransformScaled(m_bones[i]->m_worldTransform, pos, rot);
		bodies[i]->setPositionAndRotation(pos, rot);
		pWorld->addEntity(bodies[i]);
	}
	
	for(int i=0; i<constraints.getSize(); ++i)
		pWorld->addConstraint(constraints[i]);

	m_world = pWorld;
}

void CSystemObject::RemoveFromWorld()
{
	if(!m_world)
		return;

	auto& bodies = m_system->getRigidBodies();
	auto& constraints = m_system->getConstraints();
	
	for(int i=0; i<constraints.getSize(); ++i)
		m_world->removeConstraint(constraints[i]);

	for(int i=0; i<bodies.getSize(); ++i)
		m_world->removeEntity(bodies[i]);
	
	m_world = 0;
}

void CSystemObject::RenameBodies(NiNode* skeleton, hkpPhysicsSystem* system, const std::string& prefix)
{
	auto& bodies = system->getRigidBodies();
	for(int i=0; i<bodies.getSize(); ++i)
	{
		if(!bodies[i]->getName())
		{
			LogError("Illegal hkx file : body with no name");
			throw -1;
		}

		if(ni_cast(skeleton->GetObjectByName(bodies[i]->getName()), NiNode))
			continue;

		std::string newname = prefix + bodies[i]->getName();
		bodies[i]->setName(newname.c_str());
	}
}

void CSystemFormObject::ReadFromWorld()
{
	for(auto& i : m_objects)
		i.second.system->ReadFromWorld();
}

void CSystemFormObject::WriteToWorld(float invDeltaTime)
{
	for(auto& i : m_objects)
		i.second.system->WriteToWorld(invDeltaTime);
}

void CSystemFormObject::AddToWorld(hkpWorld* world)
{
	for(auto& i : m_objects)
		i.second.system->AddToWorld(world);
}

void CSystemFormObject::RemoveFromWorld()
{
	for(auto& i : m_objects)
		i.second.system->RemoveFromWorld();
}
