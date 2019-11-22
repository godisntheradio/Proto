// Fill out your copyright notice in the Description page of Project Settings.

#include "StateCameraFixed.h"
#include "CStateMachine.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
StateCameraFixed::StateCameraFixed(CStateMachine* owner) : CState(owner)
{

}

StateCameraFixed::~StateCameraFixed()
{
}

void StateCameraFixed::VAction()
{
}

void StateCameraFixed::VEntryAction()
{
}

void StateCameraFixed::VExitAction()
{
}
