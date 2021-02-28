// Fill out your copyright notice in the Description page of Project Settings.


#include "CLizard.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACLizard::ACLizard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialization
	GetCapsuleComponent()->InitCapsuleSize(10.0f, 10.0f);
	TargetLocation = FVector(350.0f, -400.0f, 12.325001f);
	Speed = 150.0f;

}

// Called when the game starts or when spawned
void ACLizard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACLizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldOffset(TargetLocation.GetSafeNormal() * Speed * DeltaTime);
}

// Called to bind functionality to input
void ACLizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

