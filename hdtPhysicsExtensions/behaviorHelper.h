#pragma once

#include "havok_helper.h"

class hkbVariableBindingSetBinding
{
public:

	enum BindingType
	{
		BINDING_TYPE_VARIABLE,
		BINDING_TYPE_CHARACTER_PROPERTY
	};

	enum InternalBindingFlags
	{
		FLAG_NONE,
		FLAG_OUTPUT
	};

	hkStringPtr memberPath;
	void* memberClass;
	hkInt32 offsetInObjectPlusOne;
	hkInt32 offsetInArrayPlusOne;
	hkInt32 rootVariableIndex;
	hkInt32 variableIndex;
	hkInt8 bitIndex;
	hkEnum<BindingType, hkInt8> bindingType;
	hkEnum<InternalBindingFlags, hkUint8> memberType;
	hkInt8 variableType;
	hkFlags<hkInt32, hkInt8> flags;
};

class hkbVariableBindingSet : public hkReferencedObject
{
public:

	hkArray<hkbVariableBindingSetBinding> bindings;
	hkInt32 indexingOfBindingToEnable;
	hkBool hasOutputBinding;
};

class hkbBindable : public hkReferencedObject
{
public:

	hkRefPtr<hkbVariableBindingSet> variableBindingSet;
	hkArray<hkbBindable*> cachedBindables;
	hkBool areBindablesCached;
};

class hkbNode : public hkbBindable
{
public:

	enum GetChildrenFlagBits
	{
		FLAG_ACTIVE_ONLY = 1,
		FLAG_GENERATORS_ONLY = 2,
		FLAG_IGNORE_REFERENCED_BEHAVIORS = 4,
	};

	enum CloneState
	{
		CLONE_STATE_DEFAULT,
		CLONE_STATE_TEMPLATE,
		CLONE_STATE_CLONE,
		CLONE_STATE_SHARABLE
	};

	hkUlong userData;
	hkStringPtr name;
	hkInt16 id;
	hkEnum<CloneState, hkInt8> cloneState;

	hkInt8 padNode;
};

class hkbGenerator : public hkbBindable
{
};

class hkbStateMachine;

class hkbBehaviorGraph : public hkbGenerator
{
	enum VariableMode
	{
		VARIABLE_MODE_DISCARD_WHEN_INACTIVE,
		VARIABLE_MODE_MAINTAIN_VALUES_WHEN_INACTIVE
	};

	hkEnum<hkInt8, VariableMode> variableMode;
	hkArray<hkInt32> uniqueIdPool;
	hkReferencedObject* idToStateMachineTemplateMap;
	hkArray<hkInt32> mirroredExtenalIdMap;
	void* pseudoRandomGenerator;
	hkbStateMachine* rootGenerator;
	void* data;
	hkbStateMachine* rootGeneratorClone;
	void* activeNodes;
	void* activeNodeTemplateToIndexMap;
	void* activeNodesChildrenIndices;
	void* globalTransitionData;
	void* eventIdMap;
	void* attributeIdMap;
	void* variableIdMap;
	void* characterPropertyIdMap;
	void* variableValueSet;
	void* nodeTemplateToCloneMap;
	void* nodeCloneToTemplateMap;
	void* stateListenerTemplateToCloneMap;
	void* nodePartitionInfo;
	hkInt32 numIntermediateOutputs;
	hkArray<void*> jobs;
	hkArray<void*> allPartitionMemory;
	hkInt16 numStaticNodes;
	hkInt16 nextUniqueId;
	hkBool isActive;
	hkBool isLinked;
	hkBool updateActiveNodes;
	hkBool stateOrTransitionChanged;
};

