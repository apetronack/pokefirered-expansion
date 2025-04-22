# 1 "data/maps/SilphCo_7F/scripts.pory"

# 2 "data/maps/SilphCo_7F/scripts.pory"
.set LOCALID_RIVAL,     1
# 3 "data/maps/SilphCo_7F/scripts.pory"
.set LOCALID_WORKER_M2, 8
# 4 "data/maps/SilphCo_7F/scripts.pory"

# 5 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_MapScripts::
# 6 "data/maps/SilphCo_7F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
# 7 "data/maps/SilphCo_7F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
# 8 "data/maps/SilphCo_7F/scripts.pory"
	.byte 0
# 9 "data/maps/SilphCo_7F/scripts.pory"

# 10 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_OnLoad::
# 11 "data/maps/SilphCo_7F/scripts.pory"
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
# 12 "data/maps/SilphCo_7F/scripts.pory"
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
# 13 "data/maps/SilphCo_7F/scripts.pory"
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
# 14 "data/maps/SilphCo_7F/scripts.pory"
	end
# 15 "data/maps/SilphCo_7F/scripts.pory"

# 16 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_OnTransition::
# 17 "data/maps/SilphCo_7F/scripts.pory"
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
# 18 "data/maps/SilphCo_7F/scripts.pory"
	end
# 19 "data/maps/SilphCo_7F/scripts.pory"

# 20 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_SetObjRocketsGone::
# 21 "data/maps/SilphCo_7F/scripts.pory"
	setobjectmovementtype LOCALID_WORKER_M2, MOVEMENT_TYPE_FACE_UP
# 22 "data/maps/SilphCo_7F/scripts.pory"
	return
# 23 "data/maps/SilphCo_7F/scripts.pory"

# 24 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalTriggerTop::
# 25 "data/maps/SilphCo_7F/scripts.pory"
	lockall
# 26 "data/maps/SilphCo_7F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 27 "data/maps/SilphCo_7F/scripts.pory"
	goto SilphCo_7F_EventScript_RivalScene
# 28 "data/maps/SilphCo_7F/scripts.pory"
	end
# 29 "data/maps/SilphCo_7F/scripts.pory"

# 30 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalTriggerBottom::
# 31 "data/maps/SilphCo_7F/scripts.pory"
	lockall
# 32 "data/maps/SilphCo_7F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/SilphCo_7F/scripts.pory"
	goto SilphCo_7F_EventScript_RivalScene
# 34 "data/maps/SilphCo_7F/scripts.pory"
	end
# 35 "data/maps/SilphCo_7F/scripts.pory"

# 36 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalScene::
# 37 "data/maps/SilphCo_7F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 38 "data/maps/SilphCo_7F/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 39 "data/maps/SilphCo_7F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 40 "data/maps/SilphCo_7F/scripts.pory"
	waitmovement 0
# 41 "data/maps/SilphCo_7F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 42 "data/maps/SilphCo_7F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 43 "data/maps/SilphCo_7F/scripts.pory"
	waitmovement 0
# 44 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
# 45 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
# 46 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
# 47 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_RivalIntro
# 48 "data/maps/SilphCo_7F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
# 49 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
# 50 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
# 51 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
# 52 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_RivalPostBattle
# 53 "data/maps/SilphCo_7F/scripts.pory"
	closemessage
# 54 "data/maps/SilphCo_7F/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 55 "data/maps/SilphCo_7F/scripts.pory"
	setflag FLAG_BEAT_RIVAL_5
# 56 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
# 57 "data/maps/SilphCo_7F/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
# 58 "data/maps/SilphCo_7F/scripts.pory"
	playse SE_WARP_IN
# 59 "data/maps/SilphCo_7F/scripts.pory"
	fadedefaultbgm
# 60 "data/maps/SilphCo_7F/scripts.pory"
	removeobject LOCALID_RIVAL
# 61 "data/maps/SilphCo_7F/scripts.pory"
	waitse
# 62 "data/maps/SilphCo_7F/scripts.pory"
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
# 63 "data/maps/SilphCo_7F/scripts.pory"
	releaseall
# 64 "data/maps/SilphCo_7F/scripts.pory"
	end
# 65 "data/maps/SilphCo_7F/scripts.pory"

# 66 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalApproachTop::
# 67 "data/maps/SilphCo_7F/scripts.pory"
	closemessage
# 68 "data/maps/SilphCo_7F/scripts.pory"
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalApproachTop
# 69 "data/maps/SilphCo_7F/scripts.pory"
	waitmovement 0
# 70 "data/maps/SilphCo_7F/scripts.pory"
	return
# 71 "data/maps/SilphCo_7F/scripts.pory"

# 72 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalApproachBottom::
# 73 "data/maps/SilphCo_7F/scripts.pory"
	return
# 74 "data/maps/SilphCo_7F/scripts.pory"

# 75 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalSquirtle::
# 76 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
# 77 "data/maps/SilphCo_7F/scripts.pory"
	return
# 78 "data/maps/SilphCo_7F/scripts.pory"

# 79 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalBulbasaur::
# 80 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
# 81 "data/maps/SilphCo_7F/scripts.pory"
	return
# 82 "data/maps/SilphCo_7F/scripts.pory"

# 83 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalCharmander::
# 84 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
# 85 "data/maps/SilphCo_7F/scripts.pory"
	return
# 86 "data/maps/SilphCo_7F/scripts.pory"

# 87 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalExitTop::
# 88 "data/maps/SilphCo_7F/scripts.pory"
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitTop
# 89 "data/maps/SilphCo_7F/scripts.pory"
	waitmovement 0
# 90 "data/maps/SilphCo_7F/scripts.pory"
	return
# 91 "data/maps/SilphCo_7F/scripts.pory"

# 92 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_RivalExitBottom::
# 93 "data/maps/SilphCo_7F/scripts.pory"
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitBottom
# 94 "data/maps/SilphCo_7F/scripts.pory"
	waitmovement 0
# 95 "data/maps/SilphCo_7F/scripts.pory"
	return
# 96 "data/maps/SilphCo_7F/scripts.pory"

# 97 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_Movement_RivalApproachTop::
# 98 "data/maps/SilphCo_7F/scripts.pory"
	walk_up
# 99 "data/maps/SilphCo_7F/scripts.pory"
	step_end
# 100 "data/maps/SilphCo_7F/scripts.pory"

# 101 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_Movement_RivalExitTop::
# 102 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 103 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 104 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 105 "data/maps/SilphCo_7F/scripts.pory"
	walk_up
# 106 "data/maps/SilphCo_7F/scripts.pory"
	delay_16
# 107 "data/maps/SilphCo_7F/scripts.pory"
	step_end
# 108 "data/maps/SilphCo_7F/scripts.pory"

# 109 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_Movement_RivalExitBottom::
# 110 "data/maps/SilphCo_7F/scripts.pory"
	walk_left
# 111 "data/maps/SilphCo_7F/scripts.pory"
	walk_up
# 112 "data/maps/SilphCo_7F/scripts.pory"
	walk_up
# 113 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 114 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 115 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 116 "data/maps/SilphCo_7F/scripts.pory"
	walk_right
# 117 "data/maps/SilphCo_7F/scripts.pory"
	delay_16
# 118 "data/maps/SilphCo_7F/scripts.pory"
	step_end
# 119 "data/maps/SilphCo_7F/scripts.pory"

# 120 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_LaprasGuy::
# 121 "data/maps/SilphCo_7F/scripts.pory"
	lock
# 122 "data/maps/SilphCo_7F/scripts.pory"
	faceplayer
# 123 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
# 124 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
# 125 "data/maps/SilphCo_7F/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_LAPRAS
# 126 "data/maps/SilphCo_7F/scripts.pory"
	givemon SPECIES_LAPRAS, 25
# 127 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
# 128 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
# 129 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 130 "data/maps/SilphCo_7F/scripts.pory"
	release
# 131 "data/maps/SilphCo_7F/scripts.pory"
	end
# 132 "data/maps/SilphCo_7F/scripts.pory"

# 133 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_ReceiveLaprasParty::
# 134 "data/maps/SilphCo_7F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 135 "data/maps/SilphCo_7F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 136 "data/maps/SilphCo_7F/scripts.pory"
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
# 137 "data/maps/SilphCo_7F/scripts.pory"
	waitmessage
# 138 "data/maps/SilphCo_7F/scripts.pory"
	waitfanfare
# 139 "data/maps/SilphCo_7F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
# 140 "data/maps/SilphCo_7F/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 141 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
# 142 "data/maps/SilphCo_7F/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 143 "data/maps/SilphCo_7F/scripts.pory"
	call EventScript_ChangePokemonNickname
# 144 "data/maps/SilphCo_7F/scripts.pory"
	goto SilphCo_7F_EventScript_EndReceiveLapras
# 145 "data/maps/SilphCo_7F/scripts.pory"
	end
# 146 "data/maps/SilphCo_7F/scripts.pory"

# 147 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_ReceiveLaprasPC::
# 148 "data/maps/SilphCo_7F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 149 "data/maps/SilphCo_7F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 150 "data/maps/SilphCo_7F/scripts.pory"
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
# 151 "data/maps/SilphCo_7F/scripts.pory"
	waitmessage
# 152 "data/maps/SilphCo_7F/scripts.pory"
	waitfanfare
# 153 "data/maps/SilphCo_7F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
# 154 "data/maps/SilphCo_7F/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 155 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
# 156 "data/maps/SilphCo_7F/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 157 "data/maps/SilphCo_7F/scripts.pory"
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
# 158 "data/maps/SilphCo_7F/scripts.pory"
	end
# 159 "data/maps/SilphCo_7F/scripts.pory"

# 160 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_LaprasTransferredToPC::
# 161 "data/maps/SilphCo_7F/scripts.pory"
	call EventScript_TransferredToPC
# 162 "data/maps/SilphCo_7F/scripts.pory"
	goto SilphCo_7F_EventScript_EndReceiveLapras
# 163 "data/maps/SilphCo_7F/scripts.pory"
	end
# 164 "data/maps/SilphCo_7F/scripts.pory"

# 165 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_EndReceiveLapras::
# 166 "data/maps/SilphCo_7F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 167 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_ExplainLapras
# 168 "data/maps/SilphCo_7F/scripts.pory"
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
# 169 "data/maps/SilphCo_7F/scripts.pory"
	release
# 170 "data/maps/SilphCo_7F/scripts.pory"
	end
# 171 "data/maps/SilphCo_7F/scripts.pory"

# 172 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_AlreadyGotLapras::
# 173 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
# 174 "data/maps/SilphCo_7F/scripts.pory"
	release
# 175 "data/maps/SilphCo_7F/scripts.pory"
	end
# 176 "data/maps/SilphCo_7F/scripts.pory"

# 177 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerM1::
# 178 "data/maps/SilphCo_7F/scripts.pory"
	lock
# 179 "data/maps/SilphCo_7F/scripts.pory"
	faceplayer
# 180 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
# 181 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
# 182 "data/maps/SilphCo_7F/scripts.pory"
	release
# 183 "data/maps/SilphCo_7F/scripts.pory"
	end
# 184 "data/maps/SilphCo_7F/scripts.pory"

# 185 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerM1RocketsGone::
# 186 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
# 187 "data/maps/SilphCo_7F/scripts.pory"
	release
# 188 "data/maps/SilphCo_7F/scripts.pory"
	end
# 189 "data/maps/SilphCo_7F/scripts.pory"

# 190 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerM2::
# 191 "data/maps/SilphCo_7F/scripts.pory"
	lock
# 192 "data/maps/SilphCo_7F/scripts.pory"
	faceplayer
# 193 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
# 194 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
# 195 "data/maps/SilphCo_7F/scripts.pory"
	release
# 196 "data/maps/SilphCo_7F/scripts.pory"
	end
# 197 "data/maps/SilphCo_7F/scripts.pory"

# 198 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerM2RocketsGone::
# 199 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
# 200 "data/maps/SilphCo_7F/scripts.pory"
	release
# 201 "data/maps/SilphCo_7F/scripts.pory"
	end
# 202 "data/maps/SilphCo_7F/scripts.pory"

# 203 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerF::
# 204 "data/maps/SilphCo_7F/scripts.pory"
	lock
# 205 "data/maps/SilphCo_7F/scripts.pory"
	faceplayer
# 206 "data/maps/SilphCo_7F/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
# 207 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_ReallyDangerousHere
# 208 "data/maps/SilphCo_7F/scripts.pory"
	release
# 209 "data/maps/SilphCo_7F/scripts.pory"
	end
# 210 "data/maps/SilphCo_7F/scripts.pory"

# 211 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_WorkerFRocketsGone::
# 212 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_ThankYouSoMuch
# 213 "data/maps/SilphCo_7F/scripts.pory"
	release
# 214 "data/maps/SilphCo_7F/scripts.pory"
	end
# 215 "data/maps/SilphCo_7F/scripts.pory"

# 216 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_FloorSign::
# 217 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
# 218 "data/maps/SilphCo_7F/scripts.pory"
	end
# 219 "data/maps/SilphCo_7F/scripts.pory"

# 220 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_Joshua::
# 221 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
# 222 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
# 223 "data/maps/SilphCo_7F/scripts.pory"
	end
# 224 "data/maps/SilphCo_7F/scripts.pory"

# 225 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_Grunt1::
# 226 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
# 227 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 228 "data/maps/SilphCo_7F/scripts.pory"
	end
# 229 "data/maps/SilphCo_7F/scripts.pory"

# 230 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_Grunt2::
# 231 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
# 232 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 233 "data/maps/SilphCo_7F/scripts.pory"
	end
# 234 "data/maps/SilphCo_7F/scripts.pory"

# 235 "data/maps/SilphCo_7F/scripts.pory"
SilphCo_7F_EventScript_Grunt3::
# 236 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
# 237 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 238 "data/maps/SilphCo_7F/scripts.pory"
	end
