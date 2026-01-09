# 1 "data/maps/PokemonTower_2F/scripts.pory"

# 2 "data/maps/PokemonTower_2F/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data/maps/PokemonTower_2F/scripts.pory"

# 4 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_MapScripts::
# 5 "data/maps/PokemonTower_2F/scripts.pory"
	.byte 0
# 6 "data/maps/PokemonTower_2F/scripts.pory"

# 7 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_Channeler::
# 8 "data/maps/PokemonTower_2F/scripts.pory"
	msgbox PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts, MSGBOX_NPC
# 9 "data/maps/PokemonTower_2F/scripts.pory"
	end
# 10 "data/maps/PokemonTower_2F/scripts.pory"

# 11 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalTriggerRight::
# 12 "data/maps/PokemonTower_2F/scripts.pory"
	lockall
# 13 "data/maps/PokemonTower_2F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 14 "data/maps/PokemonTower_2F/scripts.pory"
	goto PokemonTower_2F_EventScript_Rival
# 15 "data/maps/PokemonTower_2F/scripts.pory"
	end
# 16 "data/maps/PokemonTower_2F/scripts.pory"

# 17 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalTriggerDown::
# 18 "data/maps/PokemonTower_2F/scripts.pory"
	lockall
# 19 "data/maps/PokemonTower_2F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 20 "data/maps/PokemonTower_2F/scripts.pory"
	goto PokemonTower_2F_EventScript_Rival
# 21 "data/maps/PokemonTower_2F/scripts.pory"
	end
# 22 "data/maps/PokemonTower_2F/scripts.pory"

# 23 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_Rival::
# 24 "data/maps/PokemonTower_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 25 "data/maps/PokemonTower_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 26 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalFacePlayerRight
# 27 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalFacePlayerDown
# 28 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 29 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 30 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 31 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 32 "data/maps/PokemonTower_2F/scripts.pory"
	msgbox PokemonTower_2F_Text_RivalIntro
# 33 "data/maps/PokemonTower_2F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
# 34 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, PokemonTower_2F_EventScript_RivalSquirtle
# 35 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, PokemonTower_2F_EventScript_RivalBulbasaur
# 36 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, PokemonTower_2F_EventScript_RivalCharmander
# 37 "data/maps/PokemonTower_2F/scripts.pory"
	msgbox PokemonTower_2F_Text_RivalPostBattle
# 38 "data/maps/PokemonTower_2F/scripts.pory"
	closemessage
# 39 "data/maps/PokemonTower_2F/scripts.pory"
	setflag FLAG_BEAT_RIVAL_4
# 40 "data/maps/PokemonTower_2F/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 41 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalExitRight
# 42 "data/maps/PokemonTower_2F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalExitDown
# 43 "data/maps/PokemonTower_2F/scripts.pory"
	playse SE_EXIT
# 44 "data/maps/PokemonTower_2F/scripts.pory"
	delay 25
# 45 "data/maps/PokemonTower_2F/scripts.pory"
	fadedefaultbgm
# 46 "data/maps/PokemonTower_2F/scripts.pory"
	removeobject LOCALID_RIVAL
# 47 "data/maps/PokemonTower_2F/scripts.pory"
	setvar VAR_MAP_SCENE_POKEMON_TOWER_2F, 1
# 48 "data/maps/PokemonTower_2F/scripts.pory"
	releaseall
# 49 "data/maps/PokemonTower_2F/scripts.pory"
	end
# 50 "data/maps/PokemonTower_2F/scripts.pory"

# 51 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalFacePlayerRight::
# 52 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 53 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 54 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 55 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 56 "data/maps/PokemonTower_2F/scripts.pory"

# 57 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalFacePlayerDown::
# 58 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 59 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 60 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 61 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 62 "data/maps/PokemonTower_2F/scripts.pory"

# 63 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalSquirtle::
# 64 "data/maps/PokemonTower_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE, PokemonTower_2F_Text_RivalDefeat
# 65 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 66 "data/maps/PokemonTower_2F/scripts.pory"

# 67 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalBulbasaur::
# 68 "data/maps/PokemonTower_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR, PokemonTower_2F_Text_RivalDefeat
# 69 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 70 "data/maps/PokemonTower_2F/scripts.pory"

# 71 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalCharmander::
# 72 "data/maps/PokemonTower_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER, PokemonTower_2F_Text_RivalDefeat
# 73 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 74 "data/maps/PokemonTower_2F/scripts.pory"

# 75 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalExitRight::
# 76 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitRight
# 77 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 78 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 79 "data/maps/PokemonTower_2F/scripts.pory"

# 80 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_EventScript_RivalExitDown::
# 81 "data/maps/PokemonTower_2F/scripts.pory"
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitDown
# 82 "data/maps/PokemonTower_2F/scripts.pory"
	waitmovement 0
# 83 "data/maps/PokemonTower_2F/scripts.pory"
	return
# 84 "data/maps/PokemonTower_2F/scripts.pory"

# 85 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_Movement_RivalExitRight::
# 86 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 87 "data/maps/PokemonTower_2F/scripts.pory"
	walk_right
# 88 "data/maps/PokemonTower_2F/scripts.pory"
	walk_right
# 89 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 90 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 91 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 92 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 93 "data/maps/PokemonTower_2F/scripts.pory"
	walk_in_place_faster_right
# 94 "data/maps/PokemonTower_2F/scripts.pory"
	step_end
# 95 "data/maps/PokemonTower_2F/scripts.pory"

# 96 "data/maps/PokemonTower_2F/scripts.pory"
PokemonTower_2F_Movement_RivalExitDown::
# 97 "data/maps/PokemonTower_2F/scripts.pory"
	walk_right
# 98 "data/maps/PokemonTower_2F/scripts.pory"
	walk_right
# 99 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 100 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 101 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 102 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 103 "data/maps/PokemonTower_2F/scripts.pory"
	walk_down
# 104 "data/maps/PokemonTower_2F/scripts.pory"
	walk_in_place_faster_right
# 105 "data/maps/PokemonTower_2F/scripts.pory"
	step_end
