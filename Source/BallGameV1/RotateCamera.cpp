// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateCamera.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
URotateCamera::URotateCamera()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateCamera::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
	CameraArmComponent = GetOwner()->FindComponentByClass<USpringArmComponent>();
	InitialRotation = CameraArmComponent->GetComponentRotation();
}

void URotateCamera::SetupInputComponent()
{
	// Getting input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		// Binding functions to keypresses
		InputComponent->BindAction(TEXT("RotateCameraCW"), IE_Pressed, this, &URotateCamera::RotateCameraCW);
		InputComponent->BindAction(TEXT("RotateCameraCCW"), IE_Pressed, this, &URotateCamera::RotateCameraCCW);
	}
}

// Called every frame
void URotateCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//CameraArmComponent->SetWorldRotation(InitialRotation);

	FRotator t = CameraArmComponent->GetTargetRotation();
	UE_LOG(LogTemp, Error, TEXT("%f, %f, %f"), t.Pitch, t.Yaw, t.Roll);

}

void URotateCamera::RotateCameraCW()
{

}

void URotateCamera::RotateCameraCCW()
{
	
}

