// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCamera.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "StateCameraFollow.h"
#include "TransitionCameraChangePress.h"
#include "TransitionRegion.h"
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

	stateMachine = new CStateMachine<AMainCamera>(this);
	StateCameraFollow* cameraFollow = new StateCameraFollow(this);
	TransitionCameraChangePress* PressToFixed = new TransitionCameraChangePress(this);
	TransitionRegion* triggerToFixed = new TransitionRegion(this);
	triggerToFixed->Enter = true;

	StateCameraFixed* cameraFixed = new StateCameraFixed(this);
	TransitionCameraChangePress* PressToFollow = new TransitionCameraChangePress(this,true);

	StateCameraFixedTrigger* cameraFixedTrigger = new StateCameraFixedTrigger(this);
	TransitionRegion* triggerToFollow = new TransitionRegion(this);
	triggerToFixed->Enter = false;
	
	PressToFixed->SetTargetState(cameraFixed);
	cameraFollow->GetTransitions().Add(PressToFixed);
	triggerToFixed->SetTargetState(cameraFixedTrigger);
	cameraFollow->GetTransitions().Add(triggerToFixed);
	
	PressToFollow->SetTargetState(cameraFollow);
	cameraFixed->GetTransitions().Add(PressToFollow);

	triggerToFollow->SetTargetState(cameraFollow);
	cameraFixedTrigger->GetTransitions().Add(triggerToFollow);

	stateMachine->AddState(cameraFollow);
	stateMachine->AddState(cameraFixed);
	stateMachine->AddState(cameraFixedTrigger);
	stateMachine->Start(cameraFixed);
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
