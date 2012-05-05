#include "PapyrusWeapon.h"

#include "GameObjects.h"

namespace papyrusWeapon
{
	UInt32 GetBaseDamage(TESObjectWEAP* thisWeapon)
	{
		if (!thisWeapon)
			return 0;
		return thisWeapon->damage.GetAttackDamage();
	}

	void SetBaseDamage(TESObjectWEAP* thisWeapon, UInt32 nuDamage)
	{
		if (thisWeapon) {
			thisWeapon->damage.attackDamage = nuDamage;
		}
	}

	float GetReach(TESObjectWEAP* thisWeapon)
	{
		if (!thisWeapon)
			return 0.0;
		return thisWeapon->unk0C4.reach;
	}

	void SetReach(TESObjectWEAP* thisWeapon, float nuReach)
	{
		if (!thisWeapon)
			return;
		thisWeapon->unk0C4.reach = nuReach;
	}

	float GetSpeed(TESObjectWEAP* thisWeapon)
	{
		if (!thisWeapon)
			return 0.0;
		return thisWeapon->unk0C4.speed;
	}

	void SetSpeed(TESObjectWEAP* thisWeapon, float speed)
	{
		if (thisWeapon) {
			thisWeapon->unk0C4.speed = speed;
		}
	}

	float GetStagger(TESObjectWEAP* thisWeapon)
	{
		if (!thisWeapon)
			return 0.0;
		return thisWeapon->unk0C4.stagger;
	}

	void SetStagger(TESObjectWEAP* thisWeapon, float stagger)
	{
		if (thisWeapon) {
			thisWeapon->unk0C4.stagger = stagger;
		}
	}



	UInt32 GetWeaponType(TESObjectWEAP* thisWeapon)
	{
		if (!thisWeapon)
			return 0;
		return thisWeapon->type();
	}

	void SetWeaponType(TESObjectWEAP* thisWeapon, UInt32 nuType)
	{
		if (!thisWeapon)
			return;
		thisWeapon->unk0C4.type = nuType;
	}

}

#include "PapyrusVM.h"
#include "PapyrusNativeFunctions.h"

void papyrusWeapon::RegisterFuncs(VMClassRegistry* registry)
{
	registry->RegisterFunction(
		new NativeFunction0 <TESObjectWEAP, UInt32>("GetWeaponType", "Weapon", papyrusWeapon::GetWeaponType, registry));

	registry->RegisterFunction(
		new NativeFunction1 <TESObjectWEAP, void, UInt32>("SetWeaponType", "Weapon", papyrusWeapon::SetWeaponType, registry));


	registry->RegisterFunction(
		new NativeFunction0 <TESObjectWEAP, UInt32>("GetBaseDamage", "Weapon", papyrusWeapon::GetBaseDamage, registry));

	registry->RegisterFunction(
		new NativeFunction1 <TESObjectWEAP, void, UInt32>("SetBaseDamage", "Weapon", papyrusWeapon::SetBaseDamage, registry));

	registry->RegisterFunction(
		new NativeFunction0 <TESObjectWEAP, float>("GetReach", "Weapon", papyrusWeapon::GetReach, registry));

	registry->RegisterFunction(
		new NativeFunction1 <TESObjectWEAP, void, float>("SetReach", "Weapon", papyrusWeapon::SetReach, registry));

	registry->RegisterFunction(
		new NativeFunction0 <TESObjectWEAP, float>("GetSpeed", "Weapon", papyrusWeapon::GetSpeed, registry));

	registry->RegisterFunction(
		new NativeFunction1 <TESObjectWEAP, void, float>("SetSpeed", "Weapon", papyrusWeapon::SetSpeed, registry));

	registry->RegisterFunction(
		new NativeFunction0 <TESObjectWEAP, float>("GetStagger", "Weapon", papyrusWeapon::GetStagger, registry));

	registry->RegisterFunction(
		new NativeFunction1 <TESObjectWEAP, void, float>("SetStagger", "Weapon", papyrusWeapon::SetStagger, registry));


}