#include "InventoryComponent.h"
#include "InventoryGameState.h"
#include "InventoryCharacter.h"


UInventoryComponent::AInventoryController() 
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

int32 UInventoryComponent::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool UInventoryComponent::AddItemToInventoryByID(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		// If a Slot- or WeightLimit are not needed remove them in this line
		if (inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}




// 아래 두 함수는 캐릭터에서 구현한다.

void UInventoryComponent::SetupInputComponent()
{
    // 캐릭터에서 생성
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AInventoryController::Interact);
}

void UInventoryComponent::Interact()
{
    // 캐릭터에서 구현
    // 이런식으로
	if (inventory_component->current_interactable)
	{
		inventory_component->current_interactable->Interact(this);
	}
}