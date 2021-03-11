// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/StaticMeshActor.h"
#include "ATPath.h"
#include "CLizard.generated.h"

UCLASS()
class AI_101_API ACLizard : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI_101", meta = (AllowPrivateAccess = "true"))
	float m_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI_101", meta = (AllowPrivateAccess = "true"))
	AATPath* m_Path;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	ACLizard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Getters

	// AI_101
	void FollowPath(float DeltaTime);
};
