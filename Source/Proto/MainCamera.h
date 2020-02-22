// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "BallBase.h"
#include "CStateMachine.h"
#include "MainCamera.generated.h"
USTRUCT(BlueprintType)
struct FCameraSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Params")
		float Speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Params")
		float DisplacementSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Params")
		FVector Offset;
	FCameraSettings()
	{
		Speed = 0;
		DisplacementSpeed = 0;
		Offset = FVector::ZeroVector;
	}
};

UCLASS()
class PROTO_API AMainCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void SetTarget(ABallBase* ball);


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Params")
		ABallBase* MainTarget;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
		FCameraSettings Settings;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "OwningCamera")
		UCameraComponent* cameraRef;

	UPROPERTY(BlueprintReadWrite)
		FTransform FixedCameraPos;
	UPROPERTY(BlueprintReadWrite)
		bool isInsideCameraRegion;

	CStateMachine<AMainCamera>* stateMachine;
};


