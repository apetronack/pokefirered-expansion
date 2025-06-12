CritterCave_MapScripts::
	.byte 0


CritterCave_EventScript_MasterBugCatcher::
# 4 "data/maps/CritterCave/scripts.pory"
	trainerbattle_single TRAINER_MASTER_BUG_CATCHER, CritterCave_EventScript_MasterBugCatcher_Text_0, CritterCave_EventScript_MasterBugCatcher_Text_1, CritterCave_EventScript_DefeatedMasterBugCatcher, NO_MUSIC
# 8 "data/maps/CritterCave/scripts.pory"
	goto_if_unset FLAG_GOT_TM89, CritterCave_EventScript_MasterBugCatcher_2
CritterCave_EventScript_MasterBugCatcher_1:
# 17 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_MasterBugCatcher_Text_4
# 18 "data/maps/CritterCave/scripts.pory"
	release
	end

CritterCave_EventScript_MasterBugCatcher_2:
# 9 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_MasterBugCatcher_Text_2
# 10 "data/maps/CritterCave/scripts.pory"
	checkitemspace ITEM_TM89
# 11 "data/maps/CritterCave/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CritterCave_EventScript_MasterBugCatcher_4
	goto CritterCave_EventScript_MasterBugCatcher_1

CritterCave_EventScript_MasterBugCatcher_4:
# 12 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_MasterBugCatcher_Text_3
# 13 "data/maps/CritterCave/scripts.pory"
	release
	end


CritterCave_EventScript_DefeatedMasterBugCatcher::
# 23 "data/maps/CritterCave/scripts.pory"
	setflag FLAG_DEFEATED_MASTER_BUG_CATCHER
# 24 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_MasterBugCatcher_Text_2
# 25 "data/maps/CritterCave/scripts.pory"
	checkitemspace ITEM_TM89
# 26 "data/maps/CritterCave/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CritterCave_EventScript_DefeatedMasterBugCatcher_2
# 31 "data/maps/CritterCave/scripts.pory"
	giveitem_msg CritterCave_EventScript_DefeatedMasterBugCatcher_Text_0, ITEM_TM89
# 32 "data/maps/CritterCave/scripts.pory"
	setflag FLAG_GOT_TM89
# 33 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_DefeatedMasterBugCatcher_Text_1
# 34 "data/maps/CritterCave/scripts.pory"
	release
	end

CritterCave_EventScript_DefeatedMasterBugCatcher_2:
# 27 "data/maps/CritterCave/scripts.pory"
	msgbox CritterCave_EventScript_MasterBugCatcher_Text_3
# 28 "data/maps/CritterCave/scripts.pory"
	release
	end


CritterCave_EventScript_MasterBugCatcher_Text_0:
# 5 "data/maps/CritterCave/scripts.pory"
	.string "What are you doing here? This is my\n"
	.string "camp site! If you don't make a\l"
	.string "U-TURN and get out of here, I'll\l"
	.string "have to make you leave!$"

CritterCave_EventScript_MasterBugCatcher_Text_1:
# 6 "data/maps/CritterCave/scripts.pory"
	.string "Whoa, whoa! Take it easy! I'll back\n"
	.string "off. You can stay!$"

CritterCave_EventScript_MasterBugCatcher_Text_2:
# 9 "data/maps/CritterCave/scripts.pory"
	.string "I shouldn't have been so hasty!\n"
	.string "There's plenty of room around\l"
	.string "here for both of us. Take this as\l"
	.string "an apology!$"

CritterCave_EventScript_MasterBugCatcher_Text_3:
# 12 "data/maps/CritterCave/scripts.pory"
	.string "You should make room for this.$"

CritterCave_EventScript_MasterBugCatcher_Text_4:
# 17 "data/maps/CritterCave/scripts.pory"
	.string "Wow, you're pretty good! Most\n"
	.string "trainers can't keep up with my\l"
	.string "strategy. I bet you'll go far!$"

CritterCave_EventScript_DefeatedMasterBugCatcher_Text_0:
# 31 "data/maps/CritterCave/scripts.pory"
	.string "{PLAYER} received TM89 from the\n"
	.string "BUG CATCHER.$"

CritterCave_EventScript_DefeatedMasterBugCatcher_Text_1:
# 33 "data/maps/CritterCave/scripts.pory"
	.string "TM89 contains U-TURN. It lets your\n"
	.string "POKéMON do damage, then switch\l"
	.string "out in the same turn. It's a great\l"
	.string "way to get out of a sticky\l"
	.string "situation.$"
