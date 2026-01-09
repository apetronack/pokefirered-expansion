# 1 "data/maps/RockTunnel_1F/scripts.pory"

# 2 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_MapScripts::
# 3 "data/maps/RockTunnel_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, RockTunnel_1F_OnResume
# 4 "data/maps/RockTunnel_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
# 5 "data/maps/RockTunnel_1F/scripts.pory"
	.byte 0
# 6 "data/maps/RockTunnel_1F/scripts.pory"

# 7 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_OnResume::
# 8 "data/maps/RockTunnel_1F/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, RockTunnel_1F_EventScript_TryRemoveStaticMon
# 9 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 10 "data/maps/RockTunnel_1F/scripts.pory"

# 11 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_TryRemoveStaticMon::
# 12 "data/maps/RockTunnel_1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 14 "data/maps/RockTunnel_1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/RockTunnel_1F/scripts.pory"
	return
# 16 "data/maps/RockTunnel_1F/scripts.pory"

# 17 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_OnTransition::
# 18 "data/maps/RockTunnel_1F/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
# 19 "data/maps/RockTunnel_1F/scripts.pory"
	call_if_unset FLAG_FOUGHT_TURTWIG, RockTunnel_1F_EventScript_ShowTurtwig
# 20 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 21 "data/maps/RockTunnel_1F/scripts.pory"

# 22 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_ShowTurtwig::
# 23 "data/maps/RockTunnel_1F/scripts.pory"
	clearflag FLAG_HIDE_TURTWIG
# 24 "data/maps/RockTunnel_1F/scripts.pory"
	return
# 25 "data/maps/RockTunnel_1F/scripts.pory"

# 26 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Turtwig::
# 27 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 28 "data/maps/RockTunnel_1F/scripts.pory"
	lock
# 29 "data/maps/RockTunnel_1F/scripts.pory"
	faceplayer
# 30 "data/maps/RockTunnel_1F/scripts.pory"
	setwildbattle SPECIES_TURTWIG, 15
# 31 "data/maps/RockTunnel_1F/scripts.pory"
	waitse
# 32 "data/maps/RockTunnel_1F/scripts.pory"
	playmoncry SPECIES_TURTWIG, CRY_MODE_ENCOUNTER
# 33 "data/maps/RockTunnel_1F/scripts.pory"
	waitmoncry
# 34 "data/maps/RockTunnel_1F/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 35 "data/maps/RockTunnel_1F/scripts.pory"
	dowildbattle
# 36 "data/maps/RockTunnel_1F/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 37 "data/maps/RockTunnel_1F/scripts.pory"
	special QuestLog_CutRecording
# 38 "data/maps/RockTunnel_1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RockTunnel_1F_EventScript_FoughtTurtwig
# 40 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RockTunnel_1F_EventScript_FoughtTurtwig
# 41 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RockTunnel_1F_EventScript_FoughtTurtwig
# 42 "data/maps/RockTunnel_1F/scripts.pory"
	setflag FLAG_FOUGHT_TURTWIG
# 43 "data/maps/RockTunnel_1F/scripts.pory"
	release
# 44 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 45 "data/maps/RockTunnel_1F/scripts.pory"

# 46 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_FoughtTurtwig::
# 47 "data/maps/RockTunnel_1F/scripts.pory"
	setflag FLAG_FOUGHT_TURTWIG
# 48 "data/maps/RockTunnel_1F/scripts.pory"
	goto EventScript_RemoveStaticMon
# 49 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 50 "data/maps/RockTunnel_1F/scripts.pory"

# 51 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_RouteSign::
# 52 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
# 53 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 54 "data/maps/RockTunnel_1F/scripts.pory"

# 55 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Lenny::
# 56 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
# 57 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
# 58 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 59 "data/maps/RockTunnel_1F/scripts.pory"

# 60 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Oliver::
# 61 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
# 62 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
# 63 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 64 "data/maps/RockTunnel_1F/scripts.pory"

# 65 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Lucas::
# 66 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
# 67 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 69 "data/maps/RockTunnel_1F/scripts.pory"

# 70 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Ashton::
# 71 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
# 72 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 74 "data/maps/RockTunnel_1F/scripts.pory"

# 75 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Leah::
# 76 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
# 77 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 79 "data/maps/RockTunnel_1F/scripts.pory"

# 80 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Ariana::
# 81 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
# 82 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
# 83 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 84 "data/maps/RockTunnel_1F/scripts.pory"

# 85 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_Dana::
# 86 "data/maps/RockTunnel_1F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat, RockTunnel_1F_EventScript_DanaDefeated
# 87 "data/maps/RockTunnel_1F/scripts.pory"
	goto_if_defeated TRAINER_PICNICKER_DANA, RockTunnel_1F_EventScript_DanaHealPlayer
# 88 "data/maps/RockTunnel_1F/scripts.pory"
	release
# 89 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 90 "data/maps/RockTunnel_1F/scripts.pory"

# 91 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_DanaDefeated::
# 92 "data/maps/RockTunnel_1F/scripts.pory"
	special HealPlayerParty
# 93 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
# 94 "data/maps/RockTunnel_1F/scripts.pory"
	release
# 95 "data/maps/RockTunnel_1F/scripts.pory"
	end
# 96 "data/maps/RockTunnel_1F/scripts.pory"

# 97 "data/maps/RockTunnel_1F/scripts.pory"
RockTunnel_1F_EventScript_DanaHealPlayer::
# 98 "data/maps/RockTunnel_1F/scripts.pory"
	special HealPlayerParty
# 99 "data/maps/RockTunnel_1F/scripts.pory"
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/RockTunnel_1F/scripts.pory"
	release
# 101 "data/maps/RockTunnel_1F/scripts.pory"
	end
