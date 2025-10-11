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
	.2byte 0
# 12 "data/maps/VermilionCity/scripts.pory"

# 13 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 14 "data/maps/VermilionCity/scripts.pory"
	lockall
# 15 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 16 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 17 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 18 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 19 "data/maps/VermilionCity/scripts.pory"
	end
# 20 "data/maps/VermilionCity/scripts.pory"

# 21 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 22 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 23 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 24 "data/maps/VermilionCity/scripts.pory"
	step_end
# 25 "data/maps/VermilionCity/scripts.pory"

# 26 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 27 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 28 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 29 "data/maps/VermilionCity/scripts.pory"
	end
# 30 "data/maps/VermilionCity/scripts.pory"

# 31 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 32 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 33 "data/maps/VermilionCity/scripts.pory"
	return
# 34 "data/maps/VermilionCity/scripts.pory"

# 35 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 36 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 37 "data/maps/VermilionCity/scripts.pory"
	end
# 38 "data/maps/VermilionCity/scripts.pory"

# 39 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 40 "data/maps/VermilionCity/scripts.pory"
	lock
# 41 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 42 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 43 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 44 "data/maps/VermilionCity/scripts.pory"
	release
# 45 "data/maps/VermilionCity/scripts.pory"
	end
# 46 "data/maps/VermilionCity/scripts.pory"

# 47 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 48 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 49 "data/maps/VermilionCity/scripts.pory"
	release
# 50 "data/maps/VermilionCity/scripts.pory"
	end
# 51 "data/maps/VermilionCity/scripts.pory"

# 52 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 53 "data/maps/VermilionCity/scripts.pory"
	lock
# 54 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 55 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 56 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 57 "data/maps/VermilionCity/scripts.pory"
	release
# 58 "data/maps/VermilionCity/scripts.pory"
	end
# 59 "data/maps/VermilionCity/scripts.pory"

# 60 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 61 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 62 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 63 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 64 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 65 "data/maps/VermilionCity/scripts.pory"
	end
# 66 "data/maps/VermilionCity/scripts.pory"

# 67 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 69 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 70 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 71 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 72 "data/maps/VermilionCity/scripts.pory"
	end
# 73 "data/maps/VermilionCity/scripts.pory"

# 74 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 75 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 76 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 77 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 78 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FerrySailorNoDockAccess
# 79 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 80 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 81 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 82 "data/maps/VermilionCity/scripts.pory"
	release
# 83 "data/maps/VermilionCity/scripts.pory"
	end
# 84 "data/maps/VermilionCity/scripts.pory"

# 85 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 86 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 87 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 88 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 89 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 90 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 91 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 92 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 93 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 94 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_BoardSeagallopRainbowPass
# 96 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 97 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 98 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 99 "data/maps/VermilionCity/scripts.pory"
	end
# 100 "data/maps/VermilionCity/scripts.pory"

# 101 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_BoardSeagallopRainbowPass::
# 102 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 103 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 104 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 105 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 106 "data/maps/VermilionCity/scripts.pory"
	end
# 107 "data/maps/VermilionCity/scripts.pory"

# 108 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DeclineSeagallop::
# 109 "data/maps/VermilionCity/scripts.pory"
	release
# 110 "data/maps/VermilionCity/scripts.pory"
	end
# 111 "data/maps/VermilionCity/scripts.pory"

# 112 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 113 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 114 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 115 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 116 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 117 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 118 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseMysticDestination
# 120 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 121 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 122 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 123 "data/maps/VermilionCity/scripts.pory"
	end
# 124 "data/maps/VermilionCity/scripts.pory"

# 125 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseMysticDestination::
# 126 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 127 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 128 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 129 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 130 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 131 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 132 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 133 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 134 "data/maps/VermilionCity/scripts.pory"
	end
# 135 "data/maps/VermilionCity/scripts.pory"

# 136 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 137 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 138 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 139 "data/maps/VermilionCity/scripts.pory"
	return
# 140 "data/maps/VermilionCity/scripts.pory"

# 141 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 142 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 143 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 144 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 145 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseAuroraDestination
# 147 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 148 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 149 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 150 "data/maps/VermilionCity/scripts.pory"
	end
# 151 "data/maps/VermilionCity/scripts.pory"

# 152 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseAuroraDestination::
# 153 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 154 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 155 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 156 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 158 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 159 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 160 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 161 "data/maps/VermilionCity/scripts.pory"
	end
# 162 "data/maps/VermilionCity/scripts.pory"

# 163 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 164 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 165 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 166 "data/maps/VermilionCity/scripts.pory"
	return
# 167 "data/maps/VermilionCity/scripts.pory"

# 168 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 169 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 170 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 171 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 172 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 173 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 174 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseBothTicketsDestination
# 175 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 176 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 177 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 178 "data/maps/VermilionCity/scripts.pory"
	end
# 179 "data/maps/VermilionCity/scripts.pory"

# 180 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseBothTicketsDestination::
# 181 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 182 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 183 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 184 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 186 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 187 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 188 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 189 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 190 "data/maps/VermilionCity/scripts.pory"
	end
# 191 "data/maps/VermilionCity/scripts.pory"

# 192 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 193 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 194 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 195 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 196 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 197 "data/maps/VermilionCity/scripts.pory"
	end
# 198 "data/maps/VermilionCity/scripts.pory"

# 199 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 200 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 201 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 202 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 203 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 204 "data/maps/VermilionCity/scripts.pory"
	end
# 205 "data/maps/VermilionCity/scripts.pory"

# 206 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 207 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 208 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 209 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 210 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 211 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 212 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 213 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 214 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 215 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 216 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 217 "data/maps/VermilionCity/scripts.pory"
	end
# 218 "data/maps/VermilionCity/scripts.pory"

# 219 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 220 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 221 "data/maps/VermilionCity/scripts.pory"
	release
# 222 "data/maps/VermilionCity/scripts.pory"
	end
# 223 "data/maps/VermilionCity/scripts.pory"

# 224 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 225 "data/maps/VermilionCity/scripts.pory"
	lockall
# 226 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 227 "data/maps/VermilionCity/scripts.pory"
	end
# 228 "data/maps/VermilionCity/scripts.pory"

# 229 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 230 "data/maps/VermilionCity/scripts.pory"
	lockall
# 231 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 232 "data/maps/VermilionCity/scripts.pory"
	end
# 233 "data/maps/VermilionCity/scripts.pory"

# 234 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 235 "data/maps/VermilionCity/scripts.pory"
	lockall
# 236 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 237 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 238 "data/maps/VermilionCity/scripts.pory"
	end
# 239 "data/maps/VermilionCity/scripts.pory"

# 240 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 241 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 242 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 243 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 244 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 245 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 246 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 247 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 248 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 249 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 250 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 251 "data/maps/VermilionCity/scripts.pory"
	end
# 252 "data/maps/VermilionCity/scripts.pory"

# 253 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 254 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 255 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 256 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 257 "data/maps/VermilionCity/scripts.pory"
	end
# 258 "data/maps/VermilionCity/scripts.pory"

# 259 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 260 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 261 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 262 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 263 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSailButCanHelp
# 264 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 265 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 266 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 267 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 268 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 269 "data/maps/VermilionCity/scripts.pory"
	end
# 270 "data/maps/VermilionCity/scripts.pory"

# 271 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 272 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 273 "data/maps/VermilionCity/scripts.pory"
	end
# 274 "data/maps/VermilionCity/scripts.pory"

# 275 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 276 "data/maps/VermilionCity/scripts.pory"
	lock
# 277 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 278 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 279 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 280 "data/maps/VermilionCity/scripts.pory"
	release
# 281 "data/maps/VermilionCity/scripts.pory"
	end
# 282 "data/maps/VermilionCity/scripts.pory"

# 283 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 284 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 285 "data/maps/VermilionCity/scripts.pory"
	end
# 286 "data/maps/VermilionCity/scripts.pory"

# 287 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 288 "data/maps/VermilionCity/scripts.pory"
	lock
# 289 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 290 "data/maps/VermilionCity/scripts.pory"
	waitse
# 291 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 292 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 293 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 294 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 295 "data/maps/VermilionCity/scripts.pory"
	release
# 296 "data/maps/VermilionCity/scripts.pory"
	end
# 297 "data/maps/VermilionCity/scripts.pory"

# 298 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 299 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 300 "data/maps/VermilionCity/scripts.pory"
	end
# 301 "data/maps/VermilionCity/scripts.pory"

# 302 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 303 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 304 "data/maps/VermilionCity/scripts.pory"
	end
# 305 "data/maps/VermilionCity/scripts.pory"

# 306 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 307 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 308 "data/maps/VermilionCity/scripts.pory"
	end
# 309 "data/maps/VermilionCity/scripts.pory"

# 310 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 311 "data/maps/VermilionCity/scripts.pory"
	lockall
# 312 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 313 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 314 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 315 "data/maps/VermilionCity/scripts.pory"
	end
# 316 "data/maps/VermilionCity/scripts.pory"

# 317 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 318 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 319 "data/maps/VermilionCity/scripts.pory"
	end
# 320 "data/maps/VermilionCity/scripts.pory"

# 321 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TakeToDockArea::
# 322 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideAccept
# 323 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 324 "data/maps/VermilionCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 325 "data/maps/VermilionCity/scripts.pory"
	warp MAP_SSANNE_EXTERIOR, 32, 5
# 326 "data/maps/VermilionCity/scripts.pory"
	waitstate
# 327 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 328 "data/maps/VermilionCity/scripts.pory"
	end
# 329 "data/maps/VermilionCity/scripts.pory"

# 330 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpPier::
# 331 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUpPier
# 332 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 333 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 334 "data/maps/VermilionCity/scripts.pory"
	end
# 335 "data/maps/VermilionCity/scripts.pory"

# 336 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_WalkUpPier::
# 337 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 338 "data/maps/VermilionCity/scripts.pory"
	step_end
