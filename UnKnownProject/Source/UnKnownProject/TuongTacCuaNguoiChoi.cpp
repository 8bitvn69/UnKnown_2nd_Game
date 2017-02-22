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

	// ...
	
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
}

// Lấy vị trí và góc nhìn của viewport
void UTuongTacCuaNguoiChoi::GetLocationAndRotationOfViewport(FVector& VLocation, FRotator& VRotation) {
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT VLocation, OUT VRotation);
}