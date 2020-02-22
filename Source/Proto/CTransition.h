// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/CoreUObject/Public/Templates/Casts.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
/**
 * 
 */
template <typename T>
class CState;

template<typename T>
class PROTO_API CTransition
{
public:
	CTransition(T* owner);
	virtual ~CTransition();
	virtual void EntryAction() = 0;
	virtual bool IsTriggered() = 0;
	CState<T>* GetTargetState();
	void SetTargetState(CState<T>*);
protected:
	T* Owner;
	CState<T>* TargetState;


};
template<typename T>
CTransition<T>::CTransition(T* owner)
{
	Owner = owner;
}
template<typename T>

CTransition<T>::~CTransition()
{
}

template<typename T>
CState<T>* CTransition<T>::GetTargetState()
{
	return TargetState;
}
template<typename T>
void CTransition<T>::SetTargetState(CState<T>* newTarget)
{
	TargetState = newTarget;
}
