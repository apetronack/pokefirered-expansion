# 1 "data/maps/CeruleanCity/scripts.pory"

# 2 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_POLICEMAN, 1
# 3 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_GRUNT,     2
# 4 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_SLOWBRO,   5
# 5 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_LASS,      6
# 6 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_RIVAL,     8
# 7 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_WOMAN,     11
# 8 "data/maps/CeruleanCity/scripts.pory"
.set LOCALID_GYM_GUARDIAN, 13
# 9 "data/maps/CeruleanCity/scripts.pory"

# 10 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_MapScripts::
# 11 "data/maps/CeruleanCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
# 12 "data/maps/CeruleanCity/scripts.pory"
	.byte 0
# 13 "data/maps/CeruleanCity/scripts.pory"

# 14 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_OnTransition::
# 15 "data/maps/CeruleanCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
# 16 "data/maps/CeruleanCity/scripts.pory"
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
# 17 "data/maps/CeruleanCity/scripts.pory"
	call_if_unset FLAG_HIDE_CERULEAN_GYMGUARDIAN, CeruleanCity_EventScript_BlockGym
# 18 "data/maps/CeruleanCity/scripts.pory"
	end
# 19 "data/maps/CeruleanCity/scripts.pory"

# 20 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BlockExits::
# 21 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_POLICEMAN, 30, 12
# 22 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_SLOWBRO, 26, 31
# 23 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_LASS, 27, 31
# 24 "data/maps/CeruleanCity/scripts.pory"
	return
# 25 "data/maps/CeruleanCity/scripts.pory"

# 26 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BlockGym::
# 27 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_GUARDIAN, 31, 22
# 28 "data/maps/CeruleanCity/scripts.pory"
	return
# 29 "data/maps/CeruleanCity/scripts.pory"

# 30 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerLeft::
# 31 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 32 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 33 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 34 "data/maps/CeruleanCity/scripts.pory"
	end
# 35 "data/maps/CeruleanCity/scripts.pory"

# 36 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerMid::
# 37 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 38 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 39 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 23, 0
# 40 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 41 "data/maps/CeruleanCity/scripts.pory"
	end
# 42 "data/maps/CeruleanCity/scripts.pory"

# 43 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalTriggerRight::
# 44 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 45 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 46 "data/maps/CeruleanCity/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 24, 0
# 47 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_Rival
# 48 "data/maps/CeruleanCity/scripts.pory"
	end
# 49 "data/maps/CeruleanCity/scripts.pory"

# 50 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Rival::
# 51 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 52 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 2
# 53 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 54 "data/maps/CeruleanCity/scripts.pory"
	addobject LOCALID_RIVAL
# 55 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
# 56 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 57 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_RivalIntro
# 58 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
# 59 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
# 60 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
# 61 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
# 62 "data/maps/CeruleanCity/scripts.pory"
	famechecker FAMECHECKER_BILL, 0
# 63 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_RivalPostBattle
# 64 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 65 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 66 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
# 67 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
# 68 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
# 69 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
# 70 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
# 71 "data/maps/CeruleanCity/scripts.pory"
	setflag FLAG_GOT_FAME_CHECKER
# 72 "data/maps/CeruleanCity/scripts.pory"
	giveitem ITEM_FAME_CHECKER
# 73 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
# 74 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 75 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
# 76 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 77 "data/maps/CeruleanCity/scripts.pory"
	fadedefaultbgm
# 78 "data/maps/CeruleanCity/scripts.pory"
	removeobject LOCALID_RIVAL
# 79 "data/maps/CeruleanCity/scripts.pory"
	releaseall
# 80 "data/maps/CeruleanCity/scripts.pory"
	end
# 81 "data/maps/CeruleanCity/scripts.pory"

# 82 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalSquirtle::
# 83 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
# 84 "data/maps/CeruleanCity/scripts.pory"
	return
# 85 "data/maps/CeruleanCity/scripts.pory"

# 86 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalBulbasaur::
# 87 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
# 88 "data/maps/CeruleanCity/scripts.pory"
	return
# 89 "data/maps/CeruleanCity/scripts.pory"

# 90 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalCharmander::
# 91 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
# 92 "data/maps/CeruleanCity/scripts.pory"
	return
# 93 "data/maps/CeruleanCity/scripts.pory"

# 94 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalStartExit::
# 95 "data/maps/CeruleanCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
# 96 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
# 97 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 98 "data/maps/CeruleanCity/scripts.pory"
	return
# 99 "data/maps/CeruleanCity/scripts.pory"

# 100 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_RivalStartExitRight::
# 101 "data/maps/CeruleanCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
# 102 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
# 103 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/CeruleanCity/scripts.pory"
	return
# 105 "data/maps/CeruleanCity/scripts.pory"

# 106 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_PlayerWatchRivalExit::
# 107 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 108 "data/maps/CeruleanCity/scripts.pory"
	delay_8
# 109 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_right
# 110 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 111 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_down
# 112 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 113 "data/maps/CeruleanCity/scripts.pory"

# 114 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_PlayerWatchRivalExitRight::
# 115 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 116 "data/maps/CeruleanCity/scripts.pory"
	delay_8
# 117 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_left
# 118 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 119 "data/maps/CeruleanCity/scripts.pory"
	walk_in_place_faster_down
# 120 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 121 "data/maps/CeruleanCity/scripts.pory"

# 122 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalEnter::
# 123 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 124 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 125 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 126 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 127 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 128 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 129 "data/maps/CeruleanCity/scripts.pory"

# 130 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalStartExit::
# 131 "data/maps/CeruleanCity/scripts.pory"
	walk_right
# 132 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 133 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 134 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 135 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 136 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 137 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 138 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 139 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 140 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 141 "data/maps/CeruleanCity/scripts.pory"
	walk_left
# 142 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 143 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 144 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 145 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 146 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 147 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 148 "data/maps/CeruleanCity/scripts.pory"

# 149 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalStartExitRight::
# 150 "data/maps/CeruleanCity/scripts.pory"
	walk_left
# 151 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 152 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 153 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 154 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 155 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 156 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 157 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 158 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 159 "data/maps/CeruleanCity/scripts.pory"
	delay_16
# 160 "data/maps/CeruleanCity/scripts.pory"
	walk_right
# 161 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 162 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 163 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 164 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 165 "data/maps/CeruleanCity/scripts.pory"
	walk_up
# 166 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 167 "data/maps/CeruleanCity/scripts.pory"

# 168 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_Movement_RivalExit::
# 169 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 170 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 171 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 172 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 173 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 174 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 175 "data/maps/CeruleanCity/scripts.pory"
	walk_down
# 176 "data/maps/CeruleanCity/scripts.pory"
	step_end
# 177 "data/maps/CeruleanCity/scripts.pory"

# 178 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Grunt::
# 179 "data/maps/CeruleanCity/scripts.pory"
	lock
# 180 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 181 "data/maps/CeruleanCity/scripts.pory"
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
# 182 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_GruntIntro
# 183 "data/maps/CeruleanCity/scripts.pory"
	waitmessage
# 184 "data/maps/CeruleanCity/scripts.pory"
	playbgm MUS_ENCOUNTER_ROCKET, 0
# 185 "data/maps/CeruleanCity/scripts.pory"
	waitbuttonpress
# 186 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
# 187 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
# 188 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntDefeated
# 189 "data/maps/CeruleanCity/scripts.pory"
	end
# 190 "data/maps/CeruleanCity/scripts.pory"

# 191 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntDefeated::
# 192 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
# 193 "data/maps/CeruleanCity/scripts.pory"
	checkitemspace ITEM_TM28
# 194 "data/maps/CeruleanCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
# 195 "data/maps/CeruleanCity/scripts.pory"
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
# 196 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_BetterGetMovingBye
# 197 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 198 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 199 "data/maps/CeruleanCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 200 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 201 "data/maps/CeruleanCity/scripts.pory"
	setflag FLAG_GOT_TM28_FROM_ROCKET
# 202 "data/maps/CeruleanCity/scripts.pory"
	release
# 203 "data/maps/CeruleanCity/scripts.pory"
	end
# 204 "data/maps/CeruleanCity/scripts.pory"

# 205 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_NoRoomForTM28::
# 206 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 207 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
# 208 "data/maps/CeruleanCity/scripts.pory"
	release
# 209 "data/maps/CeruleanCity/scripts.pory"
	end
# 210 "data/maps/CeruleanCity/scripts.pory"

# 211 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTriggerTop::
# 212 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 213 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 214 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
# 215 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 216 "data/maps/CeruleanCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 217 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 218 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntTrigger
# 219 "data/maps/CeruleanCity/scripts.pory"
	end
# 220 "data/maps/CeruleanCity/scripts.pory"

# 221 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTriggerBottom::
# 222 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 223 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 224 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 225 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 226 "data/maps/CeruleanCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 227 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntTrigger
# 229 "data/maps/CeruleanCity/scripts.pory"
	end
# 230 "data/maps/CeruleanCity/scripts.pory"

# 231 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GruntTrigger::
# 232 "data/maps/CeruleanCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 233 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_GruntIntro
# 234 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_GRUNT
# 235 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
# 236 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
# 237 "data/maps/CeruleanCity/scripts.pory"
	goto CeruleanCity_EventScript_GruntDefeated
# 238 "data/maps/CeruleanCity/scripts.pory"
	end
# 239 "data/maps/CeruleanCity/scripts.pory"

# 240 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Policeman::
# 241 "data/maps/CeruleanCity/scripts.pory"
	lock
# 242 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 243 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
# 244 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 245 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_POLICEMAN, Common_Movement_FaceOriginalDirection
# 246 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 247 "data/maps/CeruleanCity/scripts.pory"
	release
# 248 "data/maps/CeruleanCity/scripts.pory"
	end
# 249 "data/maps/CeruleanCity/scripts.pory"

# 250 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_LittleBoy::
# 251 "data/maps/CeruleanCity/scripts.pory"
	lock
# 252 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 253 "data/maps/CeruleanCity/scripts.pory"
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
# 254 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
# 255 "data/maps/CeruleanCity/scripts.pory"
	release
# 256 "data/maps/CeruleanCity/scripts.pory"
	end
# 257 "data/maps/CeruleanCity/scripts.pory"

# 258 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_LittleBoySlowbroMoved::
# 259 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
# 260 "data/maps/CeruleanCity/scripts.pory"
	release
# 261 "data/maps/CeruleanCity/scripts.pory"
	end
# 262 "data/maps/CeruleanCity/scripts.pory"

# 263 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BaldingMan::
# 264 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
# 265 "data/maps/CeruleanCity/scripts.pory"
	end
# 266 "data/maps/CeruleanCity/scripts.pory"

# 267 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Youngster::
# 268 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
# 269 "data/maps/CeruleanCity/scripts.pory"
	end
# 270 "data/maps/CeruleanCity/scripts.pory"

# 271 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_CeruleanCaveGuard::
# 272 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
# 273 "data/maps/CeruleanCity/scripts.pory"
	end
# 274 "data/maps/CeruleanCity/scripts.pory"

# 275 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Woman::
# 276 "data/maps/CeruleanCity/scripts.pory"
	lock
# 277 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 278 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_WantBrightRedBicycle
# 279 "data/maps/CeruleanCity/scripts.pory"
	closemessage
# 280 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
# 281 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 282 "data/maps/CeruleanCity/scripts.pory"
	release
# 283 "data/maps/CeruleanCity/scripts.pory"
	end
# 284 "data/maps/CeruleanCity/scripts.pory"

# 285 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Lass::
# 286 "data/maps/CeruleanCity/scripts.pory"
	lock
# 287 "data/maps/CeruleanCity/scripts.pory"
	random 3
# 288 "data/maps/CeruleanCity/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 289 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
# 290 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
# 291 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
# 292 "data/maps/CeruleanCity/scripts.pory"
	waitmessage
# 293 "data/maps/CeruleanCity/scripts.pory"
	delay 40
# 294 "data/maps/CeruleanCity/scripts.pory"
	playse SE_PIN
# 295 "data/maps/CeruleanCity/scripts.pory"
	applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
# 296 "data/maps/CeruleanCity/scripts.pory"
	waitmovement 0
# 297 "data/maps/CeruleanCity/scripts.pory"
	delay 30
# 298 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
# 299 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
# 300 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
# 301 "data/maps/CeruleanCity/scripts.pory"
	release
# 302 "data/maps/CeruleanCity/scripts.pory"
	end
# 303 "data/maps/CeruleanCity/scripts.pory"

# 304 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand1::
# 305 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroUseSonicboom
# 306 "data/maps/CeruleanCity/scripts.pory"
	return
# 307 "data/maps/CeruleanCity/scripts.pory"

# 308 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand2::
# 309 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroPunch
# 310 "data/maps/CeruleanCity/scripts.pory"
	return
# 311 "data/maps/CeruleanCity/scripts.pory"

# 312 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroCommand3::
# 313 "data/maps/CeruleanCity/scripts.pory"
	message CeruleanCity_Text_SlowbroWithdraw
# 314 "data/maps/CeruleanCity/scripts.pory"
	return
# 315 "data/maps/CeruleanCity/scripts.pory"

# 316 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed1::
# 317 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroPayAttention
# 318 "data/maps/CeruleanCity/scripts.pory"
	return
# 319 "data/maps/CeruleanCity/scripts.pory"

# 320 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed2::
# 321 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_NoYouBlewItAgain
# 322 "data/maps/CeruleanCity/scripts.pory"
	return
# 323 "data/maps/CeruleanCity/scripts.pory"

# 324 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroFailed3::
# 325 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_HardToControlMonsObedience
# 326 "data/maps/CeruleanCity/scripts.pory"
	return
# 327 "data/maps/CeruleanCity/scripts.pory"

# 328 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_Slowbro::
# 329 "data/maps/CeruleanCity/scripts.pory"
	lock
# 330 "data/maps/CeruleanCity/scripts.pory"
	random 4
# 331 "data/maps/CeruleanCity/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 332 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
# 333 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
# 334 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
# 335 "data/maps/CeruleanCity/scripts.pory"
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
# 336 "data/maps/CeruleanCity/scripts.pory"
	release
# 337 "data/maps/CeruleanCity/scripts.pory"
	end
# 338 "data/maps/CeruleanCity/scripts.pory"

# 339 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText1::
# 340 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroTookSnooze
# 341 "data/maps/CeruleanCity/scripts.pory"
	return
# 342 "data/maps/CeruleanCity/scripts.pory"

# 343 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText2::
# 344 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroLoafingAround
# 345 "data/maps/CeruleanCity/scripts.pory"
	return
# 346 "data/maps/CeruleanCity/scripts.pory"

# 347 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText3::
# 348 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroTurnedAway
# 349 "data/maps/CeruleanCity/scripts.pory"
	return
# 350 "data/maps/CeruleanCity/scripts.pory"

# 351 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_SlowbroText4::
# 352 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
# 353 "data/maps/CeruleanCity/scripts.pory"
	return
# 354 "data/maps/CeruleanCity/scripts.pory"

# 355 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_CitySign::
# 356 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
# 357 "data/maps/CeruleanCity/scripts.pory"
	end
# 358 "data/maps/CeruleanCity/scripts.pory"

# 359 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_TrainerTips::
# 360 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
# 361 "data/maps/CeruleanCity/scripts.pory"
	end
# 362 "data/maps/CeruleanCity/scripts.pory"

# 363 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_BikeShopSign::
# 364 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
# 365 "data/maps/CeruleanCity/scripts.pory"
	end
# 366 "data/maps/CeruleanCity/scripts.pory"

# 367 "data/maps/CeruleanCity/scripts.pory"
CeruleanCity_EventScript_GymSign::
# 368 "data/maps/CeruleanCity/scripts.pory"
	lockall
# 369 "data/maps/CeruleanCity/scripts.pory"
	famechecker FAMECHECKER_MISTY, 0
# 370 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_Text_GymSign
# 371 "data/maps/CeruleanCity/scripts.pory"
	releaseall
# 372 "data/maps/CeruleanCity/scripts.pory"
	end

CeruleanCity_EventScript_GymGuardian::
# 386 "data/maps/CeruleanCity/scripts.pory"
	lock
# 387 "data/maps/CeruleanCity/scripts.pory"
	faceplayer
# 388 "data/maps/CeruleanCity/scripts.pory"
	setvar VAR_LAST_TALKED, 13
# 390 "data/maps/CeruleanCity/scripts.pory"
	goto_if_set FLAG_HIDE_NUGGET_BRIDGE_ROCKET, CeruleanCity_EventScript_GymGuardian_2
# 406 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_EventScript_GymGuardian_Text_3
CeruleanCity_EventScript_GymGuardian_1:
# 408 "data/maps/CeruleanCity/scripts.pory"
	release
	end

CeruleanCity_EventScript_GymGuardian_2:
# 392 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_EventScript_GymGuardian_Text_0
# 393 "data/maps/CeruleanCity/scripts.pory"
	trainerbattle_no_intro TRAINER_CERULEAN_GYM_GUARDIAN, CeruleanCity_EventScript_GymGuardian_Text_1
# 394 "data/maps/CeruleanCity/scripts.pory"
	checktrainerflag TRAINER_CERULEAN_GYM_GUARDIAN
	goto_if 1, CeruleanCity_EventScript_GymGuardian_5
# 402 "data/maps/CeruleanCity/scripts.pory"
	msgbox CeruleanCity_EventScript_GymGuardian_Text_2
	goto CeruleanCity_EventScript_GymGuardian_1

CeruleanCity_EventScript_GymGuardian_5:
# 396 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 397 "data/maps/CeruleanCity/scripts.pory"
	removeobject 13
# 398 "data/maps/CeruleanCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 399 "data/maps/CeruleanCity/scripts.pory"
	setflag FLAG_HIDE_CERULEAN_GYMGUARDIAN
	goto CeruleanCity_EventScript_GymGuardian_1


CeruleanCity_EventScript_GymGuardian_Text_0:
# 392 "data/maps/CeruleanCity/scripts.pory"
	.string "You turned down Team Rocket's\n"
	.string "offer? I guess I have to take you\l"
	.string "down myself!$"

CeruleanCity_EventScript_GymGuardian_Text_1:
# 393 "data/maps/CeruleanCity/scripts.pory"
	.string "You may have beaten me, but you\n"
	.string "won't beat Misty!$"

CeruleanCity_EventScript_GymGuardian_Text_2:
# 402 "data/maps/CeruleanCity/scripts.pory"
	.string "Team Rocket will always be one step\n"
	.string "ahead of you!$"

CeruleanCity_EventScript_GymGuardian_Text_3:
# 406 "data/maps/CeruleanCity/scripts.pory"
	.string "Boss said I should keep Misty from\n"
	.string "interfering with Team Rocket's\l"
	.string "plans! Don't get any ideas about\l"
	.string "warning her!$"
