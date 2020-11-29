// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SearchingMode.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_PROJECT_API UBTTask_SearchingMode : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_SearchingMode();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;
	
};
