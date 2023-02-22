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
	ENGINE_API UClass* Z_Construct_UClass_UInputComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
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
		{ "State2::Charge_Attacking", (int64)State2::Charge_Attacking },
		{ "State2::Combo_Savage", (int64)State2::Combo_Savage },
		{ "State2::Combo_2", (int64)State2::Combo_2 },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Superzeroes_State2_Statics::Enum_MetaDataParams[] = {
		{ "Attacking.Comment", "/**\n *\n */" },
		{ "Attacking.Name", "State2::Attacking" },
		{ "BlueprintType", "true" },
		{ "Charge_Attacking.Comment", "/**\n *\n */" },
		{ "Charge_Attacking.Name", "State2::Charge_Attacking" },
		{ "Combo_2.Comment", "/**\n *\n */" },
		{ "Combo_2.Name", "State2::Combo_2" },
		{ "Combo_Savage.Comment", "/**\n *\n */" },
		{ "Combo_Savage.Name", "State2::Combo_Savage" },
		{ "Comment", "/**\n *\n */" },
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
	DEFINE_FUNCTION(AZipZap::execSetupPlayerInput)
	{
		P_GET_OBJECT(UInputComponent,Z_Param_input_);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupPlayerInput(Z_Param_input_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZipZap::execHitCheck)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HitCheck();
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
		P_GET_PROPERTY(FFloatProperty,Z_Param_scaleVal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attack(Z_Param_scaleVal);
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
	DEFINE_FUNCTION(AZipZap::execUpdateComboAttack_Savage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateComboAttack_Savage();
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
			{ "EndAttack", &AZipZap::execEndAttack },
			{ "ExecuteJump", &AZipZap::execExecuteJump },
			{ "HitCheck", &AZipZap::execHitCheck },
			{ "InitiateComboAttack_Savage", &AZipZap::execInitiateComboAttack_Savage },
			{ "move", &AZipZap::execmove },
			{ "SetupPlayerInput", &AZipZap::execSetupPlayerInput },
			{ "UpdateAnimation", &AZipZap::execUpdateAnimation },
			{ "UpdateComboAttack_Savage", &AZipZap::execUpdateComboAttack_Savage },
			{ "UpdateState", &AZipZap::execUpdateState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZipZap_Attack_Statics
	{
		struct ZipZap_eventAttack_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZipZap_Attack_Statics::NewProp_scaleVal = { "scaleVal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZipZap_eventAttack_Parms, scaleVal), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZipZap_Attack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZipZap_Attack_Statics::NewProp_scaleVal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "Attack", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZipZap_Attack_Statics::ZipZap_eventAttack_Parms), Z_Construct_UFunction_AZipZap_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_Attack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_Attack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_Attack_Statics::FuncParams);
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
	struct Z_Construct_UFunction_AZipZap_HitCheck_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_HitCheck_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_HitCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "HitCheck", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_HitCheck_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_HitCheck_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_HitCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_HitCheck_Statics::FuncParams);
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
	struct Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZipZap, nullptr, "UpdateComboAttack_Savage", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage_Statics::FuncParams);
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_strongAttack_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_strongAttack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_strongAttackCharge_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_strongAttackCharge;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_attackInputTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_attackInputTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_characterSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_characterSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComboAttack_Savage_ExecutionTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ComboAttack_Savage_ExecutionTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitbox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_hitbox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZipZap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZipZap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZipZap_Attack, "Attack" }, // 291063423
		{ &Z_Construct_UFunction_AZipZap_EndAttack, "EndAttack" }, // 2437475914
		{ &Z_Construct_UFunction_AZipZap_ExecuteJump, "ExecuteJump" }, // 3039473597
		{ &Z_Construct_UFunction_AZipZap_HitCheck, "HitCheck" }, // 3501749777
		{ &Z_Construct_UFunction_AZipZap_InitiateComboAttack_Savage, "InitiateComboAttack_Savage" }, // 2906266353
		{ &Z_Construct_UFunction_AZipZap_move, "move" }, // 1163909924
		{ &Z_Construct_UFunction_AZipZap_SetupPlayerInput, "SetupPlayerInput" }, // 329815324
		{ &Z_Construct_UFunction_AZipZap_UpdateAnimation, "UpdateAnimation" }, // 1364801997
		{ &Z_Construct_UFunction_AZipZap_UpdateComboAttack_Savage, "UpdateComboAttack_Savage" }, // 299496926
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttack_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttack = { "strongAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, strongAttack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttackCharge_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttackCharge = { "strongAttackCharge", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, strongAttackCharge), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttackCharge_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttackCharge_MetaData)) };
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
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_characterState = { "characterState", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, characterState), Z_Construct_UEnum_Superzeroes_State2, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_MetaData)) }; // 3667271570
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_attackInputTimer_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable to keep track of how long the \"Attack\" buton is being held down\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track of how long the \"Attack\" buton is being held down" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_attackInputTimer = { "attackInputTimer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, attackInputTimer), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_attackInputTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_attackInputTimer_MetaData)) };
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_ComboAttack_Savage_ExecutionTimer_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "Comment", "// Variable to keep track of how long the savage attack is to be executed\n" },
		{ "ModuleRelativePath", "ZipZap.h" },
		{ "ToolTip", "Variable to keep track of how long the savage attack is to be executed" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_ComboAttack_Savage_ExecutionTimer = { "ComboAttack_Savage_ExecutionTimer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, ComboAttack_Savage_ExecutionTimer), METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_ComboAttack_Savage_ExecutionTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_ComboAttack_Savage_ExecutionTimer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData[] = {
		{ "Category", "ZipZap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ZipZap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox = { "hitbox", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZipZap, hitbox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZipZap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_charMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_flipbook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_run,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_jumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_simpleAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_strongAttackCharge,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_boomBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_Input,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_attackInputTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_characterSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_ComboAttack_Savage_ExecutionTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZipZap_Statics::NewProp_hitbox,
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
		{ State2_StaticEnum, TEXT("State2"), &Z_Registration_Info_UEnum_State2, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3667271570U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZipZap, AZipZap::StaticClass, TEXT("AZipZap"), &Z_Registration_Info_UClass_AZipZap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZipZap), 1147960482U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_211792407(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_ZipZap_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
