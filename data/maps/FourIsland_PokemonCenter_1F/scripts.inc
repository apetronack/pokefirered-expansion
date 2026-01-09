# 1 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_MapScripts::
# 3 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
# 4 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_OnTransition::
# 8 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	setrespawn SPAWN_FOUR_ISLAND
# 9 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	lock
# 13 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 14 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_PkmnCenterNurse
# 15 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	release
# 16 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 17 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 18 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_Man::
# 19 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
# 20 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_Woman::
# 23 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
# 24 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_Gentleman::
# 27 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
# 28 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 29 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 30 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_Darius::
# 31 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	lock
# 32 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 33 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_ZANGOOSE
# 34 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 35 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_DID_ZANGOOSE_TRADE, FourIsland_PokemonCenter_1F_EventScript_AlreadyTraded
# 36 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_DoYouHaveMonWantToTradeForMyMon, MSGBOX_YESNO
# 37 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FourIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 38 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 39 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, FourIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 40 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 41 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, FourIsland_PokemonCenter_1F_EventScript_NotRequestedMon
# 42 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_DoInGameTrade
# 43 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_ThankYou
# 44 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	setflag FLAG_DID_ZANGOOSE_TRADE
# 45 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	release
# 46 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 47 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 48 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_DeclineTrade::
# 49 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_ThatsTooBad
# 50 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	release
# 51 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 52 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_NotRequestedMon::
# 54 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 55 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_ThisIsNoMon
# 56 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	release
# 57 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
# 58 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
FourIsland_PokemonCenter_1F_EventScript_AlreadyTraded::
# 60 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	msgbox FourIsland_PokemonCenter_1F_Text_HowIsMyOldMon
# 61 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	release
# 62 "data/maps/FourIsland_PokemonCenter_1F/scripts.pory"
	end
