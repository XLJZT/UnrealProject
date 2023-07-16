// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "SpawnPointActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("StaticMeshComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	SetRootComponent(SceneComponent);
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);
	
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&ACameraPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ACameraPawn::MoveRight);
	PlayerInputComponent->BindAxis("MouseTurn",this,&ACameraPawn::MouseTurn);
	PlayerInputComponent->BindAxis("MouseLookup",this,&ACameraPawn::MouseLookup);
	PlayerInputComponent->BindAction("SpawnSquare",IE_Pressed,this,&ACameraPawn::PressSpawnSquare);
}

void ACameraPawn::MoveForward(float val)
{
	const FVector Dir = RootComponent->GetForwardVector();
	const FVector NewLoc = RootComponent->GetComponentTransform().GetLocation() + Dir * val * MoveVelocity;
	RootComponent->SetRelativeLocation(NewLoc);
}

void ACameraPawn::MoveRight(float val)
{
	const FVector Dir = RootComponent->GetRightVector();
	const FVector NewLoc = RootComponent->GetComponentTransform().GetLocation() + Dir * val * MoveVelocity;
	RootComponent->SetRelativeLocation(NewLoc);
}

void ACameraPawn::MouseTurn(float val)
{
	const FRotator Dir = RootComponent->GetRelativeRotation();
	const FRotator NewRot = Dir + FRotator(0,val * MouseVelocity,0);
	RootComponent->SetRelativeRotation(NewRot);
}

void ACameraPawn::MouseLookup(float val)
{
	const FRotator Dir = RootComponent->GetRelativeRotation();
	const FRotator NewRot = Dir + FRotator(val * MouseVelocity,0,0);
	RootComponent->SetRelativeRotation(NewRot);
}
void ACameraPawn::MoveUp(float val)
{
	const FVector NewLoc = RootComponent->GetComponentLocation() + FVector(0,0,val * MoveVelocity);
	RootComponent->SetRelativeLocation(NewLoc);
}

//按空格生成正方体
void ACameraPawn::PressSpawnSquare()
{
	const FRotator Dir = RootComponent->GetRelativeRotation();
}

