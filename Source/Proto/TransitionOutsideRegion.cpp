// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionOutsideRegion.h"

TransitionOutsideRegion::TransitionOutsideRegion(CStateMachine* owner) : CTransition(owner)
{
	cameraRef = Cast<AMainCamera>(Owner->User);
}

TransitionOutsideRegion::~TransitionOutsideRegion()
{
}

void TransitionOutsideRegion::EntryAction()
{
}

bool TransitionOutsideRegion::IsTriggered()
{
	return !cameraRef->isInsideCameraRegion;
}
