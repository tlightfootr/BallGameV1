// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveCamera.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALLGAMEV1_API UMoveCamera : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveCamera();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UStaticMeshComponent* StaticMesh = nullptr;
	class USpringArmComponent* CameraArmComponent = nullptr;
	UInputComponent* InputComponent = nullptr;

	void SetupInputComponent();
	void RotateCameraCW();
	void RotateCameraCCW();
};
