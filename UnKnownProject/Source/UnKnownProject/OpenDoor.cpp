﻿// Tac gia: Phung Trong Hieu - Sinh vien K60 vien Toan ung dung va Tin hoc - HUST

#include "UnKnownProject.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Phương thức mở cửa
void UOpenDoor::OpenDoor() {

}

// Phương thức đóng cửa
void UOpenDoor::CloseDoor() {

}