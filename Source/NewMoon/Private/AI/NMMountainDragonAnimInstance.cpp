// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NMMountainDragonAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "AI/NMMountainDragon.h"
#include "Components/CombatComponent.h"

void UNMMountainDragonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	NMMountainDragon = Cast<ANMMountainDragon>(TryGetPawnOwner());

	CheckFireSpread = false;
	CheckFireBall = false;
	bIsDead = false;
}

void UNMMountainDragonAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (NMMountainDragon == nullptr)
	{
		NMMountainDragon = Cast<ANMMountainDragon>(TryGetPawnOwner());
	}
	if (!::IsValid(NMMountainDragon)) return;

	Velocity = NMMountainDragon->GetVelocity();
	Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, NMMountainDragon->GetActorRotation());
	Velocity.Z = 0.0f;
	Speed = Velocity.Size();
	
	bIsBattleState = NMMountainDragon->bIsBattleState;
	
	bGlideAttack = NMMountainDragon->bGlideAttack;
	bFly = NMMountainDragon->bFly;

	if (!CheckFireSpread)
	{
		bFireSpreadAttack = NMMountainDragon->bFireSpreadAttack;

		if (bFireSpreadAttack)
			CheckFireSpread = true;
	}
	else
	{
		bFireSpreadAttack = false;
	}

	if (!CheckFireBall)
	{
		bFireBallAttack = NMMountainDragon->bFireBallAttack;
		
		if (bFireBallAttack)
			CheckFireBall = true;
	}
	else
	{
		bFireBallAttack = false;
	}
	
	if (NMMountainDragon->Combat->GetHP() <= 0)
	{
		bIsDead = true;
	}
}

void UNMMountainDragonAnimInstance::AnimNotify_Attack()
{
	OnAttack.Broadcast();
}
