#include "HookMenu.h"

FreezeEventHandler g_freezeEventHandler;

static const BSFixedString menuFilterList[] = 
{
	"Crafting Menu",
	"Dialogue Menu",
	"RaceSex Menu",
	"HUD Menu",
	"Cursor Menu",
	//"Fader Menu"
};

bool menuFilter(const BSFixedString& menuName)
{
	for(int i=0; i<(sizeof(menuFilterList)/sizeof(BSFixedString)); ++i)
		if(menuName == menuFilterList[i]) return false;
	return true;
}

EventResult FreezeEventHandler::ReceiveEvent(MenuOpenCloseEvent * evn, EventDispatcher<MenuOpenCloseEvent> * dispatcher)
{
	m_lock.lock();

	CWorld::getSingleton()->InitThread();
	if( evn->opening )
	{
		if(menuFilter(evn->menuName))
		{
			m_menuList.push_back(evn->menuName);
			CWorld::getSingleton()->Suspend();
		}

		if(evn->menuName == "RaceSex Menu")
			CWorld::getSingleton()->SwitchToSeperateClock();
		
		LogDebug("Push Menu : %s", evn->menuName.data);
	}
	else
	{
		if(evn->menuName == "Loading Menu")
			CWorld::getSingleton()->ClearScene();
				
		if(evn->menuName == "RaceSex Menu")
			CWorld::getSingleton()->SwitchToInternalClock();
				
		if(menuFilter(evn->menuName))
		{
			auto idx = std::find(m_menuList.begin(), m_menuList.end(), evn->menuName);
			if(idx != m_menuList.end())
			{
				m_menuList.erase(idx);
				CWorld::getSingleton()->Resume();
			}
		}
		
		LogDebug("Pop Menu : %s", evn->menuName.data);
	}

	m_lock.unlock();
	return kEvent_Continue;
}
