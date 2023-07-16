// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdGameModeBase.h"
#include "MainCharacter.h"
#include "MainPlayerController.h"

AThirdGameModeBase::AThirdGameModeBase()
{
	DefaultPawnClass = AMainCharacter::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
}

