// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
APortal::APortal()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereMesh->SetupAttachment(RootComponent);



	CubeCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("CubeComponent"));
	CubeCollider->SetupAttachment(RootComponent); 
	CubeCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	CubeCollider->OnComponentBeginOverlap.AddDynamic(this, &APortal::OnBeginOverlap);

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//on begin component begin overlap sphere

void APortal::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//debug print message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap with portal number " + PortalNumber ? "1" : "2"));

	//cast to player
	ACharacter* Player = Cast<ACharacter>(OtherActor);
	if (Player)
	{
		if (OtherPortal != nullptr)
			Player->SetActorLocation(OtherPortal->GetActorLocation());
	}
}

void APortal::ForceOverlap(AActor* OtherActor)
{
	//debug print message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap with portal number " + PortalNumber ? "1" : "2"));

	//cast to player
	ACharacter* Player = Cast<ACharacter>(OtherActor);
	if (Player && PreventLoop)
	{
		PreventLoop = false;
		if (OtherPortal != nullptr) {
			OtherPortal->PreventLoop = false;
			Player->SetActorLocation(OtherPortal->GetActorLocation());
		}
	}
}

void APortal::ForceOverlapEND(AActor* OtherActor)
{
	PreventLoop = true;

}




