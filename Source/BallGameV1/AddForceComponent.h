// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AddForceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALLGAMEV1_API UAddForceComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAddForceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere, Category = "Force")
	float ForceApplied = 70.f;
	
	UPROPERTY(EditAnywhere, Category = "Speed")
	float MaxSpeed = 900.f;

	UPROPERTY(EditAnywhere, Category = "Force")
	float StoppingMultiplier = 1.75f;

	FVector BallVelocityComponents;

	UStaticMeshComponent* StaticMeshComponent = nullptr;
	UInputComponent* InputComponent = nullptr;
	class USpringArmComponent* CameraArmComponent = nullptr;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void SetupInputComponent();

		
};
