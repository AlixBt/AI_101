// Fill out your copyright notice in the Description page of Project Settings.


#include "CLizard.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACLizard::ACLizard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialization
	GetCapsuleComponent()->InitCapsuleSize(10.0f, 10.0f);
	m_Speed = 200.0f;
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

	FollowPath(DeltaTime);
}

void ACLizard::FollowPath(float DeltaTime)
{
	// We increment the path index when we reached the previous point
	FVector CurrentPoint = m_Path->GetCurrentPathPoint();

	FVector NpcLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0.0f);
	FVector NpcToPointDistance = CurrentPoint - NpcLocation;

	if (NpcToPointDistance.Size() < 100.0f)
	{
		m_Path->IncrementPathIndex();
	}

	// We reset the path index once we are at the last point
	if (m_Path->GetPathIndex() > m_Path->GetPath().Num() - 1)
	{
		m_Path->SetPathIndex(0);
	}

	// We rotate and translate the NPC towards the current point
	FRotator NpcRotation = GetActorRotation();
	FRotator NextNpcRotation = UKismetMathLibrary::FindLookAtRotation(NpcLocation, CurrentPoint);



	SetActorRotation(UKismetMathLibrary::RInterpTo(NpcRotation, NextNpcRotation, DeltaTime, 2.5f));
	AddActorWorldOffset(GetActorForwardVector() * m_Speed * DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Size: %f"), NpcToPointDistance.Size()));
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, FString::Printf(TEXT("NPC: %s"), *NpcLocation.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, FString::Printf(TEXT("Current point: %s"), *CurrentPoint.ToString()));
}


