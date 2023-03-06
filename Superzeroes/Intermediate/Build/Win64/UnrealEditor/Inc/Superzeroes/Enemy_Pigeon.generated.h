// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_Enemy_Pigeon_generated_h
#error "Enemy_Pigeon.generated.h already included, missing '#pragma once' in Enemy_Pigeon.h"
#endif
#define SUPERZEROES_Enemy_Pigeon_generated_h

#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execProcessBulletCollision);


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execProcessBulletCollision);


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy_Pigeon(); \
	friend struct Z_Construct_UClass_AEnemy_Pigeon_Statics; \
public: \
	DECLARE_CLASS(AEnemy_Pigeon, AEnemy, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AEnemy_Pigeon)


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy_Pigeon(); \
	friend struct Z_Construct_UClass_AEnemy_Pigeon_Statics; \
public: \
	DECLARE_CLASS(AEnemy_Pigeon, AEnemy, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AEnemy_Pigeon)


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy_Pigeon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy_Pigeon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy_Pigeon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy_Pigeon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy_Pigeon(AEnemy_Pigeon&&); \
	NO_API AEnemy_Pigeon(const AEnemy_Pigeon&); \
public:


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy_Pigeon(AEnemy_Pigeon&&); \
	NO_API AEnemy_Pigeon(const AEnemy_Pigeon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy_Pigeon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy_Pigeon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy_Pigeon)


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_43_PROLOG
#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_INCLASS \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AEnemy_Pigeon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_Enemy_Pigeon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
