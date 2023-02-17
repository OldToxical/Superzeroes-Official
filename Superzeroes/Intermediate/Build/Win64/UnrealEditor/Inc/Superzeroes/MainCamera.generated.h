// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_MainCamera_generated_h
#error "MainCamera.generated.h already included, missing '#pragma once' in MainCamera.h"
#endif
#define SUPERZEROES_MainCamera_generated_h

#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_RPC_WRAPPERS
#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainCamera(); \
	friend struct Z_Construct_UClass_AMainCamera_Statics; \
public: \
	DECLARE_CLASS(AMainCamera, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AMainCamera)


#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMainCamera(); \
	friend struct Z_Construct_UClass_AMainCamera_Statics; \
public: \
	DECLARE_CLASS(AMainCamera, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AMainCamera)


#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCamera); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCamera(AMainCamera&&); \
	NO_API AMainCamera(const AMainCamera&); \
public:


#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainCamera(AMainCamera&&); \
	NO_API AMainCamera(const AMainCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCamera); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainCamera)


#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_9_PROLOG
#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_INCLASS \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_MainCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AMainCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_MainCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
