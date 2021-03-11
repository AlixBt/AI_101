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
    m_Owner = TryGetPawnOwner();

    // Ensure that owner is valid.
    if (!m_Owner)
    {
        return;
    }

    if (m_Owner->IsA(ACLizard::StaticClass()))
    {
        m_Npc = Cast<ACLizard>(m_Owner);
    }
}

void UALizard::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    // Update loop
    if (m_Npc)
    {

    }
}
