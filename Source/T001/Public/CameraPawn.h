// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class T001_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();
	UPROPERTY(EditAnywhere,Category="Variable")
	float MoveVelocity;
	UPROPERTY(EditAnywhere,Category="Variable")
	float MouseVelocity;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
	class USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
	class UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
	class USpringArmComponent* SpringArmComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveForward(float val);
	void MoveRight(float val);
	void MouseTurn(float val);
	void MouseLookup(float val);
	void MoveUp(float val);
	
	void PressSpawnSquare();
};
