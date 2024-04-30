// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PartielGameMode.generated.h"

UCLASS(minimalapi)
class APartielGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APartielGameMode();

	UPROPERTY(VisibleAnywhere)
	int32 Score = 0;

	UFUNCTION()
	void AddScore(int32 Value);
};



