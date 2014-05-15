#pragma once

#include "World.h"

class FreezeEventHandler : public BSTEventSink <MenuOpenCloseEvent>
{
public:
	FreezeEventHandler(){}
	
	virtual EventResult		ReceiveEvent(MenuOpenCloseEvent * evn, EventDispatcher<MenuOpenCloseEvent> * dispatcher);
	
	Lockable m_lock;
	std::vector<BSFixedString> m_menuList;
};

extern FreezeEventHandler g_freezeEventHandler;