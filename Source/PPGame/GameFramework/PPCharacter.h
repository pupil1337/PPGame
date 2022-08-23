// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PPCharacter.generated.h"

class UPPCompBase;

UCLASS()
class PPGAME_API APPCharacter : public ACharacter
{
	GENERATED_BODY()

	// 角色身上组件
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Components")
	TArray<TSubclassOf<UPPCompBase>> MultiClasses;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Components")
	TArray<TSubclassOf<UPPCompBase>> ServerOnlyClasses;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Components")
	TArray<TSubclassOf<UPPCompBase>> ClientsOnlyClasses;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Components")
	TArray<TSubclassOf<UPPCompBase>> AutonomousOnlyClasses;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Components")
	TArray<TSubclassOf<UPPCompBase>> SimulatedOnlyClasses;
	
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Camera System")
	float ThirdPersonFOV = 90.0f;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Camera System")
	float FirstPersonFOV = 90.0f;
	UPROPERTY(EditDefaultsOnly, Category = "PPCharacter|Camera System")
	bool bRightShoulder = true;
	
public:
	APPCharacter();
	void GetCameraParameters(float& TPFOVOut, float& FPFOVOut, bool& bRightShoulderOut) const;
	FTransform GetThirdPersonPivotTarget() const;
	FVector GetFirstPersonCameraTarget() const;
	virtual ECollisionChannel GetThirdPersonTraceParams(FVector& TraceOrigin, float& TraceRadius);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
