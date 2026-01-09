# 1 "data/maps/CeladonCity/scripts.pory"

# 2 "data/maps/CeladonCity/scripts.pory"
.set LOCALID_FAT_MAN,   2
# 3 "data/maps/CeladonCity/scripts.pory"
.set LOCALID_POLIWRATH, 3
# 4 "data/maps/CeladonCity/scripts.pory"
.set LOCALID_GYM_GUARDIAN, 16
# 5 "data/maps/CeladonCity/scripts.pory"

# 6 "data/maps/CeladonCity/scripts.pory"
CeladonCity_MapScripts::
# 7 "data/maps/CeladonCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
# 8 "data/maps/CeladonCity/scripts.pory"
	.byte 0
# 9 "data/maps/CeladonCity/scripts.pory"

# 10 "data/maps/CeladonCity/scripts.pory"
CeladonCity_OnTransition::
# 11 "data/maps/CeladonCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
# 12 "data/maps/CeladonCity/scripts.pory"
	call_if_unset FLAG_HIDE_CELADON_GYM_GUARDIAN, CeladonCity_EventScript_BlockGym
# 13 "data/maps/CeladonCity/scripts.pory"
	end
# 14 "data/maps/CeladonCity/scripts.pory"

# 15 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_BlockGym::
# 16 "data/maps/CeladonCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_GUARDIAN, 40, 34
# 17 "data/maps/CeladonCity/scripts.pory"
	return
# 18 "data/maps/CeladonCity/scripts.pory"

# 19 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_LittleGirl::
# 20 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
# 21 "data/maps/CeladonCity/scripts.pory"
	end
# 22 "data/maps/CeladonCity/scripts.pory"

# 23 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_OldMan1::
# 24 "data/maps/CeladonCity/scripts.pory"
	lock
# 25 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
# 26 "data/maps/CeladonCity/scripts.pory"
	release
# 27 "data/maps/CeladonCity/scripts.pory"
	end
# 28 "data/maps/CeladonCity/scripts.pory"

# 29 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_Woman::
# 30 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
# 31 "data/maps/CeladonCity/scripts.pory"
	end
# 32 "data/maps/CeladonCity/scripts.pory"

# 33 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_OldMan2::
# 34 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
# 35 "data/maps/CeladonCity/scripts.pory"
	end
# 36 "data/maps/CeladonCity/scripts.pory"

# 37 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_SoftboiledTutor::
# 38 "data/maps/CeladonCity/scripts.pory"
	goto EventScript_SoftboiledTutor
# 39 "data/maps/CeladonCity/scripts.pory"
	end
# 40 "data/maps/CeladonCity/scripts.pory"

# 41 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_FatMan::
# 42 "data/maps/CeladonCity/scripts.pory"
	lock
# 43 "data/maps/CeladonCity/scripts.pory"
	faceplayer
# 44 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
# 45 "data/maps/CeladonCity/scripts.pory"
	closemessage
# 46 "data/maps/CeladonCity/scripts.pory"
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
# 47 "data/maps/CeladonCity/scripts.pory"
	waitmovement 0
# 48 "data/maps/CeladonCity/scripts.pory"
	release
# 49 "data/maps/CeladonCity/scripts.pory"
	end
# 50 "data/maps/CeladonCity/scripts.pory"

# 51 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_Poliwrath::
# 52 "data/maps/CeladonCity/scripts.pory"
	lock
# 53 "data/maps/CeladonCity/scripts.pory"
	faceplayer
# 54 "data/maps/CeladonCity/scripts.pory"
	waitse
# 55 "data/maps/CeladonCity/scripts.pory"
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
# 56 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_Poliwrath
# 57 "data/maps/CeladonCity/scripts.pory"
	closemessage
# 58 "data/maps/CeladonCity/scripts.pory"
	waitmoncry
# 59 "data/maps/CeladonCity/scripts.pory"
	applymovement LOCALID_POLIWRATH, Common_Movement_FaceOriginalDirection
# 60 "data/maps/CeladonCity/scripts.pory"
	waitmovement 0
# 61 "data/maps/CeladonCity/scripts.pory"
	release
# 62 "data/maps/CeladonCity/scripts.pory"
	end
# 63 "data/maps/CeladonCity/scripts.pory"

# 64 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_RocketGrunt1::
# 65 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
# 66 "data/maps/CeladonCity/scripts.pory"
	end
# 67 "data/maps/CeladonCity/scripts.pory"

# 68 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_RocketGrunt2::
# 69 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
# 70 "data/maps/CeladonCity/scripts.pory"
	end
# 71 "data/maps/CeladonCity/scripts.pory"

# 72 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_Boy::
# 73 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
# 74 "data/maps/CeladonCity/scripts.pory"
	end
# 75 "data/maps/CeladonCity/scripts.pory"

# 76 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_SilphCoScientist::
# 77 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
# 78 "data/maps/CeladonCity/scripts.pory"
	end
# 79 "data/maps/CeladonCity/scripts.pory"

# 80 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_TrainerTips1::
# 81 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
# 82 "data/maps/CeladonCity/scripts.pory"
	end
# 83 "data/maps/CeladonCity/scripts.pory"

# 84 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_CitySign::
# 85 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
# 86 "data/maps/CeladonCity/scripts.pory"
	end
# 87 "data/maps/CeladonCity/scripts.pory"

# 88 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_GymSign::
# 89 "data/maps/CeladonCity/scripts.pory"
	lockall
# 90 "data/maps/CeladonCity/scripts.pory"
	famechecker FAMECHECKER_ERIKA, 0
# 91 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GymSign
# 92 "data/maps/CeladonCity/scripts.pory"
	releaseall
# 93 "data/maps/CeladonCity/scripts.pory"
	end
# 94 "data/maps/CeladonCity/scripts.pory"

# 95 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_MansionSign::
# 96 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
# 97 "data/maps/CeladonCity/scripts.pory"
	end
# 98 "data/maps/CeladonCity/scripts.pory"

# 99 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_DeptStoreSign::
# 100 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
# 101 "data/maps/CeladonCity/scripts.pory"
	end
# 102 "data/maps/CeladonCity/scripts.pory"

# 103 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_TrainerTips2::
# 104 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
# 105 "data/maps/CeladonCity/scripts.pory"
	end
# 106 "data/maps/CeladonCity/scripts.pory"

# 107 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_PrizeExchangeSign::
# 108 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
# 109 "data/maps/CeladonCity/scripts.pory"
	end
# 110 "data/maps/CeladonCity/scripts.pory"

# 111 "data/maps/CeladonCity/scripts.pory"
CeladonCity_EventScript_GameCornerSign::
# 112 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
# 113 "data/maps/CeladonCity/scripts.pory"
	end

CeladonCity_EventScript_GymGuardian::
# 127 "data/maps/CeladonCity/scripts.pory"
	lock
# 128 "data/maps/CeladonCity/scripts.pory"
	faceplayer
# 129 "data/maps/CeladonCity/scripts.pory"
	setvar VAR_LAST_TALKED, 16
# 131 "data/maps/CeladonCity/scripts.pory"
	goto_if_set FLAG_RESCUED_MR_FUJI, CeladonCity_EventScript_GymGuardian_2
# 147 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_EventScript_GymGuardian_Text_3
CeladonCity_EventScript_GymGuardian_1:
# 149 "data/maps/CeladonCity/scripts.pory"
	release
	end

CeladonCity_EventScript_GymGuardian_2:
# 133 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_EventScript_GymGuardian_Text_0
# 134 "data/maps/CeladonCity/scripts.pory"
	trainerbattle_no_intro TRAINER_CELADON_GYM_GUARDIAN, CeladonCity_EventScript_GymGuardian_Text_1
# 135 "data/maps/CeladonCity/scripts.pory"
	checktrainerflag TRAINER_CELADON_GYM_GUARDIAN
	goto_if 1, CeladonCity_EventScript_GymGuardian_5
# 143 "data/maps/CeladonCity/scripts.pory"
	msgbox CeladonCity_EventScript_GymGuardian_Text_2
	goto CeladonCity_EventScript_GymGuardian_1

CeladonCity_EventScript_GymGuardian_5:
# 137 "data/maps/CeladonCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 138 "data/maps/CeladonCity/scripts.pory"
	removeobject 16
# 139 "data/maps/CeladonCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 140 "data/maps/CeladonCity/scripts.pory"
	setflag FLAG_HIDE_CELADON_GYM_GUARDIAN
	goto CeladonCity_EventScript_GymGuardian_1


CeladonCity_EventScript_GymGuardian_Text_0:
# 133 "data/maps/CeladonCity/scripts.pory"
	.string "You can't come through! Erika can't\n"
	.string "be warned about Team Rocket's\l"
	.string "plans!$"

CeladonCity_EventScript_GymGuardian_Text_1:
# 134 "data/maps/CeladonCity/scripts.pory"
	.string "You may have beaten me, but Team\n"
	.string "Rocket isn't finished!$"

CeladonCity_EventScript_GymGuardian_Text_2:
# 143 "data/maps/CeladonCity/scripts.pory"
	.string "Team Rocket will always be one step\n"
	.string "ahead of you!$"

CeladonCity_EventScript_GymGuardian_Text_3:
# 147 "data/maps/CeladonCity/scripts.pory"
	.string "Boss said I should keep Erika from\n"
	.string "interfering with Team Rocket's\l"
	.string "plans! Don't get any ideas about\l"
	.string "warning her!$"
