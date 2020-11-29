// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SearchingMode.h"
#include "AIController.h"
#include "Final_Project/Characters/ShooterCharacterBase.h"
#include "Engine/World.h"

UBTTask_SearchingMode::UBTTask_SearchingMode() 
{
    NodeName = TEXT("Searching Mode");
}

EBTNodeResult::Type UBTTask_SearchingMode::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;

    AShooterCharacterBase* Character = Cast<AShooterCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
    if (!Character) return EBTNodeResult::Failed;
    // AActor* Actor = Cast<AShooterCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
    FRotator MakeRotator = { Character->GetActorRotation().Pitch, GetWorld()->GetDeltaSeconds() * 100.f, Character->GetActorRotation().Roll };
    Character->AddActorLocalRotation(MakeRotator);

    return EBTNodeResult::Succeeded;
}
