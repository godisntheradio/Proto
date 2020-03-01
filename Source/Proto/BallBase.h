// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"

#include "BallBase.generated.h"

UCLASS()
class PROTO_API ABallBase : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//
	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void MoveForwardAxis(float value);

	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void MoveRightAxis(float value);

	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void ChangeCameraModeTrue();

	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void ChangeCameraModeFalse();

	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void ChangeCameraModeToggle();

	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void UpdateCameraTransform(FTransform transform);
	// --------------
	// RPC's

	//
	UStaticMesh* GetBallModel();
	UFUNCTION(BlueprintCallable, Category = "CameraShananigans")
	bool GetChangeCameraMode();


	UFUNCTION(BlueprintCallable, Category = "BallMovement")
	void ApplyMovement();
	UFUNCTION(BlueprintCallable, Category = "Initializer")
	void BePossessed();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Item Config")
		UStaticMeshComponent* BallMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Debug")
		FString DebugString;
	UPROPERTY(BlueprintReadWrite, Replicated)
		int Id;

	UPROPERTY(BlueprintReadWrite, Replicated)
	FTransform cameraTransform;
protected:
	//input variables
	UPROPERTY(BlueprintReadWrite, Replicated)
	float forwardAxis;
	UPROPERTY(BlueprintReadWrite, Replicated)
	float rightAxis;

	bool changeCamera;
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ball Properties")
		float power;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ball Properties")
		float maxVelocity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ball Properties")
		bool shouldBePossessed;
	
};
