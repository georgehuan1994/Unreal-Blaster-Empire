// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "Blaster/Character/BlasterCharacter.h"
#include "Blaster/Weapon/Weapon.h"
#include "Engine/SkeletalMeshSocket.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCombatComponent::EquipWeapon(AWeapon* WeaponToEquip)
{
	if (Character == nullptr || WeaponToEquip == nullptr) return;
	
	// AssaultRifleSocket
	
	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	
	const USkeletalMeshSocket* AssaultRifleSocket = Character->GetMesh()->GetSocketByName(FName("AssaultRifleSocket"));
	if (AssaultRifleSocket)
	{
		AssaultRifleSocket->AttachActor(EquippedWeapon, Character->GetMesh());
	}
	
	EquippedWeapon->SetOwner(Character);
	EquippedWeapon->ShowPickupWidget(false);

	// RifleM4C
	EquippedWeapon->SetActorRelativeRotation(FRotator(0,90,0));
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

