#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ManPickup.generated.h"

UCLASS()
class INVENTORY_API AManPickup : public AInteractable
{
	GENERATED_BODY()
	
public:
	AManPickup();
	
	void Interact_Implementation(UInventoryComponent* inventory) override;

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* pickup_mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName item_id;
};