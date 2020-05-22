// Fill out your copyright notice in the Description page of Project Settings.

#include "SP_BaseCharacter.h"

// Sets default values
ASP_BaseCharacter::ASP_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;

	SetMode(SP_CharacterMode::Roaming);
}

// Called when the game starts or when spawned
void ASP_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASP_BaseCharacter::SetMode(SP_CharacterMode NewMode)
{
	Mode = NewMode;
}

void ASP_BaseCharacter::StopMovement()
{
	CharacterMovementComp->StopMovementImmediately();
}

SP_CharacterMode ASP_BaseCharacter::GetMode()
{
	return Mode;
}

// Called every frame
void ASP_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASP_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_BaseCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (OtherActor && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("Road"))
		{
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_RODE;
		}
		else if (OtherActor->ActorHasTag("Swamp"))
		{
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_SWAMP;
		}

		if (OtherActor->ActorHasTag("Character"))
		{
			ASP_BaseCharacter* OtherCharacter = Cast<ASP_BaseCharacter>(OtherActor);
			if (OtherCharacter != nullptr)
			{
				if (Mode == SP_CharacterMode::Attacking || OtherCharacter->Mode == SP_CharacterMode::Attacking)
				{
					UE_LOG(LogTemp, Warning, TEXT("Fight is starting"));
					StartBattle(OtherCharacter);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to cast OtherActor to ASP_BaseCharacter"));
			}
		}
	}
}

void ASP_BaseCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (OtherActor && (OtherActor != this))
	{
		if (OtherActor->ActorHasTag("NavigationArea"))
			CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;
	}
}

void ASP_BaseCharacter::StartBattle(ASP_BaseCharacter* OtherCharacter)
{
	if(Mode == SP_CharacterMode::Fighting || OtherCharacter->Mode == SP_CharacterMode::Fighting)
		return;
	StopMovement();
	OtherCharacter->StopMovement();

	SetMode(SP_CharacterMode::Fighting);
	OtherCharacter->SetMode(SP_CharacterMode::Fighting);

	TArray<SP_Unit*> CharacterUnitCopy = Units;
	TArray<SP_Unit*> OtherCharacterUnitCopy = OtherCharacter->Units;

	while (Units.Num() != 0 && OtherCharacter->Units.Num() != 0)
	{
		int Character1Index = SP_Random::GenerateRandomNumber(0, Units.Num() - 1);
		int Character2Index = SP_Random::GenerateRandomNumber(0, OtherCharacter->Units.Num() - 1);

		SP_Unit* RandomCharacter1Unit = Units[Character1Index];
		SP_Unit* RandomCharacter2Unit = OtherCharacter->Units[Character2Index];

		AttackUnit(RandomCharacter1Unit, RandomCharacter2Unit);
		AttackUnit(RandomCharacter2Unit, RandomCharacter1Unit);

		if (RandomCharacter1Unit->Health <= 0)
		{
			delete Units[Character1Index];
			CharacterUnitCopy.RemoveAt(Character1Index);
			Units = CharacterUnitCopy;
			UE_LOG(LogTemp, Warning, TEXT("Character i units after remove is %d"), Units.Num());
		}

		if (RandomCharacter2Unit->Health <= 0)
		{
			delete OtherCharacter->Units[Character2Index];
			OtherCharacterUnitCopy.RemoveAt(Character2Index);
			OtherCharacter->Units = OtherCharacterUnitCopy;
			UE_LOG(LogTemp, Warning, TEXT("Other Character i units after remove is %d"), OtherCharacter->Units.Num());
		}
	}

	if (Units.Num() == 0)
	{
		Destroy();
	}
	else if (OtherCharacter->Units.Num() == 0)
	{
		OtherCharacter->Destroy();
	}

	UE_LOG(LogTemp, Warning, TEXT("Fight is over"));
}

void ASP_BaseCharacter::AttackUnit(SP_Unit* AttackUnit, SP_Unit* DefendUnit)
{
	if (AttackUnit->Health > 0)
	{
		DefendUnit->Health -= AttackUnit->Damage;
	}
}
