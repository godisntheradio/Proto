// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionInsideRegion.h"
#include "CStateMachine.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Engine/World.h"
TransitionInsideRegion::TransitionInsideRegion(CStateMachine* owner) : CTransition(owner)
{
	cameraRef = Cast<AMainCamera>(Owner->User);
}

TransitionInsideRegion::~TransitionInsideRegion()
{
	
}

void TransitionInsideRegion::EntryAction()
{
	
}

bool TransitionInsideRegion::IsTriggered()
{
	return cameraRef->isInsideCameraRegion;
}