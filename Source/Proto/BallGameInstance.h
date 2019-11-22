// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BallGameInstance.generated.h"
/**
 * 
 */
UCLASS()
class PROTO_API UBallGameInstance : public UGameInstance
{
	GENERATED_BODY()
public: 
		int NumberOfGames;

		bool SendMessage();
		void ReceiveMessage();
		UFUNCTION(BlueprintCallable)
		void Join(FString url, ETravelType type);

		void OnStart();
		void Shutdown();
};
