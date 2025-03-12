// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "EnhancedPlayerInput.h"
#include "FunctionInvokeStruct.generated.h"

extern VIRTUALTRACKER_API const FName ActionFunction_META;
extern VIRTUALTRACKER_API const FName SliderFunction_META;
extern VIRTUALTRACKER_API const FName ColorFunction_META;
extern VIRTUALTRACKER_API const FName BooleanFunction_META;
extern VIRTUALTRACKER_API const FName StringFunction_META;
extern VIRTUALTRACKER_API const FName IntFunction_META;
extern VIRTUALTRACKER_API const FName TextureFunction_META;
extern VIRTUALTRACKER_API const FName NameFunction_META;
extern VIRTUALTRACKER_API const FName Vector2DFunction_META;
extern VIRTUALTRACKER_API const FName Vector3DFunction_META;

UENUM(BlueprintType)
enum class EFunctionType : uint8
{
	NONE UMETA(Hidden),
	Action,
	Slider,
	Color,
	Boolean,
	String,
	Int,
	Texture,
	Name,
	Vector2D,
	Vector3D
};

USTRUCT(BlueprintType)
struct FActionFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActionFunctionName;
};

USTRUCT(BlueprintType)
struct FSliderFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SliderFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SliderFunctionParam;
};

USTRUCT(BlueprintType)
struct FColorFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ColorFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor ColorFunctionParam;
};

USTRUCT(BlueprintType)
struct FBooleanFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName BooleanFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BooleanFunctionParam;
};

USTRUCT(BlueprintType)
struct FStringFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StringFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StringFunctionParam;
};

USTRUCT(BlueprintType)
struct FIntFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName IntFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntFunctionParam;
};

USTRUCT(BlueprintType)
struct FTextureFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TextureFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> TextureFunctionParam;
};

USTRUCT(BlueprintType)
struct FNameFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FNameFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FNameFunctionParam;
};

USTRUCT(BlueprintType)
struct FVector2DFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Vector2DFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Vector2DFunctionParam;
};

USTRUCT(BlueprintType)
struct FVector3DFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Vector3DFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Vector3DFunctionParam;
};

USTRUCT(BlueprintType)
struct FunctionInfoCollection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFunctionType EFunctionTypeMeta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FActionFunctionInfo ActionInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FSliderFunctionInfo SliderInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FColorFunctionInfo ColorInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FBooleanFunctionInfo BooleanInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FStringFunctionInfo StringInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FIntFunctionInfo IntInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FTextureFunctionInfo TextureInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FNameFunctionInfo NameInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FVector2DFunctionInfo Vector2DInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FVector3DFunctionInfo Vector3DInfo;
};

UCLASS()
class UFunctionInvokeStruct : public UEnhancedPlayerInput
{
	GENERATED_BODY()

public:

};