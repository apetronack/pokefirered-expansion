# 1 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 2 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_PROF_OAK,        4
# 3 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_BULBASAUR_BALL,  5
# 4 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_SQUIRTLE_BALL,   6
# 5 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_CHARMANDER_BALL, 7
# 6 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_RIVAL,           8
# 7 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_1,       9
# 8 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_2,       10
# 9 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 10 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
# 11 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2
# 12 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_SPECIES,   VAR_TEMP_3
# 13 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_ID,        VAR_TEMP_4
# 14 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 15 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ SHOWED_OAK_COMPLETE_DEX, FLAG_TEMP_2
# 16 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 17 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_MapScripts::
# 18 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_OnTransition
# 19 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
# 20 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
# 21 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.byte 0
# 22 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 23 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnTransition::
# 24 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_VISITED_OAKS_LAB
# 25 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene
# 26 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene
# 27 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished
# 28 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck
# 29 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 30 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 31 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck::
# 32 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
# 33 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 34 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 35 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished::
# 36 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
# 37 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 38 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 39 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene::
# 40 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 41 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 42 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_OAK
# 43 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 44 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 45 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene::
# 46 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 47 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 48 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 49 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 50 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnWarp::
# 51 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene
# 52 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 53 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 54 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene::
# 55 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 56 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 57 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 58 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnFrame::
# 59 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_ChooseStarterScene
# 60 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene
# 61 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 62 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 63 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene:: @ 8169002 
# 64 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 65 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_FACING, DIR_NORTH
# 66 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 67 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 68 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 69 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 70 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 71 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 72 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 73 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 74 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 75 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 76 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 77 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 78 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexScene::
# 79 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakSightingsOfRareMons
# 80 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 81 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth
# 82 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth
# 83 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 84 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 85 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalJustLetMeHandleEverything
# 86 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 87 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes
# 88 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth
# 89 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest
# 90 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 91 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTookBothPokedexUnits
# 92 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 93 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 94 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth
# 95 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth
# 96 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast
# 97 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest
# 98 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_1
# 99 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_2
# 100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData
# 102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
# 113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special EnableNationalPokedex
# 117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex
# 118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllCompleteThePokedex
# 119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
# 128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth::
# 132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest::
# 141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth::
# 151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth::
# 160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest::
# 165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth::
# 170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth::
# 175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth
# 176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast::
# 182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest::
# 188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk::
# 193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth::
# 201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_ChooseStarterScene::
# 209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_DUMMY
# 223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting
# 225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 60
# 227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThreeMonsChooseOne
# 228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalReact
# 231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe
# 233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival
# 234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
# 235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakEnter::
# 239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerEnter::
# 248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalReact::
# 259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
# 264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
# 267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHeyDontGoAwayYet
# 269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp
# 271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp::
# 276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
# 280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 1
# 282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
# 286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 2
# 288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
# 292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 3
# 294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattle::
# 298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
# 307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander
# 309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur
# 310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle
# 311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ The scripts for the rival approaching the player for battle are a bit bloated because
# 314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ both the player and rival can be in 3 different positions, so theres 9 different approaches
# 315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ NOTE: Names below refer to the Rival's mon (e.g. for RivalBattleSquirtle, player has Charmander)
# 316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle::
# 318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft
# 319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid
# 320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight
# 321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft::
# 324 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft
# 325 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 326 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 327 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 328 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 329 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid::
# 330 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid
# 331 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 332 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 333 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 334 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 335 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight::
# 336 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight
# 337 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 338 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 339 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 340 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 341 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle::
# 342 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 343 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 344 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 345 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 346 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft::
# 347 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 348 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 349 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 350 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 351 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 352 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 353 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 354 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 355 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid::
# 356 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 357 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 358 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 359 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 360 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 361 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 362 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 363 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight::
# 364 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 365 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 366 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 367 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 368 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 369 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 370 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander::
# 371 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft
# 372 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid
# 373 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight
# 374 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 375 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 376 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft::
# 377 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft
# 378 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 379 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 380 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 381 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 382 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid::
# 383 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid
# 384 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 385 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 386 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 387 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 388 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight::
# 389 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight
# 390 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 391 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 392 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 393 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 394 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander::
# 395 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_CHARMANDER, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 396 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 397 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 398 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 399 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft::
# 400 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 401 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 402 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 403 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 404 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 405 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 406 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 407 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 408 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 409 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid::
# 410 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 411 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 412 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 413 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 414 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 415 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 416 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 417 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 418 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight::
# 419 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 420 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 421 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 422 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 423 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 424 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 425 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 426 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur::
# 427 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft
# 428 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid
# 429 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight
# 430 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 431 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 432 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft::
# 433 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft
# 434 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 435 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 436 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 437 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 438 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid::
# 439 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid
# 440 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 441 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 442 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 443 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 444 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight::
# 445 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight
# 446 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 447 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 448 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 449 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 450 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur::
# 451 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_BULBASAUR, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 452 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 453 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 454 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 455 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft::
# 456 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 457 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 458 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 459 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 460 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 461 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 462 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 463 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid::
# 464 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 465 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 466 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 467 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 468 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 469 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 470 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight::
# 471 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 472 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 473 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 474 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 475 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 476 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle::
# 477 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special HealPlayerParty
# 478 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon
# 479 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 480 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 481 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft
# 482 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid
# 483 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight
# 484 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 485 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_EXIT
# 486 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 487 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
# 488 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
# 489 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 490 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 491 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 492 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft::
# 493 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft
# 494 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 495 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 496 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 497 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 498 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid::
# 499 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid
# 500 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 501 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 502 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 503 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 504 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight::
# 505 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight
# 506 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight
# 507 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 508 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 509 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 510 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft::
# 511 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 512 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 513 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 514 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 515 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 516 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 517 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 518 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 519 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 520 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight::
# 521 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 522 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 523 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 524 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 525 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 526 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 527 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 528 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 529 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 530 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid::
# 531 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 532 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 533 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 534 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 535 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 536 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 537 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 538 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 539 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 540 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 541 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle::
# 542 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 543 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 544 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 545 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 546 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 547 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 548 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 549 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight::
# 550 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 551 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 552 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 553 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 554 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 555 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 556 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 557 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Rival::
# 558 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 559 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 560 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter
# 561 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter
# 562 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround
# 563 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 564 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 565 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 566 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter::
# 567 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer
# 568 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 569 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 570 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 571 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter::
# 572 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher
# 573 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 574 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 575 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 576 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ProfOak::
# 577 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 578 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 579 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set SHOWED_OAK_COMPLETE_DEX, PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex
# 580 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 581 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 582 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene
# 583 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 584 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls
# 585 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1, PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene
# 586 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
# 587 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
# 588 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakWhichOneWillYouChoose
# 589 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 590 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 591 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 592 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex::
# 593 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 594 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 595 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 596 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 597 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
# 598 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon
# 599 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 600 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 601 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 602 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
# 603 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow
# 604 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 605 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 606 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 607 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene::
# 608 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe
# 609 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 610 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 611 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
# 612 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 613 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 614 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 615 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeitem ITEM_OAKS_PARCEL
# 616 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
# 617 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 618 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps
# 619 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 620 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth
# 621 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth
# 622 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 623 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 624 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 625 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
# 626 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 627 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 628 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_PIN
# 629 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
# 630 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 631 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_Delay48
# 632 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 633 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth
# 634 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast
# 635 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest
# 636 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth
# 637 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
# 638 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 639 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth
# 640 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth
# 641 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast
# 642 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest
# 643 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
# 644 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 645 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 646 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
# 647 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 648 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
# 649 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 650 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 651 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 652 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 653 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 25
# 654 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 655 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 656 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 657 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 658 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 659 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 660 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 661 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
# 662 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 663 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 664 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 665 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 666 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SHARE_EXP
# 667 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 668 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1
# 669 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
# 670 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 671 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
# 672 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 1
# 673 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
# 674 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
# 675 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth
# 676 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth
# 677 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 678 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 679 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap
# 680 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 681 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 682 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 683 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 684 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 685 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 686 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 687 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 688 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
# 689 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
# 690 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 691 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
# 692 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 1
# 693 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 694 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 695 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 696 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth::
# 697 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 698 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 699 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 700 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 701 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth::
# 702 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth
# 703 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 704 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 705 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 706 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast::
# 707 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 708 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast
# 709 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 710 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 711 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 712 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest::
# 713 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 714 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 715 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 716 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 717 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast::
# 718 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 719 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 720 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 721 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 722 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 723 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver::
# 724 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 725 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 726 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 727 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 728 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth::
# 729 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 730 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 731 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 732 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 733 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth::
# 734 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 735 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 736 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 737 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 738 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth::
# 739 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth
# 740 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 741 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 742 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 743 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 744 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 745 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast::
# 746 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 747 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 748 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 749 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 750 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 751 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest::
# 752 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 753 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 754 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 755 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 756 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast::
# 757 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 758 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 759 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 760 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 761 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 762 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk::
# 763 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 764 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 765 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 766 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 767 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 768 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk::
# 769 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 770 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 771 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 772 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 773 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 774 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 775 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth::
# 776 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 777 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 778 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 779 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 780 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 781 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 782 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 783 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls::
# 784 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 785 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 786 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 787 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 788 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 789 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 790 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_0x8009, 1, PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls  @ Player only has starter
# 791 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 792 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 793 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 794 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedex::
# 795 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 796 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, PalletTown_ProfessorOaksLab_EventScript_DexCompleted
# 797 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 798 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 799 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 800 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexCompleted::
# 801 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 802 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 803 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PokedexRating_Text_Wroooaaarrr
# 804 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 805 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth
# 806 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth
# 807 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast
# 808 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest
# 809 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 810 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 811 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 812 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 70
# 813 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 814 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag SHOWED_OAK_COMPLETE_DEX
# 815 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 816 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 817 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 818 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth::
# 819 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth
# 820 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 821 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 822 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 823 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth::
# 824 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth
# 825 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 826 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 827 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 828 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast::
# 829 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedEast
# 830 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 831 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 832 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 833 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest::
# 834 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedWest
# 835 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 836 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 837 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 838 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth::
# 839 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 840 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 841 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 842 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 843 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 844 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 845 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 846 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 847 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth::
# 848 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 849 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 850 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 851 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 852 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 853 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 854 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 855 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 856 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedEast::
# 857 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 858 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 859 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 860 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 861 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 862 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 863 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 864 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 865 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedWest::
# 866 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 867 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 868 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 869 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 870 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 871 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 872 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 873 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 874 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 875 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_Search:
# 876 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 877 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 878 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 879 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 880 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 881 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 882 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 883 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 884 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 885 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 886 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 887 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 888 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 889 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 890 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 891 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 892 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 893 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 894 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 895 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 896 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 897 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 898 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 899 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 900 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 901 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 902 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 903 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_VerticalPacing:
# 904 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 905 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 906 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 907 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 908 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 909 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 910 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 911 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 912 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 913 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 914 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene::
# 915 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 916 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 917 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 918 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 919 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 920 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakFavorToAskYouPlayer
# 921 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 922 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 923 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 924 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene::
# 925 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 926 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 927 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 928 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls::
# 929 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 930 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special QuestLog_CutRecording
# 931 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 932 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls
# 933 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	checkitem ITEM_POKE_BALL
# 934 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls
# 935 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 936 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 937 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 938 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls::
# 939 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ROUTE22, 2, PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls
# 940 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 941 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 942 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 943 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls::
# 944 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakAddedNothingToPokedex
# 945 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 946 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
# 947 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 948 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 949 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 950 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait::
# 951 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait
# 952 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 953 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 954 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 955 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls::
# 956 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakComeSeeMeSometime
# 957 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 958 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 959 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 960 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth::
# 961 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 962 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 963 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 964 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 965 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 966 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 967 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 968 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest::
# 969 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 970 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 971 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 972 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 973 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 974 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 975 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 976 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 977 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth::
# 978 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 979 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 980 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 981 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 982 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 983 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 984 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 985 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth::
# 986 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 987 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 988 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 989 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 990 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 991 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 992 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 993 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest::
# 994 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 995 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 996 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 997 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 998 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 999 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1000 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1001 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1002 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast::
# 1003 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1004 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1005 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1006 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 1007 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1008 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1009 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1010 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1011 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth::
# 1012 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1013 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1014 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1015 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1016 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1017 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth::
# 1018 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 1019 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1020 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1021 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1022 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1023 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest::
# 1024 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1025 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1026 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1027 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1028 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1029 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth::
# 1030 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 1031 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1032 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1033 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1034 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1035 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExit::
# 1036 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1037 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1038 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1039 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1040 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth::
# 1041 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1042 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1043 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1044 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1045 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest::
# 1046 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 1047 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1048 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1049 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1050 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth::
# 1051 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1052 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1053 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1054 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1055 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1056 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1057 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 1058 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 1059 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1060 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1061 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalEnter::
# 1062 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1063 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1064 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1065 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1066 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1067 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1068 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1069 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1070 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExit::
# 1071 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1072 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1073 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1074 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1075 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1076 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1077 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1078 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1079 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_BulbasaurBall::
# 1080 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1081 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1082 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 0
# 1083 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
# 1084 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_CHARMANDER
# 1085 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_CHARMANDER_BALL
# 1086 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1087 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1088 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1089 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1090 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1091 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1092 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice::
# 1093 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceRight
# 1094 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1095 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 1096 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1097 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur
# 1098 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle
# 1099 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander
# 1100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur::
# 1103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingBulbasaur, MSGBOX_YESNO
# 1104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle::
# 1109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingSquirtle, MSGBOX_YESNO
# 1110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander::
# 1115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingCharmander, MSGBOX_YESNO
# 1116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter::
# 1121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ChoseStarter::
# 1126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThisMonIsEnergetic
# 1129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 1130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
# 1132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	givemon PLAYER_STARTER_SPECIES, 5
# 1133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
# 1134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
# 1135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedMonFromOak
# 1136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 1140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_GiveNicknameToStarter
# 1141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
EventScript_GiveNicknameToStarter::
# 1145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 1146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_ChangePokemonNickname
# 1147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter::
# 1151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 1152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander
# 1153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur
# 1154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle
# 1155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander::
# 1158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander
# 1159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle::
# 1164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle
# 1165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur::
# 1170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur
# 1171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter::
# 1176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen
# 1178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject RIVAL_STARTER_ID
# 1179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 1180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, RIVAL_STARTER_SPECIES
# 1181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_RivalReceivedMonFromOak
# 1182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
# 1186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_OPENED_START_MENU, PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene
# 1187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene::
# 1191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 1192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander::
# 1195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle::
# 1206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur::
# 1215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SquirtleBall::
# 1223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 1
# 1226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_BULBASAUR
# 1228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_BULBASAUR_BALL
# 1229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CharmanderBall::
# 1236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 2
# 1239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
# 1240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_SQUIRTLE_BALL
# 1242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
# 1249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon
# 1250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1::
# 1254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear
# 1257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear::
# 1262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 5
# 1263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow
# 1264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2::
# 1268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear
# 1271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear::
# 1276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_DAISY, 0
# 1277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_DaisyWillGroomMons
# 1278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide3::
# 1282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 2
# 1285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsAuthorityOnMons
# 1286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Pokedex::
# 1290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
# 1291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Computer::
# 1294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
# 1295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeftSign::
# 1298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
# 1299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSign::
# 1302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 1303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RightSignAlt
# 1304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_SaveOptionInMenu
# 1305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSignAlt::
# 1309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
# 1310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
