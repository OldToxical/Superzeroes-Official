// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/Enemy_Mouse.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_Mouse() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy_Mouse_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy_Mouse();
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AEnemy_Mouse::execEndAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndAttack();
		P_NATIVE_END;
	}
	void AEnemy_Mouse::StaticRegisterNativesAEnemy_Mouse()
	{
		UClass* Class = AEnemy_Mouse::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndAttack", &AEnemy_Mouse::execEndAttack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy_Mouse, nullptr, "EndAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemy_Mouse_EndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_Mouse_EndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemy_Mouse);
	UClass* Z_Construct_UClass_AEnemy_Mouse_NoRegister()
	{
		return AEnemy_Mouse::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Mouse_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inCombat_MetaData[];
#endif
		static void NewProp_inCombat_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_inCombat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_idle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_idle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_walk_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_walk;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_attack_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_attack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jumpAnim_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_jumpAnim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_boomBoomImpact_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_boomBoomImpact;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_boomBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_boomBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_zipZap_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_zipZap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_playerToAttack_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playerToAttack;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Mouse_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemy_Mouse_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemy_Mouse_EndAttack, "EndAttack" }, // 780512535
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemy_Mouse.h" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	void Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat_SetBit(void* Obj)
	{
		((AEnemy_Mouse*)Obj)->inCombat = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat = { "inCombat", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AEnemy_Mouse), &Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat_SetBit, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_idle_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "Comment", "// Animations\n" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
		{ "ToolTip", "Animations" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_idle = { "idle", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, idle), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_idle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_idle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_walk_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_walk = { "walk", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, walk), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_walk_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_walk_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_attack_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_attack = { "attack", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, attack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_attack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_attack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_jumpAnim_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_jumpAnim = { "jumpAnim", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, jumpAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_jumpAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_jumpAnim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoomImpact_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "Comment", "// Particles\n" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
		{ "ToolTip", "Particles" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoomImpact = { "boomBoomImpact", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, boomBoomImpact), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoomImpact_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoomImpact_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoom_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoom = { "boomBoom", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, boomBoom), Z_Construct_UClass_ABoomBoom_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_zipZap_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_zipZap = { "zipZap", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, zipZap), Z_Construct_UClass_AZipZap_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_zipZap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_zipZap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_playerToAttack_MetaData[] = {
		{ "Category", "Enemy_Mouse" },
		{ "ModuleRelativePath", "Enemy_Mouse.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_playerToAttack = { "playerToAttack", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Mouse, playerToAttack), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_playerToAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_playerToAttack_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Mouse_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_inCombat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_walk,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_attack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_jumpAnim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoomImpact,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_boomBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_zipZap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Mouse_Statics::NewProp_playerToAttack,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Mouse_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_Mouse>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Mouse_Statics::ClassParams = {
		&AEnemy_Mouse::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemy_Mouse_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_Mouse_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Mouse_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy_Mouse()
	{
		if (!Z_Registration_Info_UClass_AEnemy_Mouse.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemy_Mouse.OuterSingleton, Z_Construct_UClass_AEnemy_Mouse_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemy_Mouse.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AEnemy_Mouse>()
	{
		return AEnemy_Mouse::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_Mouse);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Mouse_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Mouse_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemy_Mouse, AEnemy_Mouse::StaticClass, TEXT("AEnemy_Mouse"), &Z_Registration_Info_UClass_AEnemy_Mouse, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemy_Mouse), 1056619514U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Mouse_h_2303297073(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Mouse_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Mouse_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
