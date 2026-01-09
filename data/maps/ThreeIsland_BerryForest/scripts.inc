# 1 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 2 "data/maps/ThreeIsland_BerryForest/scripts.pory"
.set LOCALID_LOSTELLE, 1
# 3 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 4 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_MapScripts::
# 5 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
# 6 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	.byte 0
# 7 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 8 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_OnTransition::
# 9 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
# 10 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
# 11 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 12 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 13 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_Lostelle::
# 14 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	lock
# 15 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	faceplayer
# 16 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
# 17 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playse SE_PIN
# 18 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_LOSTELLE, Common_Movement_ExclamationMark
# 19 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 20 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
# 21 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 22 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
# 23 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 24 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitse
# 25 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
# 26 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmoncry
# 27 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setwildbattle SPECIES_HYPNO, 60
# 28 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	dowildbattle
# 29 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special QuestLog_CutRecording
# 30 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	applymovement LOCALID_LOSTELLE, Common_Movement_FacePlayer
# 31 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmovement 0
# 32 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
# 33 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 34 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
# 35 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special BufferBigGuyOrBigGirlString
# 36 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
# 37 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	closemessage
# 38 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_RESCUED_LOSTELLE
# 39 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
# 40 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
# 41 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
# 42 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
# 43 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitstate
# 44 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 45 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 46 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 47 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
# 48 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
# 49 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	return
# 50 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 51 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_Movement_LostelleLookAround::
# 52 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_left
# 53 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay_16
# 54 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_right
# 55 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay_8
# 56 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	walk_in_place_faster_left
# 57 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	step_end
# 58 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 59 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_WelcomeSign::
# 60 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
# 61 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 62 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 63 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_BewareSign::
# 64 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
# 65 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 66 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 67 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_CelebiShrine::
# 68 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 69 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special QuestLog_CutRecording
# 70 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	lock
# 71 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	faceplayer
# 72 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_unset FLAG_DEFEATED_CHAMP_1X, ThreeIsland_BerryForest_EventScript_ShrineBeforeChampion
# 73 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_set FLAG_FOUGHT_CELEBI, ThreeIsland_BerryForest_EventScript_ShrineAfterBattle
# 74 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ShrineGlowsMysteriously
# 75 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitse
# 76 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 77 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitfanfare
# 78 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ForestGuardianEmerges
# 79 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	closemessage
# 80 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay 20
# 81 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setwildbattle SPECIES_CELEBI, 50
# 82 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 83 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	message ThreeIsland_BerryForest_Text_CelebiCry
# 84 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmessage
# 85 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitmoncry
# 86 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	delay 20
# 87 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	playbgm MUS_VS_LEGEND, 0
# 88 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitbuttonpress
# 89 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 90 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	special StartLegendaryBattle
# 91 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	waitstate
# 92 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 93 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 94 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ThreeIsland_BerryForest_EventScript_DefeatedCelebi
# 95 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ThreeIsland_BerryForest_EventScript_RanFromCelebi
# 96 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ThreeIsland_BerryForest_EventScript_RanFromCelebi
# 97 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, ThreeIsland_BerryForest_EventScript_CaughtCelebi
# 98 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_FOUGHT_CELEBI
# 99 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 100 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 101 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 102 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_ShrineBeforeChampion::
# 103 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ShrineAwaitsPower
# 104 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 105 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 106 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 107 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_DefeatedCelebi::
# 108 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_FOUGHT_CELEBI
# 109 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_CelebiVanishesThroughTime
# 110 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 111 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 112 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 113 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_CaughtCelebi::
# 114 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setflag FLAG_FOUGHT_CELEBI
# 115 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_CelebiJoinsYou
# 116 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 117 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 118 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 119 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_RanFromCelebi::
# 120 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	setvar VAR_0x8004, SPECIES_CELEBI
# 121 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_CelebiDisappears
# 122 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 123 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
# 124 "data/maps/ThreeIsland_BerryForest/scripts.pory"

# 125 "data/maps/ThreeIsland_BerryForest/scripts.pory"
ThreeIsland_BerryForest_EventScript_ShrineAfterBattle::
# 126 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	msgbox ThreeIsland_BerryForest_Text_ShrineQuietNow
# 127 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	release
# 128 "data/maps/ThreeIsland_BerryForest/scripts.pory"
	end
