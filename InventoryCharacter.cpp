#include "InventoryCharacter.h"
#include "Interactable.h"
#include "AutoPickup.h"
#include "InventoryItem.h"
#include "InventoryComponent.h"


ACombatCharacter::ACombatCharacter()
{
    // . . . .
    // Create the collection sphere
    // Create the collection sphere
    collection_sphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
    collection_sphere->SetupAttachment(RootComponent);
    collection_sphere->SetSphereRadius(200.f);

    inventory_component = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
    inventory_component->SetupAttachment(RootComponent);


    // . . . . .
}

void ACombatCharacter::Tick(float Deltatime)
{
    Super::Tick(Deltatime);

    // . . . . .
    CollectAutoPickups();
    CheckForInteractables();
}

void ACombatCharacter::CollectAutoPickups() // 얘는 이미 구현되어있으니까 구현 X
{
	// // Get all overlapping Actors and store them in an array
	// TArray<AActor*> CollectedActors;
	// collection_sphere->GetOverlappingActors(CollectedActors);

	// AInventoryController* IController = Cast<AInventoryController>(GetController());

	// // For each collected Actor
	// for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	// {
	// 	// Cast the actor to AAutoPickup
	// 	AAutoPickup* const TestPickup = Cast<AAutoPickup>(CollectedActors[iCollected]);
	// 	// If the cast is successful and the pickup is valid and active 
	// 	if (TestPickup && !TestPickup->IsPendingKill())
	// 	{
	// 		TestPickup->Collect(IController);
	// 	}
	// }
}

void ACombatCharacter::CheckForInteractables()
{
	// Create a LineTrace to check for a hit
	FHitResult HitResult;

	int32 Range = 500;
	FVector StartTrace = FollowCamera->GetComponentLocation();
	FVector EndTrace = (FollowCamera->GetForwardVector() * Range) + StartTrace;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	// AInventoryController* IController = Cast<UInventoryComponent>(GetController());

	if (inventory_component)
	{
		// Check if something is hit
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			// Cast the actor to AInteractable
			AInteractable* Interactable = Cast<AInteractable>(HitResult.GetActor());
			// If the cast is successful
			if (Interactable)
			{
				inventory_component->CurrentInteractable = Interactable;
				return;
			}
		}

		inventory_component->CurrentInteractable = nullptr;
	}
}

