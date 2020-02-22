// Fill out your copyright notice in the Description page of Project Settings.

#include "StateCameraFollow.h"
#include "CStateMachine.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"

StateCameraFollow::StateCameraFollow(AMainCamera* owner) : CState(owner)
{
	
}

void StateCameraFollow::VAction()
{
	float DeltaTime = Owner->GetWorld()->GetDeltaSeconds();
	FVector newPos = Owner->MainTarget->GetActorLocation() + Owner->Settings.Offset;
	Owner->SetActorLocation(FMath::Lerp(Owner->GetActorLocation(), newPos, DeltaTime * Owner->Settings.DisplacementSpeed));
	FQuat newRotation = FQuat(UKismetMathLibrary::FindLookAtRotation(Owner->GetActorLocation(), Owner->MainTarget->GetActorLocation()));
	Owner->SetActorRotation(FQuat::Slerp(Owner->GetActorRotation().Quaternion(), newRotation, DeltaTime * Owner->Settings.DisplacementSpeed));
}

void StateCameraFollow::VEntryAction()
{
}

void StateCameraFollow::VExitAction()
{
}
