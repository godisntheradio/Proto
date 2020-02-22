// Fill out your copyright notice in the Description page of Project Settings.

#include "TransitionRegion.h"

TransitionRegion::TransitionRegion(AMainCamera* owner) : CTransition(owner)
{
	
}

TransitionRegion::~TransitionRegion()
{
}

void TransitionRegion::EntryAction()
{
}

bool TransitionRegion::IsTriggered()
{
	return Enter == Owner->isInsideCameraRegion;
}
