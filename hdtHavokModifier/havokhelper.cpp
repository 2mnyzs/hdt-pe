#include "havokhelper.h"

#include <Common\Base\keycode.cxx>
#include <Common\Base\Config\hkProductFeatures.cxx>

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

void defaultErrorReporter(const char* ch, void* p)
{
    std::cout << ch << std::endl;
}

std::function<void(const char*, void*)> errorReporter;
void errorReporterProxy(const char* ch, void* p)
{
    errorReporter(ch, p);
}

hkMemoryRouter* memoryRouter;
void initHavok(std::function<void(const char*, void*)> reporter)
{
	errorReporter = reporter;
	memoryRouter = hkMemoryInitUtil::initDefault( hkMallocAllocator::m_defaultMallocAllocator, hkMemorySystem::FrameInfo( 64 * 1024 * 1024 ) );
	hkBaseSystem::init( memoryRouter, errorReporterProxy );
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
}

void quitHavok()
{
	hkBaseSystem::quit();
	hkMemoryInitUtil::quit();
	memoryRouter = 0;
}

void initThread()
{
	hkBaseSystem::initThread(memoryRouter);
}

void quitThread()
{
	hkBaseSystem::quitThread();
}

hkpPhysicsSystem* loadPhysicsSystem(const wchar_t* path)
{
	std::ifstream fin(path, std::ios_base::binary);
	if(!fin.is_open()) return 0;
	
	std::vector<char> buf;
	while(!fin.eof()) buf.push_back(fin.get());
	fin.close();
	
	hkSerializeUtil::ErrorDetails err;
	auto resource = hkSerializeUtil::load(buf.data(), buf.size(), &err);
	if(!resource) return 0;
	
	auto system = resource->getContents<hkpPhysicsSystem>();
	if(!system)
	{
		auto data = resource->getContents<hkpPhysicsData>();
		if(!data)
		{
			auto root = resource->getContents<hkRootLevelContainer>();
			if(root)
			{
				system = (hkpPhysicsSystem*)root->findObjectByType("hkpPhysicsSystem");
				if(!system)
				{
					data = (hkpPhysicsData*)root->findObjectByType("hkpPhysicsData");
					if(data && data->getPhysicsSystems().getSize())
					{
						system = data->getPhysicsSystems()[0];
						system->addReference();
					}
					if(data) data->removeReference();
				}
				delete root;
			}
		}
		else
		{
			system = data->getPhysicsSystems()[0];
			system->addReference();
			data->removeReference();
		}
	}
	return system;
}

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

#define HK_CLASS( c ) class c;
#define HK_STRUCT( c )// struct c;
#define HK_ABSTRACT_CLASS( c ) class c;
#include HK_CLASSES_FILE
#undef HK_CLASS
#undef HK_STRUCT
#undef HK_ABSTRACT_CLASS

struct hkRTTIHelper
{
	hkRTTIHelper()
	{
#define HK_CLASS( c ) classMap[typeid(c)]=&c##Class;
#define HK_STRUCT( c ) //classMap[typeid(c)]=&c::staticClass();
#define HK_ABSTRACT_CLASS( c ) classMap[typeid(c)]=&c##Class;
#include HK_CLASSES_FILE
		
		classMap[typeid(hkpAngularFrictionConstraintData)] = &hkpAngularFrictionConstraintData::staticClass();
		
#undef HK_CLASS
#undef HK_STRUCT
#undef HK_ABSTRACT_CLASS
	}
	std::unordered_map<std::type_index, const hkClass*> classMap;
}rttiHelper;

const hkClass* getHavokClass(const hkReferencedObject* ptr)
{
	std::type_index info(typeid(*ptr));
	auto idx = rttiHelper.classMap.find(info);
	if(idx != rttiHelper.classMap.end()) return idx->second;
	else return 0;
}

void calcMassProperties(hkMassProperties& pi, const hkpShape* shape)
{
	float mass = pi.m_mass;
	if(mass <= 0) mass = 1;
	if(shape->getType() == hkcdShapeType::SPHERE)
		hkInertiaTensorComputer::computeSphereVolumeMassProperties(((hkpSphereShape*)shape)->getRadius(), mass, pi);
	else if(shape->getType() == hkcdShapeType::CYLINDER)
	{
		auto cylinder = (hkpCylinderShape*)shape;
		hkInertiaTensorComputer::computeCylinderVolumeMassProperties(cylinder->getVertex(0), cylinder->getVertex(1), cylinder->getCylinderRadius(), pi.m_mass, pi);
	}
	else if(shape->getType() == hkcdShapeType::TRIANGLE)
	{
		auto tri = (hkpTriangleShape*)shape;
		hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(tri->getVertex(0), tri->getVertex(1), tri->getVertex(2), pi.m_mass, tri->getRadius(), pi);
	}
	else if(shape->getType() == hkcdShapeType::BOX)
	{
		auto box = (hkpBoxShape*)shape;
		hkInertiaTensorComputer::computeBoxVolumeMassProperties(box->getHalfExtents(), pi.m_mass, pi);
	}
	else if(shape->getType() == hkcdShapeType::CAPSULE)
	{
		auto capsule = (hkpCapsuleShape*)shape;
		hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(capsule->getVertex(0), capsule->getVertex(1), capsule->getRadius(), pi.m_mass, pi);
	}
	else if(shape->getType() == hkcdShapeType::LIST)
	{
		auto list = (hkpListShape*)shape;
		hkArray<hkMassElement> arr;
		arr.setSize(list->getContainer()->getNumChildShapes());
		for(int i=0; i<arr.getSize(); ++i)
		{
			arr[i].m_properties.m_mass = pi.m_mass / arr.getSize();
			arr[i].m_transform.setIdentity();
		}
		hkpShapeBuffer buffer;
		hkpShapeKey key = list->getContainer()->getFirstKey();
		for(int i=0; i<arr.getSize(); ++i)
		{
			calcMassProperties(arr[i].m_properties, list->getContainer()->getChildShape(key, buffer));
			key = list->getContainer()->getNextKey(key);
		}
		hkInertiaTensorComputer::combineMassProperties(arr, pi);
	}
	else if(shape->getType() == hkcdShapeType::CONVEX_TRANSLATE)
	{
		auto t = (hkpConvexTranslateShape*)shape;
		calcMassProperties(pi, t->getChildShape());
		hkInertiaTensorComputer::shiftInertiaFromCom(t->getTranslation(), pi.m_mass, pi.m_inertiaTensor);
		pi.m_centerOfMass.add(t->getTranslation());
	}
	else if(shape->getType() == hkcdShapeType::CONVEX_TRANSFORM)
	{
		auto t = (hkpConvexTransformShape*)shape;
		hkArray<hkMassElement> arr;
		arr.setSize(1);
		arr[0].m_properties.m_mass = pi.m_mass;
		calcMassProperties(arr[0].m_properties, t->getChildShape());
		pi.m_inertiaTensor.setDiagonalMul(t->getQsTransform().m_scale, arr[0].m_properties.m_inertiaTensor);
		arr[0].m_properties.m_inertiaTensor.setDiagonalMul(t->getQsTransform().m_scale, pi.m_inertiaTensor);
		t->getTransform(&arr[0].m_transform);
		hkInertiaTensorComputer::combineMassProperties(arr, pi);
	}
	else
	{
		hkArray<hkSphere> spheres;
		hkArray<hkMassElement> pis;
		spheres.setSize(shape->getNumCollisionSpheres());
		pis.setSize(spheres.getSize());
		shape->getCollisionSpheres(&spheres[0]);
		for(int i=0; i<spheres.getSize(); ++i)
		{
			hkInertiaTensorComputer::computeSphereVolumeMassProperties(spheres[i].getRadius(), mass/spheres.getSize(), pis[i].m_properties);
			pis[i].m_transform.setIdentity();
			pis[i].m_transform.setTranslation(spheres[i].getPosition());
		}
		hkInertiaTensorComputer::combineMassProperties(pis, pi);
	}
}

void setEularZYX(hkQuaternion& q, float Z, float Y, float X)
{
	hkQuaternion qx, qy, qz;
	qx.setAxisAngle(hkVector4(1, 0, 0), X);
	qy.setAxisAngle(hkVector4(0, 1, 0), Y);
	qz.setAxisAngle(hkVector4(0, 0, 1), Z);
	q.setMul(qz, qy);
	q.mul(qx);
}


void getEularZYX(const hkQuaternion& q, float& Z, float& Y, float& X)
{
	float x = q.getComponent<0>();
	float y = q.getComponent<1>();
	float z = q.getComponent<2>();
	float w = q.getComponent<3>();
	
	float test = y*w-x*z;
	
	if(test > 0.49999f)
	{
		Z = -2 * atan2(x, w);
		Y = HK_REAL_PI/2;
		X = 0;
	}
	else if(test < -0.49999f)
	{
		Z = 2 * atan2(x, w);
		Y = -HK_REAL_PI/2;
		X = 0;
	}
	else
	{
		float sqx = x * x;
		float sqy = y * y;
		float sqz = z * z;
		Z = atan2(2*(z*w+y*x), 1-2*(sqz+sqy));
		Y = asin(2*test);
		X = atan2(2*(x*w+y*z), 1-2*(sqx+sqy));
	}
	
	if(Z < -HK_REAL_PI) Z+=HK_REAL_PI*2;
	if(Z > HK_REAL_PI) Z-= HK_REAL_PI*2;
	if(Y < -HK_REAL_PI) Y+=HK_REAL_PI*2;
	if(Y > HK_REAL_PI) Y-= HK_REAL_PI*2;
	if(X < -HK_REAL_PI) X+=HK_REAL_PI*2;
	if(X > HK_REAL_PI) X-= HK_REAL_PI*2;
}
