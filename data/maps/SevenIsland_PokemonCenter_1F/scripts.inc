# 1 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_MapScripts::
# 3 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_PokemonCenter_1F_OnTransition
# 4 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_OnTransition::
# 8 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	setrespawn SPAWN_SEVEN_ISLAND
# 9 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	lock
# 13 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 14 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_PkmnCenterNurse
# 15 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	release
# 16 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 17 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 18 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_OldMan::
# 19 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections, MSGBOX_NPC
# 20 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_Sailor::
# 23 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere, MSGBOX_NPC
# 24 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_Beauty::
# 27 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower, MSGBOX_NPC
# 28 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_BRANDON::
# 31 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	lock
# 32 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 33 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_PINSIR
# 34 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 35 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_DID_PINSIR_TRADE, SevenIsland_PokemonCenter_1F_EventScript_AlreadyTraded
# 36 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_DoYouHaveMonWantToTradeForMyMon, MSGBOX_YESNO
# 37 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SevenIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 38 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 39 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, SevenIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 40 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 41 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, SevenIsland_PokemonCenter_1F_EventScript_NotRequestedMon
# 42 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_DoInGameTrade
# 43 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_ThankYou
# 44 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	setflag FLAG_DID_PINSIR_TRADE
# 45 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	release
# 46 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 47 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 48 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_DeclineTrade::
# 49 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_ThatsTooBad
# 50 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	release
# 51 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 52 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_NotRequestedMon::
# 54 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 55 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_ThisIsNoMon
# 56 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	release
# 57 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
# 58 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
SevenIsland_PokemonCenter_1F_EventScript_AlreadyTraded::
# 60 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	msgbox SevenIsland_PokemonCenter_1F_Text_HowIsMyOldMon
# 61 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	release
# 62 "data/maps/SevenIsland_PokemonCenter_1F/scripts.pory"
	end
