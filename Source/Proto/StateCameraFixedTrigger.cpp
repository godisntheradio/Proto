// Fill out your copyright notice in the Description page of Project Settings.

#include "StateCameraFixedTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
StateCameraFixedTrigger::StateCameraFixedTrigger(CStateMachine * owner) : CState(owner)
{
}

StateCameraFixedTrigger::~StateCameraFixedTrigger()
{
}

void StateCameraFixedTrigger::VAction()
{
	float DeltaTime = cameraRef->GetWorld()->GetDeltaSeconds();
	cameraRef->SetActorLocation(FMath::Lerp(cameraRef->GetActorLocation() , cameraRef->FixedCameraPos.GetLocation(), DeltaTime * cameraRef->Settings.DisplacementSpeed));
	FQuat newRotation = FQuat(UKismetMathLibrary::FindLookAtRotation(cameraRef->GetActorLocation(), cameraRef->MainTarget->GetActorLocation()));
	cameraRef->SetActorRotation(FQuat::Slerp(cameraRef->GetActorRotation().Quaternion(), newRotation, DeltaTime * cameraRef->Settings.DisplacementSpeed));
}

void StateCameraFixedTrigger::VEntryAction()
{
	cameraRef = Cast<AMainCamera>(GetOwner()->User);
}

void StateCameraFixedTrigger::VExitAction()
{
}
