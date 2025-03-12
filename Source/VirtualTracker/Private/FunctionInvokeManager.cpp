// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionInvokeManager.h"
#include "FunctionInvokeData.h"
#include "FunctionInvokeStruct.h"

// Sets default values
AFunctionInvokeManager::AFunctionInvokeManager()
{
	
}

void AFunctionInvokeManager::InitInvokeManager(UObject* InvokeObject, EFieldIteratorFlags::SuperClassFlags SuperClassFlag, EFieldIteratorFlags::DeprecatedPropertyFlags DeprecatedFieldFlag, EFieldIteratorFlags::InterfaceClassFlags InterfaceFieldFlag)
{
	UFunctionInvokeData* TempFuncData = UFunctionInvokeData::GetDataPtr();
	FuncData = TempFuncData;

	UClass* InvokeClass = InvokeObject->GetClass();
	for (UFunction* Function : TFieldRange<UFunction>(InvokeClass, SuperClassFlag, DeprecatedFieldFlag, InterfaceFieldFlag))
	{
		if (!IsValid(Function))
		{
			continue;
		}

		FString FuncNameStr = *Function->GetName();
		if (FuncNameStr.IsEmpty())
		{
			continue;
		}

		FNativeFuncPtr NativeFuncPtr = Function->GetNativeFunc();
		if (NativeFuncPtr == nullptr)
		{
			continue;
		}

		FFunctionInvokeObjectData FuncInvokeData(InvokeObject, Function);

		if (FuncData->HasActionFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasSliderFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasColorFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasBooleanFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasStringFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasIntFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasTextureFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasNameFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasVector2DFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
		else if (FuncData->HasVector3DFunction(InvokeClass->GetName(), FuncNameStr))
		{

		}
	}
}

void AFunctionInvokeManager::ActionFunctionInvoke(FName FunctionName)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetActionFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{
		UClass* CandidateClass = CandidateFunction.FuncClass;
		FName CandidateFunctionName = CandidateFunction.FuncName;

		if (!IsValid(CandidateClass))
		{
			continue;
		}

		if (CandidateFunctionName.IsNone())
		{
			continue;
		}

		if (!CandidateFunctionName.IsEqual(FunctionName))
		{
			continue;
		}

	}
}

void AFunctionInvokeManager::SliderFunctionInvoke(FName FunctionName, float FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetSliderFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}

}

void AFunctionInvokeManager::ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetColorFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::BooleanFunctionInvoke(FName FunctionName, bool FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetBooleanFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::StringFunctionInvoke(FName FunctionName, FString FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetStringFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::IntFunctionInvoke(FName FunctionName, int32 FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetIntFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::TextureFunctionInvoke(FName FunctionName)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetTextureFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::NameFunctionInvoke(FName FunctionName, FName FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetNameFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetVector2DFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	TArray<FFunctionData> CandidateFuncDataList = FuncData->GetVector3DFunction();

	for (const FFunctionData& CandidateFunction : CandidateFuncDataList)
	{

	}
}

void AFunctionInvokeManager::PostInitProperties()
{
	Super::PostInitProperties();
	UE_LOG(LogTemp, Log, TEXT("PostInitProperties"));
}

void AFunctionInvokeManager::OnCompiled()
{
	UE_LOG(LogTemp, Log, TEXT("On Compiled"));
}
