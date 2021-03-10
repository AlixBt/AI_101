// Fill out your copyright notice in the Description page of Project Settings.


#include "ALizard.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/KismetMathLibrary.h"

UALizard::UALizard()
{
}

void UALizard::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // Cache for later use
    Owner = TryGetPawnOwner();

    // Ensure that owner is valid.
    if (!Owner)
    {
        return;
    }

    if (Owner->IsA(ACLizard::StaticClass()))
    {
        Npc = Cast<ACLizard>(Owner);
    }
}

void UALizard::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    // Update loop
    if (Npc)
    {
        
        TargetLocation = UKismetMathLibrary::VInterpTo(TargetLocation, Npc->GetTarget()->GetActorLocation(), DeltaSeconds, 6.0f);
    }
}
