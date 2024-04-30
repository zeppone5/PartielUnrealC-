// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal.generated.h"

UCLASS()
class PARTIEL_API APortal : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APortal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	class UBoxComponent* CubeCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	UStaticMeshComponent* SphereMesh;

	//property portal number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Portal)
	bool PortalNumber;

	//OtherPortal
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Portal)
	APortal* OtherPortal;

private:


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//begin ovelap declaration
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//Encore une fois je vois pas la difference avec mes coin et le overlap marche plus ici.il marchait avec un shpere component mais pas avec un box component donc je force par un bp
	UFUNCTION(BlueprintCallable)
	void ForceOverlap(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void ForceOverlapEND(AActor* OtherActor);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Portal)
	bool PreventLoop = true;

};
