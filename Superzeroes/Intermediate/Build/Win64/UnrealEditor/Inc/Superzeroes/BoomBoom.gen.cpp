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
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	SUPERZEROES_API UClass* Z_Construct_UClass_AZipZap_NoRegister();
// End Cross Module References
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
			{ "move", &ABoomBoom::execmove },
			{ "UpdateAnimation", &ABoomBoom::execUpdateAnimation },
			{ "UpdateRotation", &ABoomBoom::execUpdateRotation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_zipZap_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_zipZap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoomBoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoomBoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoomBoom_move, "move" }, // 1235895177
		{ &Z_Construct_UFunction_ABoomBoom_UpdateAnimation, "UpdateAnimation" }, // 3373191176
		{ &Z_Construct_UFunction_ABoomBoom_UpdateRotation, "UpdateRotation" }, // 1764791563
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoomBoom_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
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
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoomBoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_charMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_flipbook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_idle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_run,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_jumping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoomBoom_Statics::NewProp_zipZap,
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoomBoom, ABoomBoom::StaticClass, TEXT("ABoomBoom"), &Z_Registration_Info_UClass_ABoomBoom, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoomBoom), 1129617784U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_2834088055(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_BoomBoom_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
