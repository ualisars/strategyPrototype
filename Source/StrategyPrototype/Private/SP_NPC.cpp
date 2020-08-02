#include "SP_NPC.h"
#include "Kismet/GameplayStatics.h"
#include <math.h>
#include "SP_Town.h"

void ASP_NPC::BuyProvision()
{
	if (TownToMove)
	{
		float SpentGold = 0.0f;
		float AvailablePercentOfGold = 0.7f;
		float SpentGoldPercentage = 0.0f;
		TArray<FSP_Item> TownFood; 
		
		for (FSP_Item Item : TownToMove->Goods)
		{
			if (Item.Consumable)
				TownFood.Add(Item);
		}
	
		while (TownFood.Num() > 0 && (NeedFood() || (CountDailyFoodSupply() >= EssentialDailyFoodSupply && SpentGoldPercentage > AvailablePercentOfGold)))
		{
			SpentGoldPercentage = SpentGold / Gold;
			BuyFood(TownFood);
		}

		// remember current town to know it doesn't have enough food
		if (CountDailyFoodSupply() <= MinDailyFoodSupply)
		{
			NoProvisionTowns.Add(TownToMove);
		}
		else
		{
			NoProvisionTowns.Empty();
		}

		TownToMove = nullptr;
	}

	SetMode(SP_CharacterMode::Roaming);
}

void ASP_NPC::BuyFood(TArray<FSP_Item>& TownFood)
{
	FSP_Item Item = TownFood.Pop();
	if (Gold >= Item.Cost)
	{
		TownToMove->RemoveItem(Item);
		AddItem(Item);
	}
}

ASP_NPC::ASP_NPC()
{
	Tags.Add(FName("NPC"));

	FSP_Unit Cavalry = USP_UnitFactory::CreateUnit(SP_UnitType::Cavalry);
	AddUnit(Cavalry);
	
	FSP_Item Item1 = USP_ItemFactory::CreateItem(SP_ItemType::Sword, SP_ItemOwner::NPC);
	FSP_Item Item2 = USP_ItemFactory::CreateItem(SP_ItemType::Necklace, SP_ItemOwner::NPC);

	AddItem(Item1);
	AddItem(Item2);
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
					SetMode(SP_CharacterMode::InteractingWithTown);
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

int ASP_NPC::CountDailyFoodSupply()
{
	return floor(Food / GetDailyFoodConsumption());
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

bool ASP_NPC::NeedFood()
{
	if (CountDailyFoodSupply() < MinDailyFoodSupply)
	{
		return true;
	}
	return false;
}

