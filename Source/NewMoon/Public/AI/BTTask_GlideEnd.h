// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NewMoon.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GlideEnd.generated.h"

/**
 * 
 */
UCLASS()
class NEWMOON_API UBTTask_GlideEnd : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_GlideEnd();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
