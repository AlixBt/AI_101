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
	Speed = 0.0f;
	LizardMass = 10.0f;
	LizardForce = 50.0f;

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

	LizardAcceleration = LizardForce / LizardMass;
	Speed += LizardAcceleration * DeltaTime;

	if (LizardForce > -500.0f)
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, Speed));
	}

	LizardForce -= 1.0f;
}

// Called to bind functionality to input
void ACLizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

AStaticMeshActor* ACLizard::GetTarget() const
{
	return Target;
}

void ACLizard::CalculateDistance()
{
	FVector LizardLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 0.0f);
	FVector CubeLocation = FVector(Target->GetActorLocation().X, Target->GetActorLocation().Y, 0.0f);

	FVector Direction = CubeLocation - LizardLocation;

	if (Direction.Size() > 15.0f)
	{
		AddActorWorldOffset(GetActorForwardVector() * Speed * GetWorld()->DeltaTimeSeconds);
	}

	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Distance: %f"), Direction.Size()));
}

void ACLizard::CalculateAngle()
{
	/*FVector FowardDirection = FVector(GetActorForwardVector().X, GetActorForwardVector().Y, 0.0f);
	FVector DistanceToCube = FVector(Target->GetActorLocation().X - GetActorForwardVector().X, Target->GetActorLocation().Y - GetActorForwardVector().Y, 0.0f);

	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), FVector(GetActorLocation().X + (FowardDirection.X * 500), GetActorLocation().Y + (FowardDirection.Y * 500), GetActorLocation().Z), 50.0f, FColor::Blue);
	DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), DistanceToCube, 50.0f, FColor::Blue);

	float const Numerator = FVector::DotProduct(FowardDirection, DistanceToCube);
	float const Denominator = (FowardDirection.Size()) * (DistanceToCube.Size());

	float Angle = FGenericPlatformMath::Acos((Numerator / Denominator));*/



	FRotator OffsetRotation = UKismetMathLibrary::FindLookAtRotation(FVector(GetActorLocation().X, GetActorLocation().Y, 0.0f), FVector(Target->GetActorLocation().X, Target->GetActorLocation().Y, 0.0f));
	FRotator InterpRotation = UKismetMathLibrary::RInterpTo(GetActorRotation(), OffsetRotation, GetWorld()->DeltaTimeSeconds, 3.5f);

	SetActorRotation(InterpRotation);

	/*int ClockWise = 1;
	if (Cross(FowardDirection, DistanceToCube).Z < 0.0f)
	{
		ClockWise = -1;
	}

	AddActorWorldRotation(FRotator(0.0f, FMath::RadiansToDegrees(Angle) * ClockWise, 0.0f));*/

	/*GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, FString::Printf(TEXT("Angle: %f"), FMath::RadiansToDegrees(Angle)));*/
}

FVector ACLizard::Cross(FVector V, FVector W)
{
	float XMult = V.Y * W.Z - V.Z * W.Y;
	float YMult = V.Z * W.X - V.X * W.Z;
	float ZMult = V.X * W.Y - V.Y * W.X;

	return FVector(XMult, YMult, ZMult);
}


