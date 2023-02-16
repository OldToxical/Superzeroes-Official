// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_ZipZap_generated_h
#error "ZipZap.generated.h already included, missing '#pragma once' in ZipZap.h"
#endif
#define SUPERZEROES_ZipZap_generated_h

#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateRotation); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateRotation); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZipZap(); \
	friend struct Z_Construct_UClass_AZipZap_Statics; \
public: \
	DECLARE_CLASS(AZipZap, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAZipZap(); \
	friend struct Z_Construct_UClass_AZipZap_Statics; \
public: \
	DECLARE_CLASS(AZipZap, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZipZap(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZipZap) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZipZap); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZipZap); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZipZap(AZipZap&&); \
	NO_API AZipZap(const AZipZap&); \
public:


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZipZap(AZipZap&&); \
	NO_API AZipZap(const AZipZap&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZipZap); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZipZap); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_12_PROLOG
#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_INCLASS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AZipZap>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_ZipZap_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
