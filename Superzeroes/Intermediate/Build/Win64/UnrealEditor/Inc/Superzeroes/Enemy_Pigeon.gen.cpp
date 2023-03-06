// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/Enemy_Pigeon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_Pigeon() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy_Pigeon_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy_Pigeon();
	SUPERZEROES_API UClass* Z_Construct_UClass_AEnemy();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AEnemy_Pigeon::execEndAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndAttack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEnemy_Pigeon::execProcessBulletCollision)
	{
		P_GET_STRUCT(FVector,Z_Param_hitPos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ProcessBulletCollision(Z_Param_hitPos);
		P_NATIVE_END;
	}
	void AEnemy_Pigeon::StaticRegisterNativesAEnemy_Pigeon()
	{
		UClass* Class = AEnemy_Pigeon::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndAttack", &AEnemy_Pigeon::execEndAttack },
			{ "ProcessBulletCollision", &AEnemy_Pigeon::execProcessBulletCollision },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy_Pigeon, nullptr, "EndAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemy_Pigeon_EndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_Pigeon_EndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics
	{
		struct Enemy_Pigeon_eventProcessBulletCollision_Parms
		{
			FVector hitPos;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_hitPos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::NewProp_hitPos = { "hitPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemy_Pigeon_eventProcessBulletCollision_Parms, hitPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::NewProp_hitPos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy_Pigeon, nullptr, "ProcessBulletCollision", nullptr, nullptr, sizeof(Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::Enemy_Pigeon_eventProcessBulletCollision_Parms), Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemy_Pigeon);
	UClass* Z_Construct_UClass_AEnemy_Pigeon_NoRegister()
	{
		return AEnemy_Pigeon::StaticClass();
	}
	struct Z_Construct_UClass_AEnemy_Pigeon_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bulletProjectileBeamParticleSystem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_bulletProjectileBeamParticleSystem;
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bulletProjectileMeshParticleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_bulletProjectileMeshParticleComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bulletBeamParticleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_bulletBeamParticleComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_muzzleFlashLeftParticleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_muzzleFlashLeftParticleComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_muzzleFlashRightParticleComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_muzzleFlashRightParticleComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemy_Pigeon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemy_Pigeon_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemy_Pigeon_EndAttack, "EndAttack" }, // 185523451
		{ &Z_Construct_UFunction_AEnemy_Pigeon_ProcessBulletCollision, "ProcessBulletCollision" }, // 2040038235
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemy_Pigeon.h" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	void Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat_SetBit(void* Obj)
	{
		((AEnemy_Pigeon*)Obj)->inCombat = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat = { "inCombat", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AEnemy_Pigeon), &Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat_SetBit, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_idle_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "Comment", "// Animations\n" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
		{ "ToolTip", "Animations" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_idle = { "idle", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, idle), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_idle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_idle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_walk_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_walk = { "walk", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, walk), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_walk_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_walk_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_attack_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_attack = { "attack", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, attack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_attack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_attack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_jumpAnim_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_jumpAnim = { "jumpAnim", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, jumpAnim), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_jumpAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_jumpAnim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileBeamParticleSystem_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "Comment", "// Particles\n" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
		{ "ToolTip", "Particles" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileBeamParticleSystem = { "bulletProjectileBeamParticleSystem", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, bulletProjectileBeamParticleSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileBeamParticleSystem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileBeamParticleSystem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_boomBoom_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_boomBoom = { "boomBoom", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, boomBoom), Z_Construct_UClass_ABoomBoom_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_boomBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_boomBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_zipZap_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_zipZap = { "zipZap", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, zipZap), Z_Construct_UClass_AZipZap_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_zipZap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_zipZap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_playerToAttack_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_playerToAttack = { "playerToAttack", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, playerToAttack), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_playerToAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_playerToAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileMeshParticleComponent_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileMeshParticleComponent = { "bulletProjectileMeshParticleComponent", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, bulletProjectileMeshParticleComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileMeshParticleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileMeshParticleComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletBeamParticleComponent_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletBeamParticleComponent = { "bulletBeamParticleComponent", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, bulletBeamParticleComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletBeamParticleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletBeamParticleComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashLeftParticleComponent_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashLeftParticleComponent = { "muzzleFlashLeftParticleComponent", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, muzzleFlashLeftParticleComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashLeftParticleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashLeftParticleComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashRightParticleComponent_MetaData[] = {
		{ "Category", "Enemy_Pigeon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemy_Pigeon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashRightParticleComponent = { "muzzleFlashRightParticleComponent", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemy_Pigeon, muzzleFlashRightParticleComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashRightParticleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashRightParticleComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Pigeon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_inCombat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_walk,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_attack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_jumpAnim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileBeamParticleSystem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_boomBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_zipZap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_playerToAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletProjectileMeshParticleComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_bulletBeamParticleComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashLeftParticleComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Pigeon_Statics::NewProp_muzzleFlashRightParticleComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemy_Pigeon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_Pigeon>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Pigeon_Statics::ClassParams = {
		&AEnemy_Pigeon::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemy_Pigeon_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemy_Pigeon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Pigeon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemy_Pigeon()
	{
		if (!Z_Registration_Info_UClass_AEnemy_Pigeon.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemy_Pigeon.OuterSingleton, Z_Construct_UClass_AEnemy_Pigeon_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemy_Pigeon.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AEnemy_Pigeon>()
	{
		return AEnemy_Pigeon::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_Pigeon);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemy_Pigeon, AEnemy_Pigeon::StaticClass, TEXT("AEnemy_Pigeon"), &Z_Registration_Info_UClass_AEnemy_Pigeon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemy_Pigeon), 3781152270U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_4217308742(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
