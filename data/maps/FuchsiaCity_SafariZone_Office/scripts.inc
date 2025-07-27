# 1 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 2 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_MapScripts::
# 3 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	.byte 0
# 4 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 5 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_Worker1::
# 6 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox FuchsiaCity_SafariZone_Office_Text_NicknamedWardenSlowpoke, MSGBOX_NPC
# 7 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 8 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 9 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_Worker2::
# 10 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox FuchsiaCity_SafariZone_Office_Text_WardenIsVeryKnowledgeable, MSGBOX_NPC
# 11 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 12 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 13 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_Worker3::
# 14 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox FuchsiaCity_SafariZone_Office_Text_CouldntUnderstandWarden, MSGBOX_NPC
# 15 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 16 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 17 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_Worker4::
# 18 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox FuchsiaCity_SafariZone_Office_Text_PrizeInSafariZone, MSGBOX_NPC
# 19 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 20 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 21 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_Frank::
# 22 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	lock
# 23 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	faceplayer
# 24 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_TOTODILE
# 25 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 26 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	goto_if_set FLAG_DID_IRWIN_TRADE, FuchsiaCity_SafariZone_Office_EventScript_AlreadyTraded
# 27 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 28 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZone_Office_EventScript_DeclineTrade
# 29 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 30 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_SafariZone_Office_EventScript_DeclineTrade
# 31 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 32 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, FuchsiaCity_SafariZone_Office_EventScript_NotRequestedMon
# 33 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	call EventScript_DoInGameTrade
# 34 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 35 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	setflag FLAG_DID_IRWIN_TRADE
# 36 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	release
# 37 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 38 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 39 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_AlreadyTraded::
# 40 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 41 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	release
# 42 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 43 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 44 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_DeclineTrade::
# 45 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 46 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	release
# 47 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
# 48 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"

# 49 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
FuchsiaCity_SafariZone_Office_EventScript_NotRequestedMon::
# 50 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 51 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 52 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	release
# 53 "data/maps/FuchsiaCity_SafariZone_Office/scripts.pory"
	end
