// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Health = DefaultHealth;
	Owner = GetOwner();

	if (Owner) 
	{
		BaseMesh = Owner->FindComponentByClass<UStaticMeshComponent>();
		UE_LOG(LogTemp, Warning, TEXT("BaseMesh: %s"), *BaseMesh->GetName());
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) 
{
	float DamageToApply = Damage;

	if(DamageToApply == 0 || Health <= 0) return;

	Health = FMath::Clamp(Health - DamageToApply, 0.f, DefaultHealth);

	// Owner->PullTheDoorUp();

	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
}

