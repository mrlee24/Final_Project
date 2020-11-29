// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Final_Project/HealthComponent.h"
// Sets default values
ADoorBase::ADoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	RootComponent = DoorFrame;

	SlidingDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sliding Door"));
	SlidingDoor->SetupAttachment(RootComponent);

	ForceMeter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Force Meter"));
	ForceMeter->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComponent->InitBoxExtent(FVector(80.f, 80.f, 80.f));
	BoxComponent->SetupAttachment(ForceMeter);
}

// Called when the game starts or when spawned
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnOverlapBegin);
}

// Called every frame
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorBase::PullTheDoorUp() 
{
	if (CountHit > 5) return;
	
	TargetZ += 40.f;
	FVector NewLocation = {0.f, 45.f, TargetZ};
	SlidingDoor->SetRelativeLocation(NewLocation);
}

void ADoorBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr )) 
	{
		if (OtherActor->ActorHasTag(TEXT("Projectile")))
		{
			UE_LOG(LogTemp, Warning, TEXT("Projectile"));
			CountHit++;
			OtherActor->Destroy();
			PullTheDoorUp();
		}
	}
}
