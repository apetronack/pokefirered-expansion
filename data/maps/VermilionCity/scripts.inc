# 1 "data/maps/VermilionCity/scripts.pory"

# 2 "data/maps/VermilionCity/scripts.pory"
.equ LOCALID_FERRY_SAILOR, 6
# 3 "data/maps/VermilionCity/scripts.pory"

# 4 "data/maps/VermilionCity/scripts.pory"
VermilionCity_MapScripts::
# 5 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
# 6 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
# 7 "data/maps/VermilionCity/scripts.pory"
	.byte 0
# 8 "data/maps/VermilionCity/scripts.pory"

# 9 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnFrame::
# 10 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
# 11 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, VermilionCity_EventScript_WalkUpFromSSAnne
# 12 "data/maps/VermilionCity/scripts.pory"
	.2byte 0
# 13 "data/maps/VermilionCity/scripts.pory"

# 14 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 15 "data/maps/VermilionCity/scripts.pory"
	lockall
# 16 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 17 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 18 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 19 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 20 "data/maps/VermilionCity/scripts.pory"
	end
# 21 "data/maps/VermilionCity/scripts.pory"

# 22 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 23 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 24 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 25 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckSSAnneWarp
# 26 "data/maps/VermilionCity/scripts.pory"
	end
# 27 "data/maps/VermilionCity/scripts.pory"

# 28 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 29 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 30 "data/maps/VermilionCity/scripts.pory"
	return
# 31 "data/maps/VermilionCity/scripts.pory"

# 32 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSSAnneWarp::
# 33 "data/maps/VermilionCity/scripts.pory"
	getplayerxy VAR_0x8000, VAR_0x8001
# 34 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_0x8000, 23, VermilionCity_EventScript_CheckSSAnneWarpY
# 35 "data/maps/VermilionCity/scripts.pory"
	return
# 36 "data/maps/VermilionCity/scripts.pory"

# 37 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSSAnneWarpY::
# 38 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_0x8001, 34, VermilionCity_EventScript_SetSSAnneExitFlag
# 39 "data/maps/VermilionCity/scripts.pory"
	return
# 40 "data/maps/VermilionCity/scripts.pory"

# 41 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SetSSAnneExitFlag::
# 42 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_0, 1
# 43 "data/maps/VermilionCity/scripts.pory"
	return
# 44 "data/maps/VermilionCity/scripts.pory"

# 45 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpFromSSAnne::
# 46 "data/maps/VermilionCity/scripts.pory"
	lockall
# 47 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 48 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 49 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_0, 0
# 50 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 51 "data/maps/VermilionCity/scripts.pory"
	end
# 52 "data/maps/VermilionCity/scripts.pory"

# 53 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 54 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 55 "data/maps/VermilionCity/scripts.pory"
	end
# 56 "data/maps/VermilionCity/scripts.pory"

# 57 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 58 "data/maps/VermilionCity/scripts.pory"
	lock
# 59 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 60 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 61 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 62 "data/maps/VermilionCity/scripts.pory"
	release
# 63 "data/maps/VermilionCity/scripts.pory"
	end
# 64 "data/maps/VermilionCity/scripts.pory"

# 65 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 66 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 67 "data/maps/VermilionCity/scripts.pory"
	release
# 68 "data/maps/VermilionCity/scripts.pory"
	end
# 69 "data/maps/VermilionCity/scripts.pory"

# 70 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 71 "data/maps/VermilionCity/scripts.pory"
	lock
# 72 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 73 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 74 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 75 "data/maps/VermilionCity/scripts.pory"
	release
# 76 "data/maps/VermilionCity/scripts.pory"
	end
# 77 "data/maps/VermilionCity/scripts.pory"

# 78 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 79 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 80 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 81 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 82 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 83 "data/maps/VermilionCity/scripts.pory"
	end
# 84 "data/maps/VermilionCity/scripts.pory"

# 85 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 86 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 87 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 88 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 89 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 90 "data/maps/VermilionCity/scripts.pory"
	end
# 91 "data/maps/VermilionCity/scripts.pory"

# 92 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 93 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 94 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 95 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 96 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FerrySailorNoDockAccess
# 97 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 98 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 99 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 100 "data/maps/VermilionCity/scripts.pory"
	release
# 101 "data/maps/VermilionCity/scripts.pory"
	end
# 102 "data/maps/VermilionCity/scripts.pory"

# 103 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 104 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 105 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 106 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 107 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 108 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 109 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 110 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 111 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 112 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_BoardSeagallopRainbowPass
# 114 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 115 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 116 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 117 "data/maps/VermilionCity/scripts.pory"
	end
# 118 "data/maps/VermilionCity/scripts.pory"

# 119 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_BoardSeagallopRainbowPass::
# 120 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 121 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 122 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 123 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 124 "data/maps/VermilionCity/scripts.pory"
	end
# 125 "data/maps/VermilionCity/scripts.pory"

# 126 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DeclineSeagallop::
# 127 "data/maps/VermilionCity/scripts.pory"
	release
# 128 "data/maps/VermilionCity/scripts.pory"
	end
# 129 "data/maps/VermilionCity/scripts.pory"

# 130 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 131 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 132 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 133 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 134 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 135 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 136 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 137 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseMysticDestination
# 138 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 139 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 140 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 141 "data/maps/VermilionCity/scripts.pory"
	end
# 142 "data/maps/VermilionCity/scripts.pory"

# 143 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseMysticDestination::
# 144 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 145 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 146 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 147 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 149 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 150 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 151 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 152 "data/maps/VermilionCity/scripts.pory"
	end
# 153 "data/maps/VermilionCity/scripts.pory"

# 154 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 155 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 156 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 157 "data/maps/VermilionCity/scripts.pory"
	return
# 158 "data/maps/VermilionCity/scripts.pory"

# 159 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 160 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 161 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 162 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 163 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 164 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseAuroraDestination
# 165 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 166 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 167 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 168 "data/maps/VermilionCity/scripts.pory"
	end
# 169 "data/maps/VermilionCity/scripts.pory"

# 170 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseAuroraDestination::
# 171 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 172 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 173 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 174 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 175 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 176 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 177 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 178 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 179 "data/maps/VermilionCity/scripts.pory"
	end
# 180 "data/maps/VermilionCity/scripts.pory"

# 181 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 182 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 183 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 184 "data/maps/VermilionCity/scripts.pory"
	return
# 185 "data/maps/VermilionCity/scripts.pory"

# 186 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 187 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 188 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 189 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 190 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 191 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 192 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseBothTicketsDestination
# 193 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 194 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 195 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 196 "data/maps/VermilionCity/scripts.pory"
	end
# 197 "data/maps/VermilionCity/scripts.pory"

# 198 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseBothTicketsDestination::
# 199 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 200 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 201 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 202 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 203 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 204 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 205 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 206 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 207 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 208 "data/maps/VermilionCity/scripts.pory"
	end
# 209 "data/maps/VermilionCity/scripts.pory"

# 210 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 211 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 212 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 213 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 214 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 215 "data/maps/VermilionCity/scripts.pory"
	end
# 216 "data/maps/VermilionCity/scripts.pory"

# 217 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 218 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 219 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 220 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 221 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 222 "data/maps/VermilionCity/scripts.pory"
	end
# 223 "data/maps/VermilionCity/scripts.pory"

# 224 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 225 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 226 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 227 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 228 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 229 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 230 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 231 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 232 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 233 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 234 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 235 "data/maps/VermilionCity/scripts.pory"
	end
# 236 "data/maps/VermilionCity/scripts.pory"

# 237 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 238 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 239 "data/maps/VermilionCity/scripts.pory"
	release
# 240 "data/maps/VermilionCity/scripts.pory"
	end
# 241 "data/maps/VermilionCity/scripts.pory"

# 242 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 243 "data/maps/VermilionCity/scripts.pory"
	lockall
# 244 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 245 "data/maps/VermilionCity/scripts.pory"
	end
# 246 "data/maps/VermilionCity/scripts.pory"

# 247 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 248 "data/maps/VermilionCity/scripts.pory"
	lockall
# 249 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 250 "data/maps/VermilionCity/scripts.pory"
	end
# 251 "data/maps/VermilionCity/scripts.pory"

# 252 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 253 "data/maps/VermilionCity/scripts.pory"
	lockall
# 254 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 255 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 256 "data/maps/VermilionCity/scripts.pory"
	end
# 257 "data/maps/VermilionCity/scripts.pory"

# 258 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 259 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 260 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 261 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 262 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 263 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 264 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 265 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 266 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 267 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 268 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 269 "data/maps/VermilionCity/scripts.pory"
	end
# 270 "data/maps/VermilionCity/scripts.pory"

# 271 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 272 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 273 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 274 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 275 "data/maps/VermilionCity/scripts.pory"
	end
# 276 "data/maps/VermilionCity/scripts.pory"

# 277 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 278 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 279 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 280 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 281 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSailButCanHelp
# 282 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 283 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 284 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 285 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 286 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 287 "data/maps/VermilionCity/scripts.pory"
	end
# 288 "data/maps/VermilionCity/scripts.pory"

# 289 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 290 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 291 "data/maps/VermilionCity/scripts.pory"
	end
# 292 "data/maps/VermilionCity/scripts.pory"

# 293 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 294 "data/maps/VermilionCity/scripts.pory"
	lock
# 295 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 296 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 297 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 298 "data/maps/VermilionCity/scripts.pory"
	release
# 299 "data/maps/VermilionCity/scripts.pory"
	end
# 300 "data/maps/VermilionCity/scripts.pory"

# 301 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 302 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 303 "data/maps/VermilionCity/scripts.pory"
	end
# 304 "data/maps/VermilionCity/scripts.pory"

# 305 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 306 "data/maps/VermilionCity/scripts.pory"
	lock
# 307 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 308 "data/maps/VermilionCity/scripts.pory"
	waitse
# 309 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 310 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 311 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 312 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 313 "data/maps/VermilionCity/scripts.pory"
	release
# 314 "data/maps/VermilionCity/scripts.pory"
	end
# 315 "data/maps/VermilionCity/scripts.pory"

# 316 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 317 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 318 "data/maps/VermilionCity/scripts.pory"
	end
# 319 "data/maps/VermilionCity/scripts.pory"

# 320 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 321 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 322 "data/maps/VermilionCity/scripts.pory"
	end
# 323 "data/maps/VermilionCity/scripts.pory"

# 324 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 325 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 326 "data/maps/VermilionCity/scripts.pory"
	end
# 327 "data/maps/VermilionCity/scripts.pory"

# 328 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 329 "data/maps/VermilionCity/scripts.pory"
	lockall
# 330 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 331 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 332 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 333 "data/maps/VermilionCity/scripts.pory"
	end
# 334 "data/maps/VermilionCity/scripts.pory"

# 335 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 336 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 337 "data/maps/VermilionCity/scripts.pory"
	end
# 338 "data/maps/VermilionCity/scripts.pory"

# 339 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TakeToDockArea::
# 340 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideAccept
# 341 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 342 "data/maps/VermilionCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 343 "data/maps/VermilionCity/scripts.pory"
	warp MAP_SSANNE_EXTERIOR, 32, 5
# 344 "data/maps/VermilionCity/scripts.pory"
	waitstate
# 345 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 346 "data/maps/VermilionCity/scripts.pory"
	end
# 347 "data/maps/VermilionCity/scripts.pory"

# 348 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpPier::
# 349 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUpPier
# 350 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 351 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 352 "data/maps/VermilionCity/scripts.pory"
	end
# 353 "data/maps/VermilionCity/scripts.pory"

# 354 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_WalkUpPier::
# 355 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 356 "data/maps/VermilionCity/scripts.pory"
	step_end
