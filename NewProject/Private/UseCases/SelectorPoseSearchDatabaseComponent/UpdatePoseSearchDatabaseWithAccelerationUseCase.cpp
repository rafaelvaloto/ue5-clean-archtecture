﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UseCases/SelectorPoseSearchDatabaseComponent/UpdatePoseSearchDatabaseWithAccelerationUseCase.h"


void UUpdatePoseSearchDatabaseWithAccelerationUseCase::Handle
(
	const TScriptInterface<ISelectorPoseSearchDatabaseInterface>& Component,
	float PreviousVelocity,
	float CurrentVelocity
)
{
	TArray<IEntityAsset*> EntitiesAssets = Component->GetEntitiesAsset();

	int32 Index = 0;
	for (IEntityAsset* Entity : EntitiesAssets)
	{
		// Filtrar apenas entidades de um tipo específico
		if (
			!Entity->GetTypesValidateRule().Contains(ESelectorDatabaseValidateRuleModeEnum::Acceleration)
		)
		{
			UE_LOG(LogTemp, Warning, TEXT("NotContains ESelectorDatabaseValidateRuleModeEnum::Acceleration"));
			Index++;
			continue;
		}
		
		if (
			Entity->ValidateAll(
				Component->GetActor(),
				{
					ESelectorDatabaseValidateRuleModeEnum::Velocity, CurrentVelocity, PreviousVelocity
				}
			)
		)
		{
			Component->SetInterruptMode(EPoseSearchInterruptMode::InterruptOnDatabaseChange);
			Component->SetDatabaseCurrent(Index);
			Component->SetInterruptMode(EPoseSearchInterruptMode::DoNotInterrupt);
		}
		
		Index++;
	}
}
