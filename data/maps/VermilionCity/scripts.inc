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
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 17 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 18 "data/maps/VermilionCity/scripts.pory"
	end
# 19 "data/maps/VermilionCity/scripts.pory"

# 20 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 21 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 22 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 23 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckSSAnneWarp
# 24 "data/maps/VermilionCity/scripts.pory"
	end
# 25 "data/maps/VermilionCity/scripts.pory"

# 26 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 27 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 28 "data/maps/VermilionCity/scripts.pory"
	return
# 29 "data/maps/VermilionCity/scripts.pory"

# 30 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSSAnneWarp::
# 31 "data/maps/VermilionCity/scripts.pory"
	getplayerxy VAR_0x8000, VAR_0x8001
# 32 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_0x8000, 23, VermilionCity_EventScript_CheckSSAnneWarpY
# 33 "data/maps/VermilionCity/scripts.pory"
	return
# 34 "data/maps/VermilionCity/scripts.pory"

# 35 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSSAnneWarpY::
# 36 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_0x8001, 34, VermilionCity_EventScript_SetSSAnneExitFlag
# 37 "data/maps/VermilionCity/scripts.pory"
	return
# 38 "data/maps/VermilionCity/scripts.pory"

# 39 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SetSSAnneExitFlag::
# 40 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_0, 1
# 41 "data/maps/VermilionCity/scripts.pory"
	return
# 42 "data/maps/VermilionCity/scripts.pory"

# 43 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpFromSSAnne::
# 44 "data/maps/VermilionCity/scripts.pory"
	lockall
# 45 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 46 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_0, 0
# 48 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 49 "data/maps/VermilionCity/scripts.pory"
	end
# 50 "data/maps/VermilionCity/scripts.pory"

# 51 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 52 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 53 "data/maps/VermilionCity/scripts.pory"
	end
# 54 "data/maps/VermilionCity/scripts.pory"

# 55 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 56 "data/maps/VermilionCity/scripts.pory"
	lock
# 57 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 58 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 59 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 60 "data/maps/VermilionCity/scripts.pory"
	release
# 61 "data/maps/VermilionCity/scripts.pory"
	end
# 62 "data/maps/VermilionCity/scripts.pory"

# 63 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 64 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 65 "data/maps/VermilionCity/scripts.pory"
	release
# 66 "data/maps/VermilionCity/scripts.pory"
	end
# 67 "data/maps/VermilionCity/scripts.pory"

# 68 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 69 "data/maps/VermilionCity/scripts.pory"
	lock
# 70 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 71 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 72 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 73 "data/maps/VermilionCity/scripts.pory"
	release
# 74 "data/maps/VermilionCity/scripts.pory"
	end
# 75 "data/maps/VermilionCity/scripts.pory"

# 76 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 77 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 78 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 79 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 80 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 81 "data/maps/VermilionCity/scripts.pory"
	end
# 82 "data/maps/VermilionCity/scripts.pory"

# 83 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 84 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 85 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 86 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 87 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 88 "data/maps/VermilionCity/scripts.pory"
	end
# 89 "data/maps/VermilionCity/scripts.pory"

# 90 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 91 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 92 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 93 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 94 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FerrySailorNoDockAccess
# 95 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 96 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 97 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 98 "data/maps/VermilionCity/scripts.pory"
	release
# 99 "data/maps/VermilionCity/scripts.pory"
	end
# 100 "data/maps/VermilionCity/scripts.pory"

# 101 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 102 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 103 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 104 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 105 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 106 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 107 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 108 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 109 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 110 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 111 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_BoardSeagallopRainbowPass
# 112 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 113 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 114 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 115 "data/maps/VermilionCity/scripts.pory"
	end
# 116 "data/maps/VermilionCity/scripts.pory"

# 117 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_BoardSeagallopRainbowPass::
# 118 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 119 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 120 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 121 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 122 "data/maps/VermilionCity/scripts.pory"
	end
# 123 "data/maps/VermilionCity/scripts.pory"

# 124 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DeclineSeagallop::
# 125 "data/maps/VermilionCity/scripts.pory"
	release
# 126 "data/maps/VermilionCity/scripts.pory"
	end
# 127 "data/maps/VermilionCity/scripts.pory"

# 128 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 129 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 130 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 131 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 132 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 133 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 134 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 135 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseMysticDestination
# 136 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 137 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 138 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 139 "data/maps/VermilionCity/scripts.pory"
	end
# 140 "data/maps/VermilionCity/scripts.pory"

# 141 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseMysticDestination::
# 142 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 143 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 144 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
# 145 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 147 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 148 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 149 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 150 "data/maps/VermilionCity/scripts.pory"
	end
# 151 "data/maps/VermilionCity/scripts.pory"

# 152 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 153 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 154 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 155 "data/maps/VermilionCity/scripts.pory"
	return
# 156 "data/maps/VermilionCity/scripts.pory"

# 157 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 158 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 159 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 160 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 161 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseAuroraDestination
# 163 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 164 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 165 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 166 "data/maps/VermilionCity/scripts.pory"
	end
# 167 "data/maps/VermilionCity/scripts.pory"

# 168 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseAuroraDestination::
# 169 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 170 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 171 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
# 172 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 173 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 174 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 175 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 176 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 177 "data/maps/VermilionCity/scripts.pory"
	end
# 178 "data/maps/VermilionCity/scripts.pory"

# 179 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 180 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 181 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 182 "data/maps/VermilionCity/scripts.pory"
	return
# 183 "data/maps/VermilionCity/scripts.pory"

# 184 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 185 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 186 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 187 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopRainbowPassOrDock, MSGBOX_DEFAULT
# 188 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 189 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 190 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_ChooseBothTicketsDestination
# 191 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 192 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 193 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 194 "data/maps/VermilionCity/scripts.pory"
	end
# 195 "data/maps/VermilionCity/scripts.pory"

# 196 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseBothTicketsDestination::
# 197 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 198 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 199 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
# 200 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 201 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 202 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 203 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 204 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 205 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 206 "data/maps/VermilionCity/scripts.pory"
	end
# 207 "data/maps/VermilionCity/scripts.pory"

# 208 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 209 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 210 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 211 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 212 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 213 "data/maps/VermilionCity/scripts.pory"
	end
# 214 "data/maps/VermilionCity/scripts.pory"

# 215 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 216 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 217 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 218 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 219 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 220 "data/maps/VermilionCity/scripts.pory"
	end
# 221 "data/maps/VermilionCity/scripts.pory"

# 222 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 223 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 224 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 225 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BoardSeagallopTriPassOrDock, MSGBOX_DEFAULT
# 226 "data/maps/VermilionCity/scripts.pory"
	multichoice 0, 0, MULTICHOICE_SEAGALLOP_OR_DOCK, FALSE
# 227 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 228 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_BoardSeagallopTriPass
# 229 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TakeToDockArea
# 230 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_DeclineSeagallop
# 231 "data/maps/VermilionCity/scripts.pory"
	case 127, VermilionCity_EventScript_DeclineSeagallop
# 232 "data/maps/VermilionCity/scripts.pory"
	end
# 233 "data/maps/VermilionCity/scripts.pory"

# 234 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_BoardSeagallopTriPass::
# 235 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 236 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 237 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 238 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
# 239 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 241 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 242 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 243 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 244 "data/maps/VermilionCity/scripts.pory"
	case 127, EventScript_CancelSail
# 245 "data/maps/VermilionCity/scripts.pory"
	end
# 246 "data/maps/VermilionCity/scripts.pory"

# 247 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 248 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 249 "data/maps/VermilionCity/scripts.pory"
	release
# 250 "data/maps/VermilionCity/scripts.pory"
	end
# 251 "data/maps/VermilionCity/scripts.pory"

# 252 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 253 "data/maps/VermilionCity/scripts.pory"
	lockall
# 254 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 255 "data/maps/VermilionCity/scripts.pory"
	end
# 256 "data/maps/VermilionCity/scripts.pory"

# 257 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 258 "data/maps/VermilionCity/scripts.pory"
	lockall
# 259 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 260 "data/maps/VermilionCity/scripts.pory"
	end
# 261 "data/maps/VermilionCity/scripts.pory"

# 262 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 263 "data/maps/VermilionCity/scripts.pory"
	lockall
# 264 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 265 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 266 "data/maps/VermilionCity/scripts.pory"
	end
# 267 "data/maps/VermilionCity/scripts.pory"

# 268 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 269 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 270 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 271 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 272 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 273 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 274 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 275 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 276 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 277 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 278 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 279 "data/maps/VermilionCity/scripts.pory"
	end
# 280 "data/maps/VermilionCity/scripts.pory"

# 281 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 282 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 283 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 284 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 285 "data/maps/VermilionCity/scripts.pory"
	end
# 286 "data/maps/VermilionCity/scripts.pory"

# 287 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 288 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 289 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 290 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 291 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSailButCanHelp
# 292 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideOffer, MSGBOX_YESNO
# 293 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_TakeToDockArea
# 294 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideDecline
# 295 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 296 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 297 "data/maps/VermilionCity/scripts.pory"
	end
# 298 "data/maps/VermilionCity/scripts.pory"

# 299 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 300 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 301 "data/maps/VermilionCity/scripts.pory"
	end
# 302 "data/maps/VermilionCity/scripts.pory"

# 303 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 304 "data/maps/VermilionCity/scripts.pory"
	lock
# 305 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 306 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 307 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 308 "data/maps/VermilionCity/scripts.pory"
	release
# 309 "data/maps/VermilionCity/scripts.pory"
	end
# 310 "data/maps/VermilionCity/scripts.pory"

# 311 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 312 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 313 "data/maps/VermilionCity/scripts.pory"
	end
# 314 "data/maps/VermilionCity/scripts.pory"

# 315 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 316 "data/maps/VermilionCity/scripts.pory"
	lock
# 317 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 318 "data/maps/VermilionCity/scripts.pory"
	waitse
# 319 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 320 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 321 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 322 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 323 "data/maps/VermilionCity/scripts.pory"
	release
# 324 "data/maps/VermilionCity/scripts.pory"
	end
# 325 "data/maps/VermilionCity/scripts.pory"

# 326 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 327 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 328 "data/maps/VermilionCity/scripts.pory"
	end
# 329 "data/maps/VermilionCity/scripts.pory"

# 330 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 331 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 332 "data/maps/VermilionCity/scripts.pory"
	end
# 333 "data/maps/VermilionCity/scripts.pory"

# 334 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 335 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 336 "data/maps/VermilionCity/scripts.pory"
	end
# 337 "data/maps/VermilionCity/scripts.pory"

# 338 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 339 "data/maps/VermilionCity/scripts.pory"
	lockall
# 340 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 341 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 342 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 343 "data/maps/VermilionCity/scripts.pory"
	end
# 344 "data/maps/VermilionCity/scripts.pory"

# 345 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 346 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 347 "data/maps/VermilionCity/scripts.pory"
	end
# 348 "data/maps/VermilionCity/scripts.pory"

# 349 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TakeToDockArea::
# 350 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DockAreaGuideAccept
# 351 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 352 "data/maps/VermilionCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 353 "data/maps/VermilionCity/scripts.pory"
	warp MAP_SSANNE_EXTERIOR, 32, 5
# 354 "data/maps/VermilionCity/scripts.pory"
	waitstate
# 355 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 356 "data/maps/VermilionCity/scripts.pory"
	end
# 357 "data/maps/VermilionCity/scripts.pory"

# 358 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_WalkUpPier::
# 359 "data/maps/VermilionCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_WalkUpPier
# 360 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 361 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 362 "data/maps/VermilionCity/scripts.pory"
	end
# 363 "data/maps/VermilionCity/scripts.pory"

# 364 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_WalkUpPier::
# 365 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 366 "data/maps/VermilionCity/scripts.pory"
	step_end
