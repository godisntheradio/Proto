// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionCameraChangePress.h"

TransitionCameraChangePress::TransitionCameraChangePress(AMainCamera* owner, bool invert) : CTransition(owner)
{
	inverse = invert;
}

TransitionCameraChangePress::~TransitionCameraChangePress()
{
	
}

void TransitionCameraChangePress::EntryAction()
{
	
}

bool TransitionCameraChangePress::IsTriggered()
{
	return inverse == Owner->MainTarget->GetChangeCameraMode();
}
