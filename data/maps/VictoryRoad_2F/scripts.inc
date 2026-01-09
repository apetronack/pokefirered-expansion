# 1 "data/maps/VictoryRoad_2F/scripts.pory"

# 2 "data/maps/VictoryRoad_2F/scripts.pory"
.set LOCALID_BOULDER1, 11
# 3 "data/maps/VictoryRoad_2F/scripts.pory"
.set LOCALID_BOULDER2, 12
# 4 "data/maps/VictoryRoad_2F/scripts.pory"

# 5 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_MapScripts::
# 6 "data/maps/VictoryRoad_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
# 7 "data/maps/VictoryRoad_2F/scripts.pory"
	.byte 0
# 8 "data/maps/VictoryRoad_2F/scripts.pory"

# 9 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_OnLoad::
# 10 "data/maps/VictoryRoad_2F/scripts.pory"
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
# 11 "data/maps/VictoryRoad_2F/scripts.pory"
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
# 12 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 13 "data/maps/VictoryRoad_2F/scripts.pory"

# 14 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_SetRockBarrier1::
# 15 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
# 16 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
# 17 "data/maps/VictoryRoad_2F/scripts.pory"
	return
# 18 "data/maps/VictoryRoad_2F/scripts.pory"

# 19 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_SetRockBarrier2::
# 20 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
# 21 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
# 22 "data/maps/VictoryRoad_2F/scripts.pory"
	return
# 23 "data/maps/VictoryRoad_2F/scripts.pory"

# 24 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_FloorSwitch1::
# 25 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 26 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
# 27 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
# 28 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
# 29 "data/maps/VictoryRoad_2F/scripts.pory"
	playse SE_ICE_BREAK
# 30 "data/maps/VictoryRoad_2F/scripts.pory"
	special DrawWholeMapView
# 31 "data/maps/VictoryRoad_2F/scripts.pory"
	waitse
# 32 "data/maps/VictoryRoad_2F/scripts.pory"
	copyobjectxytoperm LOCALID_BOULDER1
# 33 "data/maps/VictoryRoad_2F/scripts.pory"
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
# 34 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
# 35 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 36 "data/maps/VictoryRoad_2F/scripts.pory"

# 37 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
# 38 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
# 39 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 40 "data/maps/VictoryRoad_2F/scripts.pory"

# 41 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_FloorSwitch2::
# 42 "data/maps/VictoryRoad_2F/scripts.pory"
	lockall
# 43 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
# 44 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
# 45 "data/maps/VictoryRoad_2F/scripts.pory"
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
# 46 "data/maps/VictoryRoad_2F/scripts.pory"
	playse SE_ICE_BREAK
# 47 "data/maps/VictoryRoad_2F/scripts.pory"
	special DrawWholeMapView
# 48 "data/maps/VictoryRoad_2F/scripts.pory"
	waitse
# 49 "data/maps/VictoryRoad_2F/scripts.pory"
	copyobjectxytoperm LOCALID_BOULDER2
# 50 "data/maps/VictoryRoad_2F/scripts.pory"
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
# 51 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
# 52 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 53 "data/maps/VictoryRoad_2F/scripts.pory"

# 54 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
# 55 "data/maps/VictoryRoad_2F/scripts.pory"
	releaseall
# 56 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 57 "data/maps/VictoryRoad_2F/scripts.pory"

# 58 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_Dawson::
# 59 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat, VictoryRoad_2F_EventScript_DawsonDefeated
# 60 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_defeated TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_EventScript_DawsonHealPlayer
# 61 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 62 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 63 "data/maps/VictoryRoad_2F/scripts.pory"

# 64 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_DawsonDefeated::
# 65 "data/maps/VictoryRoad_2F/scripts.pory"
	special HealPlayerParty
# 66 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 67 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 68 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 69 "data/maps/VictoryRoad_2F/scripts.pory"

# 70 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_DawsonHealPlayer::
# 71 "data/maps/VictoryRoad_2F/scripts.pory"
	special HealPlayerParty
# 72 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 74 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 75 "data/maps/VictoryRoad_2F/scripts.pory"

# 76 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_Daisuke::
# 77 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
# 78 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 79 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 80 "data/maps/VictoryRoad_2F/scripts.pory"

# 81 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_Nelson::
# 82 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat, VictoryRoad_2F_EventScript_NelsonDefeated
# 83 "data/maps/VictoryRoad_2F/scripts.pory"
	goto_if_defeated TRAINER_JUGGLER_NELSON, VictoryRoad_2F_EventScript_NelsonHealPlayer
# 84 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 85 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 86 "data/maps/VictoryRoad_2F/scripts.pory"

# 87 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_NelsonDefeated::
# 88 "data/maps/VictoryRoad_2F/scripts.pory"
	special HealPlayerParty
# 89 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
# 90 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 91 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 92 "data/maps/VictoryRoad_2F/scripts.pory"

# 93 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_NelsonHealPlayer::
# 94 "data/maps/VictoryRoad_2F/scripts.pory"
	special HealPlayerParty
# 95 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
# 96 "data/maps/VictoryRoad_2F/scripts.pory"
	release
# 97 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 98 "data/maps/VictoryRoad_2F/scripts.pory"

# 99 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_Gregory::
# 100 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
# 101 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/VictoryRoad_2F/scripts.pory"
	end
# 103 "data/maps/VictoryRoad_2F/scripts.pory"

# 104 "data/maps/VictoryRoad_2F/scripts.pory"
VictoryRoad_2F_EventScript_Vincent::
# 105 "data/maps/VictoryRoad_2F/scripts.pory"
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
# 106 "data/maps/VictoryRoad_2F/scripts.pory"
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
# 107 "data/maps/VictoryRoad_2F/scripts.pory"
	end
