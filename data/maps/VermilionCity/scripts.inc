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
	call_if_ge VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_ShowDockAreaGuide
# 30 "data/maps/VermilionCity/scripts.pory"
	end
# 31 "data/maps/VermilionCity/scripts.pory"

# 32 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 33 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 34 "data/maps/VermilionCity/scripts.pory"
	return
# 35 "data/maps/VermilionCity/scripts.pory"

# 36 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowDockAreaGuide::
# 37 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_HIDE_VERMILION_DOCK_GUIDE
# 38 "data/maps/VermilionCity/scripts.pory"
	return
# 39 "data/maps/VermilionCity/scripts.pory"

# 40 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 41 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 42 "data/maps/VermilionCity/scripts.pory"
	end
# 43 "data/maps/VermilionCity/scripts.pory"

# 44 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 45 "data/maps/VermilionCity/scripts.pory"
	lock
# 46 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 47 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 48 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 49 "data/maps/VermilionCity/scripts.pory"
	release
# 50 "data/maps/VermilionCity/scripts.pory"
	end
# 51 "data/maps/VermilionCity/scripts.pory"

# 52 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 53 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 54 "data/maps/VermilionCity/scripts.pory"
	release
# 55 "data/maps/VermilionCity/scripts.pory"
	end
# 56 "data/maps/VermilionCity/scripts.pory"

# 57 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 58 "data/maps/VermilionCity/scripts.pory"
	lock
# 59 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 60 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 61 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 62 "data/maps/VermilionCity/scripts.pory"
	release
# 63 "data/maps/VermilionCity/scripts.pory"
	end
# 64 "data/maps/VermilionCity/scripts.pory"

# 65 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 66 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 67 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 69 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 70 "data/maps/VermilionCity/scripts.pory"
	end
# 71 "data/maps/VermilionCity/scripts.pory"

# 72 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 73 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 74 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 75 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 76 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 77 "data/maps/VermilionCity/scripts.pory"
	end
# 78 "data/maps/VermilionCity/scripts.pory"

# 79 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 80 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 81 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 82 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 83 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 84 "data/maps/VermilionCity/scripts.pory"
	release
# 85 "data/maps/VermilionCity/scripts.pory"
	end
# 86 "data/maps/VermilionCity/scripts.pory"

# 87 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 88 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 89 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 90 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 91 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 92 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 93 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 94 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 95 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 96 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 97 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 98 "data/maps/VermilionCity/scripts.pory"
	end
# 99 "data/maps/VermilionCity/scripts.pory"

# 100 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 101 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 102 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 103 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 104 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 105 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 106 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 107 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 108 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 109 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 110 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 111 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 112 "data/maps/VermilionCity/scripts.pory"
	end
# 113 "data/maps/VermilionCity/scripts.pory"

# 114 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 115 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 116 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 117 "data/maps/VermilionCity/scripts.pory"
	return
# 118 "data/maps/VermilionCity/scripts.pory"

# 119 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 120 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 121 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 122 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 123 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 124 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 125 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 126 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 127 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 128 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 129 "data/maps/VermilionCity/scripts.pory"
	end
# 130 "data/maps/VermilionCity/scripts.pory"

# 131 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 132 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 133 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 134 "data/maps/VermilionCity/scripts.pory"
	return
# 135 "data/maps/VermilionCity/scripts.pory"

# 136 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 137 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 138 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 139 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 140 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 141 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 142 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 143 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 144 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 145 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 146 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 147 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 148 "data/maps/VermilionCity/scripts.pory"
	end
# 149 "data/maps/VermilionCity/scripts.pory"

# 150 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 151 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 152 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 153 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 154 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 155 "data/maps/VermilionCity/scripts.pory"
	end
# 156 "data/maps/VermilionCity/scripts.pory"

# 157 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 158 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 159 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 160 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 161 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 162 "data/maps/VermilionCity/scripts.pory"
	end
# 163 "data/maps/VermilionCity/scripts.pory"

# 164 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 165 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 166 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 167 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 168 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 169 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 170 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 171 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 172 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 173 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 174 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 175 "data/maps/VermilionCity/scripts.pory"
	end
# 176 "data/maps/VermilionCity/scripts.pory"

# 177 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 178 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 179 "data/maps/VermilionCity/scripts.pory"
	release
# 180 "data/maps/VermilionCity/scripts.pory"
	end
# 181 "data/maps/VermilionCity/scripts.pory"

# 182 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 183 "data/maps/VermilionCity/scripts.pory"
	lockall
# 184 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 185 "data/maps/VermilionCity/scripts.pory"
	end
# 186 "data/maps/VermilionCity/scripts.pory"

# 187 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 188 "data/maps/VermilionCity/scripts.pory"
	lockall
# 189 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 190 "data/maps/VermilionCity/scripts.pory"
	end
# 191 "data/maps/VermilionCity/scripts.pory"

# 192 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 193 "data/maps/VermilionCity/scripts.pory"
	lockall
# 194 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 195 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 196 "data/maps/VermilionCity/scripts.pory"
	end
# 197 "data/maps/VermilionCity/scripts.pory"

# 198 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 199 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 200 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 201 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 202 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 203 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 204 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 205 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 206 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 207 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 208 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 209 "data/maps/VermilionCity/scripts.pory"
	end
# 210 "data/maps/VermilionCity/scripts.pory"

# 211 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 212 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 213 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 214 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 215 "data/maps/VermilionCity/scripts.pory"
	end
# 216 "data/maps/VermilionCity/scripts.pory"

# 217 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 218 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 219 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 220 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 221 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 222 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 223 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 224 "data/maps/VermilionCity/scripts.pory"
	end
# 225 "data/maps/VermilionCity/scripts.pory"

# 226 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 227 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 228 "data/maps/VermilionCity/scripts.pory"
	end
# 229 "data/maps/VermilionCity/scripts.pory"

# 230 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 231 "data/maps/VermilionCity/scripts.pory"
	lock
# 232 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 233 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 234 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 235 "data/maps/VermilionCity/scripts.pory"
	release
# 236 "data/maps/VermilionCity/scripts.pory"
	end
# 237 "data/maps/VermilionCity/scripts.pory"

# 238 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 239 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 240 "data/maps/VermilionCity/scripts.pory"
	end
# 241 "data/maps/VermilionCity/scripts.pory"

# 242 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 243 "data/maps/VermilionCity/scripts.pory"
	lock
# 244 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 245 "data/maps/VermilionCity/scripts.pory"
	waitse
# 246 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 247 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 248 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 249 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 250 "data/maps/VermilionCity/scripts.pory"
	release
# 251 "data/maps/VermilionCity/scripts.pory"
	end
# 252 "data/maps/VermilionCity/scripts.pory"

# 253 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 254 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 255 "data/maps/VermilionCity/scripts.pory"
	end
# 256 "data/maps/VermilionCity/scripts.pory"

# 257 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 258 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 259 "data/maps/VermilionCity/scripts.pory"
	end
# 260 "data/maps/VermilionCity/scripts.pory"

# 261 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 262 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 263 "data/maps/VermilionCity/scripts.pory"
	end
# 264 "data/maps/VermilionCity/scripts.pory"

# 265 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 266 "data/maps/VermilionCity/scripts.pory"
	lockall
# 267 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 268 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 269 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 270 "data/maps/VermilionCity/scripts.pory"
	end
# 271 "data/maps/VermilionCity/scripts.pory"

# 272 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 273 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 274 "data/maps/VermilionCity/scripts.pory"
	end
# 275 "data/maps/VermilionCity/scripts.pory"

# 276 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DockAreaGuide::
# 277 "data/maps/VermilionCity/scripts.pory"
	lock
# 278 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 279 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideIntro
# 280 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 281 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 282 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 283 "data/maps/VermilionCity/scripts.pory"
	release
# 284 "data/maps/VermilionCity/scripts.pory"
	end
# 285 "data/maps/VermilionCity/scripts.pory"

# 286 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TakeToDockArea::
# 287 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideAccept
# 288 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 289 "data/maps/VermilionCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 290 "data/maps/VermilionCity/scripts.pory"
	warp MAP_SSANNE_EXTERIOR, 32, 5
# 291 "data/maps/VermilionCity/scripts.pory"
	waitstate
# 292 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 293 "data/maps/VermilionCity/scripts.pory"
	end
# 294 "data/maps/VermilionCity/scripts.pory"

# 295 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpPier::
# 296 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUpPier
# 297 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 298 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 299 "data/maps/VermilionCity/scripts.pory"
	end
# 300 "data/maps/VermilionCity/scripts.pory"

# 301 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_WalkUpPier::
# 302 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 303 "data/maps/VermilionCity/scripts.pory"
	step_end
