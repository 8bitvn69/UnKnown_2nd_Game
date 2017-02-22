// Tac gia: Phung Trong Hieu - Sinh vien K60 vien Toan ung dung va Tin hoc - HUST

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNKNOWNPROJECT_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor(); // TODO viết phương thức mở cửa
	void CloseDoor(); // TODO viết phương thức đóng cửa

private:
	UPROPERTY(EditAnywhere)
	bool CanOpenDoor = true;
	
};
