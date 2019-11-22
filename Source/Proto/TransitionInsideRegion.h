// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
#include "MainCamera.h"

/**
 * 
 */
class PROTO_API TransitionInsideRegion : public CTransition
{
public:
	TransitionInsideRegion(CStateMachine* owner);
	~TransitionInsideRegion();
	
	void EntryAction();
	bool IsTriggered();

	AMainCamera* cameraRef;
};
