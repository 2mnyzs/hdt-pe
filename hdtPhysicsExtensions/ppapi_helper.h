#pragma once

#include "skse/PapyrusArgs.h"
#include "skse/PapyrusActiveMagicEffect.h"
#include "skse/PapyrusActor.h"
#include "skse/PapyrusActorBase.h"
#include "skse/PapyrusAlias.h"
#include "skse/PapyrusArgs.h"
#include "skse/PapyrusArmor.h"
#include "skse/PapyrusArmorAddon.h"
#include "skse/PapyrusBook.h"
#include "skse/PapyrusCell.h"
#include "skse/PapyrusColorForm.h"
#include "skse/PapyrusCombatStyle.h"
#include "skse/PapyrusConstructibleObject.h"
#include "skse/PapyrusEnchantment.h"
#include "skse/PapyrusEvents.h"
#include "skse/PapyrusForm.h"
#include "skse/PapyrusGame.h"
#include "skse/PapyrusHeadPart.h"
#include "skse/PapyrusIngredient.h"
#include "skse/PapyrusInput.h"
#include "skse/PapyrusKeyword.h"
#include "skse/PapyrusMath.h"
#include "skse/PapyrusNetImmerse.h"
#include "skse/PapyrusObjectReference.h"
#include "skse/PapyrusPotion.h"
#include "skse/PapyrusQuest.h"
#include "skse/PapyrusRace.h"
#include "skse/PapyrusScroll.h"
#include "skse/PapyrusShout.h"
#include "skse/PapyrusSKSE.h"
#include "skse/PapyrusSound.h"
#include "skse/PapyrusSoundDescriptor.h"
#include "skse/PapyrusSpell.h"
#include "skse/PapyrusStringUtil.h"
#include "skse/PapyrusTextureSet.h"
#include "skse/PapyrusUI.h"
#include "skse/PapyrusUtility.h"
#include "skse/PapyrusVM.h"
#include "skse/PapyrusWeapon.h"
#include "skse/PapyrusWeather.h"
#include "skse/PapyrusNativeFunctions.h"

#include "skse/GameData.h"
#include "skse/GameTypes.h"
#include "skse/GameRTTI.h"
#include "skse/GameForms.h"
#include "skse/GameReferences.h"
#include "skse/NiGeometry.h"
#include "skse/GameStreams.h"
#include "skse/GameThreads.h"
#include "skse/Hooks_Threads.h"

template <class TBase, class TRet>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*),
	VMClassRegistry * registry
){
	return new NativeFunction0<TBase, TRet>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1),
	VMClassRegistry * registry
){
	return new NativeFunction1<TBase, TRet, TArg1>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2),
	VMClassRegistry * registry
){
	return new NativeFunction2<TBase, TRet, TArg1, TArg2>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3),
	VMClassRegistry * registry
){
	return new NativeFunction3<TBase, TRet, TArg1, TArg2, TArg3>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4),
	VMClassRegistry * registry
){
	return new NativeFunction4<TBase, TRet, TArg1, TArg2, TArg3, TArg4>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5),
	VMClassRegistry * registry
){
	return new NativeFunction5<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5, class TArg6>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6),
	VMClassRegistry * registry
){
	return new NativeFunction6<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5, class TArg6, class TArg7>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7),
	VMClassRegistry * registry
){
	return new NativeFunction7<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5, class TArg6, class TArg7, class TArg8>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8),
	VMClassRegistry * registry
){
	return new NativeFunction8<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5, class TArg6, class TArg7, class TArg8, class TArg9>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9),
	VMClassRegistry * registry
){
	return new NativeFunction9<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9>(Name, Package, callback, registry);
}

template <class TBase, class TRet, class TArg1, class TArg2, class TArg3, class TArg4, class TArg5, class TArg6, class TArg7, class TArg8, class TArg9, class TArg10>
NativeFunction* CreateNativeFunction(
	const char* Name,
	const char* Package,
	TRet (*callback)(TBase*, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9, TArg10),
	VMClassRegistry * registry
){
	return new NativeFunction10<TBase, TRet, TArg1, TArg2, TArg3, TArg4, TArg5, TArg6, TArg7, TArg8, TArg9, TArg10>(Name, Package, callback, registry);
}

#define AutoRegisterFunction( func, package, registry )	registry->RegisterFunction(CreateNativeFunction(#func, package, func, registry));
#define AutoRegisterFunction_NoWait( func, package, registry )\
	AutoRegisterFunction( func, package, registry )\
	registry->SetFunctionFlags(PackageName, #func, VMClassRegistry::kFunctionFlag_NoWait);

#define DynamicCast(obj, to) (to *) Runtime_DynamicCast((void*)(obj), 0, &typeid(obj), RTTI_ ## to, 0)