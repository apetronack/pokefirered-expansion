# 1 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 2 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ HELIX_FOSSIL, 1
# 3 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ DOME_FOSSIL,  2
# 4 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ OLD_AMBER,    3
# 5 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ SKULL_FOSSIL, 4
# 6 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ ARMOR_FOSSIL, 5
# 7 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 8 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_MapScripts::
# 9 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	.byte 0
# 10 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 11 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
# 12 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	lock
# 13 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	faceplayer
# 14 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_SPHEAL
# 15 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 16 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_DID_SEELOR_TRADE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
# 17 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 18 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
# 19 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 20 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
# 21 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 22 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
# 23 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_DoInGameTrade
# 24 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 25 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_DID_SEELOR_TRADE
# 26 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 27 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 28 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 29 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
# 30 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 31 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 32 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 33 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 34 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
# 35 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 36 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 37 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 38 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 39 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 40 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
# 41 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 42 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 43 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 44 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 45 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
# 46 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	lock
# 47 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	faceplayer
# 48 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 49 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil
# 50 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils
# 51 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon
# 52 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving
# 53 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList
# 54 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix
# 55 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList
# 56 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome
# 57 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 58 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber
# 59 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddSkullFossilToList
# 60 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilSkull
# 61 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddArmorFossilToList
# 62 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilArmor
# 63 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 64 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 65 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 66 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 67 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList::
# 68 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 69 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 70 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 71 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 72 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 73 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList::
# 74 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 75 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 76 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 77 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 78 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 79 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList::
# 80 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 81 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 82 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 83 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 84 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 85 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddSkullFossilToList::
# 86 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_SKULL_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 87 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_SKULL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 88 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 89 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 90 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 91 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddArmorFossilToList::
# 92 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_ARMOR_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 93 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_ARMOR, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 94 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 95 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 96 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 97 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse::
# 98 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 99 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 100 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 101 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil::
# 102 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoIsTooBad
# 103 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 104 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 105 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 106 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix::
# 107 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 108 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 109 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 110 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber
# 111 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_HELIX, FALSE
# 112 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
# 114 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 115 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 116 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 117 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 118 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome::
# 119 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 120 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 121 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 122 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber
# 123 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_DOME, FALSE
# 124 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 125 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
# 126 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 127 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 128 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 129 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 130 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber::
# 131 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 132 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 133 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_AMBER, FALSE
# 134 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 135 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 136 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 137 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 138 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 139 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 140 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber::
# 141 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_HELIX_AMBER, FALSE
# 142 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 143 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
# 144 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 145 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 146 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 147 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 148 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 149 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber::
# 150 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_DOME_AMBER, FALSE
# 151 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 152 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
# 153 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 154 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 155 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 156 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 157 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 158 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilSkull::
# 159 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 160 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 161 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SKULL, FALSE
# 162 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 163 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowSkullFossil
# 164 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 165 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 166 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 167 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 168 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilArmor::
# 169 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 170 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 171 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTICHOICE_ARMOR, FALSE
# 172 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 173 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowArmorFossil
# 174 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 175 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 176 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 177 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 178 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil::
# 179 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 180 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_HELIX_FOSSIL
# 181 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 182 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 183 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 184 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 185 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 186 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 187 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 188 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
# 189 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 190 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 191 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 192 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil::
# 193 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 194 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_DOME_FOSSIL
# 195 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 196 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 197 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 198 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 199 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 200 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 201 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 202 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
# 203 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 204 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 205 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 206 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber::
# 207 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 208 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_OLD_AMBER
# 209 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 210 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 211 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 212 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 213 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 214 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 215 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 216 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
# 217 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 218 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 219 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 220 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowSkullFossil::
# 221 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
# 222 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SKULL_FOSSIL
# 223 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 224 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 225 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 226 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 227 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_SKULL_FOSSIL
# 228 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 229 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 230 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SKULL_FOSSIL
# 231 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 232 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 233 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 234 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowArmorFossil::
# 235 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
# 236 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_ARMOR_FOSSIL
# 237 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 238 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 239 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 240 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 241 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_ARMOR_FOSSIL
# 242 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 243 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 244 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ARMOR_FOSSIL
# 245 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 246 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 247 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 248 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil::
# 249 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
# 250 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 251 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 252 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 253 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving::
# 254 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 255 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 256 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 257 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 258 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon::
# 259 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte
# 260 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto
# 261 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl
# 262 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SKULL_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveCranidos
# 263 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ARMOR_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveShieldon
# 264 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 265 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 266 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte::
# 267 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_OMANYTE
# 268 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 269 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 270 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_OMANYTE, 5
# 271 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 272 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_HELIX
# 273 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 274 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 275 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 276 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 277 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto::
# 278 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_KABUTO
# 279 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 280 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 281 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_KABUTO, 5
# 282 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 283 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_DOME
# 284 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 285 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 286 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 287 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 288 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl::
# 289 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
# 290 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 291 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 292 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_AERODACTYL, 5
# 293 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 294 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_AMBER
# 295 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 296 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 297 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 298 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 299 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveCranidos::
# 300 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CRANIDOS
# 301 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
# 302 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 303 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_CRANIDOS, 5
# 304 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 305 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_SKULL
# 306 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 307 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 308 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 309 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 310 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveShieldon::
# 311 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SHIELDON
# 312 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
# 313 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 314 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_SHIELDON, 5
# 315 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 316 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_ARMOR
# 317 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 318 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 319 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 320 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 321 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty::
# 322 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 323 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 324 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
# 325 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 326 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitfanfare
# 327 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
# 328 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 329 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 330 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 331 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_ChangePokemonNickname
# 332 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 333 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 334 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 335 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC::
# 336 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 337 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 338 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
# 339 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 340 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitfanfare
# 341 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
# 342 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 343 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
# 344 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 345 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
# 346 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 347 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 348 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC::
# 349 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_TransferredToPC
# 350 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 351 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 352 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 353 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon::
# 354 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 355 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 356 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 357 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils::
# 358 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
# 359 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 360 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 361 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 362 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil::
# 363 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix
# 364 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome
# 365 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 366 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 367 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 368 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix::
# 369 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 370 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 371 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 372 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 373 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome::
# 374 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 375 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 376 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
