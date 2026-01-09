#include "global.h"
#include "random.h"
#include "overworld.h"
#include "field_specials.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "string_util.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/species.h"

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 3
#define ROAMER_MAP_GROUP 3

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

enum
{
    BEAST_SLOT_0,  // First additional beast roamer slot
    BEAST_SLOT_1,  // Second additional beast roamer slot
    NUM_BEAST_ROAMERS
};

#define ROAMER (&gSaveBlock1Ptr->roamers.originalRoamer)
#define BEAST_ROAMER(id) (&gSaveBlock1Ptr->roamers.legendaryBeasts[id])
#define BEAST_ROAMERS_ACTIVE (gSaveBlock1Ptr->roamers.beastRoamersActive)
EWRAM_DATA u8 sLocationHistory[3][2] = {};
EWRAM_DATA u8 sRoamerLocation[2] = {};
EWRAM_DATA u8 sBeastRoamerLocations[NUM_BEAST_ROAMERS][2] = {};
EWRAM_DATA u8 sLastEncounteredRoamerType = 0; // 0 = none, 1 = original, 2+ = beast roamer (id+2)
EWRAM_DATA u8 sLastEncounteredBeastId = 0;

static void BeastRoamerMove(u8 beastId);
static void BeastRoamerMoveToOtherLocationSet(u8 beastId);

#define ___ MAP_NUM(UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][7] = {
    {MAP_NUM(ROUTE1), MAP_NUM(ROUTE2), MAP_NUM(ROUTE21_NORTH), MAP_NUM(ROUTE22), ___, ___, ___},
    {MAP_NUM(ROUTE2), MAP_NUM(ROUTE1), MAP_NUM(ROUTE3), MAP_NUM(ROUTE22), ___, ___, ___},
    {MAP_NUM(ROUTE3), MAP_NUM(ROUTE2), MAP_NUM(ROUTE4), ___, ___, ___, ___},
    {MAP_NUM(ROUTE4), MAP_NUM(ROUTE3), MAP_NUM(ROUTE5), MAP_NUM(ROUTE9), MAP_NUM(ROUTE24), ___, ___},
    {MAP_NUM(ROUTE5), MAP_NUM(ROUTE4), MAP_NUM(ROUTE6), MAP_NUM(ROUTE7), MAP_NUM(ROUTE8), MAP_NUM(ROUTE9), MAP_NUM(ROUTE24)},
    {MAP_NUM(ROUTE6), MAP_NUM(ROUTE5), MAP_NUM(ROUTE7), MAP_NUM(ROUTE8), MAP_NUM(ROUTE11), ___, ___},
    {MAP_NUM(ROUTE7), MAP_NUM(ROUTE5), MAP_NUM(ROUTE6), MAP_NUM(ROUTE8), MAP_NUM(ROUTE16), ___, ___},
    {MAP_NUM(ROUTE8), MAP_NUM(ROUTE5), MAP_NUM(ROUTE6), MAP_NUM(ROUTE7), MAP_NUM(ROUTE10), MAP_NUM(ROUTE12), ___},
    {MAP_NUM(ROUTE9), MAP_NUM(ROUTE4), MAP_NUM(ROUTE5), MAP_NUM(ROUTE10), MAP_NUM(ROUTE24), ___, ___},
    {MAP_NUM(ROUTE10), MAP_NUM(ROUTE8), MAP_NUM(ROUTE9), MAP_NUM(ROUTE12), ___, ___, ___},
    {MAP_NUM(ROUTE11), MAP_NUM(ROUTE6), MAP_NUM(ROUTE12), ___, ___, ___, ___},
    {MAP_NUM(ROUTE12), MAP_NUM(ROUTE10), MAP_NUM(ROUTE11), MAP_NUM(ROUTE13), ___, ___, ___},
    {MAP_NUM(ROUTE13), MAP_NUM(ROUTE12), MAP_NUM(ROUTE14), ___, ___, ___, ___},
    {MAP_NUM(ROUTE14), MAP_NUM(ROUTE13), MAP_NUM(ROUTE15), ___, ___, ___, ___},
    {MAP_NUM(ROUTE15), MAP_NUM(ROUTE14), MAP_NUM(ROUTE18), MAP_NUM(ROUTE19), ___, ___, ___},
    {MAP_NUM(ROUTE16), MAP_NUM(ROUTE7), MAP_NUM(ROUTE17), ___, ___, ___, ___},
    {MAP_NUM(ROUTE17), MAP_NUM(ROUTE16), MAP_NUM(ROUTE18), ___, ___, ___, ___},
    {MAP_NUM(ROUTE18), MAP_NUM(ROUTE15), MAP_NUM(ROUTE17), MAP_NUM(ROUTE19), ___, ___, ___},
    {MAP_NUM(ROUTE19), MAP_NUM(ROUTE15), MAP_NUM(ROUTE18), MAP_NUM(ROUTE20), ___, ___, ___},
    {MAP_NUM(ROUTE20), MAP_NUM(ROUTE19), MAP_NUM(ROUTE21_NORTH), ___, ___, ___, ___},
    {MAP_NUM(ROUTE21_NORTH), MAP_NUM(ROUTE1), MAP_NUM(ROUTE20), ___, ___, ___, ___},
    {MAP_NUM(ROUTE22), MAP_NUM(ROUTE1), MAP_NUM(ROUTE2), MAP_NUM(ROUTE23), ___, ___, ___},
    {MAP_NUM(ROUTE23), MAP_NUM(ROUTE22), MAP_NUM(ROUTE2), ___, ___, ___, ___},
    {MAP_NUM(ROUTE24), MAP_NUM(ROUTE4), MAP_NUM(ROUTE5), MAP_NUM(ROUTE9), ___, ___, ___},
    {MAP_NUM(ROUTE25), MAP_NUM(ROUTE24), MAP_NUM(ROUTE9), ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___}
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

void ClearRoamerData(void)
{
    u32 i;
    gSaveBlock1Ptr->roamers = (struct RoamerGroup){};
    sRoamerLocation[MAP_GRP] = 0;
    sRoamerLocation[MAP_NUM] = 0;
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        sBeastRoamerLocations[i][MAP_GRP] = 0;
        sBeastRoamerLocations[i][MAP_NUM] = 0;
    }
    for (i = 0; i < ARRAY_COUNT(sLocationHistory); i++)
    {
        sLocationHistory[i][MAP_GRP] = 0;
        sLocationHistory[i][MAP_NUM] = 0;
    }
    sLastEncounteredRoamerType = 0;
    sLastEncounteredBeastId = 0;
}

#define GetRoamerSpecies() ({\
    u16 a;\
    switch (GetStarterSpecies())\
    {\
    default:\
        a = SPECIES_RAIKOU;\
        break;\
    case SPECIES_BULBASAUR:\
        a = SPECIES_ENTEI;\
        break;\
    case SPECIES_CHARMANDER:\
        a = SPECIES_SUICUNE;\
        break;\
    }\
    a;\
})

void CreateInitialRoamerMon(void)
{
    struct Pokemon * mon = &gEnemyParty[0];
    u16 species = GetRoamerSpecies();
    CreateMon(mon, species, 50, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    ROAMER->species = species;
    ROAMER->level = 50;
    ROAMER->status = 0;
    ROAMER->active = TRUE;
    ROAMER->ivs = GetMonData(mon, MON_DATA_IVS);
    ROAMER->personality = GetMonData(mon, MON_DATA_PERSONALITY);
    ROAMER->hp = GetMonData(mon, MON_DATA_MAX_HP);
    ROAMER->cool = GetMonData(mon, MON_DATA_COOL);
    ROAMER->beauty = GetMonData(mon, MON_DATA_BEAUTY);
    ROAMER->cute = GetMonData(mon, MON_DATA_CUTE);
    ROAMER->smart = GetMonData(mon, MON_DATA_SMART);
    ROAMER->tough = GetMonData(mon, MON_DATA_TOUGH);
    sRoamerLocation[MAP_GRP] = ROAMER_MAP_GROUP;
    sRoamerLocation[MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
}

void InitRoamer(void)
{
    ClearRoamerData();
    CreateInitialRoamerMon();
}

// Creates the two remaining legendary beast roamers after the National Dex is obtained.
// The two beasts created are always different from the starter-dependent roamer.
// For example:
// - If player chose Charmander -> Suicune roams from One Island -> Raikou and Entei roam from National Dex
// - If player chose Squirtle -> Raikou roams from One Island -> Entei and Suicune roam from National Dex  
// - If player chose Bulbasaur -> Entei roams from One Island -> Raikou and Suicune roam from National Dex
void CreateLegendaryBeastRoamers(void)
{
    struct Pokemon *mon = &gEnemyParty[0];
    u32 i, beastIndex = 0;
    u16 allBeasts[3] = {SPECIES_RAIKOU, SPECIES_ENTEI, SPECIES_SUICUNE};
    u16 selectedBeasts[NUM_BEAST_ROAMERS];
    u16 existingRoamerSpecies = ROAMER->species;
    
    // Select the two beasts that are NOT the existing roamer
    for (i = 0; i < 3; i++)
    {
        if (allBeasts[i] != existingRoamerSpecies && beastIndex < NUM_BEAST_ROAMERS)
        {
            selectedBeasts[beastIndex] = allBeasts[i];
            beastIndex++;
        }
    }
    
    // Create the two remaining legendary beast roamers
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        CreateMon(mon, selectedBeasts[i], 50, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
        BEAST_ROAMER(i)->species = selectedBeasts[i];
        BEAST_ROAMER(i)->level = 50;
        BEAST_ROAMER(i)->status = 0;
        BEAST_ROAMER(i)->active = TRUE;
        BEAST_ROAMER(i)->ivs = GetMonData(mon, MON_DATA_IVS);
        BEAST_ROAMER(i)->personality = GetMonData(mon, MON_DATA_PERSONALITY);
        BEAST_ROAMER(i)->hp = GetMonData(mon, MON_DATA_MAX_HP);
        BEAST_ROAMER(i)->cool = GetMonData(mon, MON_DATA_COOL);
        BEAST_ROAMER(i)->beauty = GetMonData(mon, MON_DATA_BEAUTY);
        BEAST_ROAMER(i)->cute = GetMonData(mon, MON_DATA_CUTE);
        BEAST_ROAMER(i)->smart = GetMonData(mon, MON_DATA_SMART);
        BEAST_ROAMER(i)->tough = GetMonData(mon, MON_DATA_TOUGH);
        
        // Set initial locations
        sBeastRoamerLocations[i][MAP_GRP] = ROAMER_MAP_GROUP;
        sBeastRoamerLocations[i][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
    }
    
    BEAST_ROAMERS_ACTIVE = (1 << BEAST_SLOT_0) | (1 << BEAST_SLOT_1);
}

void GetLegendaryBeastNames(u8 *firstBeastName, u8 *secondBeastName)
{
    u16 existingRoamerSpecies = ROAMER->species;
    
    // Based on the existing roamer, determine which two beasts are now active
    switch (existingRoamerSpecies)
    {
        case SPECIES_RAIKOU:
            StringCopy(firstBeastName, GetSpeciesName(SPECIES_ENTEI));
            StringCopy(secondBeastName, GetSpeciesName(SPECIES_SUICUNE));
            break;
        case SPECIES_ENTEI:
            StringCopy(firstBeastName, GetSpeciesName(SPECIES_RAIKOU));
            StringCopy(secondBeastName, GetSpeciesName(SPECIES_SUICUNE));
            break;
        case SPECIES_SUICUNE:
        default:
            StringCopy(firstBeastName, GetSpeciesName(SPECIES_RAIKOU));
            StringCopy(secondBeastName, GetSpeciesName(SPECIES_ENTEI));
            break;
    }
}

void BufferLegendaryBeastNames(void)
{
    u8 firstBeastName[POKEMON_NAME_LENGTH + 1];
    u8 secondBeastName[POKEMON_NAME_LENGTH + 1];
    
    GetLegendaryBeastNames(firstBeastName, secondBeastName);
    StringCopy(gStringVar1, firstBeastName);
    StringCopy(gStringVar2, secondBeastName);
}

void BufferOriginalRoamerName(void)
{
    StringCopy(gStringVar3, GetSpeciesName(ROAMER->species));
}

void UpdateLocationHistoryForRoamer(void)
{
    sLocationHistory[2][MAP_GRP] = sLocationHistory[1][MAP_GRP];
    sLocationHistory[2][MAP_NUM] = sLocationHistory[1][MAP_NUM];

    sLocationHistory[1][MAP_GRP] = sLocationHistory[0][MAP_GRP];
    sLocationHistory[1][MAP_NUM] = sLocationHistory[0][MAP_NUM];

    sLocationHistory[0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
    sLocationHistory[0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
}

void RoamerMoveToOtherLocationSet(void)
{
    u8 mapNum = 0;

    if (!ROAMER->active)
        return;

    sRoamerLocation[MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    while (1)
    {
        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
        if (sRoamerLocation[MAP_NUM] != mapNum)
        {
            sRoamerLocation[MAP_NUM] = mapNum;
            return;
        }
    }
}

static void BeastRoamerMoveToOtherLocationSet(u8 beastId)
{
    u8 mapNum = 0;

    if (!(BEAST_ROAMERS_ACTIVE & (1 << beastId)) || !BEAST_ROAMER(beastId)->active)
        return;

    sBeastRoamerLocations[beastId][MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the beast roamer's current map
    while (1)
    {
        mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
        if (sBeastRoamerLocations[beastId][MAP_NUM] != mapNum)
        {
            sBeastRoamerLocations[beastId][MAP_NUM] = mapNum;
            return;
        }
    }
}


void RoamerMove(void)
{
    u8 locSet = 0;
    u32 i;

    // Move original roamer if active
    if (ROAMER->active)
    {
        if ((Random() % 16) == 0)
        {
            RoamerMoveToOtherLocationSet();
        }
        else
        {
            while (locSet < NUM_LOCATION_SETS)
            {
                // Find the location set that starts with the roamer's current map
                if (sRoamerLocation[MAP_NUM] == sRoamerLocations[locSet][0])
                {
                    u8 mapNum;
                    while (1)
                    {
                        // Choose a new map (excluding the first) within this set
                        // Also exclude a map if the roamer was there 2 moves ago
                        mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                        if (!(sLocationHistory[2][MAP_GRP] == ROAMER_MAP_GROUP
                           && sLocationHistory[2][MAP_NUM] == mapNum)
                           && mapNum != MAP_NUM(UNDEFINED))
                            break;
                    }
                    sRoamerLocation[MAP_NUM] = mapNum;
                    break;
                }
                locSet++;
            }
        }
    }
    
    // Move beast roamers regardless of original roamer status
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if (BEAST_ROAMERS_ACTIVE & (1 << i))
        {
            BeastRoamerMove(i);
        }
    }
}

static void BeastRoamerMove(u8 beastId)
{
    u8 locSet = 0;

    if ((Random() % 16) == 0)
    {
        BeastRoamerMoveToOtherLocationSet(beastId);
    }
    else
    {
        if (!(BEAST_ROAMERS_ACTIVE & (1 << beastId)) || !BEAST_ROAMER(beastId)->active)
            return;

        while (locSet < NUM_LOCATION_SETS)
        {
            // Find the location set that starts with the beast roamer's current map
            if (sBeastRoamerLocations[beastId][MAP_NUM] == sRoamerLocations[locSet][0])
            {
                u8 mapNum;
                while (1)
                {
                    // Choose a new map (excluding the first) within this set
                    mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                    if (mapNum != MAP_NUM(UNDEFINED))
                        break;
                }
                sBeastRoamerLocations[beastId][MAP_NUM] = mapNum;
                return;
            }
            locSet++;
        }
    }
}

bool8 IsRoamerAt(u8 mapGroup, u8 mapNum)
{
    if (ROAMER->active && mapGroup == sRoamerLocation[MAP_GRP] && mapNum == sRoamerLocation[MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

bool8 IsBeastRoamerAt(u8 beastId, u8 mapGroup, u8 mapNum)
{
    if ((BEAST_ROAMERS_ACTIVE & (1 << beastId)) && BEAST_ROAMER(beastId)->active && 
        mapGroup == sBeastRoamerLocations[beastId][MAP_GRP] && mapNum == sBeastRoamerLocations[beastId][MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

bool8 IsAnyRoamerAt(u8 mapGroup, u8 mapNum)
{
    u32 i;
    
    // Check original roamer
    if (IsRoamerAt(mapGroup, mapNum))
        return TRUE;
        
    // Check beast roamers
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if (IsBeastRoamerAt(i, mapGroup, mapNum))
            return TRUE;
    }
    
    return FALSE;
}

void CreateRoamerMonInstance(void)
{
    u32 status;
    struct Pokemon *mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, ROAMER->species, ROAMER->level, ROAMER->ivs, ROAMER->personality);
// The roamer's status field is u8, but SetMonData expects status to be u32, so will set the roamer's status
// using the status field and the following 3 bytes (cool, beauty, and cute).
#ifdef BUGFIX
    status = ROAMER->status;
    SetMonData(mon, MON_DATA_STATUS, &status);
#else
    SetMonData(mon, MON_DATA_STATUS, &ROAMER->status);
#endif
    SetMonData(mon, MON_DATA_HP, &ROAMER->hp);
    SetMonData(mon, MON_DATA_COOL, &ROAMER->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER->beauty);
    SetMonData(mon, MON_DATA_CUTE, &ROAMER->cute);
    SetMonData(mon, MON_DATA_SMART, &ROAMER->smart);
    SetMonData(mon, MON_DATA_TOUGH, &ROAMER->tough);
}

void CreateBeastRoamerMonInstance(u8 beastId)
{
    u32 status;
    struct Pokemon *mon = &gEnemyParty[0];
    struct Roamer *roamer = BEAST_ROAMER(beastId);
    
    ZeroEnemyPartyMons();
    CreateMonWithIVsPersonality(mon, roamer->species, roamer->level, roamer->ivs, roamer->personality);
#ifdef BUGFIX
    status = roamer->status;
    SetMonData(mon, MON_DATA_STATUS, &status);
#else
    SetMonData(mon, MON_DATA_STATUS, &roamer->status);
#endif
    SetMonData(mon, MON_DATA_HP, &roamer->hp);
    SetMonData(mon, MON_DATA_COOL, &roamer->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &roamer->beauty);
    SetMonData(mon, MON_DATA_CUTE, &roamer->cute);
    SetMonData(mon, MON_DATA_SMART, &roamer->smart);
    SetMonData(mon, MON_DATA_TOUGH, &roamer->tough);
}

bool8 TryStartRoamerEncounter(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    
    // Clear previous encounter tracking
    sLastEncounteredRoamerType = 0;
    sLastEncounteredBeastId = 0;
    
    // First check original roamer
    if (IsRoamerAt(mapGroup, mapNum) && ROAMER->active)
    {
        if (!IsWildLevelAllowedByRepel(ROAMER->level))
            return FALSE;
        sLastEncounteredRoamerType = 1; // Original roamer
        CreateRoamerMonInstance();
        return TRUE;
    }
    
    // Then check beast roamers
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if (IsBeastRoamerAt(i, mapGroup, mapNum))
        {
            if (!IsWildLevelAllowedByRepel(BEAST_ROAMER(i)->level))
                return FALSE;
            sLastEncounteredRoamerType = i + 2; // Beast roamer (offset by 2)
            sLastEncounteredBeastId = i;
            CreateBeastRoamerMonInstance(i);
            return TRUE;
        }
    }
    
    return FALSE;
}
void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    
    // Use encounter tracking first for more reliable identification
    if (sLastEncounteredRoamerType == 1) // Original roamer
    {
        ROAMER->hp = GetMonData(mon, MON_DATA_HP);
        ROAMER->status = GetMonData(mon, MON_DATA_STATUS);
        RoamerMoveToOtherLocationSet();
        return;
    }
    else if (sLastEncounteredRoamerType >= 2) // Beast roamer
    {
        u8 beastId = sLastEncounteredBeastId;
        if (beastId < NUM_BEAST_ROAMERS && (BEAST_ROAMERS_ACTIVE & (1 << beastId)))
        {
            BEAST_ROAMER(beastId)->hp = GetMonData(mon, MON_DATA_HP);
            BEAST_ROAMER(beastId)->status = GetMonData(mon, MON_DATA_STATUS);
            BeastRoamerMoveToOtherLocationSet(beastId);
            return;
        }
    }
    
    // Fallback: Check which roamer was battled and update accordingly
    if (IsRoamerAt(mapGroup, mapNum))
    {
        ROAMER->hp = GetMonData(mon, MON_DATA_HP);
        ROAMER->status = GetMonData(mon, MON_DATA_STATUS);
        RoamerMoveToOtherLocationSet();
        return;
    }
    
    // Check beast roamers
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if (IsBeastRoamerAt(i, mapGroup, mapNum))
        {
            BEAST_ROAMER(i)->hp = GetMonData(mon, MON_DATA_HP);
            BEAST_ROAMER(i)->status = GetMonData(mon, MON_DATA_STATUS);
            BeastRoamerMoveToOtherLocationSet(i);
            return;
        }
    }
}

void SetRoamerInactive(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    
    // Use encounter tracking first, then fall back to location-based detection
    if (sLastEncounteredRoamerType == 1) // Original roamer
    {
        ROAMER->active = FALSE;
        sLastEncounteredRoamerType = 0;
        return;
    }
    else if (sLastEncounteredRoamerType >= 2) // Beast roamer
    {
        u8 beastId = sLastEncounteredBeastId;
        if (beastId < NUM_BEAST_ROAMERS)
        {
            BEAST_ROAMER(beastId)->active = FALSE;
            BEAST_ROAMERS_ACTIVE &= ~(1 << beastId);
            sLastEncounteredRoamerType = 0;
            sLastEncounteredBeastId = 0;
            return;
        }
    }
    
    // Fallback: Check which roamer was caught/defeated and deactivate based on location
    if (IsRoamerAt(mapGroup, mapNum))
    {
        ROAMER->active = FALSE;
        return;
    }
    
    // Check beast roamers
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if (IsBeastRoamerAt(i, mapGroup, mapNum))
        {
            BEAST_ROAMER(i)->active = FALSE;
            BEAST_ROAMERS_ACTIVE &= ~(1 << i);
            return;
        }
    }
}

void GetRoamerLocation(u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[MAP_GRP];
    *mapNum = sRoamerLocation[MAP_NUM];
}

void GetBeastRoamerLocation(u8 beastId, u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sBeastRoamerLocations[beastId][MAP_GRP];
    *mapNum = sBeastRoamerLocations[beastId][MAP_NUM];
}

u16 GetRoamerLocationMapSectionId(void)
{
    if (!ROAMER->active)
        return MAPSEC_NONE;
    return Overworld_GetMapHeaderByGroupAndId(sRoamerLocation[MAP_GRP], sRoamerLocation[MAP_NUM])->regionMapSectionId;
}

u16 GetBeastRoamerLocationMapSectionId(u8 beastId)
{
    if (!(BEAST_ROAMERS_ACTIVE & (1 << beastId)) || !BEAST_ROAMER(beastId)->active)
        return MAPSEC_NONE;
    return Overworld_GetMapHeaderByGroupAndId(sBeastRoamerLocations[beastId][MAP_GRP], sBeastRoamerLocations[beastId][MAP_NUM])->regionMapSectionId;
}

// Debug function to check roamer status - call this from a field special if needed
void DebugPrintRoamerStatus(void)
{
    u32 i;
    
    // Original roamer status
    if (ROAMER->active)
    {
        // Can add debug prints here if your system supports them
        // DebugPrint("Original roamer %d active at map %d-%d", ROAMER->species, sRoamerLocation[MAP_GRP], sRoamerLocation[MAP_NUM]);
    }
    
    // Beast roamer status
    for (i = 0; i < NUM_BEAST_ROAMERS; i++)
    {
        if ((BEAST_ROAMERS_ACTIVE & (1 << i)) && BEAST_ROAMER(i)->active)
        {
            // DebugPrint("Beast roamer %d: species %d active at map %d-%d", i, BEAST_ROAMER(i)->species, sBeastRoamerLocations[i][MAP_GRP], sBeastRoamerLocations[i][MAP_NUM]);
        }
    }
}
