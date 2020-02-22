// Fill out your copyright notice in the Description page of Project Settings.

#include "StateCameraFixedTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
StateCameraFixedTrigger::StateCameraFixedTrigger(AMainCamera* owner) : CState(owner)
{
}

StateCameraFixedTrigger::~StateCameraFixedTrigger()
{
}

void StateCameraFixedTrigger::VAction()
{
	float DeltaTime = Owner->GetWorld()->GetDeltaSeconds();
	Owner->SetActorLocation(FMath::Lerp(Owner->GetActorLocation() , Owner->FixedCameraPos.GetLocation(), DeltaTime * Owner->Settings.DisplacementSpeed));
	FQuat newRotation = FQuat(UKismetMathLibrary::FindLookAtRotation(Owner->GetActorLocation(), Owner->MainTarget->GetActorLocation()));
	Owner->SetActorRotation(FQuat::Slerp(Owner->GetActorRotation().Quaternion(), newRotation, DeltaTime * Owner->Settings.DisplacementSpeed));
}

void StateCameraFixedTrigger::VEntryAction()
{
}

void StateCameraFixedTrigger::VExitAction()
{
}
