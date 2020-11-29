// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Final_ProjectPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_PROJECT_API AFinal_ProjectPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
	
	UPROPERTY()
	class UUserWidget* HUD;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
