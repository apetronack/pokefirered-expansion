# 1 "data/maps/Route2_EastBuilding/scripts.pory"

# 2 "data/maps/Route2_EastBuilding/scripts.pory"
.equ REQUIRED_SEEN_MONS, 10
# 3 "data/maps/Route2_EastBuilding/scripts.pory"

# 4 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_MapScripts::
# 5 "data/maps/Route2_EastBuilding/scripts.pory"
	.byte 0
# 6 "data/maps/Route2_EastBuilding/scripts.pory"

# 7 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_Aide::
# 8 "data/maps/Route2_EastBuilding/scripts.pory"
	lock
# 9 "data/maps/Route2_EastBuilding/scripts.pory"
	faceplayer
# 10 "data/maps/Route2_EastBuilding/scripts.pory"
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
# 11 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
# 12 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
# 13 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
# 14 "data/maps/Route2_EastBuilding/scripts.pory"
	setvar VAR_0x8004, 0
# 15 "data/maps/Route2_EastBuilding/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 16 "data/maps/Route2_EastBuilding/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_0x8006
# 17 "data/maps/Route2_EastBuilding/scripts.pory"
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
# 18 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
# 19 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
# 20 "data/maps/Route2_EastBuilding/scripts.pory"
	checkitemspace ITEM_HM05
# 21 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
# 22 "data/maps/Route2_EastBuilding/scripts.pory"
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
# 23 "data/maps/Route2_EastBuilding/scripts.pory"
	setflag FLAG_GOT_HM05
# 24 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_ExplainHM05
# 25 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 26 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 27 "data/maps/Route2_EastBuilding/scripts.pory"

# 28 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_AlreadyGotHM05::
# 29 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_ExplainHM05
# 30 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 31 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 32 "data/maps/Route2_EastBuilding/scripts.pory"

# 33 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_GetAideRequestInfo::
# 34 "data/maps/Route2_EastBuilding/scripts.pory"
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
# 35 "data/maps/Route2_EastBuilding/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_HM05
# 36 "data/maps/Route2_EastBuilding/scripts.pory"
	return
# 37 "data/maps/Route2_EastBuilding/scripts.pory"

# 38 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_Rocker::
# 39 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
# 40 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 41 "data/maps/Route2_EastBuilding/scripts.pory"

# 42 "data/maps/Route2_EastBuilding/scripts.pory"

# 43 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_Craig::
# 44 "data/maps/Route2_EastBuilding/scripts.pory"
	lock
# 45 "data/maps/Route2_EastBuilding/scripts.pory"
	faceplayer
# 46 "data/maps/Route2_EastBuilding/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_CYNDAQUIL
# 47 "data/maps/Route2_EastBuilding/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 48 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_set FLAG_DID_CINNAMON_TRADE, Route2_EastBuilding_EventScript_AlreadyTraded
# 49 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 50 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route2_EastBuilding_EventScript_DeclineTrade
# 51 "data/maps/Route2_EastBuilding/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 52 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route2_EastBuilding_EventScript_DeclineTrade
# 53 "data/maps/Route2_EastBuilding/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 54 "data/maps/Route2_EastBuilding/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, Route2_EastBuilding_EventScript_NotRequestedMon
# 55 "data/maps/Route2_EastBuilding/scripts.pory"
	call EventScript_DoInGameTrade
# 56 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 57 "data/maps/Route2_EastBuilding/scripts.pory"
	setflag FLAG_DID_CINNAMON_TRADE
# 58 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 59 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 60 "data/maps/Route2_EastBuilding/scripts.pory"

# 61 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_AlreadyTraded::
# 62 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 63 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 64 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 65 "data/maps/Route2_EastBuilding/scripts.pory"

# 66 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_DeclineTrade::
# 67 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 68 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 69 "data/maps/Route2_EastBuilding/scripts.pory"
	end
# 70 "data/maps/Route2_EastBuilding/scripts.pory"

# 71 "data/maps/Route2_EastBuilding/scripts.pory"
Route2_EastBuilding_EventScript_NotRequestedMon::
# 72 "data/maps/Route2_EastBuilding/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 73 "data/maps/Route2_EastBuilding/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 74 "data/maps/Route2_EastBuilding/scripts.pory"
	release
# 75 "data/maps/Route2_EastBuilding/scripts.pory"
	end
