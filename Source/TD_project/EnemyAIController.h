// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TD_PROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
	
};
