#include "SP_NPC.h"
#include "Kismet/GameplayStatics.h"
#include "SP_Town.h"

void ASP_NPC::BuyProvision()
{
	UE_LOG(LogTemp, Warning, TEXT("NPC buys provision"));
}

ASP_NPC::ASP_NPC()
{
	Tags.Add(FName("NPC"));

	FSP_Unit Cavalry = USP_UnitFactory::CreateUnit(SP_UnitType::Cavalry);
	Units.Add(Cavalry);

	FSP_Item Item1 = USP_ItemFactory::CreateItem(SP_ItemType::Bread, SP_ItemOwner::NPC);
	FSP_Item Item2 = USP_ItemFactory::CreateItem(SP_ItemType::Sword, SP_ItemOwner::NPC);
	FSP_Item Item3 = USP_ItemFactory::CreateItem(SP_ItemType::Necklace, SP_ItemOwner::NPC);

	AddItem(Item1);
	AddItem(Item2);
	AddItem(Item3);
}

void ASP_NPC::BeginPlay()
{
	Super::BeginPlay();

	SetNPCTask(SP_NPCTask::None);
}

void ASP_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASP_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASP_NPC::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag("Town"))
	{
		if (ASP_Town* Town = Cast<ASP_Town>(OtherActor))
		{
			if (TownToMove != nullptr && TownToMove->Name == Town->Name && Mode == SP_CharacterMode::GoingToTown)
			{
				if (Task == SP_NPCTask::BuyProvision)
				{
					BuyProvision();
				}
			}
		}
	}
}

float ASP_NPC::GetDailyFoodConsumption() const
{
	int FoodConsumptionPerDay = 3;
	return FoodConsumption * FoodConsumptionPerDay;
}

void ASP_NPC::MoveToTown(ASP_Town* Town)
{
	SetMode(SP_CharacterMode::GoingToTown);
	TownToMove = Town;
	NPC_MoveToActor(Town);
}

void ASP_NPC::SetNPCTask(SP_NPCTask NewTask)
{
	Task = NewTask;
}

SP_NPCTask ASP_NPC::GetNPCTask() const
{
	return Task;
}

