// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PowerUpBase.h"
#include "AmmoBase.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_PROJECT_API AAmmoBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* BaseMesh;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere)
	class AFinal_ProjectCharacter* Character;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class USoundBase* PickupSound;

public:	
	// Sets default values for this actor's properties
	AAmmoBase();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddAmmoToCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
