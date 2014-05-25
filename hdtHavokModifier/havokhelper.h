#ifndef HAVOKHELPER_H
#define HAVOKHELPER_H

//#define HK_CONFIG_SIMD HK_CONFIG_SIMD_ENABLED

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
#include <Common\Base\Types\Geometry\hkGeometry.h>
#include <Common\Base\Container\String\hkStringObject.h>
#include <Common\Base\Monitor\MonitorStreamAnalyzer\hkMonitorStreamAnalyzer.h>
#include <Common\GeometryUtilities\hkGeometryUtilities.h>
#include <Common\GeometryUtilities\Inertia\hkInertiaTensorComputer.h>
#include <Common\Serialize\hkSerialize.h>
#include <Common\Serialize\Serialize\hkRelocationInfo.h>
#include <Common\Serialize\ResourceDatabase\hkResourceHandle.h>
#include <Common\Serialize\Util\hkSerializeUtil.h>
#include <Common\Serialize\Util\hkRootLevelContainer.h>
#include <Common\Serialize\Util\hkStaticClassNameRegistry.h>
#include <Common\Serialize\Util\hkRootLevelContainer.h>

#include <Geometry\Internal\DataStructures\DynamicTree\hkcdDynamicAabbTree.h>
#include <Geometry\Internal\DataStructures\StaticTree\hkcdStaticAabbTree.h>

#include <Physics\Constraint\hkpConstraint.h>
#include <Physics\Constraint\Data\AngularFriction\hkpAngularFrictionConstraintData.h>
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
#include <Physics\Constraint\Motor\Callback\hkpCallbackConstraintMotor.h>
#include <Physics\Constraint\Motor\LimitedForce\hkpLimitedForceConstraintMotor.h>
#include <Physics\Constraint\Motor\Position\hkpPositionConstraintMotor.h>
#include <Physics\Constraint\Motor\SpringDamper\hkpSpringDamperConstraintMotor.h>
#include <Physics\Constraint\Motor\Velocity\hkpVelocityConstraintMotor.h>
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
#include <Physics2012\Collide\Filter\DefaultConvexList\hkpDefaultConvexListFilter.h>
#include <Physics2012\Collide\Filter\Group\hkpGroupFilter.h>
#include <Physics2012\Collide\Filter\List\hkpCollisionFilterList.h>
#include <Physics2012\Collide\Shape\Convex\Sphere\hkpSphereShape.h>
#include <Physics2012\Collide\Shape\Convex\Cylinder\hkpCylinderShape.h>
#include <Physics2012\Collide\Shape\Convex\Triangle\hkpTriangleShape.h>
#include <Physics2012\Collide\Shape\Convex\Box\hkpBoxShape.h>
#include <Physics2012\Collide\Shape\Convex\Capsule\hkpCapsuleShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexVertices\hkpConvexVerticesConnectivity.h>
#include <Physics2012\Collide\Shape\Convex\ConvexVertices\hkpConvexVerticesShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexTranslate\hkpConvexTranslateShape.h>
#include <Physics2012\Collide\Shape\Convex\ConvexTransform\hkpConvexTransformShape.h>
#include <Physics2012\Collide\Shape\Compound\Tree\Mopp\hkpMoppBvTreeShape.h>
#include <Physics2012\Collide\Shape\Compound\Collection\List\hkpListShape.h>
#include <Physics2012\Collide\Shape\Deprecated\ConvexList\hkpConvexListShape.h>
#include <Physics2012\Collide\Shape\Misc\Bv\hkpBvShape.h>
#include <Physics2012\Collide\Shape\Misc\MultiRay\hkpMultiRayShape.h>
#include <Physics2012\Collide\Shape\Misc\PhantomCallback\hkpPhantomCallbackShape.h>
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

void defaultErrorReporter(const char* ch, void* p);

#include <functional>
void initHavok(std::function<void(const char*, void*)> reporter = defaultErrorReporter);
void quitHavok();
void initThread();
void quitThread();

hkpPhysicsSystem* loadPhysicsSystem(const wchar_t* path);

const hkClass* getHavokClass(const hkReferencedObject* ptr);

void calcMassProperties(hkMassProperties& pi, const hkpShape *shape);

void setEularZYX(hkQuaternion& q, float Z, float Y, float X);
void getEularZYX(const hkQuaternion& q, float& z, float& y, float& x);

#endif // HAVOKHELPER_H
