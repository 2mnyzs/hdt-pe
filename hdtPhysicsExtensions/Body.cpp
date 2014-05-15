#include "Body.h"

const BSFixedString CBody::NPC_PELVIS("NPC Pelvis [Pelv]");
const BSFixedString CBody::NPC_SPINE("NPC Spine [Spn0]");
const BSFixedString CBody::NPC_SPINE1("NPC Spine1 [Spn1]");
const BSFixedString CBody::NPC_SPINE2("NPC Spine2 [Spn2]");
const BSFixedString CBody::NPC_NECK("NPC Neck [Neck]");
const BSFixedString CBody::NPC_HEAD("NPC Head [Head]");
const BSFixedString CBody::NPC_LUPPERARM("NPC L UpperArm [LUar]");
const BSFixedString CBody::NPC_RUPPERARM("NPC R UpperArm [RUar]");
const BSFixedString CBody::NPC_LFOREARM("NPC L Forearm [LLar]");
const BSFixedString CBody::NPC_RFOREARM("NPC R Forearm [RLar]");
const BSFixedString CBody::NPC_LHAND("NPC L Hand [LHnd]");
const BSFixedString CBody::NPC_RHAND("NPC R Hand [RHnd]");
const BSFixedString CBody::NPC_LTHIGH("NPC L Thigh [LThg]");
const BSFixedString CBody::NPC_RTHIGH("NPC R Thigh [RThg]");
const BSFixedString CBody::NPC_LCALF("NPC L Calf [LClf]");
const BSFixedString CBody::NPC_RCALF("NPC R Calf [RClf]");
const BSFixedString CBody::NPC_LFOOT("NPC L Foot [Lft ]");
const BSFixedString CBody::NPC_RFOOT("NPC R Foot [Rft ]");
const BSFixedString CBody::NPC_LPREBREAST("NPC L PreBreast");
const BSFixedString CBody::NPC_RPREBREAST("NPC R PreBreast");
const BSFixedString CBody::NPC_LBREAST("NPC L Breast");
const BSFixedString CBody::NPC_RBREAST("NPC R Breast");
const BSFixedString CBody::NPC_LBREAST01("NPC L Breast01");
const BSFixedString CBody::NPC_RBREAST01("NPC R Breast01");
const BSFixedString CBody::NPC_LPREBUTT("NPC L PreButt");
const BSFixedString CBody::NPC_RPREBUTT("NPC R PreButt");
const BSFixedString CBody::NPC_LBUTT("NPC L Butt");
const BSFixedString CBody::NPC_RBUTT("NPC R Butt");

CBody::CBody(int form)
	: CNodeObject(form)
{
}


CBody::~CBody(void)
{
}

bool CBody::CreateIfValid()
{
	
	auto pActor = DYNAMIC_CAST( LookupFormByID( m_iFormID ), TESForm, Actor );
	if(!pActor || !pActor->loadedState || !pActor->loadedState->node)
	{
		if(m_pRoot)
			LogDebug("%08x skeleton no longer exist ...", m_iFormID);
		ReleasePhysics();
		return false;
	}
	
	auto root = pActor->loadedState->node;
	if(root == m_pRoot) return true; // We already create it before

	// skeleton changed
	LogDebug("%08x skeleton change detected ...", m_iFormID);
	ReleasePhysics();

	if(!root->GetObjectByName(NPC_PELVIS)) return false;
	if(!root->GetObjectByName(NPC_SPINE)) return false;
	if(!root->GetObjectByName(NPC_SPINE1)) return false;
	if(!root->GetObjectByName(NPC_SPINE2)) return false;
	if(!root->GetObjectByName(NPC_NECK)) return false;
	if(!root->GetObjectByName(NPC_HEAD)) return false;
	if(!root->GetObjectByName(NPC_LUPPERARM)) return false;
	if(!root->GetObjectByName(NPC_RUPPERARM)) return false;
	if(!root->GetObjectByName(NPC_LFOREARM)) return false;
	if(!root->GetObjectByName(NPC_RFOREARM)) return false;
	if(!root->GetObjectByName(NPC_LHAND)) return false;
	if(!root->GetObjectByName(NPC_RHAND)) return false;
	if(!root->GetObjectByName(NPC_LTHIGH)) return false;
	if(!root->GetObjectByName(NPC_RTHIGH)) return false;
	if(!root->GetObjectByName(NPC_LCALF)) return false;
	if(!root->GetObjectByName(NPC_RCALF)) return false;
	if(!root->GetObjectByName(NPC_LFOOT)) return false;
	if(!root->GetObjectByName(NPC_RFOOT)) return false;
	if(!root->GetObjectByName(NPC_LPREBREAST)) return false;
	if(!root->GetObjectByName(NPC_RPREBREAST)) return false;
	if(!root->GetObjectByName(NPC_LBREAST)) return false;
	if(!root->GetObjectByName(NPC_RBREAST)) return false;
	if(!root->GetObjectByName(NPC_LPREBUTT)) return false;
	if(!root->GetObjectByName(NPC_RPREBUTT)) return false;
	if(!root->GetObjectByName(NPC_LBUTT)) return false;
	if(!root->GetObjectByName(NPC_RBUTT)) return false;
		
	m_pRoot = root;
	LogDebug("%08x skeleton check pass ... creating physics info", m_iFormID);

	auto AddRefNode = [this](const BSFixedString& name, hkpShape* shape, int layer)->int
	{
		NODE node;
		node.dynamic = false;
		node.group = GROUP_BODY;
		node.node = (NiNode*)m_pRoot->GetObjectByName(name);
		
		hkpRigidBodyCinfo ci;
		ci.m_friction = 0.3f;
		ci.m_motionType = hkpMotion::MOTION_KEYFRAMED;
		ci.m_qualityType = HK_COLLIDABLE_QUALITY_KEYFRAMED;
		ci.m_shape = shape;
		ci.m_restitution = 0;
		ci.m_collisionFilterInfo = hkpGroupFilter::calcFilterInfo(layer, GROUP_BODY);
		GetNiTransformScaled(node.node->m_worldTransform, ci.m_position, ci.m_rotation);
		
		node.rb = hkNew<hkpRigidBody>(ci);
		shape->removeReference();
		
		this->m_arrNodes.push_back(node);
		return m_arrNodes.size()-1;
	};

	auto AddCapsuleRefNode = [this, AddRefNode](const BSFixedString& name, const hkVector4& p1, const hkVector4& p2, float r, int layer)->int
	{
		float realScale = m_pRoot->GetObjectByName(name)->m_worldTransform.scale * scaleToHavok;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		
		hkVector4 rp1, rp2;
		rp1.setMul(p1, realScaleShape);
		rp2.setMul(p2, realScaleShape);
		hkpShape* shape;
		hkVector4 tp;
		tp.setSub(rp1, rp2);
		if(tp.length3() < 1e-4f && rp1.length3() < 1e-4f)
			shape = new hkpSphereShape(r*realScaleShape);
		else shape = new hkpCapsuleShape(rp1, rp2, r*realScaleShape);
		
		return AddRefNode(name, shape, layer);
	};
	
	// NPC COM
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_SPINE2)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4(-6.6, -4.9, 4), realScaleShape);
		p2.setMul(hkVector4( 6.6, -4.9, 4), realScaleShape);
		p3.setMul(hkVector4(-5, -1.4, 10), realScaleShape);
		p4.setMul(hkVector4( 5, -1.4, 10), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 11.8*realScaleShape),
			new hkpCapsuleShape(p3, p4, 10*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_PELVIS, shape, LAYER_NORMAL);
	}
	//Thigh
	AddCapsuleRefNode(NPC_LTHIGH, hkVector4(0, -0.25, 45.06), hkVector4( 1.5, -2.5, 5.24f), 9.84f, LAYER_NORMAL);
	AddCapsuleRefNode(NPC_RTHIGH, hkVector4(0, -0.25, 45.06), hkVector4(-1.5, -2.5f, 5.24f), 9.84f, LAYER_NORMAL);
	
	//Calf
	AddCapsuleRefNode(NPC_LCALF, hkVector4( 0.4f, -2.f, 4.f), hkVector4( 0.4f, -2.5f, 0.f), 8.f, LAYER_NORMAL);
	AddCapsuleRefNode(NPC_RCALF, hkVector4(-0.4f, -2.f, 4.f), hkVector4(-0.4f, -2.5f, 0.f), 8.f, LAYER_NORMAL);

	//Foot
	AddCapsuleRefNode(NPC_LFOOT, hkVector4(-0.03f, 3.f, 16.f), hkVector4(-0.03f, -4.f, 2.f), 6.31f, LAYER_NORMAL);
	AddCapsuleRefNode(NPC_RFOOT, hkVector4( 0.03f, 3.f, 16.f), hkVector4( 0.03f, -4.f, 2.f), 6.31f, LAYER_NORMAL);
	
	//Spine
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_SPINE)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4( 4.79, 6, 10.2), realScaleShape);
		p2.setMul(hkVector4(-4.79, 6, 10.2), realScaleShape);
		p3.setMul(hkVector4(-6.5, 6, 5), realScaleShape);
		p4.setMul(hkVector4( 6.5, 6, 5), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 10.5*realScaleShape),
			new hkpCapsuleShape(p3, p4, 10*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_SPINE1, shape, LAYER_NORMAL);
	}
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_SPINE1)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4( 2.5, 8.4, 8.79), realScaleShape);
		p2.setMul(hkVector4(-2.5, 8.4, 8.79), realScaleShape);
		p3.setMul(hkVector4(-2.8, 7.4, 2.5), realScaleShape);
		p4.setMul(hkVector4( 2.8, 7.4, 2.5), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 9.8*realScaleShape),
			new hkpCapsuleShape(p3, p4, 9*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_SPINE1, shape, LAYER_NORMAL);
	}
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_SPINE2)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		float r = 11;

		hkpShape* subShapes[3];
		hkVector4 p1(4.32, 5.7, 11.5), p2(-4.32, 5.7, 11.5);
		p1.setMul(p1, realScaleShape);
		p2.setMul(p2, realScaleShape);
		subShapes[0] = new hkpCapsuleShape(p1, p2, 11*realScaleShape);
		
		p1.setMul(hkVector4( 9, 1.3, 20), realScaleShape);
		p2.setMul(hkVector4(-9, 1.3, 20), realScaleShape);
		subShapes[1] = new hkpCapsuleShape(p1, p2, 9.8*realScaleShape);

		p1.setMul(hkVector4( 3, 8, 3.5), realScaleShape);
		p2.setMul(hkVector4(-3, 8, 3.5), realScaleShape);
		subShapes[2] = new hkpCapsuleShape(p1, p2, 10.5*realScaleShape);

		auto shape = new hkpListShape(subShapes, 3, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		
		AddRefNode(NPC_SPINE2, shape, LAYER_NORMAL);
	}

	//Head
	AddCapsuleRefNode(NPC_NECK, hkVector4(0, 1.91, 0), hkVector4(0, 1.91, 6.3), 6.93, LAYER_NORMAL);
	AddCapsuleRefNode(NPC_HEAD, hkVector4(0, 4.78, 4.21), hkVector4(0, 3.57, 8.01), 11.87, LAYER_NORMAL);
	
	//Arm
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_LUPPERARM)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4(3.6, 0.8, -1), realScaleShape);
		p2.setMul(hkVector4(3, 0, 10), realScaleShape);
		p3.setMul(hkVector4(3, 0, 10), realScaleShape);
		p4.setMul(hkVector4(0, 0.5, 30.538), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 5.5*realScaleShape),
			new hkpCapsuleShape(p3, p4, 5*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_LUPPERARM, shape, LAYER_NORMAL);
	}
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_RUPPERARM)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4(-3.6, 0.8, -1), realScaleShape);
		p2.setMul(hkVector4(-3, 0, 10), realScaleShape);
		p3.setMul(hkVector4(-3, 0, 10), realScaleShape);
		p4.setMul(hkVector4(0, 0.5, 30.538), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 5.5*realScaleShape),
			new hkpCapsuleShape(p3, p4, 5*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_RUPPERARM, shape, LAYER_NORMAL);
	}
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_LFOREARM)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4(0, 2.3, 0), realScaleShape);
		p2.setMul(hkVector4(0, 1.4, 10), realScaleShape);
		p3.setMul(hkVector4(0, 1.4, 10), realScaleShape);
		p4.setMul(hkVector4(0, 0.5, 22), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 4.5*realScaleShape),
			new hkpCapsuleShape(p3, p4, 4*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_LFOREARM, shape, LAYER_NORMAL);
	}
	{
		float realScale = scaleToHavok * m_pRoot->GetObjectByName(NPC_RFOREARM)->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;
		hkVector4 p1, p2, p3, p4;
		p1.setMul(hkVector4(0, 2.3, 0), realScaleShape);
		p2.setMul(hkVector4(0, 1.4, 10), realScaleShape);
		p3.setMul(hkVector4(0, 1.4, 10), realScaleShape);
		p4.setMul(hkVector4(0, 0.5, 22), realScaleShape);

		hkpShape* subShapes[] = {
			new hkpCapsuleShape(p1, p2, 4.5*realScaleShape),
			new hkpCapsuleShape(p3, p4, 4*realScaleShape),
		};
		auto shape = new hkpListShape(subShapes, 2, hkpShapeContainer::REFERENCE_POLICY_IGNORE);
		AddRefNode(NPC_RFOREARM, shape, LAYER_NORMAL);
	}
	AddCapsuleRefNode(NPC_LHAND, hkVector4(-0.45, -1, 8), hkVector4(-0.45, -2, 10), 8, LAYER_VIRTUAL);
	AddCapsuleRefNode(NPC_RHAND, hkVector4( 0.45, -1, 8), hkVector4( 0.45, -2, 10), 8, LAYER_VIRTUAL);

	//Pre
	int iLPreBreast = AddCapsuleRefNode(NPC_LPREBREAST, hkVector4(0, 0, 0), hkVector4(0, 0, 0), 1, LAYER_VIRTUAL);
	int iRPreBreast = AddCapsuleRefNode(NPC_RPREBREAST, hkVector4(0, 0, 0), hkVector4(0, 0, 0), 1, LAYER_VIRTUAL);
	int iLPreButt = AddCapsuleRefNode(NPC_LPREBUTT, hkVector4(-2.2, 6.3, -4), hkVector4(-2.35, 6.3, -5), 11.5, LAYER_NORMAL);
	int iRPreButt = AddCapsuleRefNode(NPC_RPREBUTT, hkVector4( 2.2, 6.3, -4), hkVector4( 2.35, 6.3, -5), 11.5, LAYER_NORMAL);

	//Dyn
	auto AddBreast = [=](bool l)
	{
		NODE node;
		node.dynamic = true;
		node.group = GROUP_BODY;
		node.node = (NiNode*)m_pRoot->GetObjectByName(l ? NPC_LBREAST : NPC_RBREAST);
		SetNiTransformScaled(node.node->m_localTransform, hkTransform::getIdentity());
		NiAVObject::ControllerUpdateContext ctx;
		node.node->UpdateWorldData(&ctx);

		float realScale = scaleToHavok * node.node->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;

		hkVector4 p1((l?1:-1), 7, -5.5f), p2((l?2:-2), 0, -5.5f);
		p1.mul(realScaleShape);
		p2.mul(realScaleShape);
		auto shape = new hkpCapsuleShape(p1, p2, 9.f*realScaleShape);

		hkpRigidBodyCinfo ci;
		hkMassProperties pi;
		hkVector4 massCenter(0, 0.01, 0);
		hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(hkVector4::getZero(), massCenter, 0.03, 0.5, pi);
		ci.m_angularDamping = 0.2;
		ci.m_friction = 0.3;
		ci.m_shape = shape;
		ci.m_collisionFilterInfo = hkpGroupFilter::calcFilterInfo(LAYER_VIRTUAL, GROUP_BODY);
		GetNiTransformScaled(node.node->m_worldTransform, ci.m_position, ci.m_rotation);
		
		node.rb = hkNew<hkpRigidBody>(ci);
		shape->removeReference();

		this->m_arrNodes.push_back(node);

		int parentIdx = l ? iLPreBreast : iRPreBreast;
		auto* parent = &this->m_arrNodes[parentIdx];
		hkVector4 zero(0, 0, 0), pivot(0, 0, 0), twist(0, 1, 0), plane(0, 0, 1);

		auto pLimit = new hkpGenericConstraintData;
		hkpConstraintConstructionKit kit;
		kit.begin(pLimit);
		{
			kit.setPivotA(pivot);
			kit.setPivotB(pivot);
			kit.constrainAllLinearDof();
			hkMatrix3 rot = hkMatrix3::getIdentity();
			kit.setAngularBasisA(rot);
			kit.setAngularBasisB(rot);
			kit.setAngularLimit(0, -0.3, 0.3);
			kit.setAngularLimit(1, -0.3, 0.3);
			kit.setAngularLimit(2, -0.3, 0.3);
			kit.setStrength(0.00075);
			kit.constrainAllAngularDof();
			kit.restoreStrength();
		}
		kit.end();
		assert(pLimit->isValid());
		
		m_arrConstraints.push_back(hkNew<hkpConstraintInstance>(node.rb, parent->rb, pLimit));
		pLimit->removeReference();
	};
	AddBreast(1);
	AddBreast(0);

	//Butt
	auto AddButt = [=](bool l)
	{
		NODE node;
		node.dynamic = true;
		node.group = GROUP_BODY;
		node.node = (NiNode*)m_pRoot->GetObjectByName(l ? NPC_LBUTT : NPC_RBUTT);
		SetNiTransformScaled(node.node->m_localTransform, hkTransform::getIdentity());
		NiAVObject::ControllerUpdateContext ctx;
		node.node->UpdateWorldData(&ctx);
		float realScale = scaleToHavok * node.node->m_worldTransform.scale;
		float realScaleShape = realScale * scaleShapeToSkyrim;

		hkVector4 p1, p2;
		p1.setMul(hkVector4(l ? -2.1 : 2.1, 6.3, -4), realScaleShape);
		p2.setMul(hkVector4(l ? -2.25 : 2.25, 6.3, -5), realScaleShape);
		auto shape = new hkpCapsuleShape(p1, p2,  10.8*realScaleShape);
		
		hkpRigidBodyCinfo ci;
		hkMassProperties pi;
		hkVector4 massCenter(0, -0.01, 0);
		hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(hkVector4::getZero(), massCenter, 0.03, 0.5, pi);
		ci.setMassProperties(pi);
		ci.m_angularDamping = 0.1;
		ci.m_friction = 0.3;
		ci.m_shape = shape;
		ci.m_collisionFilterInfo = hkpGroupFilter::calcFilterInfo(LAYER_VIRTUAL, GROUP_BODY);
		GetNiTransformScaled(node.node->m_worldTransform, ci.m_position, ci.m_rotation);
		
		node.rb = hkNew<hkpRigidBody>(ci);
		shape->removeReference();

		this->m_arrNodes.push_back(node);
		
		int parentIdx = l ? iLPreButt : iRPreButt;
		auto* parent = &this->m_arrNodes[parentIdx];
		hkVector4 zero(0, 0, 0), pivot(0, 0, 0), twist(0, -1, 0), plane(0, 0, 1);
		
		auto pLimit = new hkpGenericConstraintData;
		hkpConstraintConstructionKit kit;
		kit.begin(pLimit);
		{
			kit.setPivotA(pivot);
			kit.setPivotB(pivot);
			kit.constrainAllLinearDof();
			hkMatrix3 rot = hkMatrix3::getIdentity();
			kit.setAngularBasisA(rot);
			kit.setAngularBasisB(rot);
			kit.setAngularLimit(0, -0.1, 0.1);
			kit.constrainToAngularDof(1);
			kit.setAngularLimit(2, -0.3, 0.3);
			kit.setStrength(0.0015);
			kit.constrainAllAngularDof();
			kit.restoreStrength();
		}
		kit.end();
		assert(pLimit->isValid());
		
		m_arrConstraints.push_back(hkNew<hkpConstraintInstance>(node.rb, parent->rb, pLimit));
		pLimit->removeReference();
	};
	AddButt(1);
	AddButt(0);
	
	LogDebug("Physics info updated : %08x", m_iFormID);
	
	return true;
}