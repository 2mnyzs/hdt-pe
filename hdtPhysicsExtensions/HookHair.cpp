#include "HookHair.h"
#include "ResourceManager.h"

NiNode* ClassHair::TEST_00432070(NiNode* a, void* b)
{
	auto ret = CALL_MEMBER_FN(this, UNKNOWN_00432070)(a, b);
	return ret;
}

const BSFixedString& MyBSFaceGenModelExtraData::GetBone(UINT idx)
{
	if(idx < 8) return bones[idx];
	static const BSFixedString empty("");
	return empty;
}

UINT MyBSFaceGenNiNode::MySkinFace(NiNode* skeleton, UINT unk)
{
	return CALL_MEMBER_FN(this, SkinFace)(skeleton, unk);
}

namespace PlayerHead
{
	
	static Lockable lock;
	static BSFaceGenNiNode* oldHead = 0;
	static const std::string prefix = "|HDTHDPT|";
	static volatile bool isUpdating = false;
	
	void OnHeadRelease()
	{
		auto player = DYNAMIC_CAST(LookupFormByID(0x14), TESForm, Actor);
		if(!player || !player->loadedState || !player->loadedState->node) return;

		auto npc = player->loadedState->node;
		CWorld::getSingleton()->RemoveSystemObject((UINT32)oldHead);
		
		ClearNode(npc, prefix);
		
		if(oldHead) oldHead->DecRef();
		oldHead = 0;
	}

	void OnHeadAttach( BSFaceGenNiNode* head )
	{
		if(head)
		{
			auto player = DYNAMIC_CAST(LookupFormByID(0x14), TESForm, Actor);
			if(!player || !player->loadedState || !player->loadedState->node) return;

			auto npc = player->loadedState->node;

			for(int i=0; i<head->m_children.m_arrayBufLen; ++i)
			{
				if(!head->m_children[i]) continue;
				auto tri = head->m_children[i]->GetAsNiGeometry();
				if(!tri) continue;
				
				NiNode* mesh = 0;
				auto fmd = (BSFaceGenModelExtraData*)CALL_MEMBER_FN(tri, FindExtraData)("FMD");
				if(fmd && fmd->m_model && fmd->m_model->unk08 && fmd->m_model->unk08->m_meshRoot)
					mesh = fmd->m_model->unk08->m_meshRoot;
				if(!mesh || mesh->m_name == "WorldRoot Node") continue;

				RenameNode(npc, mesh, prefix);
				CombineTree(npc, mesh);

				//CALL_MEMBER_FN((MyBSFaceGenNiNode*)head, SkinHeadpart)(npc, tri, 1);

				CWorld::getSingleton()->ScanAndAdd((UINT32)head, prefix, npc, mesh);
			}

			head->IncRef();
		}
		oldHead = head;
	}
}

void MyBSFaceGenNiNode::MySkinHeadpart(NiNode* skeleton, NiGeometry * headpart, UINT unk)
{
	PlayerHead::lock.lock();
	if(headpart->m_parent == PlayerHead::oldHead && !PlayerHead::isUpdating)
	{
		PlayerHead::OnHeadRelease();
		PlayerHead::OnHeadAttach((BSFaceGenNiNode*)headpart->m_parent);
	}
	PlayerHead::lock.unlock();
	CALL_MEMBER_FN(this, SkinHeadpart)(skeleton, headpart, unk);
/*
40460288  sub         esp,0Ch  						; esp + 0c
4046028B  mov         dword ptr [esp+8],ecx
005A83C7  mov         ecx,dword ptr [esp+14h]  
005A83CB  test        ecx,ecx  
005A83CD  je          005A8497 						;if(!headpart) return;
005A83D3  push        ebp  							; esp + 10
005A83D4  mov         ebp,dword ptr [ecx+0B4h]  	; //ebp = headpart->m_spSkinInstance;
005A83DA  test        ebp,ebp  
005A83DC  je          005A8496  					;if(!headpart->m_spSkinInstance) return;
005A83E2  mov         eax,dword ptr [ebp+8]
005A83E5  test        eax,eax  
005A83E7  je          005A8496 						;if(!headpart->m_spSkinInstance->m_spSkinData)  return;
005A83ED  mov         edx,dword ptr [ebp+14h]  
005A83F0  mov         eax,dword ptr [eax+44h]  
005A83F3  mov         dword ptr [esp+8],eax  		;auto numBones = headpart->m_spSkinInstance->m_spSkinData->m_uiBones;
005A83F7  mov         dword ptr [esp+4],edx  		;auto bones = headpart->m_spSkinInstance->m_ppkBones;
005A83FB  test        edx,edx  				
005A83FD  je          005A8496  					;if(!bones) return;
005A8403  test        eax,eax  				
005A8405  je          005A8496  					;if(!numBones) return;
005A840B  push        esi  							; esp + 14
005A840C  xor         esi,esi  						; esi = 0
005A840E  test        eax,eax  
005A8410  jbe         005A848E  					;if(numBones<0) goto RET;
005A8416  push        ebx  							; esp + 18
005A8417  push        edi  							; esp + 1c
005A8418  mov         edi,dword ptr [esp+20h]  		; edi = skeleton
005A841C  jmp         005A8424  
005A841E  mov         edi,edi  
// begin for										;for(int i=0; i<numBones; ++i) {
005A8420  mov         ecx,dword ptr [esp+24h]  		;	ecx = headpart
005A8424  push        1B1DF00h  
005A8429  call        00AB45F0  			
005A842E  test        eax,eax  						;	eax = headpart->GetObjectByName("FMD"); // BSFaceGenModelExtraData
005A8430  je          005A843C 						;	if(eax)
005A8432  push        esi  
005A8433  mov         ecx,eax  
005A8435  call        005A8220  					;		eax = eax->005A8220(i);
005A843A  jmp         005A8441  
005A843C  call        00771290  					;	else eax = BSFixedString("");
005A8441  mov         ebx,eax  						;	ebx = eax;
005A8443  mov         ecx,ebx						;	ecx = eax;
005A8445  call        00A50AC0  					;	eax = typeid(ecx)
005A844A  mov         ecx,edi						;	ecx = skeleton;
005A844C  test        eax,eax						;	if(eax)
005A844E  jbe         005A845D  					;	
005A8450  mov         eax,dword ptr [edi]	 		;
005A8452  mov         edx,dword ptr [eax+9Ch]  		;
005A8458  push        ebx  							;
005A8459  call        edx  							;		eax = skeleton->GetObjectByName(ebx);
005A845B  jmp         005A8472  
005A845D  mov         eax,dword ptr [esp+10h]  		;	else
005A8461  mov         eax,dword ptr [eax+esi*4]  	;	
005A8464  mov         edx,dword ptr [edi]  			;		
005A8466  add         eax,8 
005A8469  push        eax  
005A846A  mov         eax,dword ptr [edx+9Ch]  
005A8470  call        eax  							;		eax = skeleton->GetObjectByName(bones[i]->m_name);
005A8472  test        eax,eax  	
005A8474  je          005A8485  					;	if(!eax) continue;
005A8476  mov         ecx,dword ptr [ebp+14h]  		;
005A8479  mov         dword ptr [ecx+esi*4],eax  	;	headpart->m_skinInstance->m_ppkBones[i] = eax;
005A847C  mov         edx,dword ptr [ebp+18h]  		;
005A847F  add         eax,54h  
005A8482  mov         dword ptr [edx+esi*4],eax  	;	edx = headpart->m_skinInstance->m_ppkBoneTransforms[i] = &eax->m_worldTransform;
005A8485  inc         esi
005A8486  cmp         esi,dword ptr [esp+14h]  
005A848A  jb          005A8420  
// end for											;}
005A848C  pop         edi  
005A848D  pop         ebx  
// RET:
005A848E  mov         eax,dword ptr [esp+10h]  
005A8492  mov         dword ptr [ebp+10h],eax  		;headpart->m_spSkinInstance->m_pkRootParent = this;
005A8495  pop         esi  
005A8496  pop         ebp  
005A8497  add         esp,0Ch  
005A849A  ret         0Ch  
*/
}

void MYNPC::MyBindHead(Actor* actor, BSFaceGenNiNode** head)
{
	CWorld::getSingleton()->InitThread();

	// player
	if(actor->formID == 0x14)
	{
		PlayerHead::lock.lock();
		if(PlayerHead::oldHead)
			PlayerHead::OnHeadRelease();

		PlayerHead::OnHeadAttach(*head);
		PlayerHead::lock.unlock();
	}

	PlayerHead::isUpdating = true;
	CALL_MEMBER_FN(this, BindHead)(actor, head);
	PlayerHead::isUpdating = false;
}

void HookHair()
{
	DetourAttach((void**)ClassHair::_UNKNOWN_00432070_GetPtr(), (void*)GetFnAddr(&ClassHair::TEST_00432070));
	DetourAttach((void**)MyBSFaceGenModelExtraData::_GetBone_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenModelExtraData::GetBone));
	DetourAttach((void**)MyBSFaceGenNiNode::_SkinHeadpart_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenNiNode::MySkinHeadpart));
	DetourAttach((void**)MyBSFaceGenNiNode::_SkinFace_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenNiNode::MySkinFace));
	DetourAttach((void**)MYNPC::_BindHead_GetPtr(), (void*)GetFnAddr(&MYNPC::MyBindHead));
}

void DehookHair()
{
	DetourDetach((void**)ClassHair::_UNKNOWN_00432070_GetPtr(), (void*)GetFnAddr(&ClassHair::TEST_00432070));
	DetourDetach((void**)MyBSFaceGenModelExtraData::_GetBone_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenModelExtraData::GetBone));
	DetourDetach((void**)MyBSFaceGenNiNode::_SkinHeadpart_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenNiNode::MySkinHeadpart));
	DetourDetach((void**)MyBSFaceGenNiNode::_SkinFace_GetPtr(), (void*)GetFnAddr(&MyBSFaceGenNiNode::MySkinFace));
	DetourDetach((void**)MYNPC::_BindHead_GetPtr(), (void*)GetFnAddr(&MYNPC::MyBindHead));
}

