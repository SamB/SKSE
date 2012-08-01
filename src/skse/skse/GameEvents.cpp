#include "GameEvents.h"

// For testing
//EventDispatcher<TESSleepStartEvent>* g_sleepStartEventDispatcher = (EventDispatcher<TESSleepStartEvent>*) 0x012DAC10;
EventDispatcher<InputEvent,InputEvent*> ** g_inputEventDispatcher = (EventDispatcher<InputEvent,InputEvent*>**) 0x01AD5DD4;
// TESActivateEvent																														0x12DA4F0
// TESActiveEffectApplyRemoveEvent																										0x12DA520
// TESActorLocationChangeEvent																											0x12DA550
// TESBookReadEvent																														0x12DA580
// TESCellAttachDetachEvent																												0x12DA5B0
// TESCellFullyLoadedEvent																												0x12DA5E0
// TESCombatEvent																														0x12DA640
// TESContainerChangedEvent																												0x12DA670
// TESDeathEvent																														0x12DA6A0
// TESDestructionStageChangedEvent																										0x12DA6D0
// TESEnterBleedoutEvent																												0x12DA700
// TESEquipEvent																														0x12DA730
// TESFormDeleteEvent																													0x12DA760
// TESFurnitureEvent																													0x12DA790
// TESGrabReleaseEvent																													0x12DA7C0
// TESHitEvent																															0x12DA7F0
// TESLoadGameEvent																														0x12DA850
// TESLockChangedEvent																													0x12DA880
// TESMagicEffectApplyEvent																												0x12DA8B0
// TESMagicWardHitEvent																													0x12DA8E0
// TESMoveAttachDetachEvent																												0x12DA910
// TESObjectLoadedEvent																													0x12DA940
// TESObjectREFRTranslationEvent																										0x12DA970
// TESOpenCloseEvent																													0x12DA9A0
// TESPackageEvent																														0x12DA9D0
// TESPerkEntryRunEvent																													0x12DAA00
// TESQuestInitEvent																													0x12DAA30
// TESQuestStageEvent																													0x12DAA60
// TESResetEvent																														0x12DAAF0
// TESResolveNPCTemplatesEvent																											0x12DAB20
// TESSceneEvent																														0x12DAB50
// TESSceneActionEvent																													0x12DAB80
// TESScenePhaseEvent																													0x12DABB0
// TESSellEvent																															0x12DABE0
// TESSleepStartEvent																													0x12DAC10
// TESSleepStopEvent																													0x12DAC40
// TESSpellCastEvent																													0x12DAC70
// TESTopicInfoEvent																													0x12DACD0
// TESTrackedStatsEvent																													0x12DAD00
// TESTrapHitEvent																														0x12DAD30
// TESTriggerEvent																														0x12DAD60
// TESTriggerEnterEvent																													0x12DAD90
// TESTriggerLeaveEvent																													0x12DADC0
// TESUniqueIDChangeEvent																												0x12DADF0
// TESSwitchRaceCompleteEvent																											0x12DAE80
// TESPlayerBowShotEvent																												0x12DAEA0
