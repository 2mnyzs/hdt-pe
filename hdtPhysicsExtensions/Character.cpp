#include "Character.h"
#include "common.h"

#include "World.h"

hkpPhysicsSystem* LoadDefaultBBP()
{
	CWorld::getSingleton()->InitThread();

	static const auto path = "Data\\SKSE\\Plugins\\hdtPhysicsExtensionsDefaultBBP.xml";
	
	auto system = LoadPhysicsFile(path);
	if(!system)
	{
		LogWarning("Invalid havok serialize file : %s", path);
		return 0;
	}
	for(int i=0; i<system->getRigidBodies().getSize(); ++i)
		system->getRigidBodies()[i]->setCollisionFilterInfo(-1);
	return system;
}

bool CBody::CreateIfValid()
{
	auto ref = DYNAMIC_CAST(LookupFormByID(m_formID), TESForm, Actor);
	if(!ref) return false;
	auto loadedState = ref->loadedState;
	if(!loadedState || !loadedState->node) return false;
	auto root = loadedState->node;
	
	if(m_objects.size() && root == m_objects.begin()->second.model)
		return true;

	if(!ni_cast(root->GetObjectByName("NPC L Breast"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC R Breast"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC L PreBreast"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC R PreBreast"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC L Butt"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC R Butt"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC L PreButt"), NiNode)) return false;
	if(!ni_cast(root->GetObjectByName("NPC R PreButt"), NiNode)) return false;

	if(m_objects.size())
		m_objects.clear();
	
	auto system = LoadDefaultBBP();
	if(!system) return false;
	
	Info body;
	body.model = root;
	body.system = std::shared_ptr<CSystemObject>(new CSystemObject);
	if( body.system->BindPhysicsInfo(system, body.model) )
	{
		m_objects.insert(std::make_pair(0, body));
		return true;
	}
	return false;
}

void CBody::ReadFromWorld()
{
	CSystemFormObject::ReadFromWorld();
	if(m_formID == 0x14)
	{
		auto player = DYNAMIC_CAST(LookupFormByID(m_formID), TESForm, PlayerCharacter);
		if(!player) return;
		auto root = player->firstPersonSkeleton;
		if(!root) return;
		
		auto& bones = m_objects.begin()->second.system->getBones();
		auto system = m_objects.begin()->second.system->getSystem();
		for(int i=0; i<bones.getSize(); ++i)
		{
			if(!bones[i]) continue;
			if(system->getRigidBodies()[i]->isFixedOrKeyframed()) continue;
			auto mapto = CastNiNode( root->GetObjectByName(bones[i]->m_name) );
			if(!mapto) continue;

			mapto->m_localTransform = bones[i]->m_localTransform;
			UpdateWorldData(mapto);
		}
	}
}