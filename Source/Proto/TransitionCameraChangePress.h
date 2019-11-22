// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API TransitionCameraChangePress : public CTransition
{
public:
	TransitionCameraChangePress(CStateMachine* owner, bool invert = false);
	~TransitionCameraChangePress();

	void EntryAction();
	bool IsTriggered();

	AMainCamera* cameraRef;
	bool inverse;
};
