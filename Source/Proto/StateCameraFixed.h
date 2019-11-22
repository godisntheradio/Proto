// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CState.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API StateCameraFixed : public CState
{
public:
	StateCameraFixed(CStateMachine* owner);
	~StateCameraFixed();
	void VAction();
	void VEntryAction();
	void VExitAction();

	AMainCamera* cameraRef;
};
