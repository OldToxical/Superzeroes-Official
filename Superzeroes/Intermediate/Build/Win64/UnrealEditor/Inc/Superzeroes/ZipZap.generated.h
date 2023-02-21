// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInputComponent;
#ifdef SUPERZEROES_ZipZap_generated_h
#error "ZipZap.generated.h already included, missing '#pragma once' in ZipZap.h"
#endif
#define SUPERZEROES_ZipZap_generated_h

#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetupPlayerInput); \
	DECLARE_FUNCTION(execInitiateComboAttack_Savage); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateComboAttack_Savage); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetupPlayerInput); \
	DECLARE_FUNCTION(execInitiateComboAttack_Savage); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateComboAttack_Savage); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZipZap(); \
	friend struct Z_Construct_UClass_AZipZap_Statics; \
public: \
	DECLARE_CLASS(AZipZap, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_INCLASS \
private: \
	static void StaticRegisterNativesAZipZap(); \
	friend struct Z_Construct_UClass_AZipZap_Statics; \
public: \
	DECLARE_CLASS(AZipZap, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_STANDARD_CONSTRUCTORS \
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


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZipZap(AZipZap&&); \
	NO_API AZipZap(const AZipZap&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZipZap); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZipZap); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZipZap)


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_25_PROLOG
#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_INCLASS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_ZipZap_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AZipZap>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_ZipZap_h


#define FOREACH_ENUM_STATE2(op) \
	op(State2::Idle) \
	op(State2::Running) \
	op(State2::Jumping) \
	op(State2::Attacking) \
	op(State2::Charge_Attacking) \
	op(State2::Combo_Savage) \
	op(State2::Combo_2) 

enum class State2 : uint8;
template<> SUPERZEROES_API UEnum* StaticEnum<State2>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
