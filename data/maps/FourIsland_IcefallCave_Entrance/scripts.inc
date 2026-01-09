# 1 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 2 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_MapScripts::
# 3 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_IcefallCave_Entrance_OnTransition
# 4 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 6 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_OnTransition::
# 7 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE
# 8 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	end
# 9 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 10 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_EventScript_Wanda::
# 11 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	lock
# 12 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	faceplayer
# 13 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_CARNIVINE
# 14 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 15 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	goto_if_set FLAG_DID_CARNIVINE_TRADE, FourIsland_IcefallCave_Entrance_EventScript_AlreadyTraded
# 16 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	msgbox FourIsland_IcefallCave_Entrance_Text_DoYouHaveMonWantToTradeForMyMon, MSGBOX_YESNO
# 17 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FourIsland_IcefallCave_Entrance_EventScript_DeclineTrade
# 18 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 19 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, FourIsland_IcefallCave_Entrance_EventScript_DeclineTrade
# 20 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 21 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, FourIsland_IcefallCave_Entrance_EventScript_NotRequestedMon
# 22 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	call EventScript_DoInGameTrade
# 23 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	msgbox FourIsland_IcefallCave_Entrance_Text_ThankYou
# 24 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	setflag FLAG_DID_CARNIVINE_TRADE
# 25 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	release
# 26 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	end
# 27 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 28 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_EventScript_DeclineTrade::
# 29 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	msgbox FourIsland_IcefallCave_Entrance_Text_ThatsTooBad
# 30 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	release
# 31 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	end
# 32 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 33 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_EventScript_NotRequestedMon::
# 34 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 35 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	msgbox FourIsland_IcefallCave_Entrance_Text_ThisIsNoMon
# 36 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	release
# 37 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	end
# 38 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"

# 39 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
FourIsland_IcefallCave_Entrance_EventScript_AlreadyTraded::
# 40 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	msgbox FourIsland_IcefallCave_Entrance_Text_HowIsMyOldMon
# 41 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	release
# 42 "data/maps/FourIsland_IcefallCave_Entrance/scripts.pory"
	end
