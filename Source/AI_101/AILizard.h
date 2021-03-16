// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CLizard.h"
#include "AILizard.generated.h"

/**
 * 
 */
UCLASS()
class AI_101_API AAILizard : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY()
	ACLizard* m_Npc;

public:
	// Constructor
	AAILizard(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get());

	// AAIController functions
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* const OwnPawn) override;
	virtual void Tick(float DeltaSeconds) override;
};
