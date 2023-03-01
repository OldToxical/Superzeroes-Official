// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef SUPERZEROES_Trash_generated_h
#error "Trash.generated.h already included, missing '#pragma once' in Trash.h"
#endif
#define SUPERZEROES_Trash_generated_h

#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execoverlapEnd); \
	DECLARE_FUNCTION(execoverlapBegin);


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execoverlapEnd); \
	DECLARE_FUNCTION(execoverlapBegin);


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrash(); \
	friend struct Z_Construct_UClass_ATrash_Statics; \
public: \
	DECLARE_CLASS(ATrash, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(ATrash)


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_INCLASS \
private: \
	static void StaticRegisterNativesATrash(); \
	friend struct Z_Construct_UClass_ATrash_Statics; \
public: \
	DECLARE_CLASS(ATrash, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(ATrash)


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrash(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrash) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrash); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrash); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrash(ATrash&&); \
	NO_API ATrash(const ATrash&); \
public:


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrash(ATrash&&); \
	NO_API ATrash(const ATrash&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrash); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrash); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrash)


#define FID_Superzeroes_Source_Superzeroes_Trash_h_18_PROLOG
#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_INCLASS \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_Trash_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Trash_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class ATrash>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_Trash_h


#define FOREACH_ENUM_TRASHSTATE(op) \
	op(trashState::Idle) \
	op(trashState::Hurt) 

enum class trashState : uint8;
template<> SUPERZEROES_API UEnum* StaticEnum<trashState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
