#pragma once

#include "PhysObject.h"

class CBody : public CNodeObject
{
public:
	CBody(int form);
	~CBody(void);

	virtual bool CreateIfValid();
protected:
	
	static const BSFixedString NPC_PELVIS;
	static const BSFixedString NPC_SPINE;
	static const BSFixedString NPC_SPINE1;
	static const BSFixedString NPC_SPINE2;
	static const BSFixedString NPC_NECK;
	static const BSFixedString NPC_HEAD;
	static const BSFixedString NPC_LUPPERARM;
	static const BSFixedString NPC_RUPPERARM;
	static const BSFixedString NPC_LFOREARM;
	static const BSFixedString NPC_RFOREARM;
	static const BSFixedString NPC_LHAND;
	static const BSFixedString NPC_RHAND;
	static const BSFixedString NPC_LTHIGH;
	static const BSFixedString NPC_RTHIGH;
	static const BSFixedString NPC_LCALF;
	static const BSFixedString NPC_RCALF;
	static const BSFixedString NPC_LFOOT;
	static const BSFixedString NPC_RFOOT;
	static const BSFixedString NPC_LPREBREAST;
	static const BSFixedString NPC_RPREBREAST;
	static const BSFixedString NPC_LBREAST;
	static const BSFixedString NPC_RBREAST;
	static const BSFixedString NPC_LBREAST01;
	static const BSFixedString NPC_RBREAST01;
	static const BSFixedString NPC_LPREBUTT;
	static const BSFixedString NPC_RPREBUTT;
	static const BSFixedString NPC_LBUTT;
	static const BSFixedString NPC_RBUTT;
};

