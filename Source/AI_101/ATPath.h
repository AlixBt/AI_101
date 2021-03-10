// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATPath.generated.h"

UCLASS()
class AI_101_API AATPath : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
	TArray<FVector> Path;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AATPath();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
