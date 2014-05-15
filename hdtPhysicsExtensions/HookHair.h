#pragma once

#include "common.h"
#include "detours.h"
#include "ppapi_helper.h"
#include "netimmerse_helper.h"

#include "World.h"

// empty class only for hook thiscall

class MyBSFaceGenModelExtraData : public BSFaceGenModelExtraData
{
public:
	MEMBER_FN_PREFIX(BSFaceGenModelExtraData);

	const BSFixedString& GetBone(UINT idx);
	// rewrite the fucking CTD-friendly func;
	DEFINE_MEMBER_FN_HOOK(GetBone, const BSFixedString&, 0x005A8220, UINT idx);
};

class MyBSFaceGenNiNode : public BSFaceGenNiNode
{
public:
	MEMBER_FN_PREFIX(MyBSFaceGenNiNode);

	UINT MySkinFace(NiNode* skeleton, UINT unk);
	DEFINE_MEMBER_FN_HOOK(SkinFace, UINT, 0x005A88A0, NiNode*, UINT);

	void MySkinHeadpart(NiNode* skeleton, NiGeometry * headpart, UINT unk);
	DEFINE_MEMBER_FN_HOOK(SkinHeadpart, void, 0x005A83C0, NiNode* skeleton, NiGeometry * headpart, UINT unk);
};

class MYNPC : public TESNPC
{
public:

	MEMBER_FN_PREFIX(MYNPC);
	DEFINE_MEMBER_FN_HOOK(GetFaceGenHead, void, 0x0056AEB0, void*, UINT);
	DEFINE_MEMBER_FN_HOOK(BindHead, void, 0x00569990, Actor*, BSFaceGenNiNode**);

	void MyBindHead(Actor*, BSFaceGenNiNode**);
};

class QueuedHead : public BaseFormComponent
{
public:
	MEMBER_FN_PREFIX(QueuedHead);
	DEFINE_MEMBER_FN_HOOK(Init, void, 0x0042BCF0);
};

class ClassHair
{
public:
	
	NiNode* TEST_00432070(NiNode*, void*);
	NiObject * MyClone(NiCloningProcess* kCloning);	// NiObject::Clone

	MEMBER_FN_PREFIX(ClassHair);
	DEFINE_MEMBER_FN_HOOK(UNKNOWN_00432070, NiNode*, 0x00432070, NiNode*, void*);	// Apply morph ?

	UINT unk0; //vtbl
	UINT unk1;
	struct
	{
		UINT unk0;
		NiNode* meshRoot;
		NiGeometry* triShape;
	}* unk2;
};

void HookHair();
void DehookHair();
void ScanHair();

typedef void (*fnBindHead)(Actor*, BGSHeadPart*);
static fnBindHead BindHead = (fnBindHead)0x005AA230;