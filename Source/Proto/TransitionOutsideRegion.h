// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API TransitionOutsideRegion : public CTransition
{
public:
	TransitionOutsideRegion(CStateMachine* owner);
	~TransitionOutsideRegion();
	void EntryAction();
	bool IsTriggered();

	AMainCamera* cameraRef;
};