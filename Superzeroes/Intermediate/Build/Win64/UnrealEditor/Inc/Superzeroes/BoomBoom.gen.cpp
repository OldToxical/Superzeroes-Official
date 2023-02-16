// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/BoomBoom.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoomBoom() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
// End Cross Module References
	void ABoomBoom::StaticRegisterNativesABoomBoom()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoomBoom);
	UClass* Z_Construct_UClass_ABoomBoom_NoRegister()
	{
		return ABoomBoom::StaticClass();
	}
	struct Z_Construct_UClass_ABoomBoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoomBoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BoomBoom.h" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoomBoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoomBoom>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoomBoom_Statics::ClassParams = {
		&ABoomBoom::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoomBoom()
	{
		if (!Z_Registration_Info_UClass_ABoomBoom.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoomBoom.OuterSingleton, Z_Construct_UClass_ABoomBoom_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoomBoom.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<ABoomBoom>()
	{
		return ABoomBoom::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoomBoom);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoomBoom, ABoomBoom::StaticClass, TEXT("ABoomBoom"), &Z_Registration_Info_UClass_ABoomBoom, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoomBoom), 2551196246U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_3570058516(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
