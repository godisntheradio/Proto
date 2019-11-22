// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CState.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API StateCameraFixedTrigger : public CState
{
public:
	StateCameraFixedTrigger(CStateMachine* owner);
	~StateCameraFixedTrigger();

	void VAction();
	void VEntryAction();
	void VExitAction();

	AMainCamera* cameraRef;

};
