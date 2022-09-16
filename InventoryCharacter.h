// 기존 CombatCharacter 클래스에 기능 추가하여 사용

#include "CoreMinimal.h"


class ACombatCharacter : public ACharacter
{
protected:
    virtual void Tick(float DeltaTime) override;

public:
    // . . . .
    /** Collection sphere */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USphereComponent* collection_sphere;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UInventoryComponent* inventory_component;

    /** Function to collect every AutoPickup in range. */
    void CollectAutoPickups();
    /** Function to check for the closest Interactable in sight and in range. */
    void CheckForInteractables();
public:


}



