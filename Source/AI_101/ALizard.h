// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CLizard.h"
#include "ALizard.generated.h"

/**
 * 
 */
UCLASS()
class AI_101_API UALizard : public UAnimInstance
{
	GENERATED_BODY()

	// Utility
	APawn* m_Owner;
	ACLizard* m_Npc;

	// Procedural

public:
	// Constructors
	UALizard();

	// UAnimInstance functions
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
