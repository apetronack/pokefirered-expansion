# 1 "data/maps/SSAnne_Exterior/scripts.pory"

# 2 "data/maps/SSAnne_Exterior/scripts.pory"
.set LOCALID_SS_ANNE, 1
# 3 "data/maps/SSAnne_Exterior/scripts.pory"

# 4 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_MapScripts::
# 5 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
# 6 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAnne_Exterior_OnFrame
# 7 "data/maps/SSAnne_Exterior/scripts.pory"
	.byte 0
# 8 "data/maps/SSAnne_Exterior/scripts.pory"

# 9 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_OnTransition::
# 10 "data/maps/SSAnne_Exterior/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
# 11 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 12 "data/maps/SSAnne_Exterior/scripts.pory"

# 13 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_OnFrame::
# 14 "data/maps/SSAnne_Exterior/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 1, SSAnne_Exterior_ExitSSAnne
# 15 "data/maps/SSAnne_Exterior/scripts.pory"
	.2byte 0
# 16 "data/maps/SSAnne_Exterior/scripts.pory"

# 17 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_ExitSSAnne::
# 18 "data/maps/SSAnne_Exterior/scripts.pory"
	lockall
# 19 "data/maps/SSAnne_Exterior/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 20 "data/maps/SSAnne_Exterior/scripts.pory"
	call_if_le VAR_0x8005, 6, SSAnne_Exterior_WalkDown
# 21 "data/maps/SSAnne_Exterior/scripts.pory"
	call_if_ge VAR_0x8005, 7, SSAnne_Exterior_WalkInPlaceDown
# 22 "data/maps/SSAnne_Exterior/scripts.pory"
	fadenewbgm MUS_SURF
# 23 "data/maps/SSAnne_Exterior/scripts.pory"
	delay 50
# 24 "data/maps/SSAnne_Exterior/scripts.pory"
	special DoSSAnneDepartureCutscene
# 25 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 26 "data/maps/SSAnne_Exterior/scripts.pory"
	removeobject LOCALID_SS_ANNE
# 27 "data/maps/SSAnne_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_Exterior_Movement_Exit
# 28 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmovement 0
# 29 "data/maps/SSAnne_Exterior/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 2
# 30 "data/maps/SSAnne_Exterior/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 31 "data/maps/SSAnne_Exterior/scripts.pory"
	warp MAP_VERMILION_CITY, 23, 34
# 32 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 33 "data/maps/SSAnne_Exterior/scripts.pory"
	releaseall
# 34 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 35 "data/maps/SSAnne_Exterior/scripts.pory"

# 36 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_WalkDown::
# 37 "data/maps/SSAnne_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_Exterior_Movement_WalkDown
# 38 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmovement 0
# 39 "data/maps/SSAnne_Exterior/scripts.pory"
	return
# 40 "data/maps/SSAnne_Exterior/scripts.pory"

# 41 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_WalkInPlaceDown::
# 42 "data/maps/SSAnne_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 43 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmovement 0
# 44 "data/maps/SSAnne_Exterior/scripts.pory"
	return
# 45 "data/maps/SSAnne_Exterior/scripts.pory"

# 46 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_Movement_Exit::
# 47 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 48 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 49 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 50 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 51 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 52 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 53 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 54 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 55 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_up
# 56 "data/maps/SSAnne_Exterior/scripts.pory"
	step_end
# 57 "data/maps/SSAnne_Exterior/scripts.pory"

# 58 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_Movement_WalkDown::
# 59 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 60 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 61 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 62 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 63 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 64 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 65 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 66 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 67 "data/maps/SSAnne_Exterior/scripts.pory"
	walk_down
# 68 "data/maps/SSAnne_Exterior/scripts.pory"
	step_end
# 69 "data/maps/SSAnne_Exterior/scripts.pory"

# 70 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_TruckTile::
# 71 "data/maps/SSAnne_Exterior/scripts.pory"
	lock
# 72 "data/maps/SSAnne_Exterior/scripts.pory"
	faceplayer
# 73 "data/maps/SSAnne_Exterior/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 74 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_set FLAG_ENCOUNTERED_MEW_TRUCK, SSAnne_Exterior_EventScript_TruckEmpty
# 75 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_unset FLAG_DEFEATED_CHAMP_1X, SSAnne_Exterior_EventScript_TruckNormal
# 76 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_unset FLAG_GOT_HM04, SSAnne_Exterior_EventScript_TruckNeedStrength
# 77 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_TruckMysteriousSound
# 78 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_UseStrengthOnTruck
# 79 "data/maps/SSAnne_Exterior/scripts.pory"
	closemessage
# 80 "data/maps/SSAnne_Exterior/scripts.pory"
	dofieldeffect FLDEFF_USE_STRENGTH
# 81 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 82 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_TruckRevealsSecret
# 83 "data/maps/SSAnne_Exterior/scripts.pory"
	waitse
# 84 "data/maps/SSAnne_Exterior/scripts.pory"
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
# 85 "data/maps/SSAnne_Exterior/scripts.pory"
	delay 40
# 86 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmoncry
# 87 "data/maps/SSAnne_Exterior/scripts.pory"
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
# 88 "data/maps/SSAnne_Exterior/scripts.pory"
	setwildbattle SPECIES_MEW, 50
# 89 "data/maps/SSAnne_Exterior/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 90 "data/maps/SSAnne_Exterior/scripts.pory"
	special StartLegendaryBattle
# 91 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 92 "data/maps/SSAnne_Exterior/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 93 "data/maps/SSAnne_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 94 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SSAnne_Exterior_EventScript_DefeatedMew
# 95 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SSAnne_Exterior_EventScript_RanFromMew
# 96 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SSAnne_Exterior_EventScript_RanFromMew
# 97 "data/maps/SSAnne_Exterior/scripts.pory"
	setflag FLAG_ENCOUNTERED_MEW_TRUCK
# 98 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 99 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 100 "data/maps/SSAnne_Exterior/scripts.pory"

# 101 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_DefeatedMew::
# 102 "data/maps/SSAnne_Exterior/scripts.pory"
	setflag FLAG_ENCOUNTERED_MEW_TRUCK
# 103 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 104 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 105 "data/maps/SSAnne_Exterior/scripts.pory"

# 106 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_RanFromMew::
# 107 "data/maps/SSAnne_Exterior/scripts.pory"
	setflag FLAG_ENCOUNTERED_MEW_TRUCK
# 108 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 109 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 110 "data/maps/SSAnne_Exterior/scripts.pory"

# 111 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_TruckEmpty::
# 112 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_TruckEmpty, MSGBOX_SIGN
# 113 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 114 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 115 "data/maps/SSAnne_Exterior/scripts.pory"

# 116 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_TruckNormal::
# 117 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_TruckNormal, MSGBOX_SIGN
# 118 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 119 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 120 "data/maps/SSAnne_Exterior/scripts.pory"

# 121 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_TruckNeedStrength::
# 122 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_TruckNeedStrength, MSGBOX_SIGN
# 123 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 124 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 125 "data/maps/SSAnne_Exterior/scripts.pory"

# 126 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_ReturnSailor::
# 127 "data/maps/SSAnne_Exterior/scripts.pory"
	lock
# 128 "data/maps/SSAnne_Exterior/scripts.pory"
	faceplayer
# 129 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_ReturnSailorOffer, MSGBOX_YESNO
# 130 "data/maps/SSAnne_Exterior/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_Exterior_EventScript_ReturnToVermilion
# 131 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_ReturnSailorDecline
# 132 "data/maps/SSAnne_Exterior/scripts.pory"
	release
# 133 "data/maps/SSAnne_Exterior/scripts.pory"
	end
# 134 "data/maps/SSAnne_Exterior/scripts.pory"

# 135 "data/maps/SSAnne_Exterior/scripts.pory"
SSAnne_Exterior_EventScript_ReturnToVermilion::
# 136 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_Text_ReturnSailorAccept
# 137 "data/maps/SSAnne_Exterior/scripts.pory"
	closemessage
# 138 "data/maps/SSAnne_Exterior/scripts.pory"
	fadescreen FADE_TO_BLACK
# 139 "data/maps/SSAnne_Exterior/scripts.pory"
	warp MAP_VERMILION_CITY, 23, 34
# 140 "data/maps/SSAnne_Exterior/scripts.pory"
	waitstate
# 141 "data/maps/SSAnne_Exterior/scripts.pory"
	releaseall
# 142 "data/maps/SSAnne_Exterior/scripts.pory"
	end

SSAnne_Exterior_EventScript_BoardShipCheck::
# 146 "data/maps/SSAnne_Exterior/scripts.pory"
	lockall
# 147 "data/maps/SSAnne_Exterior/scripts.pory"
	compare VAR_MAP_SCENE_VERMILION_CITY, 3
	goto_if_ge SSAnne_Exterior_EventScript_BoardShipCheck_2
SSAnne_Exterior_EventScript_BoardShipCheck_1:
# 150 "data/maps/SSAnne_Exterior/scripts.pory"
	releaseall
	return

SSAnne_Exterior_EventScript_BoardShipCheck_2:
# 148 "data/maps/SSAnne_Exterior/scripts.pory"
	goto SSAnne_Exterior_EventScript_ShipGone
	goto SSAnne_Exterior_EventScript_BoardShipCheck_1


SSAnne_Exterior_EventScript_ShipGone::
# 154 "data/maps/SSAnne_Exterior/scripts.pory"
	msgbox SSAnne_Exterior_EventScript_ShipGone_Text_0
# 155 "data/maps/SSAnne_Exterior/scripts.pory"
	closemessage
# 156 "data/maps/SSAnne_Exterior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 157 "data/maps/SSAnne_Exterior/scripts.pory"
	waitmovement 0
# 158 "data/maps/SSAnne_Exterior/scripts.pory"
	releaseall
	return


SSAnne_Exterior_EventScript_ShipGone_Text_0:
# 154 "data/maps/SSAnne_Exterior/scripts.pory"
	.string "The S.S. ANNE has already\n"
	.string "departed. There's nothing here but\l"
	.string "an empty docking area.$"
