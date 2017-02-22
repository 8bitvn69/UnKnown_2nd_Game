// Tac gia: Phung Trong Hieu - Sinh vien K60 vien Toan ung dung va Tin hoc - HUST

#pragma once

#include "Components/ActorComponent.h"
#include "TuongTacCuaNguoiChoi.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNKNOWNPROJECT_API UTuongTacCuaNguoiChoi : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTuongTacCuaNguoiChoi();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float DoDaiTia = 50.0f; // Ð? dài c?a tia phát ra t? viewport ð? s? d?ng cho k? thu?t LineTrace(RayCast) 

	void GetLocationAndRotationOfViewport(FVector&, FRotator&);
	
};
