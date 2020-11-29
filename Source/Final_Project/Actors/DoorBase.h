// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

UCLASS()
class FINAL_PROJECT_API ADoorBase : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SlidingDoor;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ForceMeter;

	UPROPERTY()
	class UBoxComponent* BoxComponent;

	void PullTheDoorUp();

	float TargetZ = 0.f;

	int CountHit = 0;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Sets default values for this actor's properties
	ADoorBase();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
