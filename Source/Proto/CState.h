// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTransition.h"
/**
 * 
 */
template<typename T>
class PROTO_API CState
{
public:
	CState(T* owner);
	virtual ~CState();
	virtual void VAction() = 0;
	virtual void VEntryAction() = 0;
	virtual void VExitAction() = 0;
	TArray<CTransition<T>*>& GetTransitions();
protected:
	T* Owner;
	TArray<CTransition<T>*> Transitions;
	
};

template<typename T>
CState<T>::CState(T* o)
{
	Owner = o;
	Transitions = TArray<CTransition<T>*>();
}

template<typename T>
CState<T>::~CState()
{
}

template<typename T>
TArray<CTransition<T>*>& CState<T>::GetTransitions()
{
	return Transitions;
}
