// Tac gia: Phung Trong Hieu - Sinh vien K60 vien Toan ung dung va Tin hoc - HUST

#include "UnKnownProject.h"
#include "TuongTacCuaNguoiChoi.h"

#define OUT

// Sets default values for this component's properties
UTuongTacCuaNguoiChoi::UTuongTacCuaNguoiChoi()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTuongTacCuaNguoiChoi::BeginPlay()
{
	Super::BeginPlay();

	CaiDatDauVao();
	
}


// Called every frame
void UTuongTacCuaNguoiChoi::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector ViTri;
	FRotator GocQuay;
	GetLocationAndRotationOfViewport(ViTri, GocQuay);
	FVector LineTraceEnd = ViTri + GocQuay.Vector() * DoDaiTia;

	DrawDebugLine(
		GetWorld(),
		ViTri,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.0f,
		0.0f,
		3.0f
	);

	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		ViTri,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_GameTraceChannel1),
		TraceParameters
	);

	if (Hit.GetActor() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Cham vao tay nam cua: %s"), *(Hit.GetActor()->GetName()))
	}
}

// Lấy vị trí và góc nhìn của viewport
void UTuongTacCuaNguoiChoi::GetLocationAndRotationOfViewport(FVector& VLocation, FRotator& VRotation) {
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT VLocation, OUT VRotation);
}

// Cài đặt đầu vào điều khiển
void UTuongTacCuaNguoiChoi::CaiDatDauVao() {
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tim thay InputComponent"))

		InputComponent->BindAction("TuongTac", EInputEvent::IE_Pressed, this, &UTuongTacCuaNguoiChoi::ThucHienTuongTac);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Khong tim thay InputComponent"))
	}

}

// Thực hiện việc tương tác với môi trường
void UTuongTacCuaNguoiChoi::ThucHienTuongTac() {

}