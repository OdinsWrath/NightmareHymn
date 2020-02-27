// Fill out your copyright notice in the Description page of Project Settings.


#include "NHbaseCharacter.h"
#include "Camera/CameraComponent.h"	// Provides access to camera options
#include "Components/CapsuleComponent.h"	// Provides access to character collision
#include "Components/InputComponent.h"	// Provides ability to receive and bind inputs
#include "GameFramework/SpringArmComponent.h"	// Provides access to the camera boom stand
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"	// Provides access to the camera arm



ANHbaseCharacter::ANHbaseCharacter()
{
	// Initializes the size of the collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// Disable controller rotation features
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Attach the camera boom stand to the collision capsule so that the camera will
	// follow the character as it moves
	CameraBoomComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoomComp->SetupAttachment(RootComponent);
	CameraBoomComp->SetUsingAbsoluteRotation(true); // Prevent the camera from rotating as the character
													// switches directions
	CameraBoomComp->bDoCollisionTest = false;
	
	// Create and attach a camera to the boom stand
	SideViewCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SideViewCameraComp->SetupAttachment(CameraBoomComp, USpringArmComponent::SocketName);
	SideViewCameraComp->bUsePawnControlRotation = false; // Prevent player input from rotating the camera

	// Create character mesh so that it will be displayed in game
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	MeshComp->SetupAttachment(RootComponent);

	// Establish character movement component & functionality
	GetCharacterMovement()->bOrientRotationToMovement = true; // Make character face movement direction
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); 
	GetCharacterMovement()->GravityScale = 2.f;	// Set gravity on character
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
}


void ANHbaseCharacter::MoveRight(float Value)
{
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}


void ANHbaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Make sure to call the parent function first
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANHbaseCharacter::MoveRight);
}

