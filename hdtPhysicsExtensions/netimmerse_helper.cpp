#include "netimmerse_helper.h"

void UpdateWorldData(NiAVObject* node)
{
	if(!node) return;
	if(!node->m_parent)
		node->m_worldTransform = node->m_localTransform;
	else
	{
		/*
		hkQsTransform p, l, s;
		GetNiTransform(node->m_parent->m_worldTransform, p);
		GetNiTransform(node->m_localTransform, l);
		s.setMul(p, l);
		SetNiTransform(node->m_worldTransform, s);*/
		NiAVObject::ControllerUpdateContext ctx;
		node->UpdateWorldData(&ctx);
	}
}

void UpdateWorldDataToChild(NiNode* node)
{
	if(!node) return;
	for(int i=0; i<node->m_children.m_arrayBufLen; ++i)
	{
		UpdateWorldData(node->m_children[i]);
		auto next = CastNiNode(node->m_children[i]);
		if(!next) continue;
		UpdateWorldDataToChild(next);
	}
}

void UpdateWorldDataFromRoot(NiAVObject* node)
{
	if(node->m_parent)
		UpdateWorldDataFromRoot(node->m_parent);
	
	UpdateWorldData(node);
}

void UpdateLocalData(NiAVObject* dst)
{
	if(!dst) return;
	if(dst->m_parent)
	{
		hkTransform pt, st;
		GetNiTransform(dst->m_parent->m_worldTransform, pt);
		GetNiTransform(dst->m_worldTransform, st);
		hkTransform pLc;
		pLc.setMulInverseMul(pt, st);
		pLc.getTranslation().mul(1/dst->m_parent->m_worldTransform.scale);
		SetNiTransform(dst->m_localTransform, pLc);
	
		//NiAVObject::ControllerUpdateContext ctx;
		//dst->UpdateWorldData(&ctx);
		//if(dst->GetAsNiNode())
		//	dst->GetAsNiNode()->UpdateUpwardPass();
		UpdateWorldDataToChild(dst->GetAsNiNode());
	}
	else dst->m_localTransform = dst->m_worldTransform;
}

int CombineTree(NiNode* to, NiNode* from)
{
	NiAVObject::ControllerUpdateContext ctx;
	to->UpdateWorldData(&ctx);
	int sum = 0;
	for(int i=0; i<from->m_children.m_size; ++i)
	{
		auto src = ni_cast(from->m_children[i], NiNode);
		if(!src) continue;
		
		auto dst = CastNiNode(to->GetObjectByName(src->m_name));
		if(!dst || !src->m_name.data)
		{
			NiCloningProcess kCloning;
			NiObject* tp = CALL_MEMBER_FN(src, Clone)(&kCloning);
			NiNode* clone = ni_cast(tp, NiNode);
			if(clone->m_collision)
				clone->m_collision->DecRef();
			clone->m_collision = 0;
			to->AttachChild(clone, false);
			dst = clone;
			LogDebug("Attach bone - %s", dst->m_name.data);
			++sum;
		}
		sum += CombineTree(dst, src);
	}
	return sum;
}

void ClearNode(NiNode* from, const std::string& prefix)
{
	if(!from) return;

	int size = from->m_children.m_size;
	for(int i=0; i<size; ++i)
	{
		auto src = CastNiNode(from->m_children[i]);
		if(!src) continue;

		if( src->m_name.data && !strncmp(src->m_name.data, prefix.c_str(), prefix.length()) )
		{
			BSFixedString name = src->m_name;
			from->RemoveChild(src);
		}
		else ClearNode(src, prefix);
	}
}

bool ShouldRename(NiNode* root, NiAVObject* node, const std::string& prefix)
{
	if(!node->m_name.data)
		return false;

	if(!strncmp(node->m_name.data, prefix.c_str(), prefix.length()))
		return false;

	return !CastNiNode(root->GetObjectByName(node->m_name.data));
}

void RenameNode(NiNode* root, NiNode* node, const std::string& prefix)
{
	for(int i=0; i<node->m_children.m_size; ++i)
	{
		auto bone = CastNiNode(node->m_children[i]);
		if(bone)
		{
			if(ShouldRename(root, bone, prefix))
				bone->m_name = prefix + bone->m_name.data;
			RenameNode(root, bone, prefix);
		}
	}
}

void CancelRename(NiNode* node, const std::string& prefix)
{
	for(int i=0; i<node->m_children.m_size; ++i)
	{
		auto bone = CastNiNode(node->m_children[i]);
		if(bone)
		{
			if(node->m_name.data && !strncmp(node->m_name.data, prefix.c_str(), prefix.length()))
				bone->m_name = bone->m_name.data + prefix.length();
			CancelRename(bone, prefix);
		}
	}
}

bool IsMyAncestor(NiAVObject* me, NiNode* r)
{
	while(me && me!=r)
		me = me->m_parent;
	return me==r;
}
