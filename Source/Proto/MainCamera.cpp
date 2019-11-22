// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCamera.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "StateCameraFollow.h"
#include "TransitionCameraChangePress.h"
#include "TransitionInsideRegion.h"
#include "TransitionOutsideRegion.h"
#include "StateCameraFixed.h"
#include "StateCameraFixedTrigger.h"
// Sets default values
AMainCamera::AMainCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cameraRef = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	cameraRef->SetupAttachment(RootComponent);
	Settings = FCameraSettings();

	stateMachine = new CStateMachine(this);
	StateCameraFollow* cameraFollow = new StateCameraFollow(stateMachine);
	TransitionCameraChangePress* PressToFixed = new TransitionCameraChangePress(stateMachine);
	TransitionInsideRegion* triggerToFixed = new TransitionInsideRegion(stateMachine);

	StateCameraFixed* cameraFixed = new StateCameraFixed(stateMachine);
	TransitionCameraChangePress* PressToFollow = new TransitionCameraChangePress(stateMachine,true);

	StateCameraFixedTrigger* cameraFixedTrigger = new StateCameraFixedTrigger(stateMachine);
	TransitionOutsideRegion* triggerToFollow = new TransitionOutsideRegion(stateMachine);
	
	PressToFixed->SetTargetState(cameraFixed);
	cameraFollow->GetTransitions().Add(PressToFixed);
	triggerToFixed->SetTargetState(cameraFixedTrigger);
	cameraFollow->GetTransitions().Add(triggerToFixed);
	
	PressToFollow->SetTargetState(cameraFollow);
	cameraFixed->GetTransitions().Add(PressToFollow);

	triggerToFollow->SetTargetState(cameraFollow);
	cameraFixedTrigger->GetTransitions().Add(triggerToFollow);



	stateMachine->SetInitialState(cameraFollow);
	stateMachine->AddState(cameraFollow);
	stateMachine->AddState(cameraFixed);
	stateMachine->AddState(cameraFixedTrigger);
	stateMachine->Start();
}

// Called when the game starts or when spawned
void AMainCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (stateMachine && MainTarget)
	{
		stateMachine->Update();
		
	}
	
}

void AMainCamera::SetTarget(ABallBase * ball)
{
	MainTarget = ball;
}
