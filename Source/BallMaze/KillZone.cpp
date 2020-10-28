// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"
#include "Ball.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKillZone::AKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::OnOverlapBegin);
	

}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Black, TEXT("TEST"));

	if (Cast<ABall>(OtherActor) != nullptr)
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);

	}
}

