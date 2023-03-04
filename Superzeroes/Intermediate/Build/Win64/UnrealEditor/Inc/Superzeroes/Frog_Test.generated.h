// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPERZEROES_Frog_Test_generated_h
#error "Frog_Test.generated.h already included, missing '#pragma once' in Frog_Test.h"
#endif
#define SUPERZEROES_Frog_Test_generated_h

#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_SPARSE_DATA
#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execProcessBulletCollision);


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndAttack); \
	DECLARE_FUNCTION(execProcessBulletCollision);


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFrog_Test(); \
	friend struct Z_Construct_UClass_AFrog_Test_Statics; \
public: \
	DECLARE_CLASS(AFrog_Test, AEnemy, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AFrog_Test)


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_INCLASS \
private: \
	static void StaticRegisterNativesAFrog_Test(); \
	friend struct Z_Construct_UClass_AFrog_Test_Statics; \
public: \
	DECLARE_CLASS(AFrog_Test, AEnemy, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Superzeroes"), NO_API) \
	DECLARE_SERIALIZER(AFrog_Test)


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFrog_Test(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFrog_Test) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFrog_Test); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFrog_Test); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFrog_Test(AFrog_Test&&); \
	NO_API AFrog_Test(const AFrog_Test&); \
public:


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFrog_Test(AFrog_Test&&); \
	NO_API AFrog_Test(const AFrog_Test&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFrog_Test); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFrog_Test); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFrog_Test)


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_43_PROLOG
#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_RPC_WRAPPERS \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_INCLASS \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_SPARSE_DATA \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_INCLASS_NO_PURE_DECLS \
	FID_Superzeroes_Source_Superzeroes_Frog_Test_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERZEROES_API UClass* StaticClass<class AFrog_Test>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Superzeroes_Source_Superzeroes_Frog_Test_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
