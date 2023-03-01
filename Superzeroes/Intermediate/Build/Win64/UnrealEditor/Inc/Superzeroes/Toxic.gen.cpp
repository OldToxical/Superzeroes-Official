// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Superzeroes/Toxic.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToxic() {}
// Cross Module References
	SUPERZEROES_API UClass* Z_Construct_UClass_AToxic_NoRegister();
	SUPERZEROES_API UClass* Z_Construct_UClass_AToxic();
	PAPER2D_API UClass* Z_Construct_UClass_APaperSpriteActor();
	UPackage* Z_Construct_UPackage__Script_Superzeroes();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AToxic::execoverlapEnd)
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
	DEFINE_FUNCTION(AToxic::execoverlapBegin)
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
	void AToxic::StaticRegisterNativesAToxic()
	{
		UClass* Class = AToxic::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "overlapBegin", &AToxic::execoverlapBegin },
			{ "overlapEnd", &AToxic::execoverlapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AToxic_overlapBegin_Statics
	{
		struct Toxic_eventoverlapBegin_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_overlappedComp = { "overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapBegin_Parms, overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_overlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_overlappedComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherActor = { "otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapBegin_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherComp = { "otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapBegin_Parms, otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherComp_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherBodyIndex = { "otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapBegin_Parms, otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((Toxic_eventoverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Toxic_eventoverlapBegin_Parms), &Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapBegin_Parms, result), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_result_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_result_MetaData)) }; // 1416937132
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AToxic_overlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_overlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_otherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapBegin_Statics::NewProp_result,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Toxic.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AToxic_overlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AToxic, nullptr, "overlapBegin", nullptr, nullptr, sizeof(Z_Construct_UFunction_AToxic_overlapBegin_Statics::Toxic_eventoverlapBegin_Parms), Z_Construct_UFunction_AToxic_overlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AToxic_overlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AToxic_overlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AToxic_overlapEnd_Statics
	{
		struct Toxic_eventoverlapEnd_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_overlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_overlappedComp = { "overlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapEnd_Parms, overlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_overlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_overlappedComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherActor = { "otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapEnd_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherComp = { "otherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapEnd_Parms, otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherComp_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherBodyIndex = { "otherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Toxic_eventoverlapEnd_Parms, otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AToxic_overlapEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_overlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToxic_overlapEnd_Statics::NewProp_otherBodyIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToxic_overlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Toxic.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AToxic_overlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AToxic, nullptr, "overlapEnd", nullptr, nullptr, sizeof(Z_Construct_UFunction_AToxic_overlapEnd_Statics::Toxic_eventoverlapEnd_Parms), Z_Construct_UFunction_AToxic_overlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AToxic_overlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AToxic_overlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AToxic_overlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AToxic_overlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AToxic);
	UClass* Z_Construct_UClass_AToxic_NoRegister()
	{
		return AToxic::StaticClass();
	}
	struct Z_Construct_UClass_AToxic_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitbox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_hitbox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AToxic_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperSpriteActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Superzeroes,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AToxic_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AToxic_overlapBegin, "overlapBegin" }, // 4065810224
		{ &Z_Construct_UFunction_AToxic_overlapEnd, "overlapEnd" }, // 104591802
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AToxic_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "Toxic.h" },
		{ "ModuleRelativePath", "Toxic.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AToxic_Statics::NewProp_hitbox_MetaData[] = {
		{ "Category", "Toxic" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Toxic.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AToxic_Statics::NewProp_hitbox = { "hitbox", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AToxic, hitbox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AToxic_Statics::NewProp_hitbox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AToxic_Statics::NewProp_hitbox_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AToxic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AToxic_Statics::NewProp_hitbox,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AToxic_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AToxic>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AToxic_Statics::ClassParams = {
		&AToxic::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AToxic_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AToxic_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AToxic_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AToxic_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AToxic()
	{
		if (!Z_Registration_Info_UClass_AToxic.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AToxic.OuterSingleton, Z_Construct_UClass_AToxic_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AToxic.OuterSingleton;
	}
	template<> SUPERZEROES_API UClass* StaticClass<AToxic>()
	{
		return AToxic::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AToxic);
	struct Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Toxic_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Toxic_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AToxic, AToxic::StaticClass, TEXT("AToxic"), &Z_Registration_Info_UClass_AToxic, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AToxic), 3408480398U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Toxic_h_1967397103(TEXT("/Script/Superzeroes"),
		Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Toxic_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Superzeroes_Source_Superzeroes_Toxic_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
