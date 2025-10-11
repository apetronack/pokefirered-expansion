# 1 "data/maps/SixIsland_AlteringCave/scripts.pory"

# 2 "data/maps/SixIsland_AlteringCave/scripts.pory"
SixIsland_AlteringCave_MapScripts::
# 3 "data/maps/SixIsland_AlteringCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
# 4 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.byte 0
# 5 "data/maps/SixIsland_AlteringCave/scripts.pory"

# 6 "data/maps/SixIsland_AlteringCave/scripts.pory"
SixIsland_AlteringCave_OnTransition::
# 7 "data/maps/SixIsland_AlteringCave/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
# 8 "data/maps/SixIsland_AlteringCave/scripts.pory"
	end

SixIsland_AlteringCave_EventScript_AuroraGuardian::
# 11 "data/maps/SixIsland_AlteringCave/scripts.pory"
	trainerbattle_single TRAINER_AURORA_GUARDIAN, SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_0, SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_1, SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian, NO_MUSIC
# 15 "data/maps/SixIsland_AlteringCave/scripts.pory"
	goto_if_unset FLAG_RECEIVED_AURORA_TICKET, SixIsland_AlteringCave_EventScript_AuroraGuardian_2
SixIsland_AlteringCave_EventScript_AuroraGuardian_1:
# 25 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_4
# 26 "data/maps/SixIsland_AlteringCave/scripts.pory"
	release
	end

SixIsland_AlteringCave_EventScript_AuroraGuardian_2:
# 16 "data/maps/SixIsland_AlteringCave/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 17 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_2
# 18 "data/maps/SixIsland_AlteringCave/scripts.pory"
	checkitemspace ITEM_AURORA_TICKET
# 19 "data/maps/SixIsland_AlteringCave/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SixIsland_AlteringCave_EventScript_AuroraGuardian_4
	goto SixIsland_AlteringCave_EventScript_AuroraGuardian_1

SixIsland_AlteringCave_EventScript_AuroraGuardian_4:
# 20 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_3
# 21 "data/maps/SixIsland_AlteringCave/scripts.pory"
	release
	end


SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian::
# 31 "data/maps/SixIsland_AlteringCave/scripts.pory"
	setflag FLAG_BEAT_AURORA_GUARDIAN
# 32 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_2
# 33 "data/maps/SixIsland_AlteringCave/scripts.pory"
	checkitemspace ITEM_AURORA_TICKET
# 34 "data/maps/SixIsland_AlteringCave/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_2
# 39 "data/maps/SixIsland_AlteringCave/scripts.pory"
	giveitem_msg SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_Text_0, ITEM_AURORA_TICKET
# 40 "data/maps/SixIsland_AlteringCave/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 41 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_Text_1
# 42 "data/maps/SixIsland_AlteringCave/scripts.pory"
	release
	end

SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_2:
# 35 "data/maps/SixIsland_AlteringCave/scripts.pory"
	msgbox SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_3
# 36 "data/maps/SixIsland_AlteringCave/scripts.pory"
	release
	end


SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_0:
# 12 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "...$"

SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_1:
# 13 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "Superb, it should be said.$"

SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_2:
# 17 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "You have demonstrated immense skill.\n"
	.string "This is your well-earned reward.$"

SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_3:
# 20 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "You should make room for this.$"

SixIsland_AlteringCave_EventScript_AuroraGuardian_Text_4:
# 25 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "Safe travels, skilled one.$"

SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_Text_0:
# 39 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "{PLAYER} received an AURORA\n"
	.string "TICKET from the AURORA GUARDIAN.$"

SixIsland_AlteringCave_EventScript_DefeatedAuroraGuardian_Text_1:
# 41 "data/maps/SixIsland_AlteringCave/scripts.pory"
	.string "Travel to Vermillion City and\n"
	.string "present this ticket to the\l"
	.string "dockmaster. He will take you to a\l"
	.string "special place only a select few\l"
	.string "are worthy of visiting.$"
