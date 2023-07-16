// Fill out your copyright notice in the Description page of Project Settings.


#include "PointActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h"

DECLARE_LOG_CATEGORY_CLASS(LOG_POINT,All,All)
// Sets default values
APointActor::APointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APointActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Green,GetName());
}

// Called every frame
void APointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

