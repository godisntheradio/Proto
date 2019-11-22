// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionCameraChangePress.h"

TransitionCameraChangePress::TransitionCameraChangePress(CStateMachine* owner, bool invert) : CTransition(owner)
{
	inverse = invert;
	cameraRef = Cast<AMainCamera>(Owner->User);
}

TransitionCameraChangePress::~TransitionCameraChangePress()
{
	
}

void TransitionCameraChangePress::EntryAction()
{
	
}

bool TransitionCameraChangePress::IsTriggered()
{
	if (inverse)
	{
		return !cameraRef->MainTarget->GetChangeCameraMode();
	}
	else
	{	
		return cameraRef->MainTarget->GetChangeCameraMode();
	}
}
