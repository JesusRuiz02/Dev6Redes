// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zone.generated.h"

class USphereComponent;

UCLASS()
class DEV6RED_API AZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZone();
protected:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComp;

		// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
public:	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
