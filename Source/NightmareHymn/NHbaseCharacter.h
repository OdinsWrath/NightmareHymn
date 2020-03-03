// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NHbaseCharacter.generated.h"

UCLASS()
class NIGHTMAREHYMN_API ANHbaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Camera component used for accessing camera properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* SideViewCameraComp;

	// Camera component that allows the camera to be set to follow the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* CameraBoomComp;

	// Mesh component used to display the this player character inside the game
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
		class UStaticMeshComponent* MeshComp;

protected:
	// Handles moving this character's position right/left within the level
	void MoveRight(float Value);

		/* NOTE: Jumping functionality is inherited from the parent Character class */

	// Binds inputs to character functionality
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:	
	// Constructor for this character class
	ANHbaseCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComp; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoomComp; }
};
