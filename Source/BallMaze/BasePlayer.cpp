// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include <algorithm>
#include <iostream>
// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	/*SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");*/

	RootComponent = Mesh;
	/*SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);*/

	//Mesh->SetSimulatePhysics(true);
	bUseControllerRotationYaw = false;
	
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("ForwardInput", this, &ABasePlayer::MoveForward);
	InputComponent->BindAxis("HorizontalInput", this, &ABasePlayer::MoveHorizontal);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayer::Jump);
}

void ABasePlayer::MoveForward(float value)
{
	/*FVector forceToAdd = FVector(1, 0, 0) * moveSpeed * value;
	Mesh->AddForce(forceToAdd);*/
	
	
	AddActorLocalRotation(FRotator(0, 0, FMath::Clamp(value, -90.0f,90.0f)));
	
}

void ABasePlayer::MoveHorizontal(float value)
{
	/*FVector forceToAdd = FVector(0, 1, 0) * moveSpeed * value;
	Mesh->AddForce(forceToAdd);*/
	AddActorLocalRotation(FRotator(FMath::Clamp(value, -90.0f, 90.0f), 0, 0));
	//Mesh->AddRelativeRotation(newRotation, false, 0, ETeleportType::None);
}



