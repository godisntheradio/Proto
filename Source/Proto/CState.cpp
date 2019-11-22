// Fill out your copyright notice in the Description page of Project Settings.

#include "CState.h"

CState::CState(CStateMachine* o)
{
	Owner = o;
	Transitions = TArray<CTransition*>();
}

CState::~CState()
{
}

TArray<CTransition*>& CState::GetTransitions()
{
	// TODO: insert return statement here
	return Transitions;
}

CStateMachine * CState::GetOwner()
{
	return Owner;
}