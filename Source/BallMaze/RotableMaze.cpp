// Fill out your copyright notice in the Description page of Project Settings.


#include "RotableMaze.h"

// Sets default values
ARotableMaze::ARotableMaze()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

}

// Called when the game starts or when spawned
void ARotableMaze::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotableMaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARotableMaze::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("ForwardInput", this, &ARotableMaze::MoveForward);
	InputComponent->BindAxis("HorizontalInput", this, &ARotableMaze::MoveHorizontal);

}
void ARotableMaze::MoveForward(float value)
{
	/*FVector forceToAdd = FVector(1, 0, 0) * moveSpeed * value;
	Mesh->AddForce(forceToAdd);*/


	AddActorLocalRotation(FRotator(0, 0, FMath::Clamp(value, -90.0f, 90.0f)));

}

void ARotableMaze::MoveHorizontal(float value)
{
	AddActorLocalRotation(FRotator(FMath::Clamp(value, -90.0f, 90.0f), 0, 0));
	
}

