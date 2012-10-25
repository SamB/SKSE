; returns the form for the item worn at the specified slotMask
; use Armor.GetMaskForSlot() to generate appropriate slotMask
Form Function GetWornForm(int slotMask) native

; returns the number of added spells for the actor
Int Function GetSpellCount() native

; returns the specified added spell for the actor
Spell Function GetNthSpell(int n) native

Function QueueNiNodeUpdate() native