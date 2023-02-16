// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define SUPERZEROES_Enemy_generated_h

#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execmoveRight); \
	DECLARE_FUNCTION(execmoveLeft); \
	DECLARE_FUNCTION(execUpdateRotation); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execmoveRight); \
	DECLARE_FUNCTION(execmoveLeft); \
	DECLARE_FUNCTION(execUpdateRotation); \
	DECLARE_FUNCTION(execUpdateAnimation);


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AEnemy)


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public:


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy(AEnemy&&); \
	NO_API AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy)


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_15_PROLOG
#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_INCLASS \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_Enemy_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Enemy_h_19_ENHANCED_CONSTRUCTORS \
protected: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
