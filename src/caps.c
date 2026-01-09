#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    // Level cap is chosen according to the first unset flag in `sLevelCapFlagMap`
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_BADGE01_GET,    13}, // TRAINER_LEADER_BROCK
        {FLAG_GOT_FAME_CHECKER, 20}, // TRAINER_RIVAL_CERULEAN
        {FLAG_BADGE02_GET,    24}, // TRAINER_LEADER_MISTY
        {FLAG_BEAT_RIVAL_3,   27}, // TRAINER_RIVAL_SS_ANNE
        {FLAG_BADGE03_GET,    29}, // TRAINER_LEADER_LT_SURGE
        {FLAG_HIDE_CELADON_ROCKETS, 35}, // TRAINER_BOSS_GIOVANNI
        {FLAG_BEAT_RIVAL_4, 37}, // TRAINER_RIVAL_POKEMON_TOWER
        {FLAG_BADGE04_GET,    39}, // TRAINER_LEADER_ERIKA
        {FLAG_BEAT_RIVAL_5,   45}, // TRAINER_RIVAL_SILPH
        {FLAG_HIDE_SAFFRON_ROCKETS, 47}, // TRAINER_BOSS_GIOVANNI_2
        {FLAG_BADGE05_GET,    49}, // TRAINER_LEADER_SABRINA
        {FLAG_BADGE06_GET,    55}, // TRAINER_LEADER_KOGA
        {FLAG_BADGE07_GET,    57}, // TRAINER_LEADER_BLAINE
        {FLAG_BADGE08_GET,    59}, // TRAINER_LEADER_GIOVANNI
        {FLAG_BEAT_RIVAL_6,   61}, // TRAINER_RIVAL_ROUTE22_LATE
        {FLAG_DEFEATED_LORELEI_1X, 69}, // TRAINER_ELITE_FOUR_LORELEI
        {FLAG_DEFEATED_BRUNO_1X,   70}, // TRAINER_ELITE_FOUR_BRUNO
        {FLAG_DEFEATED_AGATHA_1X,  71}, // TRAINER_ELITE_FOUR_AGATHA
        {FLAG_DEFEATED_LANCE_1X,   72}, // TRAINER_ELITE_FOUR_LANCE
        {FLAG_DEFEATED_CHAMP_1X,   73}, // TRAINER_CHAMPION_FIRST
        {FLAG_SYS_GAME_CLEAR,  MAX_LEVEL},
    };
    
    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{

    static const u16 sEvCapFlagMap[][2] = {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, 30},
        {FLAG_BADGE02_GET, 90},
        {FLAG_BADGE03_GET, 150},
        {FLAG_BADGE04_GET, 210},
        {FLAG_BADGE05_GET, 270},
        {FLAG_BADGE06_GET, 330},
        {FLAG_BADGE07_GET, 390},
        {FLAG_BADGE08_GET, 450},
        {FLAG_SYS_GAME_CLEAR, MAX_TOTAL_EVS},
    };

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}
