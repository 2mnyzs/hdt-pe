#pragma once

#include "skse\NiControllers.h"
#include "skse\NiExtraData.h"
#include "skse\NiGeometry.h"
#include "skse\NiInterpolators.h"
#include "skse\NiMaterial.h"
#include "skse\NiNodes.h"
#include "skse\NiProperties.h"
#include "skse\NiRTTI.h"
#include "skse\NiSerialization.h"
#include "skse\NiTextures.h"

#include "common.h"
#include "havok_helper.h"

#define DEFINE_MEMBER_FN_HOOK(functionName, retnType, address, ...)		\
	typedef retnType (_MEMBER_FN_BASE_TYPE::* _##functionName##_type)(__VA_ARGS__);	\
																					\
	static inline _##functionName##_type * _##functionName##_GetPtr(void)			\
	{																				\
		static UInt32 _address = address;											\
		return (_##functionName##_type *)&_address;									\
	}

class bhkRefObject : public NiObject{};
class bhkSerializable : public bhkRefObject{};
class bhkShape : public bhkSerializable{};

class bhkSphereRepShape : public bhkShape
{
public:
	enum {
		HAV_MAT_STONE,
		HAV_MAT_CLOTH,
		HAV_MAT_DIRT,
		HAV_MAT_GLASS,
		HAV_MAT_GRASS,
		HAV_MAT_METAL,
		HAV_MAT_ORGANIC,
		HAV_MAT_SKIN,
		HAV_MAT_WATER,
		HAV_MAT_WOOD,
		HAV_MAT_HEAVY_STONE,
		HAV_MAT_HEAVY_METAL,
		HAV_MAT_HEAVY_WOOD,
		HAV_MAT_CHAIN,
		HAV_MAT_SNOW,
		HAV_MAT_STONE_STAIRS,
		HAV_MAT_CLOTH_STAIRS,
		HAV_MAT_DIRT_STAIRS,
		HAV_MAT_GLASS_STAIRS,
		HAV_MAT_GRASS_STAIRS,
		HAV_MAT_METAL_STAIRS,
		HAV_MAT_ORGANIC_STAIRS,
		HAV_MAT_SKIN_STAIRS,
		HAV_MAT_WATER_STAIRS,
		HAV_MAT_WOOD_STAIRS,
		HAV_MAT_HEAVY_STONE_STAIRS,
		HAV_MAT_HEAVY_METAL_STAIRS,
		HAV_MAT_HEAVY_WOOD_STAIRS,
		HAV_MAT_CHAIN_STAIRS,
		HAV_MAT_SNOW_STAIRS,
		HAV_MAT_ELEVATOR
	};

	UINT32 m_material;
	float m_radius;
};
class bhkConvexShape : public bhkSphereRepShape{};
class bhkSphereShape : public bhkConvexShape{};

class bhkBoxShape : public bhkConvexShape
{
public:
	UINT8 m_unk[8];
	NiPoint3 m_halfBox;
	float m_minimumSize;
};

class bhkCapsuleShape : public bhkConvexShape
{
public:
	UINT8 m_unk[8];
	NiPoint3 m_pointA;
	float m_radiusA;
	NiPoint3 m_pointB;
	float m_radiusB;
};
/*
class bhkConvexVerticesShape : public bhkConvexShape
{
public:
	float		m_unk[6];
	UINT32		m_numVertices;
	NiPoint3*	m_vertices;
	UINT32		m_numNormals;
	NiPoint3*	m_normals;
};*/

class bhkShapeCollection : public bhkShape{};
class bhkListShape : public bhkShapeCollection
{
public:
	/*
	UINT32		m_numShapes;
	bhkShape*	m_shapes;
	UINT32		m_material;
	float		m_unkf[6];
	UINT32		m_numUnkInt;
	UINT32*		m_unkInt;*/
};

class bhkConstraint : public bhkSerializable
{
public:
	hkpConstraintInstance* m_instance;
};

class bhkWorldObject : public bhkSerializable{};

class bhkEntity : public bhkWorldObject{};
class bhkRigidBody : public bhkEntity
{
public:
	hkpRigidBody* m_rigidBody;
	UINT32 unk0[3];
	bhkConstraint** m_constraints;
	UINT32 m_numConstraints;
	UINT32 m_capacity;
};

class NiCollisionObject : public NiObject
{
public:
	NiAVObject* m_target;
};

class bhkNiCollisionObject : public NiCollisionObject
{
public:
	UINT16 m_flags;
	bhkRigidBody* m_body;
};
class bhkCollisionObject : public bhkNiCollisionObject{};

class bhkBlendCollisionObject : public bhkNiCollisionObject
{
public:
	float unk[2];
};

void UpdateWorldData(NiAVObject* node);
void UpdateWorldDataToChild(NiNode* node);
void UpdateWorldDataFromRoot(NiAVObject* node);
void UpdateLocalData(NiAVObject* dst);

int CombineTree(NiNode* to, NiNode* from);
void ClearNode(NiNode* from, const std::string& prefix);
bool ShouldRename(NiNode* root, NiAVObject* node, const std::string& prefix);
void RenameNode(NiNode* root, NiNode* node, const std::string& prefix);
void CancelRename(NiNode* node, const std::string& prefix);

bool IsMyAncestor(NiAVObject* me, NiNode* r);
inline NiNode* CastNiNode(NiObject* obj){ return obj ? obj->GetAsNiNode() : 0; }