// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIControllerBase.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AShooterAIControllerBase::BeginPlay() 
{
    Super::BeginPlay();

    if (AIBehavior)
    {
        RunBehaviorTree(AIBehavior);
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}