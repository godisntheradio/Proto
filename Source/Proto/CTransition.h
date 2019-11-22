// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/CoreUObject/Public/Templates/Casts.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
/**
 * 
 */
class CStateMachine;
class CState;
class PROTO_API CTransition
{
public:
	CTransition(CStateMachine* owner);
	virtual ~CTransition();
	virtual void EntryAction() = 0;
	virtual bool IsTriggered() = 0;
	CState* GetTargetState();
	void SetTargetState(CState*);
protected:
	CStateMachine * Owner;
	CState* TargetState;
};
