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
	StateCameraFixed* cameraFixed = new StateCameraFixed(this);
	StateCameraFixedTrigger* cameraFixedTrigger = new StateCameraFixedTrigger(this);

	TransitionCameraChangePress* PressToFixed = new TransitionCameraChangePress(this);
	TransitionCameraChangePress* PressToFollow = new TransitionCameraChangePress(this,true);
	TransitionRegion* triggerToFixed = new TransitionRegion(this);
	triggerToFixed->Enter = true;
	TransitionRegion* triggerToFollow = new TransitionRegion(this);
	triggerToFollow->Enter = false;
	
	cameraFollow->AddTransitions(PressToFixed);
	PressToFixed->SetTargetState(cameraFixed);

	cameraFixed->AddTransitions(PressToFollow);
	PressToFollow->SetTargetState(cameraFollow);

	cameraFixedTrigger->AddTransitions(triggerToFollow);
	triggerToFollow->SetTargetState(cameraFollow);

	cameraFixed->AddTransitions(triggerToFixed);
	cameraFollow->AddTransitions(triggerToFixed);
	triggerToFixed->SetTargetState(cameraFixedTrigger);

	stateMachine->AddState(cameraFollow);
	stateMachine->AddState(cameraFixed);
	stateMachine->AddState(cameraFixedTrigger);

	stateMachine->Start(cameraFollow);
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
