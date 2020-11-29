// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_PlayerLocationIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Engine/Engine.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen() 
{
    NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (!PlayerPawn) return;

    if (!OwnerComp.GetAIOwner()) return;

    float DistanceToPlayer = (PlayerPawn->GetActorLocation() - OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation()).Size();

    if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) 
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);

    if (!OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    
}
