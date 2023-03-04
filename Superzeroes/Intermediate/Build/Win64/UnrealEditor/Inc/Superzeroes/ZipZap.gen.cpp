// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/ZipZap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZipZap() {}
// Cross Module References
	SUPERZEROES_API UEnum* Z_Construct_UEnum_Superzeroes_State2();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UInputComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_State2;
	static UEnum* State2_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_State2.OuterSingleton)
		{
			Z_Registration_Info_UEnum_State2.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Superzeroes_State2, Z_Construct_UPackage__Script_Superzeroes(), TEXT("State2"));
		}
		return Z_Registration_Info_UEnum_State2.OuterSingleton;
	}
	template<> SUPERZEROES_API UEnum* StaticEnum<State2>()
	{
		return State2_StaticEnum();
	}
	struct Z_Construct_UEnum_Superzeroes_State2_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Superzeroes_State2_Statics::Enumerators[] = {
		{ "State2::Idle", (int64)State2::Idle },
		{ "State2::Running", (int64)State2::Running },
		{ "State2::Jumping", (int64)State2::Jumping },
		{ "State2::Attacking", (int64)State2::Attacking },
		{ "State2::Combo_Projectile", (int64)State2::Combo_Projectile },
		{ "State2::Hurt", (int64)State2::Hurt },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Superzeroes_State2_Statics::Enum_MetaDataParams[] = {
		{ "Attacking.Comment", "/**\n *\n */" },
		{ "Attacking.Name", "State2::Attacking" },
		{ "BlueprintType", "true" },
		{ "Combo_Projectile.Comment", "/**\n *\n */" },
		{ "Combo_Projectile.Name", "State2::Combo_Projectile" },
		{ "Comment", "/**\n *\n */" },
		{ "Hurt.Comment", "/**\n *\n */" },
		{ "Hurt.Name", "State2::Hurt" },
		{ "Idle.Comment", "/**\n *\n */" },
		{ "Idle.Name", "State2::Idle" },
		{ "Jumping.Comment", "/**\n *\n */" },
		{ "Jumping.Name", "State2::Jumping" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "Running.Comment", "/**\n *\n */" },
		{ "Running.Name", "State2::Running" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Superzeroes_State2_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Superzeroes,
		nullptr,
		"State2",
		"State2",
		Z_Construct_UEnum_Superzeroes_State2_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Superzeroes_State2_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_Superzeroes_State2_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Superzeroes_State2_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Superzeroes_State2()
	{
		if (!Z_Registration_Info_UEnum_State2.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_State2.InnerSingleton, Z_Construct_UEnum_Superzeroes_State2_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_State2.InnerSingleton;
	}
	DEFINE_FUNCTION(AZipZap::execsetHealth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_newHealth);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->setHealth(Z_Param_newHealth);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execgetHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->getHealth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execoverlapEnd)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_overlappedComp);
		P_GET_OBJECT(AActor,Z_Param_otherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_otherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_otherBodyIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->overlapEnd(Z_Param_overlappedComp,Z_Param_otherActor,Z_Param_otherComp,Z_Param_otherBodyIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execoverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_overlappedComp);
		P_GET_OBJECT(AActor,Z_Param_otherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_otherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_otherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_result);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->overlapBegin(Z_Param_overlappedComp,Z_Param_otherActor,Z_Param_otherComp,Z_Param_otherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_result);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execProcessHit)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_damage_);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ProcessHit(Z_Param_damage_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execSetupPlayerInput)
	{
		P_GET_OBJECT(UInputComponent,Z_Param_input_);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupPlayerInput(Z_Param_input_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execSetBoomBoomReference)
	{
		P_GET_OBJECT(ABoomBoom,Z_Param_boomBoom_);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetBoomBoomReference(Z_Param_boomBoom_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execIsFacingBoomBoom)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsFacingBoomBoom();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execStopProjectileAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopProjectileAttack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execElectrify)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Electrify();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execUpdateComboAttack_Projectile)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateComboAttack_Projectile();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execInitiateComboAttack_Projectile)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_directionRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitiateComboAttack_Projectile(Z_Param_directionRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execInitiateComboAttack_Savage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitiateComboAttack_Savage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execEndAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndAttack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execExecuteJump)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ExecuteJump();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execmove)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_scaleVal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->move(Z_Param_scaleVal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execUpdateState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execUpdateAnimation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAnimation();
		P_NATIVE_END;
	}
	void AZipZap::StaticRegisterNativesAZipZap()
	{
		UClass* Class = AZipZap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Attack", &AZipZap::execAttack },
			{ "Electrify", &AZipZap::execElectrify },
			{ "EndAttack", &AZipZap::execEndAttack },
			{ "ExecuteJump", &AZipZap::execExecuteJump },
			{ "getHealth", &AZipZap::execgetHealth },
			{ "InitiateComboAttack_Projectile", &AZipZap::execInitiateComboAttack_Projectile },
			{ "InitiateComboAttack_Savage", &AZipZap::execInitiateComboAttack_Savage },
			{ "IsFacingBoomBoom", &AZipZap::execIsFacingBoomBoom },
			{ "move", &AZipZap::execmove },
			{ "overlapBegin", &AZipZap::execoverlapBegin },
			{ "overlapEnd", &AZipZap::execoverlapEnd },
			{ "ProcessHit", &AZipZap::execProcessHit },
			{ "SetBoomBoomReference", &AZipZap::execSetBoomBoomReference },
			{ "setHealth", &AZipZap::execsetHealth },
			{ "SetupPlayerInput", &AZipZap::execSetupPlayerInput },
			{ "StopProjectileAttack", &AZipZap::execStopProjectileAttack },
			{ "UpdateAnimation", &AZipZap::execUpdateAnimation },
			{ "UpdateComboAttack_Projectile", &AZipZap::execUpdateComboAttack_Projectile },
			{ "UpdateState", &AZipZap::execUpdateState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZipZap_Attack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "Attack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_Attack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_Electrify_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_Electrify_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_Electrify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "Electrify", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_Electrify_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_Electrify_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_Electrify()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_Electrify_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_EndAttack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_EndAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_EndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "EndAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_EndAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_EndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_EndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_EndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_ExecuteJump_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_ExecuteJump_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_ExecuteJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "ExecuteJump", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_ExecuteJump_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_ExecuteJump_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_ExecuteJump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_ExecuteJump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_getHealth_Statics
	{
		struct ZipZap_eventgetHealth_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_getHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventgetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_getHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_getHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_getHealth_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_getHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "getHealth", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_getHealth_Statics::ZipZap_eventgetHealth_Parms), Z_Construct_UFunction_AZipZap_getHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_getHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_getHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_getHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_getHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_getHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics
	{
		struct ZipZap_eventInitiateComboAttack_Projectile_Parms
		{
			float directionRotation;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_directionRotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::NewProp_directionRotation = { "directionRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventInitiateComboAttack_Projectile_Parms, directionRotation), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::NewProp_directionRotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "InitiateComboAttack_Projectile", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::ZipZap_eventInitiateComboAttack_Projectile_Parms), Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "InitiateComboAttack_Savage", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics
	{
		struct ZipZap_eventIsFacingBoomBoom_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZipZap_eventIsFacingBoomBoom_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZipZap_eventIsFacingBoomBoom_Parms), &Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "IsFacingBoomBoom", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::ZipZap_eventIsFacingBoomBoom_Parms), Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_IsFacingBoomBoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_IsFacingBoomBoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_move_Statics
	{
		struct ZipZap_eventmove_Parms
		{
			float scaleVal;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_scaleVal;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_move_Statics::NewProp_scaleVal = { "scaleVal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventmove_Parms, scaleVal), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_move_Statics::NewProp_scaleVal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "move", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_move_Statics::ZipZap_eventmove_Parms), Z_Construct_UFunction_AZipZap_move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_move_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_move_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_move_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_overlapBegin_Statics
	{
		struct ZipZap_eventoverlapBegin_Parms
		{
			UPrimitiveComponent* overlappedComp;
			AActor* otherActor;
			UPrimitiveComponent* otherComp;
			int32 otherBodyIndex;
			bool bFromSweep;
			FHitResult result;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_overlappedComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_overlappedComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_otherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_otherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_overlappedComp = { "overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapBegin_Parms, overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_overlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_overlappedComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherActor = { "otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapBegin_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherComp = { "otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapBegin_Parms, otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherComp_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherBodyIndex = { "otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapBegin_Parms, otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((ZipZap_eventoverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZipZap_eventoverlapBegin_Parms), &Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapBegin_Parms, result), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_result_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_result_MetaData)) }; // 1416937132
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_overlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_overlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_otherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapBegin_Statics::NewProp_result,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_overlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "overlapBegin", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::ZipZap_eventoverlapBegin_Parms), Z_Construct_UFunction_AZipZap_overlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_overlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_overlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_overlapEnd_Statics
	{
		struct ZipZap_eventoverlapEnd_Parms
		{
			UPrimitiveComponent* overlappedComp;
			AActor* otherActor;
			UPrimitiveComponent* otherComp;
			int32 otherBodyIndex;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_overlappedComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_overlappedComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_otherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_otherBodyIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_overlappedComp = { "overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapEnd_Parms, overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_overlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_overlappedComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherActor = { "otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapEnd_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherComp = { "otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapEnd_Parms, otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherComp_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherBodyIndex = { "otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventoverlapEnd_Parms, otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_overlapEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_overlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_overlapEnd_Statics::NewProp_otherBodyIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_overlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_overlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "overlapEnd", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::ZipZap_eventoverlapEnd_Parms), Z_Construct_UFunction_AZipZap_overlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_overlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_overlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_overlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_ProcessHit_Statics
	{
		struct ZipZap_eventProcessHit_Parms
		{
			float damage_;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_damage_;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_ProcessHit_Statics::NewProp_damage_ = { "damage_", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventProcessHit_Parms, damage_), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_ProcessHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_ProcessHit_Statics::NewProp_damage_,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_ProcessHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_ProcessHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "ProcessHit", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_ProcessHit_Statics::ZipZap_eventProcessHit_Parms), Z_Construct_UFunction_AZipZap_ProcessHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_ProcessHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_ProcessHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_ProcessHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_ProcessHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_ProcessHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics
	{
		struct ZipZap_eventSetBoomBoomReference_Parms
		{
			ABoomBoom* boomBoom_;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_boomBoom_;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::NewProp_boomBoom_ = { "boomBoom_", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventSetBoomBoomReference_Parms, boomBoom_), Z_Construct_UClass_ABoomBoom_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::NewProp_boomBoom_,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "SetBoomBoomReference", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::ZipZap_eventSetBoomBoomReference_Parms), Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_SetBoomBoomReference()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_SetBoomBoomReference_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_setHealth_Statics
	{
		struct ZipZap_eventsetHealth_Parms
		{
			float newHealth;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_newHealth;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_setHealth_Statics::NewProp_newHealth = { "newHealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventsetHealth_Parms, newHealth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_setHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_setHealth_Statics::NewProp_newHealth,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_setHealth_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_setHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "setHealth", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_setHealth_Statics::ZipZap_eventsetHealth_Parms), Z_Construct_UFunction_AZipZap_setHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_setHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_setHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_setHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_setHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_setHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics
	{
		struct ZipZap_eventSetupPlayerInput_Parms
		{
			UInputComponent* input_;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_input__MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_input_;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::NewProp_input__MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::NewProp_input_ = { "input_", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventSetupPlayerInput_Parms, input_), Z_Construct_UClass_UInputComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::NewProp_input__MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::NewProp_input__MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::NewProp_input_,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "SetupPlayerInput", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::ZipZap_eventSetupPlayerInput_Parms), Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_SetupPlayerInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_SetupPlayerInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//UFUNCTION(BlueprintCallable)\n//void HitCheck();\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "UFUNCTION(BlueprintCallable)\nvoid HitCheck();" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "StopProjectileAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_StopProjectileAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_StopProjectileAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "UpdateAnimation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_UpdateAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_UpdateAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "UpdateComboAttack_Projectile", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZipZap_UpdateState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_UpdateState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_UpdateState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "UpdateState", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_UpdateState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_UpdateState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_UpdateState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_UpdateState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZipZap);
	UClass* Z_Construct_UClass_AZipZap_NoRegister()
	{
		return AZipZap::StaticClass();
	}
	struct Z_Construct_UClass_AZipZap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_charMove_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_charMove;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_flipbook_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_flipbook;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_idle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_idle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_run_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_run;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jumping_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_jumping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_simpleAttack_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_simpleAttack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_initiateBoomBoomSavageComboAttack_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_initiateBoomBoomSavageComboAttack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_projectileFly_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_projectileFly;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hurt_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_hurt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_boomBoom_Hurt_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_boomBoom_Hurt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
		static const UECodeGen_Private::FBytePropertyParams NewProp_characterState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_characterState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_characterState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_boomBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_boomBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Input_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Input;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_characterSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_characterSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jumpPreludeTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_jumpPreludeTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_projectileAttackResetStateTimeoutTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_projectileAttackResetStateTimeoutTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isElectrified_MetaData[];
#endif
		static void NewProp_isElectrified_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isElectrified;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_health_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_health;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitbox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_hitbox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_collision_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_collision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_toxicDamage_MetaData[];
#endif
		static void NewProp_toxicDamage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_toxicDamage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZipZap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZipZap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZipZap_Attack, "Attack" }, // 494988708
		{ &Z_Construct_UFunction_AZipZap_Electrify, "Electrify" }, // 4172678014
		{ &Z_Construct_UFunction_AZipZap_EndAttack, "EndAttack" }, // 2437475914
		{ &Z_Construct_UFunction_AZipZap_ExecuteJump, "ExecuteJump" }, // 3039473597
		{ &Z_Construct_UFunction_AZipZap_getHealth, "getHealth" }, // 594873499
		{ &Z_Construct_UFunction_AZipZap_InitiateComboAttack_Projectile, "InitiateComboAttack_Projectile" }, // 3150779999
		{ &Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage, "InitiateComboAttack_Savage" }, // 2906266353
		{ &Z_Construct_UFunction_AZipZap_IsFacingBoomBoom, "IsFacingBoomBoom" }, // 765056432
		{ &Z_Construct_UFunction_AZipZap_move, "move" }, // 1163909924
		{ &Z_Construct_UFunction_AZipZap_overlapBegin, "overlapBegin" }, // 2623765507
		{ &Z_Construct_UFunction_AZipZap_overlapEnd, "overlapEnd" }, // 1617716341
		{ &Z_Construct_UFunction_AZipZap_ProcessHit, "ProcessHit" }, // 116635519
		{ &Z_Construct_UFunction_AZipZap_SetBoomBoomReference, "SetBoomBoomReference" }, // 441722268
		{ &Z_Construct_UFunction_AZipZap_setHealth, "setHealth" }, // 126306932
		{ &Z_Construct_UFunction_AZipZap_SetupPlayerInput, "SetupPlayerInput" }, // 329815324
		{ &Z_Construct_UFunction_AZipZap_StopProjectileAttack, "StopProjectileAttack" }, // 645114334
		{ &Z_Construct_UFunction_AZipZap_UpdateAnimation, "UpdateAnimation" }, // 1364801997
		{ &Z_Construct_UFunction_AZipZap_UpdateComboAttack_Projectile, "UpdateComboAttack_Projectile" }, // 301353700
		{ &Z_Construct_UFunction_AZipZap_UpdateState, "UpdateState" }, // 2685393501
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ZipZap.h" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_charMove_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_charMove = { "charMove", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, charMove), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_charMove_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_charMove_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook = { "flipbook", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, flipbook), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_idle_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_idle = { "idle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, idle), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_idle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_idle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_run_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_run = { "run", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, run), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_run_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_run_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_jumping_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_jumping = { "jumping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, jumping), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_jumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_jumping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack = { "simpleAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, simpleAttack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_initiateBoomBoomSavageComboAttack_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_initiateBoomBoomSavageComboAttack = { "initiateBoomBoomSavageComboAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, initiateBoomBoomSavageComboAttack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_initiateBoomBoomSavageComboAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_initiateBoomBoomSavageComboAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_projectileFly_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_projectileFly = { "projectileFly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, projectileFly), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_projectileFly_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_projectileFly_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_hurt_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_hurt = { "hurt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, hurt), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_hurt_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_hurt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_Hurt_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_Hurt = { "boomBoom_Hurt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, boomBoom_Hurt), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_Hurt_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_Hurt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_rotation_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_rotation_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Enum instance for the character's state\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Enum instance for the character's state" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_characterState = { "characterState", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, characterState), Z_Construct_UEnum_Superzeroes_State2, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_MetaData)) }; // 3086242876
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom = { "boomBoom", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, boomBoom), Z_Construct_UClass_ABoomBoom_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_Input_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_Input = { "Input", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, Input), Z_Construct_UClass_UInputComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_Input_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_Input_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable for the character's speed\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable for the character's speed" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed = { "characterSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, characterSpeed), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_jumpPreludeTimer_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable to keep track of what time should pass to execute the jump\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track of what time should pass to execute the jump" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_jumpPreludeTimer = { "jumpPreludeTimer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, jumpPreludeTimer), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_jumpPreludeTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_jumpPreludeTimer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_projectileAttackResetStateTimeoutTimer_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable to keep track of what time should pass to start following whether zip zap is falling when he's in projectile attack state\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track of what time should pass to start following whether zip zap is falling when he's in projectile attack state" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_projectileAttackResetStateTimeoutTimer = { "projectileAttackResetStateTimeoutTimer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, projectileAttackResetStateTimeoutTimer), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_projectileAttackResetStateTimeoutTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_projectileAttackResetStateTimeoutTimer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable to keep track whether zip zap is electrified while he's executing his projectile combo attack\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track whether zip zap is electrified while he's executing his projectile combo attack" },
	};
#endif
	void Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified_SetBit(void* Obj)
	{
		((AZipZap*)Obj)->isElectrified = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified = { "isElectrified", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZipZap), &Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_health_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "//Variable to keep track of Zip Zap's health\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track of Zip Zap's health" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_health = { "health", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, health), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_health_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox = { "hitbox", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, hitbox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_collision_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_collision = { "collision", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, collision), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_collision_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_collision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	void Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage_SetBit(void* Obj)
	{
		((AZipZap*)Obj)->toxicDamage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage = { "toxicDamage", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZipZap), &Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZipZap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_charMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_run,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_jumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_initiateBoomBoomSavageComboAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_projectileFly,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_hurt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom_Hurt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_Input,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_jumpPreludeTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_projectileAttackResetStateTimeoutTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_isElectrified,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_health,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_collision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_toxicDamage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZipZap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZipZap>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZipZap_Statics::ClassParams = {
		&AZipZap::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZipZap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZipZap()
	{
		if (!Z_Registration_Info_UClass_AZipZap.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZipZap.OuterSingleton, Z_Construct_UClass_AZipZap_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZipZap.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AZipZap>()
	{
		return AZipZap::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZipZap);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::EnumInfo[] = {
		{ State2_StaticEnum, TEXT("State2"), &Z_Registration_Info_UEnum_State2, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3086242876U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZipZap, AZipZap::StaticClass, TEXT("AZipZap"), &Z_Registration_Info_UClass_AZipZap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZipZap), 1722096604U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_4175487304(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
