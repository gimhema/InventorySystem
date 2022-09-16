#include "Interactable.h"
#include "InventoryItem.h"

class UInventoryComponent 
{
    // . . . . .
protected:
    void Interact();

	virtual void SetupInputComponent() override; // 캐릭터에서 처리함

public:
    UInventoryComponent();

	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AInteractable* current_interactable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FInventoryItem> inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 inventory_slot_limit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 inventory_weight_limit;
public:

}