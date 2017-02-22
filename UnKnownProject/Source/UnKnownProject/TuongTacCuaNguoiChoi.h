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
	void ThucHienTuongTac(); // TODO viết phương thức thực hiện tương tác

private:
	UPROPERTY(EditAnywhere)
	float DoDaiTia = 50.0f; // Độ dài của tia phát ra từ viewport được sử dụng cho kỹ thuật LineTrace(RayCast)
	UInputComponent* InputComponent = nullptr;

	void GetLocationAndRotationOfViewport(FVector&, FRotator&);
	void CaiDatDauVao();
};
