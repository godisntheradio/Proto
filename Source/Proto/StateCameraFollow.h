// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CState.h"
#include "MainCamera.h"
/**
 * 
 */
class PROTO_API StateCameraFollow : public CState<AMainCamera>
{
public:
	StateCameraFollow(AMainCamera* owner);
	void VAction();
	void VEntryAction();
	void VExitAction();
};
