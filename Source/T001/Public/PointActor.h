// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointActor.generated.h"

UCLASS()
class T001_API APointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	class USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	class UStaticMeshComponent* StaticMeshComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
