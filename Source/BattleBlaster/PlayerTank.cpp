// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "InputMappingContext.h"

APlayerTank::APlayerTank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComp->SetupAttachment(CapsuleCollisionComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);


}

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	APlayerController *PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		if (LocalPlayer)
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem;
			Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
			if (Subsystem)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerTank::Move);
		EIC->BindAction(TurnAction, ETriggerEvent::Triggered, this, &APlayerTank::Turn);
	}
}

void APlayerTank::Move(const FInputActionValue& Value)
{
	float MoveValue = Value.Get<float>();
	FVector DeltaLocation = FVector(MoveValue * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0, 0);
	AddActorLocalOffset(DeltaLocation, true);
	UE_LOG(LogTemp, Display, TEXT("Move function called value is %f"), MoveValue);
}

void APlayerTank::Turn(const FInputActionValue& Value)
{
	float TurnValue = Value.Get<float>();
	FRotator DeltaRotation = FRotator(0, TurnValue * TurnSpeed * GetWorld()->GetDeltaSeconds(), 0);
	AddActorLocalRotation(DeltaRotation, true);
	UE_LOG(LogTemp, Display, TEXT("Turn function called value is %f"), TurnValue);
}
