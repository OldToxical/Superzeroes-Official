// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/BoxTrigger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoxTrigger() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoxTrigger_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoxTrigger();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABoxTrigger::execOverlapEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OverlapEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoxTrigger::execOverlapBegin)
	{
		P_GET_OBJECT(AActor,Z_Param_otherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OverlapBegin(Z_Param_otherActor);
		P_NATIVE_END;
	}
	void ABoxTrigger::StaticRegisterNativesABoxTrigger()
	{
		UClass* Class = ABoxTrigger::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OverlapBegin", &ABoxTrigger::execOverlapBegin },
			{ "OverlapEnd", &ABoxTrigger::execOverlapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics
	{
		struct BoxTrigger_eventOverlapBegin_Parms
		{
			AActor* otherActor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::NewProp_otherActor = { "otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoxTrigger_eventOverlapBegin_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::NewProp_otherActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoxTrigger.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoxTrigger, nullptr, "OverlapBegin", nullptr, nullptr, sizeof(Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::BoxTrigger_eventOverlapBegin_Parms), Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoxTrigger_OverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoxTrigger_OverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoxTrigger.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoxTrigger, nullptr, "OverlapEnd", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoxTrigger_OverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoxTrigger_OverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoxTrigger);
	UClass* Z_Construct_UClass_ABoxTrigger_NoRegister()
	{
		return ABoxTrigger::StaticClass();
	}
	struct Z_Construct_UClass_ABoxTrigger_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_colliderPlaneActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_colliderPlaneActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoxTrigger_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATriggerBox,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoxTrigger_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoxTrigger_OverlapBegin, "OverlapBegin" }, // 3403774831
		{ &Z_Construct_UFunction_ABoxTrigger_OverlapEnd, "OverlapEnd" }, // 1917418720
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoxTrigger_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BoxTrigger.h" },
		{ "ModuleRelativePath", "BoxTrigger.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoxTrigger_Statics::NewProp_colliderPlaneActor_MetaData[] = {
		{ "Category", "BoxTrigger" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BoxTrigger.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoxTrigger_Statics::NewProp_colliderPlaneActor = { "colliderPlaneActor", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoxTrigger, colliderPlaneActor), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoxTrigger_Statics::NewProp_colliderPlaneActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoxTrigger_Statics::NewProp_colliderPlaneActor_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoxTrigger_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoxTrigger_Statics::NewProp_colliderPlaneActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoxTrigger_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoxTrigger>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoxTrigger_Statics::ClassParams = {
		&ABoxTrigger::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoxTrigger_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoxTrigger_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoxTrigger_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoxTrigger_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoxTrigger()
	{
		if (!Z_Registration_Info_UClass_ABoxTrigger.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoxTrigger.OuterSingleton, Z_Construct_UClass_ABoxTrigger_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoxTrigger.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<ABoxTrigger>()
	{
		return ABoxTrigger::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoxTrigger);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoxTrigger_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoxTrigger_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoxTrigger, ABoxTrigger::StaticClass, TEXT("ABoxTrigger"), &Z_Registration_Info_UClass_ABoxTrigger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoxTrigger), 3902193076U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoxTrigger_h_2863971265(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoxTrigger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoxTrigger_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
