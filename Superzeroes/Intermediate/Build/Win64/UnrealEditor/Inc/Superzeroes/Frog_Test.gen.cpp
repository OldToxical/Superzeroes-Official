// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/Frog_Test.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFrog_Test() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_AFrog_Test_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AFrog_Test();
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
// End Cross Module References
	void AFrog_Test::StaticRegisterNativesAFrog_Test()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFrog_Test);
	UClass* Z_Construct_UClass_AFrog_Test_NoRegister()
	{
		return AFrog_Test::StaticClass();
	}
	struct Z_Construct_UClass_AFrog_Test_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFrog_Test_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFrog_Test_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Frog_Test.h" },
		{ "ModuleRelativePath", "Frog_Test.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFrog_Test_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFrog_Test>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFrog_Test_Statics::ClassParams = {
		&AFrog_Test::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFrog_Test_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFrog_Test_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFrog_Test()
	{
		if (!Z_Registration_Info_UClass_AFrog_Test.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFrog_Test.OuterSingleton, Z_Construct_UClass_AFrog_Test_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFrog_Test.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AFrog_Test>()
	{
		return AFrog_Test::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFrog_Test);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Frog_Test_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Frog_Test_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFrog_Test, AFrog_Test::StaticClass, TEXT("AFrog_Test"), &Z_Registration_Info_UClass_AFrog_Test, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFrog_Test), 636977326U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Frog_Test_h_3500828335(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Frog_Test_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Frog_Test_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
