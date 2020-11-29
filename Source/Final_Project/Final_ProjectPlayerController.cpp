// Fill out your copyright notice in the Description page of Project Settings.


#include "Final_ProjectPlayerController.h"
#include "Blueprint/UserWidget.h"


void AFinal_ProjectPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass); 
    if  (HUD)
        HUD->AddToViewport(1);
}
