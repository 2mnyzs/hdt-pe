#pragma once

#include "PhysObject.h"

class CHair : public CSystemFormObject
{
public:
	CHair(int form);
	~CHair(void);

	virtual bool CreateIfValid();
	virtual void WriteToWorld(float invDeltaTime);

protected:

	void Clear();
	void LoadPhysicsSystem(NiNode* model, const char* path);
	
	NiNode* m_skeleton;

	struct Model
	{
		Model():m_sceneRoot(0){}

		NiNode* m_sceneRoot;
		std::vector<std::pair<NiNode*, NiNode*>> m_boneMap;
	};

	std::unordered_map<NiGeometry*, Model> m_modelMap;
};

