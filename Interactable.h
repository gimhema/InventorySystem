#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class AInteractable : public AActor
{
	GENERATED_BODY()

public:
	AInteractable();

	UFUNCTION(BlueprintNativeEvent)
	void Interact(class UInventoryComponent* inventory);
	virtual void Interact_Implementation(class UInventoryComponent* inventory);

	UPROPERTY(EditDefaultsOnly)
	FString name;

	UPROPERTY(EditDefaultsOnly)
	FString action;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	FString GetInteractText() const;
};