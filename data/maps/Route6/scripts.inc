# 1 "data/maps/Route6/scripts.pory"

# 2 "data/maps/Route6/scripts.pory"
Route6_MapScripts::
# 3 "data/maps/Route6/scripts.pory"
	.byte 0
# 4 "data/maps/Route6/scripts.pory"

# 5 "data/maps/Route6/scripts.pory"
Route6_EventScript_UndergroundPathSign::
# 6 "data/maps/Route6/scripts.pory"
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
# 7 "data/maps/Route6/scripts.pory"
	end
# 8 "data/maps/Route6/scripts.pory"

# 9 "data/maps/Route6/scripts.pory"
Route6_EventScript_Julie::
# 10 "data/maps/Route6/scripts.pory"
	lock
# 11 "data/maps/Route6/scripts.pory"
	faceplayer
# 12 "data/maps/Route6/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_CHIKORITA
# 13 "data/maps/Route6/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 14 "data/maps/Route6/scripts.pory"
	goto_if_set FLAG_DID_LITLFOOT_TRADE, Route6_EventScript_AlreadyTraded
# 15 "data/maps/Route6/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 16 "data/maps/Route6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route6_EventScript_DeclineTrade
# 17 "data/maps/Route6/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 18 "data/maps/Route6/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route6_EventScript_DeclineTrade
# 19 "data/maps/Route6/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 20 "data/maps/Route6/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, Route6_EventScript_NotRequestedMon
# 21 "data/maps/Route6/scripts.pory"
	call EventScript_DoInGameTrade
# 22 "data/maps/Route6/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 23 "data/maps/Route6/scripts.pory"
	setflag FLAG_DID_LITLFOOT_TRADE
# 24 "data/maps/Route6/scripts.pory"
	release
# 25 "data/maps/Route6/scripts.pory"
	end
# 26 "data/maps/Route6/scripts.pory"

# 27 "data/maps/Route6/scripts.pory"
Route6_EventScript_AlreadyTraded::
# 28 "data/maps/Route6/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 29 "data/maps/Route6/scripts.pory"
	release
# 30 "data/maps/Route6/scripts.pory"
	end
# 31 "data/maps/Route6/scripts.pory"

# 32 "data/maps/Route6/scripts.pory"
Route6_EventScript_DeclineTrade::
# 33 "data/maps/Route6/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 34 "data/maps/Route6/scripts.pory"
	release
# 35 "data/maps/Route6/scripts.pory"
	end
# 36 "data/maps/Route6/scripts.pory"

# 37 "data/maps/Route6/scripts.pory"
Route6_EventScript_NotRequestedMon::
# 38 "data/maps/Route6/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 39 "data/maps/Route6/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 40 "data/maps/Route6/scripts.pory"
	release
# 41 "data/maps/Route6/scripts.pory"
	end
