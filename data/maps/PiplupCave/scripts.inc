# 1 "data/maps/PiplupCave/scripts.pory"

# 2 "data/maps/PiplupCave/scripts.pory"
PiplupCave_MapScripts::
# 3 "data/maps/PiplupCave/scripts.pory"
    map_script MAP_SCRIPT_ON_RESUME, PiplupCave_OnResume
# 4 "data/maps/PiplupCave/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, PiplupCave_OnTransition
# 5 "data/maps/PiplupCave/scripts.pory"
    .byte 0
# 6 "data/maps/PiplupCave/scripts.pory"

# 7 "data/maps/PiplupCave/scripts.pory"
PiplupCave_OnResume::
# 8 "data/maps/PiplupCave/scripts.pory"
    call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PiplupCave_EventScript_TryRemoveStaticMon
# 9 "data/maps/PiplupCave/scripts.pory"
    end
# 10 "data/maps/PiplupCave/scripts.pory"

# 11 "data/maps/PiplupCave/scripts.pory"
PiplupCave_EventScript_TryRemoveStaticMon::
# 12 "data/maps/PiplupCave/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/PiplupCave/scripts.pory"
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 14 "data/maps/PiplupCave/scripts.pory"
    removeobject VAR_LAST_TALKED
# 15 "data/maps/PiplupCave/scripts.pory"
    return
# 16 "data/maps/PiplupCave/scripts.pory"

# 17 "data/maps/PiplupCave/scripts.pory"
PiplupCave_OnTransition::
# 18 "data/maps/PiplupCave/scripts.pory"
    setworldmapflag FLAG_WORLD_MAP_PIPLUP_CAVE
# 19 "data/maps/PiplupCave/scripts.pory"
    call_if_unset FLAG_FOUGHT_PIPLUP, PiplupCave_EventScript_ShowPiplup
# 20 "data/maps/PiplupCave/scripts.pory"
    end
# 21 "data/maps/PiplupCave/scripts.pory"

# 22 "data/maps/PiplupCave/scripts.pory"
PiplupCave_EventScript_ShowPiplup::
# 23 "data/maps/PiplupCave/scripts.pory"
    clearflag FLAG_HIDE_PIPLUP
# 24 "data/maps/PiplupCave/scripts.pory"
    return
# 25 "data/maps/PiplupCave/scripts.pory"

# 26 "data/maps/PiplupCave/scripts.pory"
PiplupCave_EventScript_Piplup::
# 27 "data/maps/PiplupCave/scripts.pory"
    goto_if_questlog EventScript_ReleaseEnd
# 28 "data/maps/PiplupCave/scripts.pory"
    lock
# 29 "data/maps/PiplupCave/scripts.pory"
    faceplayer
# 30 "data/maps/PiplupCave/scripts.pory"
    setwildbattle SPECIES_PIPLUP, 15
# 31 "data/maps/PiplupCave/scripts.pory"
    waitse
# 32 "data/maps/PiplupCave/scripts.pory"
    playmoncry SPECIES_PIPLUP, CRY_MODE_ENCOUNTER
# 33 "data/maps/PiplupCave/scripts.pory"
    waitmoncry
# 34 "data/maps/PiplupCave/scripts.pory"
    setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 35 "data/maps/PiplupCave/scripts.pory"
    dowildbattle
# 36 "data/maps/PiplupCave/scripts.pory"
    clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 37 "data/maps/PiplupCave/scripts.pory"
    special QuestLog_CutRecording
# 38 "data/maps/PiplupCave/scripts.pory"
    specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/PiplupCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, PiplupCave_EventScript_FoughtPiplup
# 40 "data/maps/PiplupCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PiplupCave_EventScript_FoughtPiplup
# 41 "data/maps/PiplupCave/scripts.pory"
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PiplupCave_EventScript_FoughtPiplup
# 42 "data/maps/PiplupCave/scripts.pory"
    setflag FLAG_FOUGHT_PIPLUP
# 43 "data/maps/PiplupCave/scripts.pory"
    release
# 44 "data/maps/PiplupCave/scripts.pory"
    end
# 45 "data/maps/PiplupCave/scripts.pory"

# 46 "data/maps/PiplupCave/scripts.pory"
PiplupCave_EventScript_FoughtPiplup::
# 47 "data/maps/PiplupCave/scripts.pory"
    setflag FLAG_FOUGHT_PIPLUP
# 48 "data/maps/PiplupCave/scripts.pory"
    goto EventScript_RemoveStaticMon
# 49 "data/maps/PiplupCave/scripts.pory"
    end
