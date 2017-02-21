// Tác giả: Phùng Trọng Hiếu - Sinh viên K60 viện Toán ứng dụng và Tin học - Đại học Bách Khoa Hà Nội

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

	float DoDai = 100.0f;
	FVector ViTri;
	FRotator GocQuay;
	GetPlayerLocationAndRotation(ViTri, GocQuay);

	FVector LineTraceEnd = ViTri + GocQuay.Vector() * DoDai;

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

/* Lấy vị trí và góc quay hiện tại của viewport */
void UTuongTacCuaNguoiChoi::GetPlayerLocationAndRotation(FVector& PLocation, FRotator& PRotation) {
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PLocation, OUT PRotation);
}