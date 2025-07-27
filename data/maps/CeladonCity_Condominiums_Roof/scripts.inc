# 1 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 2 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_MapScripts::
# 3 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	.byte 0
# 4 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 5 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_EventScript_Sign::
# 6 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox CeladonCity_Condominiums_Roof_Text_IKnowEverything, MSGBOX_SIGN
# 7 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	end
# 8 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 9 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_EventScript_Scotti::
# 10 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	lock
# 11 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	faceplayer
# 12 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_TREECKO
# 13 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 14 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	goto_if_set FLAG_DID_STU_TRADE, CeladonCity_Condominiums_Roof_EventScript_AlreadyTraded
# 15 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 16 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_Roof_EventScript_DeclineTrade
# 17 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 18 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, CeladonCity_Condominiums_Roof_EventScript_DeclineTrade
# 19 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 20 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, CeladonCity_Condominiums_Roof_EventScript_NotRequestedMon
# 21 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	call EventScript_DoInGameTrade
# 22 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 23 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	setflag FLAG_DID_STU_TRADE
# 24 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	release
# 25 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	end
# 26 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 27 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_EventScript_AlreadyTraded::
# 28 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 29 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	release
# 30 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	end
# 31 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 32 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_EventScript_DeclineTrade::
# 33 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 34 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	release
# 35 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	end
# 36 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"

# 37 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
CeladonCity_Condominiums_Roof_EventScript_NotRequestedMon::
# 38 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 39 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 40 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	release
# 41 "data/maps/CeladonCity_Condominiums_Roof/scripts.pory"
	end
