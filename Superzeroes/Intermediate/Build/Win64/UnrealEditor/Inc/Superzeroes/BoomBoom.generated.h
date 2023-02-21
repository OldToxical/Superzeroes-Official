// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_BoomBoom_generated_h
#error "BoomBoom.generated.h already included, missing '#pragma once' in BoomBoom.h"
#endif
#define SUPERZEROES_BoomBoom_generated_h

#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInitiateComboAttack_Savage); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execExecuteJump); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateComboAttack_Savage); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInitiateComboAttack_Savage); \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execExecuteJump); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execUpdateComboAttack_Savage); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoomBoom(); \
	friend struct Z_Construct_UClass_ABoomBoom_Statics; \
public: \
	DECLARE_CLASS(ABoomBoom, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(ABoomBoom)


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_INCLASS \
private: \
	static void StaticRegisterNativesABoomBoom(); \
	friend struct Z_Construct_UClass_ABoomBoom_Statics; \
public: \
	DECLARE_CLASS(ABoomBoom, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(ABoomBoom)


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoomBoom(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoomBoom) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoomBoom); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoomBoom); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoomBoom(ABoomBoom&&); \
	NO_API ABoomBoom(const ABoomBoom&); \
public:


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoomBoom(ABoomBoom&&); \
	NO_API ABoomBoom(const ABoomBoom&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoomBoom); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoomBoom); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoomBoom)


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_26_PROLOG
#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_INCLASS \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_BoomBoom_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class ABoomBoom>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_BoomBoom_h


#define FOREACH_ENUM_STATE(op) \
	op(State::Idle) \
	op(State::Running) \
	op(State::Jumping) \
	op(State::Attacking) \
	op(State::Combo_Savage) \
	op(State::Combo_2) 

enum class State;
template<> SUPERZEROES_API UEnum* StaticEnum<State>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
