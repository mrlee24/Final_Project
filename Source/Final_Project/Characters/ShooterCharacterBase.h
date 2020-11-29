// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacterBase.generated.h"

UCLASS()
class FINAL_PROJECT_API AShooterCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USceneComponent* FP_MuzzleLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class AFinal_ProjectProjectile> ProjectileClass;

public:
	// Sets default values for this character's properties
	AShooterCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	void Shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
