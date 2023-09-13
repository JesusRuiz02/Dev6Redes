// Fill out your copyright notice in the Description page of Project Settings.


#include "Zone.h"

#include "Components/SphereComponent.h"
#include "Dev6Red/Dev6RedCharacter.h"

// Sets default values
AZone::AZone()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);
}



// Called when the game starts or when spawned
void AZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	ADev6RedCharacter* Player = Cast<ADev6RedCharacter>(OtherActor);

	if (Player)
	{
		if (Player->score >= 5)
		{
			Player->CompleteLevel();
		}
	}
}




