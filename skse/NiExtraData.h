#pragma once

#include "skse/NiTypes.h"
#include "skse/NiObjects.h"
#include "skse/GameTypes.h"

class BSFaceGenKeyframe
{
public:
	virtual ~BSFaceGenKeyframe();

	virtual void Unk_01(void); // pure
	virtual void Unk_02(void); // pure
	virtual void Unk_03(void); // pure
	virtual void Unk_04(void); // pure
	virtual void Unk_05(void); // pure
	virtual void Unk_06(void); // pure
	virtual void Unk_07(void); // pure
	virtual void Unk_08(void); // pure
	virtual void Unk_09(void); // pure
	virtual void Unk_0A(void); // pure
	virtual void Unk_0B(void); // pure
	virtual void Unk_0C(void);
	virtual void Unk_0D(void);
};

class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
public:
	UInt32	unk04;	// 04
	UInt32	unk08;	// 08
	UnkArray	unk0C;	// 0C
};
STATIC_ASSERT(sizeof(BSFaceGenKeyframeMultiple) == 0x18);

class NiExtraData : public NiObject
{
public:
	BSFixedString m_name;	// 08
};

// 1B4
class BSFaceGenAnimationData : public NiExtraData
{
public:
	enum {
		kNumKeyframes = 12
	};
	void	* unk08;						// 08
	UInt32	unk0C;							// 0C
	BSFaceGenKeyframeMultiple	keyFrames[kNumKeyframes];	// 10
	UInt32	unk1A0[(0x1A0 - 0x130) >> 2];	// 1A0
	UInt8	unk1A4;							// 1A4
	UInt8	unk1A5;							// 1A5
	UInt8	overrideFlag;					// 1A6
	UInt8	unk1A7;							// 1A7
	UInt32	unk1A8[(0x1B4 - 0x1A8) >> 2];	// 1A8

	MEMBER_FN_PREFIX(BSFaceGenAnimationData);
	DEFINE_MEMBER_FN(SetExpression, void, 0x0059DB90, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetPhonome, void, 0x005352D0, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetModifier, void, 0x005352A0, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetCustom, void, 0x00535300, UInt32 type, float value);
	DEFINE_MEMBER_FN(Reset, void, 0x0059E320, float value, UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4);
	
};

class NiStringExtraData : public NiExtraData
{
public:
	BSFixedString m_stringData;	// 0c
};

class NiStringsExtraData : public NiExtraData
{
public:
	UINT32 m_count;
	BSFixedString* m_strings;
};

STATIC_ASSERT(offsetof(BSFaceGenAnimationData, overrideFlag) == 0x1A6);
STATIC_ASSERT(sizeof(BSFaceGenAnimationData) == 0x1B4);

class BSFaceGenModel : public NiRefObject
{
public:

	struct Data08
	{
		UInt32 unk00; // 00
		NiNode* m_meshRoot;
		NiGeometry* m_triShape;
		UInt32 unk0C; // 0C
		BSFaceGenMorphData * unk10; // 10
	};
	Data08 * unk08; // 08
	UInt32 unk0C; // 0C
	
	MEMBER_FN_PREFIX(BSFaceGenModel);
	DEFINE_MEMBER_FN(LoadModel, UINT32, 0x005A60D0, const char*, const char*, UINT);
};

class BSFaceGenModelExtraData : public NiExtraData
{
public:
	BSFaceGenModel* m_model;
	BSFixedString bones[8];
	//MEMBER_FN_PREFIX(BSFaceGenModelExtraData);
	//DEFINE_MEMBER_FN(GetData, const BSFixedString&, 0x005A8220, UINT idx);	//Fucking bugly function if idx > 8;
	/*
005A8220  mov         eax,dword ptr [esp+4] 		 
005A8224  cmp         eax,8  				
005A8227  ja          005A8230  				;if(x <= 8)
005A8229  lea         eax,[ecx+eax*4+10h]  		;return (this+x*4+10h);
005A822D  ret         4  
005A8230  mov         eax,1  				;
005A8235  test        byte ptr ds:[12E32F0h],al  	;
005A823B  jne         005A825F  
005A823D  or          dword ptr ds:[12E32F0h],eax  
005A8243  push        10D1068h  
005A8248  mov         ecx,12E32ECh  
005A824D  call        00A511C0  
005A8252  push        103CE70h  
005A8257  call        00F520BC  
005A825C  add         esp,4  				;static UNKTYPE 12E32ECh
005A825F  mov         eax,12E32ECh  		;return 12E32ECh
005A8264  ret         4  
	*/
};
