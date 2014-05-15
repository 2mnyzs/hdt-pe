#pragma once

#include "havok_helper.h"
#include "netimmerse_helper.h"
#include "common.h"

class CPhysObject : public Lockable
{
public:
	virtual ~CPhysObject(void){};

	virtual bool CreateIfValid() = 0;
	
	virtual void ReadFromWorld() = 0;
	virtual void WriteToWorld(float invDeltaTime) = 0;

	virtual void AddToWorld(hkpWorld* pWorld) = 0;
	virtual void RemoveFromWorld() = 0;
};

class CFormObject : public CPhysObject
{
public:
	CFormObject(int form):m_formID(form){}
	int GetID() const{ return m_formID; }

protected:
	const int m_formID;
};

class CSystemObject : public CPhysObject
{
public:
	CSystemObject(){ m_system = 0; m_world = 0; m_skeleton = 0; }
	virtual ~CSystemObject();
	
	bool BindPhysicsInfo(hkpPhysicsSystem* m_system, NiNode* skeleton);

	virtual bool CreateIfValid(){ return true; }
	
	virtual void ReadFromWorld();
	virtual void WriteToWorld(float invDeltaTime);

	virtual void AddToWorld(hkpWorld* pWorld);
	virtual void RemoveFromWorld();
	
	static void RenameBodies(NiNode* skeleton, hkpPhysicsSystem* system, const std::string& prefix);

	const hkArray<NiNode*>& getBones() const{ return m_bones; }
	const hkpPhysicsSystem* getSystem() const{ return m_system; }
	
protected:
	
	hkpPhysicsSystem* m_system;
	hkArray<NiNode*> m_bones;
	NiNode* m_skeleton;
	
	hkpWorld* m_world;
};

class CSystemFormObject : public CFormObject
{
public:

	CSystemFormObject(int form):CFormObject(form){}
	virtual bool CreateIfValid() = 0;

	virtual void ReadFromWorld();
	virtual void WriteToWorld(float invDeltaTime);
	virtual void AddToWorld(hkpWorld* pWorld);
	virtual void RemoveFromWorld();
	
protected:
	
	struct Info
	{
		Info():model(0), system(0){}
		NiNode* model;
		std::shared_ptr<CSystemObject> system;
	};

	std::unordered_multimap<UINT32, Info> m_objects;
};

bool IsVanillaBone(const char* name);