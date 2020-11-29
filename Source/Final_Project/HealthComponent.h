// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINAL_PROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.f;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "false"))
	float Health = 0.f;

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	AActor* Owner;
	
	class UStaticMeshComponent* BaseMesh;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
