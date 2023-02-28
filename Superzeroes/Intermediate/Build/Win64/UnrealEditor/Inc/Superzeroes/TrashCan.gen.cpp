// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/TrashCan.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrashCan() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_ATrashCan_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ATrashCan();
	PAPER2D_API UClass* Z_Construct_UClass_APaperSpriteActor();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SUPERZEROES_API UClass* Z_Construct_UClass_ATrash_NoRegister();
// End Cross Module References
	void ATrashCan::StaticRegisterNativesATrashCan()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATrashCan);
	UClass* Z_Construct_UClass_ATrashCan_NoRegister()
	{
		return ATrashCan::StaticClass();
	}
	struct Z_Construct_UClass_ATrashCan_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sprite_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_sprite;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_capsule_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_capsule;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_idle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_idle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_timeBetweenShoots_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_timeBetweenShoots;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trash_BP_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Trash_BP;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrashCan_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperSpriteActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "TrashCan.h" },
		{ "ModuleRelativePath", "TrashCan.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::NewProp_sprite_MetaData[] = {
		{ "Category", "TrashCan" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TrashCan.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrashCan_Statics::NewProp_sprite = { "sprite", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrashCan, sprite), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::NewProp_sprite_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::NewProp_sprite_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::NewProp_capsule_MetaData[] = {
		{ "Category", "TrashCan" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TrashCan.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrashCan_Statics::NewProp_capsule = { "capsule", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrashCan, capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::NewProp_capsule_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::NewProp_capsule_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::NewProp_idle_MetaData[] = {
		{ "Category", "TrashCan" },
		{ "ModuleRelativePath", "TrashCan.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATrashCan_Statics::NewProp_idle = { "idle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrashCan, idle), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::NewProp_idle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::NewProp_idle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::NewProp_timeBetweenShoots_MetaData[] = {
		{ "Category", "TrashCan" },
		{ "Comment", "// time between shots fired by trash can\n" },
		{ "ModuleRelativePath", "TrashCan.h" },
		{ "ToolTip", "time between shots fired by trash can" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATrashCan_Statics::NewProp_timeBetweenShoots = { "timeBetweenShoots", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrashCan, timeBetweenShoots), METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::NewProp_timeBetweenShoots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::NewProp_timeBetweenShoots_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrashCan_Statics::NewProp_Trash_BP_MetaData[] = {
		{ "Category", "TrashCan" },
		{ "ModuleRelativePath", "TrashCan.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATrashCan_Statics::NewProp_Trash_BP = { "Trash_BP", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrashCan, Trash_BP), Z_Construct_UClass_ATrash_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::NewProp_Trash_BP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::NewProp_Trash_BP_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATrashCan_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrashCan_Statics::NewProp_sprite,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrashCan_Statics::NewProp_capsule,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrashCan_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrashCan_Statics::NewProp_timeBetweenShoots,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrashCan_Statics::NewProp_Trash_BP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrashCan_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrashCan>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATrashCan_Statics::ClassParams = {
		&ATrashCan::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATrashCan_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATrashCan_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATrashCan_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrashCan()
	{
		if (!Z_Registration_Info_UClass_ATrashCan.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATrashCan.OuterSingleton, Z_Construct_UClass_ATrashCan_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATrashCan.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<ATrashCan>()
	{
		return ATrashCan::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrashCan);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_TrashCan_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_TrashCan_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATrashCan, ATrashCan::StaticClass, TEXT("ATrashCan"), &Z_Registration_Info_UClass_ATrashCan, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATrashCan), 3530188647U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_TrashCan_h_957825492(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_TrashCan_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_TrashCan_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
