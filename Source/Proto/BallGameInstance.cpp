// Fill out your copyright notice in the Description page of Project Settings.

#include "BallGameInstance.h"
#include "Containers/Array.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "Engine/EngineBaseTypes.h"

bool UBallGameInstance::SendMessage()
{

	return true;
}

void UBallGameInstance::ReceiveMessage()
{

}

void UBallGameInstance::Join(FString url, ETravelType type)
{
	APlayerController* controller = GetFirstLocalPlayerController();
	if (controller != nullptr)
	{
		controller->ClientTravel(url, type, true);
	}

}

void UBallGameInstance::OnStart()
{
}

void UBallGameInstance::Shutdown()
{
}
