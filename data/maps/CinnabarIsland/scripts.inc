# 1 "data/maps/CinnabarIsland/scripts.pory"

# 2 "data/maps/CinnabarIsland/scripts.pory"
.equ LOCALID_BILL, 3
# 3 "data/maps/CinnabarIsland/scripts.pory"
.equ LOCALID_SEAGALLOP, 4
# 4 "data/maps/CinnabarIsland/scripts.pory"
.set LOCALID_MANSION_GUARDIAN, 5
# 5 "data/maps/CinnabarIsland/scripts.pory"

# 6 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_MapScripts::
# 7 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
# 8 "data/maps/CinnabarIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_OnFrame
# 9 "data/maps/CinnabarIsland/scripts.pory"
	.byte 0
# 10 "data/maps/CinnabarIsland/scripts.pory"

# 11 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_OnTransition::
# 12 "data/maps/CinnabarIsland/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CINNABAR_ISLAND
# 13 "data/maps/CinnabarIsland/scripts.pory"
	call CinnabarIsland_EventScript_CheckUnlockGym
# 14 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND, 1, CinnabarIsland_EventScript_ReadyObjectsSailToOneIsland
# 15 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND, 3, CinnabarIsland_EventScript_ReadyObjectsReturnFromSeviiIslands
# 16 "data/maps/CinnabarIsland/scripts.pory"
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1, CinnabarIsland_EventScript_ReadyObjectsSailToOneIslandFromPokeCenter
# 17 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_HIDE_CINNABAR_MANSION_GUARDIAN, CinnabarIsland_EventScript_BlockMansion
# 18 "data/maps/CinnabarIsland/scripts.pory"
	end
# 19 "data/maps/CinnabarIsland/scripts.pory"

# 20 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BlockMansion::
# 21 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_MANSION_GUARDIAN, 8, 4
# 22 "data/maps/CinnabarIsland/scripts.pory"
	return
# 23 "data/maps/CinnabarIsland/scripts.pory"

# 24 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ReadyObjectsSailToOneIslandFromPokeCenter::
# 25 "data/maps/CinnabarIsland/scripts.pory"
	savebgm MUS_FOLLOW_ME
# 26 "data/maps/CinnabarIsland/scripts.pory"
	setflag FLAG_TEMP_2
# 27 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_BILL, 15, 12
# 28 "data/maps/CinnabarIsland/scripts.pory"
	setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_LEFT
# 29 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_SEAGALLOP, 30, 12
# 30 "data/maps/CinnabarIsland/scripts.pory"
	return
# 31 "data/maps/CinnabarIsland/scripts.pory"

# 32 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ReadyObjectsSailToOneIsland::
# 33 "data/maps/CinnabarIsland/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 34 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_ge VAR_0x8004, 18, CinnabarIsland_EventScript_MoveSeagallopDown
# 35 "data/maps/CinnabarIsland/scripts.pory"
	setflag FLAG_TEMP_2
# 36 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_BILL, 18, 12
# 37 "data/maps/CinnabarIsland/scripts.pory"
	setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
# 38 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_SEAGALLOP, 30, 12
# 39 "data/maps/CinnabarIsland/scripts.pory"
	return
# 40 "data/maps/CinnabarIsland/scripts.pory"

# 41 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_MoveSeagallopDown::
# 42 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_SEAGALLOP, 30, 8
# 43 "data/maps/CinnabarIsland/scripts.pory"
	return
# 44 "data/maps/CinnabarIsland/scripts.pory"

# 45 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ReadyObjectsReturnFromSeviiIslands::
# 46 "data/maps/CinnabarIsland/scripts.pory"
	setobjectxyperm LOCALID_BILL, 21, 8
# 47 "data/maps/CinnabarIsland/scripts.pory"
	setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
# 48 "data/maps/CinnabarIsland/scripts.pory"
	return
# 49 "data/maps/CinnabarIsland/scripts.pory"

# 50 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_CheckUnlockGym::
# 51 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_set FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY, CinnabarIsland_EventScript_UnlockGym
# 52 "data/maps/CinnabarIsland/scripts.pory"
	return
# 53 "data/maps/CinnabarIsland/scripts.pory"

# 54 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_UnlockGym::
# 55 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_TEMP_1, 1
# 56 "data/maps/CinnabarIsland/scripts.pory"
	return
# 57 "data/maps/CinnabarIsland/scripts.pory"

# 58 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_OnFrame::
# 59 "data/maps/CinnabarIsland/scripts.pory"
	map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1, CinnabarIsland_EventScript_ExitPokeCenterForOneIsland
# 60 "data/maps/CinnabarIsland/scripts.pory"
	map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND, 1, CinnabarIsland_EventScript_BillScene
# 61 "data/maps/CinnabarIsland/scripts.pory"
	map_script_2 VAR_MAP_SCENE_CINNABAR_ISLAND, 3, CinnabarIsland_EventScript_ReturnFromSeviiIslands
# 62 "data/maps/CinnabarIsland/scripts.pory"
	.2byte 0
# 63 "data/maps/CinnabarIsland/scripts.pory"

# 64 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ExitPokeCenterForOneIsland::
# 65 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 66 "data/maps/CinnabarIsland/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 67 "data/maps/CinnabarIsland/scripts.pory"
	savebgm MUS_DUMMY
# 68 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 69 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 2
# 70 "data/maps/CinnabarIsland/scripts.pory"
	delay 20
# 71 "data/maps/CinnabarIsland/scripts.pory"
	call CinnabarIsland_EventScript_SailToOneIsland
# 72 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 73 "data/maps/CinnabarIsland/scripts.pory"
	end
# 74 "data/maps/CinnabarIsland/scripts.pory"

# 75 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ReturnFromSeviiIslands::
# 76 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 77 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 78 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IfYouHaveTriPassYouCanGoAgain
# 79 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 80 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillExit
# 81 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 82 "data/maps/CinnabarIsland/scripts.pory"
	removeobject LOCALID_BILL
# 83 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 4
# 84 "data/maps/CinnabarIsland/scripts.pory"
	setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
# 85 "data/maps/CinnabarIsland/scripts.pory"
	clearflag FLAG_HIDE_LOSTELLE_IN_HER_HOME
# 86 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 87 "data/maps/CinnabarIsland/scripts.pory"
	end
# 88 "data/maps/CinnabarIsland/scripts.pory"

# 89 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillExit::
# 90 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 91 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 92 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 93 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 94 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 95 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 96 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 97 "data/maps/CinnabarIsland/scripts.pory"

# 98 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillScene::
# 99 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 100 "data/maps/CinnabarIsland/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 101 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillFacePlayer1
# 102 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillFacePlayer2
# 103 "data/maps/CinnabarIsland/scripts.pory"
	playse SE_PIN
# 104 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
# 105 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 106 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, Common_Movement_Delay48
# 107 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 108 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillApproachPlayer1
# 109 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillApproachPlayer2
# 110 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_HeyIfItIsntPlayer
# 111 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_ComeWithMeToOneIsland, MSGBOX_YESNO
# 112 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_EventScript_AgreeSailToOneIsland
# 113 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_EventScript_DeclineSailToOneIsland
# 114 "data/maps/CinnabarIsland/scripts.pory"
	end
# 115 "data/maps/CinnabarIsland/scripts.pory"

# 116 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillFacePlayer1::
# 117 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
# 118 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 119 "data/maps/CinnabarIsland/scripts.pory"
	return
# 120 "data/maps/CinnabarIsland/scripts.pory"

# 121 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillFacePlayer2::
# 122 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterLeft
# 123 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 124 "data/maps/CinnabarIsland/scripts.pory"
	return
# 125 "data/maps/CinnabarIsland/scripts.pory"

# 126 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillApproachPlayer1::
# 127 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachPlayer1
# 128 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 129 "data/maps/CinnabarIsland/scripts.pory"
	return
# 130 "data/maps/CinnabarIsland/scripts.pory"

# 131 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillApproachPlayer2::
# 132 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachPlayer2
# 133 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 134 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 135 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 136 "data/maps/CinnabarIsland/scripts.pory"
	return
# 137 "data/maps/CinnabarIsland/scripts.pory"

# 138 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_AgreeSailToOneIsland::
# 139 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_AllRightLetsGo
# 140 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 141 "data/maps/CinnabarIsland/scripts.pory"
	call CinnabarIsland_EventScript_SailToOneIsland
# 142 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 143 "data/maps/CinnabarIsland/scripts.pory"
	end
# 144 "data/maps/CinnabarIsland/scripts.pory"

# 145 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_DeclineSailToOneIsland::
# 146 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IllBeWaitingInPokeCenter
# 147 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 148 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BillExitToPokeCenter
# 149 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BillReturnToPokeCenter
# 150 "data/maps/CinnabarIsland/scripts.pory"
	removeobject LOCALID_BILL
# 151 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 2
# 152 "data/maps/CinnabarIsland/scripts.pory"
	clearflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
# 153 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 154 "data/maps/CinnabarIsland/scripts.pory"
	end
# 155 "data/maps/CinnabarIsland/scripts.pory"

# 156 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillExitToPokeCenter::
# 157 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillExitToPokeCenter
# 158 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 159 "data/maps/CinnabarIsland/scripts.pory"
	return
# 160 "data/maps/CinnabarIsland/scripts.pory"

# 161 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillExitToPokeCenter::
# 162 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 163 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 164 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 165 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 166 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 167 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 168 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 169 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 170 "data/maps/CinnabarIsland/scripts.pory"

# 171 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BillReturnToPokeCenter::
# 172 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerWatchBillExit
# 173 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillApproachDoor
# 174 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 175 "data/maps/CinnabarIsland/scripts.pory"
	opendoor 14, 11
# 176 "data/maps/CinnabarIsland/scripts.pory"
	waitdooranim
# 177 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillReEnterPokeCenter
# 178 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 179 "data/maps/CinnabarIsland/scripts.pory"
	closedoor 14, 11
# 180 "data/maps/CinnabarIsland/scripts.pory"
	waitdooranim
# 181 "data/maps/CinnabarIsland/scripts.pory"
	return
# 182 "data/maps/CinnabarIsland/scripts.pory"

# 183 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_PlayerWatchBillExit::
# 184 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 185 "data/maps/CinnabarIsland/scripts.pory"
	walk_in_place_faster_right
# 186 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 187 "data/maps/CinnabarIsland/scripts.pory"

# 188 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillApproachDoor::
# 189 "data/maps/CinnabarIsland/scripts.pory"
	delay_16
# 190 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 191 "data/maps/CinnabarIsland/scripts.pory"
	walk_in_place_faster_up
# 192 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 193 "data/maps/CinnabarIsland/scripts.pory"

# 194 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillReEnterPokeCenter::
# 195 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
# 196 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 197 "data/maps/CinnabarIsland/scripts.pory"
	set_invisible
# 198 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 199 "data/maps/CinnabarIsland/scripts.pory"

# 200 "data/maps/CinnabarIsland/scripts.pory"
@ Can be triggered outside, or after talking to Bill in the poke center
# 201 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_SailToOneIsland::
# 202 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_ApproachShore
# 203 "data/maps/CinnabarIsland/scripts.pory"
	addobject LOCALID_SEAGALLOP
# 204 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BoatArrive
# 205 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BoatArriveExitedPokeCenter
# 206 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_MyPalsBoatArrived
# 207 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 208 "data/maps/CinnabarIsland/scripts.pory"
	call_if_unset FLAG_TEMP_2, CinnabarIsland_EventScript_BoardBoat
# 209 "data/maps/CinnabarIsland/scripts.pory"
	call_if_set FLAG_TEMP_2, CinnabarIsland_EventScript_BoardBoatExitedPokeCenter
# 210 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 2
# 211 "data/maps/CinnabarIsland/scripts.pory"
	removeobject LOCALID_BILL
# 212 "data/maps/CinnabarIsland/scripts.pory"
	delay 40
# 213 "data/maps/CinnabarIsland/scripts.pory"
	setflag FLAG_HIDE_CINNABAR_SEAGALLOP
# 214 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 1
# 215 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_CINNABAR_ISLAND
# 216 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_ONE_ISLAND
# 217 "data/maps/CinnabarIsland/scripts.pory"
	goto EventScript_SetSail
# 218 "data/maps/CinnabarIsland/scripts.pory"
	end
# 219 "data/maps/CinnabarIsland/scripts.pory"

# 220 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_ApproachShore::
# 221 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_ApproachShore
# 222 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ApproachShore
# 223 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 224 "data/maps/CinnabarIsland/scripts.pory"
	return
# 225 "data/maps/CinnabarIsland/scripts.pory"

# 226 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BoatArrive::
# 227 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillFaceBoat
# 228 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_SEAGALLOP, CinnabarIsland_Movement_BoatArrive
# 229 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 230 "data/maps/CinnabarIsland/scripts.pory"
	return
# 231 "data/maps/CinnabarIsland/scripts.pory"

# 232 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BoatArriveExitedPokeCenter::
# 233 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_SEAGALLOP, CinnabarIsland_Movement_BoatArrive
# 234 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 235 "data/maps/CinnabarIsland/scripts.pory"
	return
# 236 "data/maps/CinnabarIsland/scripts.pory"

# 237 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BoardBoat::
# 238 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillBoardBoat
# 239 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerBoardBoat
# 240 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 241 "data/maps/CinnabarIsland/scripts.pory"
	return
# 242 "data/maps/CinnabarIsland/scripts.pory"

# 243 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_BoardBoatExitedPokeCenter::
# 244 "data/maps/CinnabarIsland/scripts.pory"
	applymovement LOCALID_BILL, CinnabarIsland_Movement_BillBoardBoatFromShore
# 245 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_PlayerBoardBoatFromShore
# 246 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 247 "data/maps/CinnabarIsland/scripts.pory"
	return
# 248 "data/maps/CinnabarIsland/scripts.pory"

# 249 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BoatArrive::
# 250 "data/maps/CinnabarIsland/scripts.pory"
	delay_16
# 251 "data/maps/CinnabarIsland/scripts.pory"
	delay_16
# 252 "data/maps/CinnabarIsland/scripts.pory"
	walk_fast_left
# 253 "data/maps/CinnabarIsland/scripts.pory"
	walk_fast_left
# 254 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 255 "data/maps/CinnabarIsland/scripts.pory"
	walk_slower_left
# 256 "data/maps/CinnabarIsland/scripts.pory"
	walk_slower_left
# 257 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 258 "data/maps/CinnabarIsland/scripts.pory"

# 259 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillBoardBoat::
# 260 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 261 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 262 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 263 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 264 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 265 "data/maps/CinnabarIsland/scripts.pory"
	set_invisible
# 266 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 267 "data/maps/CinnabarIsland/scripts.pory"

# 268 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillApproachPlayer1::
# 269 "data/maps/CinnabarIsland/scripts.pory"
	walk_up
# 270 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 271 "data/maps/CinnabarIsland/scripts.pory"

# 272 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillApproachPlayer2::
# 273 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 274 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 275 "data/maps/CinnabarIsland/scripts.pory"
	walk_left
# 276 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 277 "data/maps/CinnabarIsland/scripts.pory"

# 278 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillFaceBoat::
# 279 "data/maps/CinnabarIsland/scripts.pory"
	delay_16
# 280 "data/maps/CinnabarIsland/scripts.pory"
	delay_16
# 281 "data/maps/CinnabarIsland/scripts.pory"
	delay_8
# 282 "data/maps/CinnabarIsland/scripts.pory"
	walk_in_place_faster_right
# 283 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 284 "data/maps/CinnabarIsland/scripts.pory"

# 285 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_ApproachShore::
# 286 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 287 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 288 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 289 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 290 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 291 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 292 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 293 "data/maps/CinnabarIsland/scripts.pory"

# 294 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_BillBoardBoatFromShore::
# 295 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 296 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 297 "data/maps/CinnabarIsland/scripts.pory"
	set_invisible
# 298 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 299 "data/maps/CinnabarIsland/scripts.pory"

# 300 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_PlayerBoardBoat::
# 301 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 302 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 303 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 304 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 305 "data/maps/CinnabarIsland/scripts.pory"
	walk_in_place_faster_right
# 306 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 307 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 308 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 309 "data/maps/CinnabarIsland/scripts.pory"
	set_invisible
# 310 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 311 "data/maps/CinnabarIsland/scripts.pory"

# 312 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_PlayerBoardBoatFromShore::
# 313 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 314 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 315 "data/maps/CinnabarIsland/scripts.pory"
	walk_right
# 316 "data/maps/CinnabarIsland/scripts.pory"
	delay_4
# 317 "data/maps/CinnabarIsland/scripts.pory"
	set_invisible
# 318 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 319 "data/maps/CinnabarIsland/scripts.pory"

# 320 "data/maps/CinnabarIsland/scripts.pory"
@ Triggered when VAR_TEMP_1 is 0
# 321 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_GymDoorLocked::
# 322 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 323 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 324 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 325 "data/maps/CinnabarIsland/scripts.pory"
	delay 20
# 326 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_DoorIsLocked
# 327 "data/maps/CinnabarIsland/scripts.pory"
	closemessage
# 328 "data/maps/CinnabarIsland/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ForcePlayerFromDoor
# 329 "data/maps/CinnabarIsland/scripts.pory"
	waitmovement 0
# 330 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 331 "data/maps/CinnabarIsland/scripts.pory"
	end
# 332 "data/maps/CinnabarIsland/scripts.pory"

# 333 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_Movement_ForcePlayerFromDoor::
# 334 "data/maps/CinnabarIsland/scripts.pory"
	walk_down
# 335 "data/maps/CinnabarIsland/scripts.pory"
	step_end
# 336 "data/maps/CinnabarIsland/scripts.pory"

# 337 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_Woman::
# 338 "data/maps/CinnabarIsland/scripts.pory"
	lock
# 339 "data/maps/CinnabarIsland/scripts.pory"
	faceplayer
# 340 "data/maps/CinnabarIsland/scripts.pory"
	famechecker FAMECHECKER_BLAINE, 3
# 341 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab
# 342 "data/maps/CinnabarIsland/scripts.pory"
	release
# 343 "data/maps/CinnabarIsland/scripts.pory"
	end
# 344 "data/maps/CinnabarIsland/scripts.pory"

# 345 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_OldMan::
# 346 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
# 347 "data/maps/CinnabarIsland/scripts.pory"
	end
# 348 "data/maps/CinnabarIsland/scripts.pory"

# 349 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_IslandSign::
# 350 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
# 351 "data/maps/CinnabarIsland/scripts.pory"
	end
# 352 "data/maps/CinnabarIsland/scripts.pory"

# 353 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_PokemonLabSign::
# 354 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
# 355 "data/maps/CinnabarIsland/scripts.pory"
	end
# 356 "data/maps/CinnabarIsland/scripts.pory"

# 357 "data/maps/CinnabarIsland/scripts.pory"
CinnabarIsland_EventScript_GymSign::
# 358 "data/maps/CinnabarIsland/scripts.pory"
	lockall
# 359 "data/maps/CinnabarIsland/scripts.pory"
	famechecker FAMECHECKER_BLAINE, 0
# 360 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_GymSign
# 361 "data/maps/CinnabarIsland/scripts.pory"
	releaseall
# 362 "data/maps/CinnabarIsland/scripts.pory"
	end

CinnabarIsland_EventScript_MansionGuardian::
# 367 "data/maps/CinnabarIsland/scripts.pory"
	lock
# 368 "data/maps/CinnabarIsland/scripts.pory"
	faceplayer
# 369 "data/maps/CinnabarIsland/scripts.pory"
	setvar VAR_LAST_TALKED, 5
# 371 "data/maps/CinnabarIsland/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, CinnabarIsland_EventScript_MansionGuardian_2
# 387 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_EventScript_MansionGuardian_Text_3
CinnabarIsland_EventScript_MansionGuardian_1:
# 389 "data/maps/CinnabarIsland/scripts.pory"
	release
	end

CinnabarIsland_EventScript_MansionGuardian_2:
# 373 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_EventScript_MansionGuardian_Text_0
# 374 "data/maps/CinnabarIsland/scripts.pory"
	trainerbattle_no_intro TRAINER_CINNABAR_MANSION_GUARDIAN, CinnabarIsland_EventScript_MansionGuardian_Text_1
# 375 "data/maps/CinnabarIsland/scripts.pory"
	checktrainerflag TRAINER_CINNABAR_MANSION_GUARDIAN
	goto_if 1, CinnabarIsland_EventScript_MansionGuardian_5
# 383 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_EventScript_MansionGuardian_Text_2
	goto CinnabarIsland_EventScript_MansionGuardian_1

CinnabarIsland_EventScript_MansionGuardian_5:
# 377 "data/maps/CinnabarIsland/scripts.pory"
	fadescreen FADE_TO_BLACK
# 378 "data/maps/CinnabarIsland/scripts.pory"
	removeobject 5
# 379 "data/maps/CinnabarIsland/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 380 "data/maps/CinnabarIsland/scripts.pory"
	setflag FLAG_HIDE_CINNABAR_MANSION_GUARDIAN
	goto CinnabarIsland_EventScript_MansionGuardian_1


CinnabarIsland_EventScript_MansionGuardian_Text_0:
# 373 "data/maps/CinnabarIsland/scripts.pory"
	.string "I can't let you through! Team\n"
	.string "Rocket is up to no good in the\l"
	.string "Cinnabar Mansion, and I can't let\l"
	.string "you interfere with their plans!$"

CinnabarIsland_EventScript_MansionGuardian_Text_1:
# 374 "data/maps/CinnabarIsland/scripts.pory"
	.string "You may have beaten me, but Team\n"
	.string "Rocket isn't finished!$"

CinnabarIsland_EventScript_MansionGuardian_Text_2:
# 383 "data/maps/CinnabarIsland/scripts.pory"
	.string "Team Rocket will always be one step\n"
	.string "ahead of you!$"

CinnabarIsland_EventScript_MansionGuardian_Text_3:
# 387 "data/maps/CinnabarIsland/scripts.pory"
	.string "Cinnabar Mansion is off-limits! Team\n"
	.string "Rocket is up to no good in there,\l"
	.string "and I can't let you interfere with\l"
	.string "their plans!$"
