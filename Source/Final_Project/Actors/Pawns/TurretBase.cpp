// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Final_ProjectProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Final_ProjectCharacter.h"
#include "Engine/World.h"

// Sets default values
ATurretBase::ATurretBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned
void ATurretBase::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandler, this, &ATurretBase::CheckFireCondition, FireRate, true);

	PlayerCharacter = Cast<AFinal_ProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void ATurretBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
    if (!PlayerCharacter || ReturnDistanceToPlayer() > FireRange) {return;}

    RotateTurret(PlayerCharacter->GetActorLocation());
}

void ATurretBase::RotateTurret(FVector LookAtTarget) 
{
	FVector LookAtTargetCleaned = FVector(
		LookAtTarget.X,
		LookAtTarget.Y,
		TurretMesh->GetComponentLocation().Z);

	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

void ATurretBase::Fire() 
{
	if (ProjectileClass)
	{
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotaion = ProjectileSpawnPoint->GetComponentRotation();

		AFinal_ProjectProjectile* TempProjectile = GetWorld()->SpawnActor<AFinal_ProjectProjectile>(ProjectileClass, SpawnLocation, SpawnRotaion);
		TempProjectile->SetOwner(this);
	}
}

void ATurretBase::CheckFireCondition() 
{
    if (!PlayerCharacter) { return; }

    if (ReturnDistanceToPlayer() < FireRange)
        Fire();
}

float ATurretBase::ReturnDistanceToPlayer() 
{
	if (!PlayerCharacter)
        return 0.f;

    return FVector::Dist(PlayerCharacter->GetActorLocation(), this->GetActorLocation());
}
