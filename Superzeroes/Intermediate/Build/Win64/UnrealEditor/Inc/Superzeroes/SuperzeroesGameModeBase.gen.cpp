// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/SuperzeroesGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperzeroesGameModeBase() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_ASuperzeroesGameModeBase_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ASuperzeroesGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
// End Cross Module References
	void ASuperzeroesGameModeBase::StaticRegisterNativesASuperzeroesGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperzeroesGameModeBase);
	UClass* Z_Construct_UClass_ASuperzeroesGameModeBase_NoRegister()
	{
		return ASuperzeroesGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASuperzeroesGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SuperzeroesGameModeBase.h" },
		{ "ModuleRelativePath", "SuperzeroesGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperzeroesGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::ClassParams = {
		&ASuperzeroesGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperzeroesGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ASuperzeroesGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperzeroesGameModeBase.OuterSingleton, Z_Construct_UClass_ASuperzeroesGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperzeroesGameModeBase.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<ASuperzeroesGameModeBase>()
	{
		return ASuperzeroesGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperzeroesGameModeBase);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_SuperzeroesGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_SuperzeroesGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperzeroesGameModeBase, ASuperzeroesGameModeBase::StaticClass, TEXT("ASuperzeroesGameModeBase"), &Z_Registration_Info_UClass_ASuperzeroesGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperzeroesGameModeBase), 1630900862U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_SuperzeroesGameModeBase_h_3146534386(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_SuperzeroesGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_SuperzeroesGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
