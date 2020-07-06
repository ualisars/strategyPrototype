#include "SP_BaseCharacter.h"

ASP_BaseCharacter::ASP_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add(FName("Character"));

	CharacterCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CharacterCollisionComp"));
	CharacterCollisionComp->SetGenerateOverlapEvents(true);
	CharacterCollisionComp->SetupAttachment(RootComponent);
	CharacterCollisionComp->InitCapsuleSize(88.0f, 80.0f);
	CharacterCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ASP_BaseCharacter::OnOverlapBegin);
	CharacterCollisionComp->OnComponentEndOverlap.AddDynamic(this, &ASP_BaseCharacter::OnOverlapEnd);
	
	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	CharacterMovementComp = GetCharacterMovement();
	CharacterMovementComp->MaxWalkSpeed = MAX_WALK_SPEED_DEFAULT;

	SetMode(SP_CharacterMode::Roaming);
}

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

void ASP_BaseCharacter::InteractWithCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("Character is overlapping with other characters"));
}

SP_CharacterMode ASP_BaseCharacter::GetMode()
{
	return Mode;
}

FName ASP_BaseCharacter::GetName() const
{
	return Name;
}

void ASP_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

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

void ASP_BaseCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASP_BaseCharacter* OtherCharacter = Cast<ASP_BaseCharacter>(OtherActor);
	if (OtherActor && (OtherActor != this) && OtherCharacter)
	{
		if (!OtherCharacter->ActorHasTag("Player") && Mode == SP_CharacterMode::GoingToCharacter && OtherCharacter == CharacterToMove)
		{
			InteractWithCharacter();
		}
		OverlappingCharacter = OtherCharacter;
	}
}

void ASP_BaseCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	ASP_BaseCharacter* OtherCharacter = Cast<ASP_BaseCharacter>(OtherActor);
	if (OtherActor && (OtherActor != this) && OtherCharacter)
	{
		OverlappingCharacter = nullptr;
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

	TArray<FSP_Unit*> CharacterUnitCopy = Units;
	TArray<FSP_Unit*> OtherCharacterUnitCopy = OtherCharacter->Units;

	while (Units.Num() != 0 && OtherCharacter->Units.Num() != 0)
	{
		int Character1Index = SP_Random::GenerateRandomNumber(0, Units.Num() - 1);
		int Character2Index = SP_Random::GenerateRandomNumber(0, OtherCharacter->Units.Num() - 1);

		FSP_Unit* RandomCharacter1Unit = Units[Character1Index];
		FSP_Unit* RandomCharacter2Unit = OtherCharacter->Units[Character2Index];

		AttackUnit(RandomCharacter1Unit, RandomCharacter2Unit);
		AttackUnit(RandomCharacter2Unit, RandomCharacter1Unit);

		if (RandomCharacter1Unit->Health <= 0)
		{
			delete Units[Character1Index];
			CharacterUnitCopy.RemoveAt(Character1Index);
			Units = CharacterUnitCopy;
		}

		if (RandomCharacter2Unit->Health <= 0)
		{
			delete OtherCharacter->Units[Character2Index];
			OtherCharacterUnitCopy.RemoveAt(Character2Index);
			OtherCharacter->Units = OtherCharacterUnitCopy;
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

void ASP_BaseCharacter::AttackUnit(FSP_Unit* AttackUnit, FSP_Unit* DefendUnit)
{
	if (AttackUnit->Health > 0)
	{
		DefendUnit->Health -= AttackUnit->Damage;
	}
}
