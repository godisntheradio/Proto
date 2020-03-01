// Fill out your copyright notice in the Description page of Project Settings.

#include "BallBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "MainCamera.h"
#include "BallGameInstance.h"
#include "UnrealNetwork.h"
// Sets default values
ABallBase::ABallBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("BallStaticMesh"));
	if (RootComponent == nullptr)
	{
		RootComponent = BallMesh;
	}
	else
	{
		BallMesh->SetupAttachment(RootComponent);
	}

	BallMesh->SetStaticMesh(GetBallModel());
	BallMesh->SetSimulatePhysics(true);

	cameraTransform = FTransform();

	forwardAxis = 0;
	rightAxis = 0;
	shouldBePossessed = false;
}

// Called when the game starts or when spawned
void ABallBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ABallBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABallBase, Id);
	DOREPLIFETIME(ABallBase, forwardAxis);
	DOREPLIFETIME(ABallBase, rightAxis);
	DOREPLIFETIME(ABallBase, cameraTransform);
}

void ABallBase::MoveForwardAxis(float value)
{
	forwardAxis = value;

}



#pragma optimize("", off)
void ABallBase::ApplyMovement()
{
	FVector velocity = BallMesh->GetComponentVelocity();
	FVector clamped = velocity.GetClampedToSize(0, maxVelocity);
	BallMesh->SetPhysicsLinearVelocity(clamped);
	DebugString = "velocity magnitude: " + FString::SanitizeFloat(velocity.Size());
	if (rightAxis != 0 || forwardAxis != 0)
	{
		FVector cameraForward = cameraTransform.GetRotation().GetForwardVector();
		FVector cameraRight = cameraTransform.GetRotation().GetRightVector();
		cameraForward.Z = 0;
		cameraRight.Z = 0;
		cameraForward.Normalize();
		cameraRight.Normalize();

		FVector movement = FVector(forwardAxis * cameraForward + rightAxis * cameraRight);
		BallMesh->AddForce(movement* power,NAME_None,true);
	}
}
#pragma optimize("", on)

void ABallBase::MoveRightAxis(float value)
{
	rightAxis = value;
}
void ABallBase::ChangeCameraModeTrue()
{
	changeCamera = true;
}
void ABallBase::ChangeCameraModeFalse()
{
	changeCamera = false;
}
void ABallBase::ChangeCameraModeToggle()
{
	changeCamera = !changeCamera;
}
void ABallBase::UpdateCameraTransform(FTransform transform)
{
	cameraTransform = transform;
	//UE_LOG(LogTemp, Warning, TEXT("camera location x = %.1f y = %.1f"), cameraTransform.GetLocation().X, cameraTransform.GetLocation().Y);
}
UStaticMesh * ABallBase::GetBallModel()
{
	UStaticMesh* mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Objects/Golfball/golfball.golfball"));
	return mesh;
}

bool ABallBase::GetChangeCameraMode()
{
	return changeCamera;
}

void ABallBase::BePossessed()
{
	for (TActorIterator<AMainCamera> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		UE_LOG(LogTemp, Warning, TEXT("achou camera %s |"), *ActorItr->GetName());
		ActorItr->SetTarget(this);
	}
}
