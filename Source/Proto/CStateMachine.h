// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Array.h"
#include "CState.h"


/**
 * 
 */
template<typename T>
class PROTO_API CStateMachine
{
public:
	CStateMachine(T* stateMachineUser);
	~CStateMachine();

	CState<T>* InitialState;
	CState<T>* CurrentState;
	void Start(CState<T>* startState);
	void Update();
	CStateMachine<T>* AddState(CState<T>* newState);

	T* User;
private:
	TArray<CState<T>*> StateList;
};

template <typename T>
CStateMachine<T>::CStateMachine(T* stateMachineUser)
{
	StateList = TArray<CState<T>*>();
	User = stateMachineUser;
}
template <typename T>
CStateMachine<T>::~CStateMachine()
{
}
template <typename T>
void CStateMachine<T>::Start(CState<T>* startState)
{
	InitialState = startState;
	CurrentState = InitialState;
	CurrentState->VEntryAction();
}
template <typename T>
void CStateMachine<T>::Update()
{
	if (CurrentState)
	{
		CTransition<T>* triggeredTransition = nullptr;
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
			CState<T>* targetState = triggeredTransition->GetTargetState();
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
template <typename T>
CStateMachine<T>* CStateMachine<T>::AddState(CState<T>* newState)
{
	StateList.Add(newState);
	return this;
}