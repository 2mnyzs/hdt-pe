#include "ResourceManager.h"

ResourceManager::ResourceManager(void)
{
	DetourAttach((void**)NiObjectProxy::_release_GetPtr(), (void*)GetFnAddr(&NiObjectProxy::myRelease));
}

ResourceManager::~ResourceManager(void)
{
	DetourDetach((void**)NiObjectProxy::_release_GetPtr(), (void*)GetFnAddr(&NiObjectProxy::myRelease));
}

ResourceManager* ResourceManager::get()
{
	static ResourceManager mgr;
	return &mgr;
}

bool ResourceManager::RegisterCallback(NiObject* object, std::function<void(NiObject*)> callback)
{
	m_lock.lock();
	auto ret = m_callbacks.insert(std::make_pair(object, callback)).second;
	m_lock.unlock();
	return ret;
}

void ResourceManager::UnregisterCallback(NiObject* object)
{
	m_lock.lock();
	m_callbacks.erase(object);
	m_lock.unlock();
}

void ResourceManager::NiObjectProxy::myRelease()
{
	if(this)
	{
		auto mgr = ResourceManager::get();
		auto node = (NiObject*)this;
		mgr->m_lock.lock();
		auto iter = mgr->m_callbacks.find(node);
		if(iter != mgr->m_callbacks.end())
		{
			iter->second(node);
			mgr->m_callbacks.erase(node);
		}
		mgr->m_lock.unlock();
	}
	CALL_MEMBER_FN(this, release)();
}