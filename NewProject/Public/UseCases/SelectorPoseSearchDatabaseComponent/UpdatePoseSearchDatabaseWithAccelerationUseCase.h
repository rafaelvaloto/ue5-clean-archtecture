﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NewProject/Interfaces/MotionMatchHelpersComponents/SelectorPoseSearchDatabaseInterface.h"
#include "UObject/Object.h"
#include "UpdatePoseSearchDatabaseWithAccelerationUseCase.generated.h"

/**
 * 
 */
UCLASS()
class NEWPROJECT_API UUpdatePoseSearchDatabaseWithAccelerationUseCase : public UObject
{
	GENERATED_BODY()

public:
	static void Handle
	(
		const TScriptInterface<ISelectorPoseSearchDatabaseInterface>& Component,
		float PreviousVelocity,
		float CurrentVelocity,
		float Acceleration
	);
};
