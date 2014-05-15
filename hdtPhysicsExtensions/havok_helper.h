#pragma once

#include "ppapi_helper.h"
#include "common.h"

#pragma pack( push, 8 )

#include <Common\Base\hkBase.h>
#include <Common\Base\KeyCode.h>
#include <Common\Base\System\hkBaseSystem.h>
#include <Common\Base\System\Error\hkDefaultError.h>
#include <Common\Base\Memory\Allocator\hkMemoryAllocator.h>
#include <Common\Base\Memory\System\hkMemorySystem.h>
#include <Common\Base\Memory\System\Util\hkMemoryInitUtil.h>
#include <Common\Base\Memory\Allocator\Malloc\hkMallocAllocator.h>
#include <Common\Base\Thread\JobQueue\hkJobQueue.h>
#include <Common\Base\Thread\Job\ThreadPool\Cpu\hkCpuJobThreadPool.h>
#include <Common\GeometryUtilities\hkGeometryUtilities.h>
#include <Common\GeometryUtilities\Inertia\hkInertiaTensorComputer.h>
#include <Common\Serialize\hkSerialize.h>
#include <Common\Serialize\Serialize\hkRelocationInfo.h>
#include <Common\Serialize\Util\hkSerializeUtil.h>
#include <Common\Serialize\Util\hkRootLevelContainer.h>
#include <Common\Serialize\Util\hkStaticClassNameRegistry.h>
#include <Common\Serialize\Util\hkRootLevelContainer.h>

#include <Physics\Constraint\hkpConstraint.h>
#include <Physics\Constraint\Data\BallAndSocket\hkpBallAndSocketConstraintData.h>
#include <Physics\Constraint\Data\Clearance\hkpLinearClearanceConstraintData.h>
#include <Physics\Constraint\Data\CogWheel\hkpCogWheelConstraintData.h>
#include <Physics\Constraint\Data\DeformableFixed\hkpDeformableFixedConstraintData.h>
#include <Physics\Constraint\Data\Fixed\hkpFixedConstraintData.h>
#include <Physics\Constraint\Data\Hinge\hkpHingeConstraintData.h>
#include <Physics\Constraint\Data\HingeLimits\hkpHingeLimitsData.h>
#include <Physics\Constraint\Data\LimitedHinge\hkpLimitedHingeConstraintData.h>
#include <Physics\Constraint\Data\PointToPath\hkpLinearParametricCurve.h>
#include <Physics\Constraint\Data\PointToPath\hkpPointToPathConstraintData.h>
#include <Physics\Constraint\Data\PointToPlane\hkpPointToPlaneConstraintData.h>
#include <Physics\Constraint\Data\Prismatic\hkpPrismaticConstraintData.h>
#include <Physics\Constraint\Data\Pulley\hkpPulleyConstraintData.h>
#include <Physics\Constraint\Data\RackAndPinion\hkpRackAndPinionConstraintData.h>
#include <Physics\Constraint\Data\Ragdoll\hkpRagdollConstraintData.h>
#include <Physics\Constraint\Data\RagdollLimits\hkpRagdollLimitsData.h>
#include <Physics\Constraint\Data\Rotational\hkpRotationalConstraintData.h>
#include <Physics\Constraint\Data\StiffSpring\hkpStiffSpringConstraintData.h>
#include <Physics\Constraint\Data\Wheel\hkpWheelConstraintData.h>
#include <Physics\Constraint\Motor\Position\hkpPositionConstraintMotor.h>
#include <Physics\Constraint\Motor\Velocity\hkpVelocityConstraintMotor.h>
#include <Physics\Constraint\Motor\LimitedForce\hkpLimitedForceConstraintMotor.h>
#include <Physics\Constraint\Motor\SpringDamper\hkpSpringDamperConstraintMotor.h>
#include <Physics2012\Dynamics\hkpDynamics.h>
#include <Physics2012\Utilities\Actions\Wind\hkpWind.h>
#include <Physics2012\Utilities\Actions\Wind\hkpWindAction.h>
#include <Physics2012\Utilities\Actions\Wind\hkpWindRegion.h>
#include <Physics2012\Utilities\Actions\Wind\hkpPrevailingWind.h>
#include <Physics2012\Dynamics\World\hkpWorld.h>
#include <Physics2012\Dynamics\World\hkpPhysicsSystem.h>
#include <Physics2012\Dynamics\World\Util\hkpWorldConstraintUtil.h>
#include <Physics2012\Dynamics\Entity\hkpRigidBody.h>
#include <Physics2012\Dynamics\Constraint\hkpConstraintInstance.h>
#include <Physics2012\Dynamics\Constraint\Chain\hkpConstraintChainData.h>
#include <Physics2012\Dynamics\Constraint\Chain\hkpConstraintChainInstance.h>
#include <Physics2012\Dynamics\Constraint\Chain\BallSocket\hkpBallSocketChainData.h>
#include <Physics2012\Dynamics\Constraint\Chain\StiffSpring\hkpStiffSpringChainData.h>
#include <Physics2012\Dynamics\Constraint\Chain\Powered\hkpPoweredChainData.h>
#include <Physics2012\Dynamics\Constraint\Util\hkpConstraintStabilizationUtil.h>
#include <Physics2012\Dynamics\Constraint\Breakable\hkpBreakableConstraintData.h>
#include <Physics2012\Dynamics\Constraint\Malleable\hkpMalleableConstraintData.h>
#include <Physics2012\Dynamics\Constraint\ConstraintKit\hkpGenericConstraintData.h>
#include <Physics2012\Dynamics\Constraint\ConstraintKit\hkpGenericConstraintParameters.h>
#include <Physics2012\Dynamics\Constraint\ConstraintKit\hkpGenericConstraintScheme.h>
#include <Physics2012\Dynamics\Constraint\ConstraintKit\hkpConstraintConstructionKit.h>
#include <Physics2012\Dynamics\Collide\Filter\Pair\hkpPairCollisionFilter.h>
#include <Physics2012\Dynamics\Collide\Filter\Constraint\hkpConstraintCollisionFilter.h>
#include <Physics2012\Collide\Filter\Group\hkpGroupFilter.h>
#include <Physics2012\Collide\Filter\List\hkpCollisionFilterList.h>
#include <Physics2012\Collide\Shape\Convex\Sphere\hkpSphereShape.h>
#include <Physics2012\Collide\Shape\Convex\Cylinder\hkpCylinderShape.h>
#include <Physics2012\Collide\Shape\Convex\Triangle\hkpTriangleShape.h>
#include <Physics2012\Collide\Shape\Convex\Box\hkpBoxShape.h>
#include <Physics2012\Collide\Shape\Convex\Capsule\hkpCapsuleShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexVertices\hkpConvexVerticesShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexTranslate\hkpConvexTranslateShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexTransform\hkpConvexTransformShape.h>
#include <Physics2012\Collide\Shape\Compound\Collection\List\hkpListShape.h>
#include <Physics2012\Collide\Shape\Query\hkpShapeRayCastInput.h>
#include <Physics2012\Collide\Query\CastUtil\hkpWorldRayCastInput.h>
#include <Physics2012\Collide\Agent\ConvexAgent\SphereBox\hkpSphereBoxAgent.h>			
#include <Physics2012\Collide\Dispatch\hkpAgentRegisterUtil.h>
#include <Physics2012\Utilities\Collide\ShapeUtils\ShapeScaling\hkpShapeScalingUtility.h>
#include <Physics2012\Utilities\Dynamics\KeyFrame\hkpKeyFrameUtility.h>
#include <Physics2012\Utilities\Dynamics\ScaleSystem\hkpSystemScalingUtility.h>
#include <Physics2012\Utilities\Serialize\hkpPhysicsData.h>

#include <Animation\Animation\hkaAnimation.h>
#include <Animation\Animation\Animation\hkaAnimation.h>

#pragma pack( pop )

void GetNiTransform(const NiTransform& in, hkQsTransform& out);
void SetNiTransform(NiTransform& out, const hkQsTransform& in);
void GetNiTransform(const NiTransform& in, hkTransform& out);
void SetNiTransform(NiTransform& out, const hkTransform& in);
void GetNiTransform(const NiTransform& in, hkVector4& pos, hkQuaternion& rot);
void SetNiTransform(NiTransform& out, const hkVector4& pos, const hkQuaternion& rot);

void GetNiTransformScaled(const NiTransform& in, hkTransform& out);
void SetNiTransformScaled(NiTransform& out, const hkTransform& in);
void GetNiTransformScaled(const NiTransform& in, hkVector4& pos, hkQuaternion& rot);
void SetNiTransformScaled(NiTransform& out, const hkVector4& pos, const hkQuaternion& rot);
void GetNiTransformScaled(const NiTransform& in, hkQsTransform& out);
void SetNiTransformScaled(NiTransform& out, const hkQsTransform& in);

static const float scaleToHavok = 0.01425;
static const float scaleToSkyrim = 1 / scaleToHavok;

static const float TIME_TICK = 1/60.f;
static const auto TIME_TICK_US = std::chrono::microseconds((long long)(TIME_TICK*1e+6));

void CalcLocalTransform(NiAVObject* dst);

template <class T> hkRefNew<T> hkMove(T* p){ return p; }
template <class T> hkRefNew<T> hkNew(){ return new T; }
template <class T, class TArg0> hkRefNew<T> hkNew(const TArg0& arg0){ return new T(arg0); }
template <class T, class TArg0, class TArg1>
hkRefNew<T> hkNew(const TArg0& arg0, const TArg1& arg1)
{ return new T(arg0, arg1); }
template <class T, class TArg0, class TArg1, class TArg2>
hkRefNew<T> hkNew(const TArg0& arg0, const TArg1& arg1, const TArg2& arg2)
{ return new T(arg0, arg1, arg2); }
template <class T, class TArg0, class TArg1, class TArg2, class TArg3>
hkRefNew<T> hkNew(const TArg0& arg0, const TArg1& arg1, const TArg2& arg2, const TArg3& arg3)
{ return new T(arg0, arg1, arg2, arg3); }
template <class T, class A0, class A1, class A2, class A3, class A4>
hkRefNew<T> hkNew(const A0& arg0, const A1& arg1, const A2& arg2, const A3& arg3, const A4& a4)
{ return new T(arg0, arg1, arg2, arg3, a4); }
template <class T, class A0, class A1, class A2, class A3, class A4, class A5>
hkRefNew<T> hkNew(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
{ return new T(a0, a1, a2, a3, a4, a5); }

inline bool IsDynamic(hkpMotion::MotionType type)
{
	return !(type == hkpMotion::MOTION_FIXED || type == hkpMotion::MOTION_KEYFRAMED);
}

void ScaleConstraint(hkpConstraintData* data, float scaleA, float scaleB);
void ScaleRigidBody(hkpRigidBody* rb, float scale);
bool ScaleSystemWithNode(const hkArray<NiNode*>& bones, hkpPhysicsSystem* system, float defaultScale);

class MyGroupFilter : public hkpCollisionFilter
{
public:

	MyGroupFilter(){ m_type = HK_FILTER_CUSTOM; }
	/// Checks two collidables
	virtual hkBool isCollisionEnabled( const hkpCollidable& a, const hkpCollidable& b ) const;

		/// hkpShapeCollectionFilter interface forwarding
	virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& a, const hkpCdBody& b, 
										   const HK_SHAPE_CONTAINER& bContainer, hkpShapeKey bKey ) const;

		/// hkpShapeCollectionFilter interface forwarding
	virtual hkBool isCollisionEnabled( const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, 
									   const hkpCdBody& collectionBodyB, const HK_SHAPE_CONTAINER& containerShapeA, 
									   const HK_SHAPE_CONTAINER& containerShapeB, 
									   hkpShapeKey keyA, hkpShapeKey keyB ) const;

		/// hkpRayShapeCollectionFilter interface forwarding
	virtual hkBool isCollisionEnabled( const hkpShapeRayCastInput& aInput, const HK_SHAPE_CONTAINER& bContainer, 
									   hkpShapeKey bKey ) const;

		/// hkpRayCollidableFilter interface forwarding
	virtual hkBool isCollisionEnabled( const hkpWorldRayCastInput& a, const hkpCollidable& collidableB ) const;

	static hkUint32 calcCollisionInfo(hkUint32 myGroup, hkUint32 noCollideWith);
	static bool isFiltered(hkUint32 a, hkUint32 b);
	static bool isCollisionEnabled(hkUint32 a, hkUint32 b);

};

hkpPhysicsSystem* LoadPhysicsFile(const char* path);
