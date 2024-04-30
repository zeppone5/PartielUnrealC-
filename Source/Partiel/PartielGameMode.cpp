// Copyright Epic Games, Inc. All Rights Reserved.

#include "PartielGameMode.h"
#include "PartielCharacter.h"
#include "UObject/ConstructorHelpers.h"

APartielGameMode::APartielGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void APartielGameMode::AddScore(int32 Value)
{
	Score += Value;
	//debug print message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Score: " + FString::FromInt(Score)));

}
