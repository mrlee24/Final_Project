// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_PROJECT_API AShooterAIControllerBase : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	protected:
	virtual void BeginPlay() override;
};
