// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"
#include "Ball.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
APickupItem::APickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>("TriggerCapsule");

	RootComponent = Mesh;
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnOverlapBegin);
	RollValue = 1.0f;
	
}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FQuat QuatRotation = FQuat(FRotator(0, RollValue, 0));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);


}
int score = 0;
void APickupItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult)
{
	
	

	if(Cast<ABall>(OtherActor) != nullptr)
	{
		Destroy();
		score++;
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("SCORE: %d"), score));

	}

	if (score == 20)
	{
		UGameplayStatics::OpenLevel(this, "GameOver");
		score = 0;
	}
}

