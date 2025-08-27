#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

#include "global.h"

void ClearRoamerData(void);
void ClearRoamerLocationData(void);
void InitRoamer(void);
void CreateLegendaryBeastRoamers(void);
void GetLegendaryBeastNames(u8 *firstBeastName, u8 *secondBeastName);
void BufferLegendaryBeastNames(void);
void BufferOriginalRoamerName(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
bool8 IsRoamerAt(u8 mapGroup, u8 mapNum);
bool8 IsBeastRoamerAt(u8 beastId, u8 mapGroup, u8 mapNum);
bool8 IsAnyRoamerAt(u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(void);
void CreateBeastRoamerMonInstance(u8 beastId);
u8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(void);
void GetRoamerLocation(u8 *mapGroup, u8 *mapNum);
void GetBeastRoamerLocation(u8 beastId, u8 *mapGroup, u8 *mapNum);
u16 GetRoamerLocationMapSectionId(void);
u16 GetBeastRoamerLocationMapSectionId(u8 beastId);

#endif // GUARD_ROAMER_H
