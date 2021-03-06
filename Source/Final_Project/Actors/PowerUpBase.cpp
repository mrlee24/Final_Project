// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"

// Sets default values
APowerUpBase::APowerUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	BoxComponent->SetCollisionProfileName("Trigger");

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	BaseMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APowerUpBase::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APowerUpBase::OnOverlapBegin);
}

// Called every frame
void APowerUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerUpBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr )) 
	{
		if (!OtherActor->ActorHasTag(TEXT("Projectile"))) // It could be set by Player Class but I am too lazy to do so :D
		{
			Character = Cast<ACharacter>(OtherActor);

			PowerUp();
			Destroy();
		}
	}
}

void APowerUpBase::PowerUp() { Character->JumpMaxCount = 2; }
