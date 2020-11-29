// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Final_Project/Final_ProjectCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AAmmoBase::AAmmoBase()
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
void AAmmoBase::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AAmmoBase::OnOverlapBegin);
}

// Called every frame
void AAmmoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAmmoBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr )) 
	{
		if (!OtherActor->ActorHasTag(TEXT("Projectile"))) // It could be set by Player Class but I am too lazy to do so :D
		{
			Character = Cast<AFinal_ProjectCharacter>(OtherActor);
			AddAmmoToCharacter();
			Destroy();
		}
	}
}

void AAmmoBase::AddAmmoToCharacter() 
{
    UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
    Character->SetCurrentMaxAmmo(12);
}
