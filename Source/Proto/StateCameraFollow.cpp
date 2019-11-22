// Fill out your copyright notice in the Description page of Project Settings.

#include "StateCameraFollow.h"
#include "CStateMachine.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"

StateCameraFollow::StateCameraFollow(CStateMachine * owner) : CState(owner)
{
	
}

void StateCameraFollow::VAction()
{
	float DeltaTime = cameraRef->GetWorld()->GetDeltaSeconds();
	FVector newPos = cameraRef->MainTarget->GetActorLocation() + cameraRef->Settings.Offset;
	cameraRef->SetActorLocation(FMath::Lerp(cameraRef->GetActorLocation(), newPos, DeltaTime * cameraRef->Settings.DisplacementSpeed));
	FQuat newRotation = FQuat(UKismetMathLibrary::FindLookAtRotation(cameraRef->GetActorLocation(), cameraRef->MainTarget->GetActorLocation()));
	cameraRef->SetActorRotation(FQuat::Slerp(cameraRef->GetActorRotation().Quaternion(), newRotation, DeltaTime * cameraRef->Settings.DisplacementSpeed));
}

void StateCameraFollow::VEntryAction()
{
	cameraRef = Cast<AMainCamera>(GetOwner()->User);
}

void StateCameraFollow::VExitAction()
{
}
