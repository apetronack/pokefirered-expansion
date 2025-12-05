# 1 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_MapScripts::
# 3 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_PokemonCenter_1F_OnTransition
# 4 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	.byte 0
# 6 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 7 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_OnTransition::
# 8 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	setrespawn SPAWN_FIVE_ISLAND
# 9 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 10 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 11 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_Nurse::
# 12 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	lock
# 13 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 14 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_PkmnCenterNurse
# 15 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	release
# 16 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 17 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 18 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_Chef::
# 19 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_OnMyWayToPrepareMeal, MSGBOX_NPC
# 20 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_CooltrainerF::
# 23 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_YoureOnQuestToCatchEveryMon, MSGBOX_NPC
# 24 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 25 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 26 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_Lilly::
# 27 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	lock
# 28 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	faceplayer
# 29 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_SEVIPER
# 30 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpeciesInfo
# 31 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_DID_SEVIPER_TRADE, FiveIsland_PokemonCenter_1F_EventScript_AlreadyTraded
# 32 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_DoYouHaveMonWantToTradeForMyMon, MSGBOX_YESNO
# 33 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FiveIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 34 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_ChooseMonForInGameTrade
# 35 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, FiveIsland_PokemonCenter_1F_EventScript_DeclineTrade
# 36 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_GetInGameTradeSpecies
# 37 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	goto_if_ne VAR_RESULT, VAR_0x8009, FiveIsland_PokemonCenter_1F_EventScript_NotRequestedMon
# 38 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	call EventScript_DoInGameTrade
# 39 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_ThankYou
# 40 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	setflag FLAG_DID_SEVIPER_TRADE
# 41 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	release
# 42 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 43 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 44 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_DeclineTrade::
# 45 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_ThatsTooBad
# 46 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	release
# 47 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 48 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_NotRequestedMon::
# 50 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 51 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_ThisIsNoMon
# 52 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	release
# 53 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
# 54 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"

# 55 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
FiveIsland_PokemonCenter_1F_EventScript_AlreadyTraded::
# 56 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	msgbox FiveIsland_PokemonCenter_1F_Text_HowIsMyOldMon
# 57 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	release
# 58 "data/maps/FiveIsland_PokemonCenter_1F/scripts.pory"
	end
