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
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 93 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 94 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 95 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 96 "data/maps/VermilionCity/scripts.pory"
	end
# 97 "data/maps/VermilionCity/scripts.pory"

# 98 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 99 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 100 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 101 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 102 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 103 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 104 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 105 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 107 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 108 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 109 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 110 "data/maps/VermilionCity/scripts.pory"
	end
# 111 "data/maps/VermilionCity/scripts.pory"

# 112 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 113 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 114 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 115 "data/maps/VermilionCity/scripts.pory"
	return
# 116 "data/maps/VermilionCity/scripts.pory"

# 117 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 118 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 119 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 120 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 121 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 122 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 124 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 125 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 126 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 127 "data/maps/VermilionCity/scripts.pory"
	end
# 128 "data/maps/VermilionCity/scripts.pory"

# 129 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 130 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 131 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 132 "data/maps/VermilionCity/scripts.pory"
	return
# 133 "data/maps/VermilionCity/scripts.pory"

# 134 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 135 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 136 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 137 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 138 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 139 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 140 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 141 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 142 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 143 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 144 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 145 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 146 "data/maps/VermilionCity/scripts.pory"
	end
# 147 "data/maps/VermilionCity/scripts.pory"

# 148 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 149 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 150 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 151 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 152 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 153 "data/maps/VermilionCity/scripts.pory"
	end
# 154 "data/maps/VermilionCity/scripts.pory"

# 155 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 156 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 157 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 158 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 159 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 160 "data/maps/VermilionCity/scripts.pory"
	end
# 161 "data/maps/VermilionCity/scripts.pory"

# 162 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 163 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 164 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 165 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 166 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 167 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 168 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 169 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 170 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 171 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 172 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 173 "data/maps/VermilionCity/scripts.pory"
	end
# 174 "data/maps/VermilionCity/scripts.pory"

# 175 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 176 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 177 "data/maps/VermilionCity/scripts.pory"
	release
# 178 "data/maps/VermilionCity/scripts.pory"
	end
# 179 "data/maps/VermilionCity/scripts.pory"

# 180 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 181 "data/maps/VermilionCity/scripts.pory"
	lockall
# 182 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 183 "data/maps/VermilionCity/scripts.pory"
	end
# 184 "data/maps/VermilionCity/scripts.pory"

# 185 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 186 "data/maps/VermilionCity/scripts.pory"
	lockall
# 187 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 188 "data/maps/VermilionCity/scripts.pory"
	end
# 189 "data/maps/VermilionCity/scripts.pory"

# 190 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 191 "data/maps/VermilionCity/scripts.pory"
	lockall
# 192 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 193 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 194 "data/maps/VermilionCity/scripts.pory"
	end
# 195 "data/maps/VermilionCity/scripts.pory"

# 196 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 197 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 198 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 199 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 200 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 201 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 202 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 203 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 204 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 205 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 206 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 207 "data/maps/VermilionCity/scripts.pory"
	end
# 208 "data/maps/VermilionCity/scripts.pory"

# 209 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 210 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 211 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 212 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 213 "data/maps/VermilionCity/scripts.pory"
	end
# 214 "data/maps/VermilionCity/scripts.pory"

# 215 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 216 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 217 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 218 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 219 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSailButCanHelp
# 220 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 221 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 222 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 223 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 224 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 225 "data/maps/VermilionCity/scripts.pory"
	end
# 226 "data/maps/VermilionCity/scripts.pory"

# 227 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 228 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 229 "data/maps/VermilionCity/scripts.pory"
	end
# 230 "data/maps/VermilionCity/scripts.pory"

# 231 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 232 "data/maps/VermilionCity/scripts.pory"
	lock
# 233 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 234 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 235 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 236 "data/maps/VermilionCity/scripts.pory"
	release
# 237 "data/maps/VermilionCity/scripts.pory"
	end
# 238 "data/maps/VermilionCity/scripts.pory"

# 239 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 240 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 241 "data/maps/VermilionCity/scripts.pory"
	end
# 242 "data/maps/VermilionCity/scripts.pory"

# 243 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 244 "data/maps/VermilionCity/scripts.pory"
	lock
# 245 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 246 "data/maps/VermilionCity/scripts.pory"
	waitse
# 247 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 248 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 249 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 250 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 251 "data/maps/VermilionCity/scripts.pory"
	release
# 252 "data/maps/VermilionCity/scripts.pory"
	end
# 253 "data/maps/VermilionCity/scripts.pory"

# 254 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 255 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 256 "data/maps/VermilionCity/scripts.pory"
	end
# 257 "data/maps/VermilionCity/scripts.pory"

# 258 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 259 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 260 "data/maps/VermilionCity/scripts.pory"
	end
# 261 "data/maps/VermilionCity/scripts.pory"

# 262 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 263 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 264 "data/maps/VermilionCity/scripts.pory"
	end
# 265 "data/maps/VermilionCity/scripts.pory"

# 266 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 267 "data/maps/VermilionCity/scripts.pory"
	lockall
# 268 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 269 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 270 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 271 "data/maps/VermilionCity/scripts.pory"
	end
# 272 "data/maps/VermilionCity/scripts.pory"

# 273 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 274 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 275 "data/maps/VermilionCity/scripts.pory"
	end
# 276 "data/maps/VermilionCity/scripts.pory"

# 277 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TakeToDockArea::
# 278 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideAccept
# 279 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 280 "data/maps/VermilionCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 281 "data/maps/VermilionCity/scripts.pory"
	warp MAP_SSANNE_EXTERIOR, 32, 5
# 282 "data/maps/VermilionCity/scripts.pory"
	waitstate
# 283 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 284 "data/maps/VermilionCity/scripts.pory"
	end
# 285 "data/maps/VermilionCity/scripts.pory"

# 286 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpPier::
# 287 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUpPier
# 288 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 289 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 290 "data/maps/VermilionCity/scripts.pory"
	end
# 291 "data/maps/VermilionCity/scripts.pory"

# 292 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_WalkUpPier::
# 293 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 294 "data/maps/VermilionCity/scripts.pory"
	step_end
