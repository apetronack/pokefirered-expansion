# 1 "data/maps/LavenderTown_House1/scripts.pory"

# 2 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_MapScripts::
# 3 "data/maps/LavenderTown_House1/scripts.pory"
	.byte 0
# 4 "data/maps/LavenderTown_House1/scripts.pory"

# 5 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_CooltrainerF::
# 6 "data/maps/LavenderTown_House1/scripts.pory"
	lock
# 7 "data/maps/LavenderTown_House1/scripts.pory"
	faceplayer
# 8 "data/maps/LavenderTown_House1/scripts.pory"
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
# 9 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
# 10 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 11 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 12 "data/maps/LavenderTown_House1/scripts.pory"

# 13 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_CooltrainerFGhostGone::
# 14 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
# 15 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 16 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 17 "data/maps/LavenderTown_House1/scripts.pory"

# 18 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_Cubone::
# 19 "data/maps/LavenderTown_House1/scripts.pory"
	lock
# 20 "data/maps/LavenderTown_House1/scripts.pory"
	faceplayer
# 21 "data/maps/LavenderTown_House1/scripts.pory"
	waitse
# 22 "data/maps/LavenderTown_House1/scripts.pory"
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
# 23 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox LavenderTown_House1_Text_Cubone
# 24 "data/maps/LavenderTown_House1/scripts.pory"
	waitmoncry
# 25 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 26 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 27 "data/maps/LavenderTown_House1/scripts.pory"

# 28 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_Jessica::
# 29 "data/maps/LavenderTown_House1/scripts.pory"
	lock
# 30 "data/maps/LavenderTown_House1/scripts.pory"
	faceplayer
# 31 "data/maps/LavenderTown_House1/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_MUDKIP
# 32 "data/maps/LavenderTown_House1/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 33 "data/maps/LavenderTown_House1/scripts.pory"
	goto_if_set FLAG_DID_TOADETTE_TRADE, LavenderTown_House1_EventScript_AlreadyTraded
# 34 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
# 35 "data/maps/LavenderTown_House1/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavenderTown_House1_EventScript_DeclineTrade
# 36 "data/maps/LavenderTown_House1/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 37 "data/maps/LavenderTown_House1/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House1_EventScript_DeclineTrade
# 38 "data/maps/LavenderTown_House1/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 39 "data/maps/LavenderTown_House1/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, LavenderTown_House1_EventScript_NotRequestedMon
# 40 "data/maps/LavenderTown_House1/scripts.pory"
	call EventScript_DoInGameTrade
# 41 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox Trade_Text_HeyThanks
# 42 "data/maps/LavenderTown_House1/scripts.pory"
	setflag FLAG_DID_TOADETTE_TRADE
# 43 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 44 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 45 "data/maps/LavenderTown_House1/scripts.pory"

# 46 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_AlreadyTraded::
# 47 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 48 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 49 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 50 "data/maps/LavenderTown_House1/scripts.pory"

# 51 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_DeclineTrade::
# 52 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 53 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 54 "data/maps/LavenderTown_House1/scripts.pory"
	end
# 55 "data/maps/LavenderTown_House1/scripts.pory"

# 56 "data/maps/LavenderTown_House1/scripts.pory"
LavenderTown_House1_EventScript_NotRequestedMon::
# 57 "data/maps/LavenderTown_House1/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 58 "data/maps/LavenderTown_House1/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 59 "data/maps/LavenderTown_House1/scripts.pory"
	release
# 60 "data/maps/LavenderTown_House1/scripts.pory"
	end
