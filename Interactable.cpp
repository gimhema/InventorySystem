#include "Interactable.h"

AInteractable::AInteractable()
{
	name = "Interactable";
	action = "interact";
}

void AInteractable::Interact_Implementation(UInventoryComponent* Controller)
{
	return;
}

FString AInteractable::GetInteractText() const 
{
	return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action); 
}