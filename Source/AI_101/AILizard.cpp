// Fill out your copyright notice in the Description page of Project Settings.


#include "AILizard.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"

AAILizard::AAILizard(FObjectInitializer const& ObjectInitializer)
{
    // Initialization
    m_Npc = nullptr;
}

void AAILizard::BeginPlay()
{
    Super::BeginPlay();
}

void AAILizard::OnPossess(APawn* const OwnPawn)
{
    Super::OnPossess(OwnPawn);

    if (OwnPawn->IsA(ACLizard::StaticClass()))
    {
        m_Npc = Cast<ACLizard>(OwnPawn);
    }
}

void AAILizard::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (m_Npc)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI controller"));
    }
}
