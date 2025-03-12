// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FunctionInvokeManager.generated.h"

struct FFunctionData;
class UFunctionInvokeData;

USTRUCT(BlueprintType)
struct FFunctionInvokeInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UClass* FunctionOwner;

	UPROPERTY(Transient)
	UFunction* InvokeFunction;

public:
	FFunctionInvokeInfo()
	{
		FunctionOwner = nullptr;
		InvokeFunction = nullptr;
	}

	FFunctionInvokeInfo(UClass* InFunctionOwner, UFunction* InInvokeFunction)
	{
		FunctionOwner = InFunctionOwner;
		InvokeFunction = InInvokeFunction;
	}

	bool IsValidData() const
	{
		return IsValid(FunctionOwner) && IsValid(InvokeFunction);
	}
};

USTRUCT(BlueprintType)
struct FFunctionInvokeObjectData
{
	GENERATED_BODY()

public:
	TObjectPtr<UObject> InvokeObject;
	TObjectPtr<UFunction> InvokeFunctionName;

	FFunctionInvokeObjectData()
		: InvokeObject(nullptr)
		, InvokeFunctionName(nullptr)
	{}

	FFunctionInvokeObjectData(UObject* InUObject, UFunction* InInvokeFunctionName)
		: InvokeObject(InUObject)
		, InvokeFunctionName(InInvokeFunctionName)
	{}

};

UCLASS()
class VIRTUALTRACKER_API AFunctionInvokeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AFunctionInvokeManager();

public:
	void InitInvokeManager(UObject* InvokeObject,
		EFieldIteratorFlags::SuperClassFlags SuperClassFlag = EFieldIteratorFlags::IncludeSuper,
		EFieldIteratorFlags::DeprecatedPropertyFlags DeprecatedFieldFlag = EFieldIteratorFlags::ExcludeDeprecated,
		EFieldIteratorFlags::InterfaceClassFlags InterfaceFieldFlag = EFieldIteratorFlags::ExcludeInterfaces);

public:
	void ActionFunctionInvoke(FName FunctionName);
	void SliderFunctionInvoke(FName FunctionName, float FuncParam);
	void ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam);
	void BooleanFunctionInvoke(FName FunctionName, bool FuncParam);
	void StringFunctionInvoke(FName FunctionName, FString FuncParam);
	void IntFunctionInvoke(FName FunctionName, int32 FuncParam);
	void TextureFunctionInvoke(FName FunctionName);
	void NameFunctionInvoke(FName FunctionName, FName FuncParam);
	void Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam);
	void Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFunctionInvokeData> FuncData;
	
	UPROPERTY(Transient)
	TArray< FFunctionInvokeObjectData> FunctionInvokeObject;

#if WITH_EDITOR
protected:
	virtual void PostInitProperties() override;
	virtual void OnCompiled();
#endif

};
