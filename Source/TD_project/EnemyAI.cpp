// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"
#include "EnemyAIController.h"
#include "Waypoint.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld()) {
		UE_LOG(LogTemp, Warning, TEXT("got world"), );
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	}
	MoveToWaypoints();
}

// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAI::MoveToWaypoints() {
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController) {
		UE_LOG(LogTemp, Warning, TEXT("Controller found"));
		if (CurrentWaypoint <= Waypoints.Num()) {
			for (AActor* Waypoint : Waypoints) {
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);

				if (WaypointItr) {
					UE_LOG(LogTemp, Warning, TEXT("Waypoint found with order: %d"), WaypointItr->GetWaypointOrder());
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint) {
						UE_LOG(LogTemp, Warning, TEXT("Moving to waypoint: %d"), CurrentWaypoint);
						EnemyAIController->MoveToActor(WaypointItr, 0.f);
						CurrentWaypoint++;
						break;
					}
				}
				else {
					UE_LOG(LogTemp, Error, TEXT("Waypoint cast failed"));
				}
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No more waypoints to move to"));
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Controller cast failed"));
	}
}

