// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "Final_Project/Characters/ShooterCharacterBase.h"

UBTTask_Shoot::UBTTask_Shoot() 
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;

    AShooterCharacterBase* Character = Cast<AShooterCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
    
    if (!Character) return EBTNodeResult::Failed;

    float DistanceToPlayer = (Character->GetActorLocation() - OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation()).Size();

    if (DistanceToPlayer <= 500.f) 
        Character->Shoot();
        
    return EBTNodeResult::Succeeded;
}

