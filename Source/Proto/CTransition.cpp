// Fill out your copyright notice in the Description page of Project Settings.

#include "CTransition.h"

CTransition::CTransition(CStateMachine* owner)
{
	Owner = owner;
}

CTransition::~CTransition()
{
}

CState * CTransition::GetTargetState()
{
	return TargetState;
}

void CTransition::SetTargetState(CState * newTarget)
{
	TargetState = newTarget;
}
