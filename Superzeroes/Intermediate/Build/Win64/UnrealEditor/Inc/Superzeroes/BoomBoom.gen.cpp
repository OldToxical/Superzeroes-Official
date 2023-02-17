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
	SUPERZEROES_API UEnum* Z_Construct_UEnum_Superzeroes_State();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_ABoomBoom();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_State;
	static UEnum* State_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_State.OuterSingleton)
		{
			Z_Registration_Info_UEnum_State.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Superzeroes_State, Z_Construct_UPackage__Script_Superzeroes(), TEXT("State"));
		}
		return Z_Registration_Info_UEnum_State.OuterSingleton;
	}
	template<> SUPERZEROES_API UEnum* StaticEnum<State>()
	{
		return State_StaticEnum();
	}
	struct Z_Construct_UEnum_Superzeroes_State_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Superzeroes_State_Statics::Enumerators[] = {
		{ "State::Idle", (int64)State::Idle },
		{ "State::Running", (int64)State::Running },
		{ "State::Jumping", (int64)State::Jumping },
		{ "State::Attacking", (int64)State::Attacking },
		{ "State::Combo_1", (int64)State::Combo_1 },
		{ "State::Combo_2", (int64)State::Combo_2 },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Superzeroes_State_Statics::Enum_MetaDataParams[] = {
		{ "Attacking.Name", "State::Attacking" },
		{ "Combo_1.Name", "State::Combo_1" },
		{ "Combo_2.Name", "State::Combo_2" },
		{ "Idle.Name", "State::Idle" },
		{ "Jumping.Name", "State::Jumping" },
		{ "ModuleRelativePath", "BoomBoom.h" },
		{ "Running.Name", "State::Running" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Superzeroes_State_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Superzeroes,
		nullptr,
		"State",
		"State",
		Z_Construct_UEnum_Superzeroes_State_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Superzeroes_State_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_Superzeroes_State_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Superzeroes_State_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Superzeroes_State()
	{
		if (!Z_Registration_Info_UEnum_State.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_State.InnerSingleton, Z_Construct_UEnum_Superzeroes_State_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_State.InnerSingleton;
	}
	DEFINE_FUNCTION(ABoomBoom::execEndAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndAttack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoomBoom::execAttack)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_scaleVal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attack(Z_Param_scaleVal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoomBoom::execmove)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_scaleVal);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->move(Z_Param_scaleVal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoomBoom::execUpdateRotation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateRotation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoomBoom::execUpdateAnimation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAnimation();
		P_NATIVE_END;
	}
	void ABoomBoom::StaticRegisterNativesABoomBoom()
	{
		UClass* Class = ABoomBoom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Attack", &ABoomBoom::execAttack },
			{ "EndAttack", &ABoomBoom::execEndAttack },
			{ "move", &ABoomBoom::execmove },
			{ "UpdateAnimation", &ABoomBoom::execUpdateAnimation },
			{ "UpdateRotation", &ABoomBoom::execUpdateRotation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoomBoom_Attack_Statics
	{
		struct BoomBoom_eventAttack_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoomBoom_Attack_Statics::NewProp_scaleVal = { "scaleVal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoomBoom_eventAttack_Parms, scaleVal), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoomBoom_Attack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoomBoom_Attack_Statics::NewProp_scaleVal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoomBoom_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoomBoom_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoomBoom, nullptr, "Attack", nullptr, nullptr, sizeof(Z_Construct_UFunction_ABoomBoom_Attack_Statics::BoomBoom_eventAttack_Parms), Z_Construct_UFunction_ABoomBoom_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_Attack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoomBoom_Attack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_Attack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoomBoom_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoomBoom_Attack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoomBoom_EndAttack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoomBoom_EndAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoomBoom_EndAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoomBoom, nullptr, "EndAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoomBoom_EndAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_EndAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoomBoom_EndAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoomBoom_EndAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoomBoom_move_Statics
	{
		struct BoomBoom_eventmove_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABoomBoom_move_Statics::NewProp_scaleVal = { "scaleVal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BoomBoom_eventmove_Parms, scaleVal), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoomBoom_move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoomBoom_move_Statics::NewProp_scaleVal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoomBoom_move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoomBoom_move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoomBoom, nullptr, "move", nullptr, nullptr, sizeof(Z_Construct_UFunction_ABoomBoom_move_Statics::BoomBoom_eventmove_Parms), Z_Construct_UFunction_ABoomBoom_move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_move_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoomBoom_move_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_move_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoomBoom_move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoomBoom_move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoomBoom, nullptr, "UpdateAnimation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoomBoom_UpdateAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoomBoom_UpdateAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoomBoom, nullptr, "UpdateRotation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoomBoom_UpdateRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoomBoom_UpdateRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoomBoom);
	UClass* Z_Construct_UClass_ABoomBoom_NoRegister()
	{
		return ABoomBoom::StaticClass();
	}
	struct Z_Construct_UClass_ABoomBoom_Statics
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_zipZap_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_zipZap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_attackInputTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_attackInputTimer;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_characterState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_characterState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_characterState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoomBoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoomBoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoomBoom_Attack, "Attack" }, // 2372999996
		{ &Z_Construct_UFunction_ABoomBoom_EndAttack, "EndAttack" }, // 2072088278
		{ &Z_Construct_UFunction_ABoomBoom_move, "move" }, // 1235895177
		{ &Z_Construct_UFunction_ABoomBoom_UpdateAnimation, "UpdateAnimation" }, // 3373191176
		{ &Z_Construct_UFunction_ABoomBoom_UpdateRotation, "UpdateRotation" }, // 1764791563
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BoomBoom.h" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove = { "charMove", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, charMove), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook = { "flipbook", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, flipbook), Z_Construct_UClass_UPaperFlipbookComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle = { "idle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, idle), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_run_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_run = { "run", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, run), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_run_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_run_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping = { "jumping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, jumping), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_simpleAttack_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_simpleAttack = { "simpleAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, simpleAttack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_simpleAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_simpleAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttack_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttack = { "strongAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, strongAttack), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttack_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttackCharge_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttackCharge = { "strongAttackCharge", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, strongAttackCharge), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttackCharge_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttackCharge_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap = { "zipZap", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, zipZap), Z_Construct_UClass_AZipZap_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_attackInputTimer_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_attackInputTimer = { "attackInputTimer", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, attackInputTimer), METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_attackInputTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_attackInputTimer_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState_MetaData[] = {
		{ "Category", "BoomBoom" },
		{ "ModuleRelativePath", "BoomBoom.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState = { "characterState", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoomBoom, characterState), Z_Construct_UEnum_Superzeroes_State, METADATA_PARAMS(Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState_MetaData)) }; // 3664248686
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoomBoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_run,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_simpleAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_strongAttackCharge,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_attackInputTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_characterState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoomBoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoomBoom>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoomBoom_Statics::ClassParams = {
		&ABoomBoom::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoomBoom_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoomBoom_Statics::PropPointers),
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
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::EnumInfo[] = {
		{ State_StaticEnum, TEXT("State"), &Z_Registration_Info_UEnum_State, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3664248686U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoomBoom, ABoomBoom::StaticClass, TEXT("ABoomBoom"), &Z_Registration_Info_UClass_ABoomBoom, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoomBoom), 2977715133U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_1469757487(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
