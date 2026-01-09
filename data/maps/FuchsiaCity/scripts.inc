# 1 "data/maps/FuchsiaCity/scripts.pory"

# 2 "data/maps/FuchsiaCity/scripts.pory"
.set LOCALID_GYM_GUARDIAN, 17
# 3 "data/maps/FuchsiaCity/scripts.pory"

# 4 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_MapScripts::
# 5 "data/maps/FuchsiaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
# 6 "data/maps/FuchsiaCity/scripts.pory"
	.byte 0
# 7 "data/maps/FuchsiaCity/scripts.pory"

# 8 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_OnTransition::
# 9 "data/maps/FuchsiaCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
# 10 "data/maps/FuchsiaCity/scripts.pory"
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
# 11 "data/maps/FuchsiaCity/scripts.pory"
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
# 12 "data/maps/FuchsiaCity/scripts.pory"
	call_if_unset FLAG_HIDE_FUSCHIA_GYM_GUARDIAN, FuchsiaCity_EventScript_BlockGym
# 13 "data/maps/FuchsiaCity/scripts.pory"
	end
# 14 "data/maps/FuchsiaCity/scripts.pory"

# 15 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_BlockGym::
# 16 "data/maps/FuchsiaCity/scripts.pory"
	setobjectxyperm LOCALID_GYM_GUARDIAN, 4, 37
# 17 "data/maps/FuchsiaCity/scripts.pory"
	return
# 18 "data/maps/FuchsiaCity/scripts.pory"

# 19 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SetOmanyteGfx::
# 20 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
# 21 "data/maps/FuchsiaCity/scripts.pory"
	return
# 22 "data/maps/FuchsiaCity/scripts.pory"

# 23 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SetKabutoGfx::
# 24 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
# 25 "data/maps/FuchsiaCity/scripts.pory"
	return
# 26 "data/maps/FuchsiaCity/scripts.pory"

# 27 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LittleBoy::
# 28 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
# 29 "data/maps/FuchsiaCity/scripts.pory"
	end
# 30 "data/maps/FuchsiaCity/scripts.pory"

# 31 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OldMan::
# 32 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
# 33 "data/maps/FuchsiaCity/scripts.pory"
	end
# 34 "data/maps/FuchsiaCity/scripts.pory"

# 35 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Erik::
# 36 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
# 37 "data/maps/FuchsiaCity/scripts.pory"
	end
# 38 "data/maps/FuchsiaCity/scripts.pory"

# 39 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Youngster::
# 40 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
# 41 "data/maps/FuchsiaCity/scripts.pory"
	end
# 42 "data/maps/FuchsiaCity/scripts.pory"

# 43 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Lass::
# 44 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 45 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 46 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 3
# 47 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
# 48 "data/maps/FuchsiaCity/scripts.pory"
	release
# 49 "data/maps/FuchsiaCity/scripts.pory"
	end
# 50 "data/maps/FuchsiaCity/scripts.pory"

# 51 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_CitySign::
# 52 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
# 53 "data/maps/FuchsiaCity/scripts.pory"
	end
# 54 "data/maps/FuchsiaCity/scripts.pory"

# 55 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneSign::
# 56 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
# 57 "data/maps/FuchsiaCity/scripts.pory"
	end
# 58 "data/maps/FuchsiaCity/scripts.pory"

# 59 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariGameSign::
# 60 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
# 61 "data/maps/FuchsiaCity/scripts.pory"
	end
# 62 "data/maps/FuchsiaCity/scripts.pory"

# 63 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_WardensHomeSign::
# 64 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
# 65 "data/maps/FuchsiaCity/scripts.pory"
	end
# 66 "data/maps/FuchsiaCity/scripts.pory"

# 67 "data/maps/FuchsiaCity/scripts.pory"
@ Unused
# 68 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneOfficeSign::
# 69 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
# 70 "data/maps/FuchsiaCity/scripts.pory"
	end
# 71 "data/maps/FuchsiaCity/scripts.pory"

# 72 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_GymSign::
# 73 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 74 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 0
# 75 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_GymSign
# 76 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 77 "data/maps/FuchsiaCity/scripts.pory"
	end
# 78 "data/maps/FuchsiaCity/scripts.pory"

# 79 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_ChanseySign::
# 80 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 81 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_CHANSEY
# 82 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 83 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_CHANSEY, 10, 3
# 84 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ChanseySign
# 85 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 86 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 87 "data/maps/FuchsiaCity/scripts.pory"
	end
# 88 "data/maps/FuchsiaCity/scripts.pory"

# 89 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_VoltorbSign::
# 90 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 91 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_VOLTORB
# 92 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 93 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_VOLTORB, 10, 3
# 94 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_VoltorbSign
# 95 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 96 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 97 "data/maps/FuchsiaCity/scripts.pory"
	end
# 98 "data/maps/FuchsiaCity/scripts.pory"

# 99 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_KangaskhanSign::
# 100 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 101 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KANGASKHAN
# 102 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 103 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KANGASKHAN, 10, 3
# 104 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KangaskhanSign
# 105 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 106 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 107 "data/maps/FuchsiaCity/scripts.pory"
	end
# 108 "data/maps/FuchsiaCity/scripts.pory"

# 109 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SlowpokeSign::
# 110 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 111 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_SLOWPOKE
# 112 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 113 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_SLOWPOKE, 10, 3
# 114 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SlowpokeSign
# 115 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 116 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 117 "data/maps/FuchsiaCity/scripts.pory"
	end
# 118 "data/maps/FuchsiaCity/scripts.pory"

# 119 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LaprasSign::
# 120 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 121 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 122 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 123 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_LAPRAS, 10, 3
# 124 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_LaprasSign
# 125 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 126 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 127 "data/maps/FuchsiaCity/scripts.pory"
	end
# 128 "data/maps/FuchsiaCity/scripts.pory"

# 129 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_FossilMonSign::
# 130 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 131 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
# 132 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KABUTO
# 133 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 134 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KABUTO, 10, 3
# 135 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KabutoSign
# 136 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 137 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 138 "data/maps/FuchsiaCity/scripts.pory"
	end
# 139 "data/maps/FuchsiaCity/scripts.pory"

# 140 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OmanyteSign::
# 141 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_OMANYTE
# 142 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 143 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_OMANYTE, 10, 3
# 144 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_OmanyteSign
# 145 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 146 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 147 "data/maps/FuchsiaCity/scripts.pory"
	end

FuchsiaCity_EventScript_GymGuardian::
# 152 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 153 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 154 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_LAST_TALKED, 17
# 156 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FuchsiaCity_EventScript_GymGuardian_2
# 172 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_GymGuardian_Text_3
FuchsiaCity_EventScript_GymGuardian_1:
# 174 "data/maps/FuchsiaCity/scripts.pory"
	release
	end

FuchsiaCity_EventScript_GymGuardian_2:
# 158 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_GymGuardian_Text_0
# 159 "data/maps/FuchsiaCity/scripts.pory"
	trainerbattle_no_intro TRAINER_FUSCHIA_GYM_GUARDIAN, FuchsiaCity_EventScript_GymGuardian_Text_1
# 160 "data/maps/FuchsiaCity/scripts.pory"
	checktrainerflag TRAINER_FUSCHIA_GYM_GUARDIAN
	goto_if 1, FuchsiaCity_EventScript_GymGuardian_5
# 168 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_GymGuardian_Text_2
	goto FuchsiaCity_EventScript_GymGuardian_1

FuchsiaCity_EventScript_GymGuardian_5:
# 162 "data/maps/FuchsiaCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 163 "data/maps/FuchsiaCity/scripts.pory"
	removeobject 17
# 164 "data/maps/FuchsiaCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 165 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_HIDE_FUSCHIA_GYM_GUARDIAN
	goto FuchsiaCity_EventScript_GymGuardian_1


FuchsiaCity_EventScript_GymGuardian_Text_0:
# 158 "data/maps/FuchsiaCity/scripts.pory"
	.string "You can't come through! Koga can't\n"
	.string "be warned about Team Rocket's\l"
	.string "plans!$"

FuchsiaCity_EventScript_GymGuardian_Text_1:
# 159 "data/maps/FuchsiaCity/scripts.pory"
	.string "You may have beaten me, but Team\n"
	.string "Rocket isn't finished!$"

FuchsiaCity_EventScript_GymGuardian_Text_2:
# 168 "data/maps/FuchsiaCity/scripts.pory"
	.string "Team Rocket will always be one step\n"
	.string "ahead of you!$"

FuchsiaCity_EventScript_GymGuardian_Text_3:
# 172 "data/maps/FuchsiaCity/scripts.pory"
	.string "Boss said I should keep Koga from\n"
	.string "interfering with Team Rocket's\l"
	.string "plans! Don't get any ideas about\l"
	.string "warning him!$"
