# 1 "data/maps/LavenderTown/scripts.pory"

# 2 "data/maps/LavenderTown/scripts.pory"
.set LOCAL_ID_TOWER_GUARDIAN, 4
# 3 "data/maps/LavenderTown/scripts.pory"

# 4 "data/maps/LavenderTown/scripts.pory"
LavenderTown_MapScripts::
# 5 "data/maps/LavenderTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
# 6 "data/maps/LavenderTown/scripts.pory"
	.byte 0
# 7 "data/maps/LavenderTown/scripts.pory"

# 8 "data/maps/LavenderTown/scripts.pory"
LavenderTown_OnTransition::
# 9 "data/maps/LavenderTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
# 10 "data/maps/LavenderTown/scripts.pory"
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
# 11 "data/maps/LavenderTown/scripts.pory"
	setflag FLAG_HIDE_SS_ANNE_RIVAL
# 12 "data/maps/LavenderTown/scripts.pory"
	call_if_unset FLAG_HIDE_POKEMON_TOWER_GUARDIAN, LavenderTown_EventScript_BlockPokemonTower
# 13 "data/maps/LavenderTown/scripts.pory"
	end
# 14 "data/maps/LavenderTown/scripts.pory"

# 15 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_BlockPokemonTower::
# 16 "data/maps/LavenderTown/scripts.pory"
	setobjectxyperm LOCAL_ID_TOWER_GUARDIAN, 18, 7
# 17 "data/maps/LavenderTown/scripts.pory"
	return
# 18 "data/maps/LavenderTown/scripts.pory"

# 19 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_LittleGirl::
# 20 "data/maps/LavenderTown/scripts.pory"
	lock
# 21 "data/maps/LavenderTown/scripts.pory"
	faceplayer
# 22 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
# 23 "data/maps/LavenderTown/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
# 24 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_JustImaginingWhiteHand
# 25 "data/maps/LavenderTown/scripts.pory"
	release
# 26 "data/maps/LavenderTown/scripts.pory"
	end
# 27 "data/maps/LavenderTown/scripts.pory"

# 28 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_LittleGirlBelieve::
# 29 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_SoThereAreBelievers
# 30 "data/maps/LavenderTown/scripts.pory"
	release
# 31 "data/maps/LavenderTown/scripts.pory"
	end
# 32 "data/maps/LavenderTown/scripts.pory"

# 33 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_WorkerM::
# 34 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
# 35 "data/maps/LavenderTown/scripts.pory"
	end
# 36 "data/maps/LavenderTown/scripts.pory"

# 37 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_Boy::
# 38 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
# 39 "data/maps/LavenderTown/scripts.pory"
	end
# 40 "data/maps/LavenderTown/scripts.pory"

# 41 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_TownSign::
# 42 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
# 43 "data/maps/LavenderTown/scripts.pory"
	end
# 44 "data/maps/LavenderTown/scripts.pory"

# 45 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_SilphScopeNotice::
# 46 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
# 47 "data/maps/LavenderTown/scripts.pory"
	end
# 48 "data/maps/LavenderTown/scripts.pory"

# 49 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_VolunteerHouseSign::
# 50 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
# 51 "data/maps/LavenderTown/scripts.pory"
	end
# 52 "data/maps/LavenderTown/scripts.pory"

# 53 "data/maps/LavenderTown/scripts.pory"
LavenderTown_EventScript_PokemonTowerSign::
# 54 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
# 55 "data/maps/LavenderTown/scripts.pory"
	end

LavenderTown_EventScript_TowerGuardian::
# 60 "data/maps/LavenderTown/scripts.pory"
	lock
# 61 "data/maps/LavenderTown/scripts.pory"
	faceplayer
# 62 "data/maps/LavenderTown/scripts.pory"
	setvar VAR_LAST_TALKED, 4
# 64 "data/maps/LavenderTown/scripts.pory"
	goto_if_set FLAG_HIDE_CELADON_ROCKETS, LavenderTown_EventScript_TowerGuardian_2
# 80 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_TowerGuardian_Text_3
LavenderTown_EventScript_TowerGuardian_1:
# 82 "data/maps/LavenderTown/scripts.pory"
	release
	end

LavenderTown_EventScript_TowerGuardian_2:
# 66 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_TowerGuardian_Text_0
# 67 "data/maps/LavenderTown/scripts.pory"
	trainerbattle_no_intro TRAINER_POKEMON_TOWER_GUARDIAN, LavenderTown_EventScript_TowerGuardian_Text_1
# 68 "data/maps/LavenderTown/scripts.pory"
	checktrainerflag TRAINER_POKEMON_TOWER_GUARDIAN
	goto_if 1, LavenderTown_EventScript_TowerGuardian_5
# 76 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_TowerGuardian_Text_2
	goto LavenderTown_EventScript_TowerGuardian_1

LavenderTown_EventScript_TowerGuardian_5:
# 70 "data/maps/LavenderTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 71 "data/maps/LavenderTown/scripts.pory"
	removeobject 4
# 72 "data/maps/LavenderTown/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 73 "data/maps/LavenderTown/scripts.pory"
	setflag FLAG_HIDE_POKEMON_TOWER_GUARDIAN
	goto LavenderTown_EventScript_TowerGuardian_1


LavenderTown_EventScript_TowerGuardian_Text_0:
# 66 "data/maps/LavenderTown/scripts.pory"
	.string "You dared to defy BOSS GIOVANNI?\n"
	.string "I will do what I must!$"

LavenderTown_EventScript_TowerGuardian_Text_1:
# 67 "data/maps/LavenderTown/scripts.pory"
	.string "This isn't the last you'll see of me!$"

LavenderTown_EventScript_TowerGuardian_Text_2:
# 76 "data/maps/LavenderTown/scripts.pory"
	.string "That's what you get for messing with\n"
	.string "Team Rocket!$"

LavenderTown_EventScript_TowerGuardian_Text_3:
# 80 "data/maps/LavenderTown/scripts.pory"
	.string "Get lost! Team Rocket has business\n"
	.string "here!$"
