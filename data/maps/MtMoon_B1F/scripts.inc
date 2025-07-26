# 1 "data/maps/MtMoon_B1F/scripts.pory"

# 2 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_MapScripts::
# 3 "data/maps/MtMoon_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtMoon_B1F_OnResume
# 4 "data/maps/MtMoon_B1F/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B1F_OnTransition
# 5 "data/maps/MtMoon_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/MtMoon_B1F/scripts.pory"

# 7 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_OnResume::
# 8 "data/maps/MtMoon_B1F/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MtMoon_B1F_EventScript_TryRemoveStaticMon
# 9 "data/maps/MtMoon_B1F/scripts.pory"
	end
# 10 "data/maps/MtMoon_B1F/scripts.pory"

# 11 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_EventScript_TryRemoveStaticMon::
# 12 "data/maps/MtMoon_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 14 "data/maps/MtMoon_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/MtMoon_B1F/scripts.pory"
	return
# 16 "data/maps/MtMoon_B1F/scripts.pory"

# 17 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_OnTransition::
# 18 "data/maps/MtMoon_B1F/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_B1F
# 19 "data/maps/MtMoon_B1F/scripts.pory"
	call_if_unset FLAG_FOUGHT_CHIMCHAR, MtMoon_B1F_EventScript_ShowChimchar
# 20 "data/maps/MtMoon_B1F/scripts.pory"
	end
# 21 "data/maps/MtMoon_B1F/scripts.pory"

# 22 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_EventScript_ShowChimchar::
# 23 "data/maps/MtMoon_B1F/scripts.pory"
	clearflag FLAG_HIDE_CHIMCHAR
# 24 "data/maps/MtMoon_B1F/scripts.pory"
	return
# 25 "data/maps/MtMoon_B1F/scripts.pory"

# 26 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_EventScript_Chimchar::
# 27 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 28 "data/maps/MtMoon_B1F/scripts.pory"
	lock
# 29 "data/maps/MtMoon_B1F/scripts.pory"
	faceplayer
# 30 "data/maps/MtMoon_B1F/scripts.pory"
	setwildbattle SPECIES_CHIMCHAR, 13
# 31 "data/maps/MtMoon_B1F/scripts.pory"
	waitse
# 32 "data/maps/MtMoon_B1F/scripts.pory"
	playmoncry SPECIES_CHIMCHAR, CRY_MODE_ENCOUNTER
# 33 "data/maps/MtMoon_B1F/scripts.pory"
	waitmoncry
# 34 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 35 "data/maps/MtMoon_B1F/scripts.pory"
	dowildbattle
# 36 "data/maps/MtMoon_B1F/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 37 "data/maps/MtMoon_B1F/scripts.pory"
	special QuestLog_CutRecording
# 38 "data/maps/MtMoon_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMoon_B1F_EventScript_FoughtChimchar
# 40 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMoon_B1F_EventScript_FoughtChimchar
# 41 "data/maps/MtMoon_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMoon_B1F_EventScript_FoughtChimchar
# 42 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_FOUGHT_CHIMCHAR
# 43 "data/maps/MtMoon_B1F/scripts.pory"
	release
# 44 "data/maps/MtMoon_B1F/scripts.pory"
	end
# 45 "data/maps/MtMoon_B1F/scripts.pory"

# 46 "data/maps/MtMoon_B1F/scripts.pory"
MtMoon_B1F_EventScript_FoughtChimchar::
# 47 "data/maps/MtMoon_B1F/scripts.pory"
	setflag FLAG_FOUGHT_CHIMCHAR
# 48 "data/maps/MtMoon_B1F/scripts.pory"
	goto EventScript_RemoveStaticMon
# 49 "data/maps/MtMoon_B1F/scripts.pory"
	end
