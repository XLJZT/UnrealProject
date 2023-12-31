// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPointActor.h"

#include <SceneExport.h>

#include "Components/BoxComponent.h"

// Sets default values
ASpawnPointActor::ASpawnPointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(GetRootComponent());
	
	BoxComponent->SetBoxExtent(FVector(PointLen));
	//生成Point的边长
	SquareLen = X_num * (SpanLen+PointLen) - SpanLen;
}

// Called when the game starts or when spawned
void ASpawnPointActor::BeginPlay()
{
	Super::BeginPlay();
	//CreatePoint();
}

// Called every frame
void ASpawnPointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ASpawnPointActor::CreatePoint()
{
	if(GetWorld())
	{
		const FVector SpawnLoction = GetActorLocation();
		const FVector InitLoc = SpawnLoction - FVector(SquareLen/2 + PointLen/2);
		for (int32 i =0;i<X_num;i++)
		{
			for(int32 j =0;j<X_num;++j)
			{
				for(int32 k =0;k<X_num;++k)
				{
					FVector NewLoc = InitLoc + FVector(i,j,k)*(SpanLen+PointLen);
					AddNoiseOffset(NewLoc,i,j,k,X_num);
					const FTransform Transform = FTransform(FRotator::ZeroRotator,NewLoc);
					APointActor* Point = GetWorld()->SpawnActor<APointActor>(PointActor,Transform);
					//GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Green,Point->GetName());
					
				} 
			}
		}
	}
}

void ASpawnPointActor::AddNoiseOffset(FVector &Loc,int32 X,int32 Y,int32 Z,int32 Num)
{
	//矩阵最边上的六个面不加噪声
	if(X==0||Y==0||Z==0) return;
	if(X==Num-1||Y==Num-1||Z==Num-1) return;
	//生成三维噪声
	const FVector NoiseVector = FVector( FMath::FRandRange(-NoiseOffset, NoiseOffset),
						FMath::FRandRange(-NoiseOffset, NoiseOffset),
						FMath::FRandRange(-NoiseOffset, NoiseOffset));
	Loc = Loc + NoiseVector;
}
