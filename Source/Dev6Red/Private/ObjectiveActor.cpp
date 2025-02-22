// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveActor.h"

#include "Components/SphereComponent.h"
#include "Dev6Red/Dev6RedCharacter.h"
#include "Dev6Red/Dev6RedProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObjectiveActor::AObjectiveActor()
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
void AObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveActor::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickUpFX, GetActorLocation());
}


void AObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	PlayEffect();
	ADev6RedProjectile* Projectile = Cast<ADev6RedProjectile>(OtherActor);
	//ADev6RedProjectile* MyProjectile = Cast<ADev6RedProjectile>(OtherActor);
	if (ADev6RedProjectile* MyProjectile = Cast<ADev6RedProjectile>(OtherActor))
	{
		Destroy();
		Projectile->ObjectiveHit();
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Funciona");
	}
	else
	{
		PlayEffect();
	}
	
	
}

