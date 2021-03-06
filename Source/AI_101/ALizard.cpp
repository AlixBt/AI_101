// Fill out your copyright notice in the Description page of Project Settings.


#include "ALizard.h"

UALizard::UALizard()
{
    TargetLocation = FVector(500.0f, 0.0f, 0.0f);
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
        TargetLocation = Npc->GetTargetLocation();
    }
}
