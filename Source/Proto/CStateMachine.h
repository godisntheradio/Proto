// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CState.h"


/**
 * 
 */
class PROTO_API CStateMachine
{
public:
	CStateMachine(AActor* stateMachineUser);
	~CStateMachine();

	CState* InitialState;
	CState* CurrentState;
	void Start();
	void Update();
	void AddState(CState* newState);
	void SetInitialState(CState* initState);

	AActor* User;
private:
	TArray<CState*> StateList;
};
