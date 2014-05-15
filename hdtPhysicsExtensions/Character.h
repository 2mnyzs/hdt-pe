#pragma once

#include "PhysObject.h"
#include "Hair.h"
#include <vector>

class CBody : public CSystemFormObject
{
public:
	CBody(int form) : CSystemFormObject(form){}
	virtual bool CreateIfValid();
	virtual void ReadFromWorld();
};

typedef CBody CCharacter;
