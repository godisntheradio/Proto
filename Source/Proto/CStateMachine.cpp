// Fill out your copyright notice in the Description page of Project Settings.

#include "CStateMachine.h"



CStateMachine::CStateMachine(AActor* stateMachineUser)
{
	StateList = TArray<CState*>();
	User = stateMachineUser;
}

CStateMachine::~CStateMachine()
{
}

void CStateMachine::Start()
{
	CurrentState = InitialState;
	CurrentState->VEntryAction();
}

void CStateMachine::Update()
{
	if (CurrentState)
	{
		CTransition* triggeredTransition = nullptr;
		for (size_t i = 0; i < CurrentState->GetTransitions().Num(); i++)
		{
			if (CurrentState->GetTransitions()[i]->IsTriggered())
			{
				triggeredTransition = CurrentState->GetTransitions()[i];
			}
		}

		if (triggeredTransition)
		{
			triggeredTransition->EntryAction();
			CState* targetState = triggeredTransition->GetTargetState();
			CurrentState->VExitAction();
			targetState->VEntryAction();
			CurrentState = targetState;
		}
		else
		{
			CurrentState->VAction();
		}
	}
}

void CStateMachine::AddState(CState * newState)
{
	StateList.Add(newState);
}

void CStateMachine::SetInitialState(CState * initState)
{
	InitialState = initState;
}
