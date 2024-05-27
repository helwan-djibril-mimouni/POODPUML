// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "EnemyAI.h"

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
	AEnemyAI* EnemyAI = Cast<AEnemyAI>(AController::GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("probably not"), );

	if (EnemyAI) {
		EnemyAI->MoveToWaypoints();
	}
}
