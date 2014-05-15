#include "Hair.h"

CHair::CHair(int form)
	: CSystemFormObject(form)
{
	m_skeleton = 0;
}

CHair::~CHair(void)
{
	Clear();
}

void CHair::Clear()
{
	m_objects.clear();

	for(auto& i : m_modelMap)
	{
		i.first->DecRef();
		if(i.second.m_sceneRoot)
			i.second.m_sceneRoot->DecRef();
	}

	m_modelMap.clear();
}

bool CHair::CreateIfValid()
{
	auto ref = DYNAMIC_CAST(LookupFormByID(m_formID), TESForm, Actor);
	if(!ref) return false;
	auto loadedState = ref->loadedState;
	if(!loadedState || !loadedState->node) return false;
	auto root = ref->GetFaceGenNiNode();
	if(!root) return false;

	auto newSkeleton = loadedState->node;
	if(m_skeleton != newSkeleton)
	{
		Clear();
		m_skeleton = newSkeleton;
	}
	
	for(auto i = m_modelMap.begin(); i!=m_modelMap.end(); )
	{
		if( i->first->m_uiRefCount == 1 || !IsMyAncestor(i->first, root) )
		{
			if(i->second.m_sceneRoot)
			{
				m_objects.erase((UINT32)i->second.m_sceneRoot);
				i->second.m_sceneRoot->DecRef();
			}
			i->first->DecRef();
			m_modelMap.erase(i);
			i = m_modelMap.begin();
		}
		else ++i;
	}
	
	for(int i=0; i<root->m_children.m_size; ++i)
	{
		auto subnode = ni_cast(root->m_children[i], NiGeometry);
		if(!subnode) continue;
		auto tp = m_modelMap.insert(std::make_pair(subnode, Model()));
		if(!tp.second) continue;
		subnode->IncRef();
		auto& myModel = tp.first->second;

		NiNode* sceneRoot = 0;
		for(int j=0; j<subnode->m_spSkinInstance->m_spSkinData->m_uiBones; ++j)
		{
			auto bone = subnode->m_spSkinInstance->m_ppkBones[j];
			while(bone != m_skeleton && bone->m_parent)
				bone = bone->m_parent;
			if(bone != m_skeleton)
			{
				sceneRoot = ni_cast(bone, NiNode);
				break;
			}
		}

		if(!sceneRoot) continue;
		myModel.m_sceneRoot = sceneRoot;
		sceneRoot->IncRef();

		for(int j=0; j<subnode->m_spSkinInstance->m_spSkinData->m_uiBones; ++j)
		{
			auto boneB = ni_cast( subnode->m_spSkinInstance->m_ppkBones[j], NiNode );
			if(boneB && !boneB->m_name.data) continue;

			auto boneA = ni_cast( sceneRoot->GetObjectByName(boneB->m_name), NiNode );
			if(boneA && boneB && boneB!=boneA)
				myModel.m_boneMap.push_back(std::make_pair(boneA, boneB));
			/*
			std::sort(myModel.m_boneMap.begin(), myModel.m_boneMap.end(),
			[](std::pair<NiNode*, NiNode*>& a, std::pair<NiNode*, NiNode*>& b)->bool
			{
				if(a.first == b.first) return false;
				return IsMyAncestor(a.first, b.first);
			});*/
		}
		
		for(int j=0; j<sceneRoot->m_extraDataLen; ++j)
		{
			auto string = ni_cast(sceneRoot->m_extraData[j], NiStringExtraData);
			if(string && string->m_name.data && string->m_name == "HDT Havok Path" && string->m_stringData.data)
				LoadPhysicsSystem(sceneRoot, string->m_stringData.data);

			auto strings = ni_cast(sceneRoot->m_extraData[j], NiStringsExtraData);
			if(strings && strings->m_name.data && strings->m_name == "HDT Havok Path")
			{
				for(int k=0; k<strings->m_count; ++k)
					if(strings->m_strings[k].data)
						LoadPhysicsSystem(sceneRoot, strings->m_strings[k].data);
			}
		}
		
		for(auto& i : myModel.m_boneMap)
		{
			i.first->m_worldTransform = i.second->m_worldTransform;
			UpdateWorldDataToChild(i.first);
		}
	}
	
	return m_modelMap.size();
}

void CHair::LoadPhysicsSystem(NiNode* model, const char* path)
{
	auto system = LoadPhysicsFile(path);
	if(!system)
	{
		LogWarning("Invalid havok serialize file : %s", path);
		return;
	}
	
	Info info;
	info.system = std::shared_ptr<CSystemObject>(new CSystemObject);
	if(info.system->BindPhysicsInfo(system, model))
	{
		info.model = model;
		m_objects.insert(std::make_pair((UINT32)model, info));
	}
	system->removeReference();
}

void CHair::WriteToWorld(float invDeltaTime)
{
	for(auto& i : m_modelMap)
	{
		for(auto& j : i.second.m_boneMap)
		{
			j.first->m_worldTransform = j.second->m_worldTransform;
			UpdateWorldDataToChild(j.first);
		}
	}
	
	CSystemFormObject::WriteToWorld(invDeltaTime);
}