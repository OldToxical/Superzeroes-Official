// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/MainCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainCamera() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_AMainCamera_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AMainCamera();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
// End Cross Module References
	void AMainCamera::StaticRegisterNativesAMainCamera()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainCamera);
	UClass* Z_Construct_UClass_AMainCamera_NoRegister()
	{
		return AMainCamera::StaticClass();
	}
	struct Z_Construct_UClass_AMainCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMainCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainCamera_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MainCamera.h" },
		{ "ModuleRelativePath", "MainCamera.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMainCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainCamera>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainCamera_Statics::ClassParams = {
		&AMainCamera::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_AMainCamera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMainCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMainCamera()
	{
		if (!Z_Registration_Info_UClass_AMainCamera.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainCamera.OuterSingleton, Z_Construct_UClass_AMainCamera_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMainCamera.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AMainCamera>()
	{
		return AMainCamera::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainCamera);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_MainCamera_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_MainCamera_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMainCamera, AMainCamera::StaticClass, TEXT("AMainCamera"), &Z_Registration_Info_UClass_AMainCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainCamera), 1562175437U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_MainCamera_h_298445041(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_MainCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_MainCamera_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
