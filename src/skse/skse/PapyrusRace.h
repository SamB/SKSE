#pragma once

class TESRace;
class SpellItem;
class VMClassRegistry;
struct StaticFunctionTag;

namespace papyrusRace
{
	void RegisterFuncs(VMClassRegistry* registry);

	UInt32 GetSpellCount(TESRace* thisRace);
	SpellItem* GetNthSpell(TESRace* thisRace, UInt32 n);
	
	bool IsRaceFlagSet(TESRace* thisRace, UInt32 flag);
	void SetRaceFlag(TESRace* thisRace, UInt32 flag);
	void ClearRaceFlag(TESRace* thisRace, UInt32 flag);

	UInt32 GetNumPlayableRaces(StaticFunctionTag * base);
	TESRace * GetNthPlayableRace(StaticFunctionTag * base, UInt32 n);
}