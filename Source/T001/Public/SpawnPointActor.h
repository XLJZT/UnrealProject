// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointActor.h"
#include "SpawnPointActor.generated.h"

UCLASS()
class T001_API ASpawnPointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPointActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	class USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	class UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	class UBoxComponent* BoxComponent;
	//生成的类型
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SpawnPoint")
	TSubclassOf<APointActor> PointActor;
	//间隔长度
	UPROPERTY(EditAnywhere,Category="SpawnPoint")
	float SpanLen = 20.0f;
	//点的边长,初始设置应为40
	UPROPERTY(EditAnywhere,Category="SpawnPoint")
	float PointLen = 40.0f;
	//轴上数量
	UPROPERTY(EditAnywhere,Category="SpawnPoint")
	int32 X_num = 10;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreatePoint();
private:
	float SquareLen;
};
