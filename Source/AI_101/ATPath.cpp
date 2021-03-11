// Fill out your copyright notice in the Description page of Project Settings.


#include "ATPath.h"

// Sets default values
AATPath::AATPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialization
	m_PathIndex = 0;
}

// Called when the game starts or when spawned
void AATPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> AATPath::GetPath() const
{
	return m_Path;
}

int AATPath::GetPathIndex() const
{
	return m_PathIndex;
}

FVector AATPath::GetCurrentPathPoint() const
{
	return GetActorTransform().TransformPosition(m_Path[m_PathIndex]);
}

void AATPath::IncrementPathIndex()
{
	m_PathIndex++;
}

void AATPath::SetPathIndex(int PathIndex)
{
	m_PathIndex = PathIndex;
}

