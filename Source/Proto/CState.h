// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
/**
 * 
 */
class CStateMachine;
class PROTO_API CState
{
public:
	CState(CStateMachine* owner);
	virtual ~CState();
	virtual void VAction() = 0;
	virtual void VEntryAction() = 0;
	virtual void VExitAction() = 0;
	TArray<CTransition*>& GetTransitions();

	CStateMachine* GetOwner();
private:
	CStateMachine * Owner;
	TArray<CTransition*> Transitions;
	
};
