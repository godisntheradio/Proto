// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API TransitionRegion : public CTransition<AMainCamera>
{
public:
	TransitionRegion(AMainCamera* owner);
	~TransitionRegion();
	void EntryAction();
	bool IsTriggered();

	bool Enter;
};
