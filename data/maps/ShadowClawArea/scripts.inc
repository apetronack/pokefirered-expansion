ShadowClawArea_MapScripts::
	.byte 0


ShadowClawArea_EventScript_MasterChanneler::
# 4 "data/maps/ShadowClawArea/scripts.pory"
	trainerbattle_single TRAINER_MASTER_CHANNELER, ShadowClawArea_EventScript_MasterChanneler_Text_0, ShadowClawArea_EventScript_MasterChanneler_Text_1, ShadowClawArea_EventScript_DefeatedMasterChanneler, NO_MUSIC
# 8 "data/maps/ShadowClawArea/scripts.pory"
	goto_if_unset FLAG_GOT_TM65, ShadowClawArea_EventScript_MasterChanneler_2
ShadowClawArea_EventScript_MasterChanneler_1:
# 17 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_MasterChanneler_Text_4
# 18 "data/maps/ShadowClawArea/scripts.pory"
	release
	end

ShadowClawArea_EventScript_MasterChanneler_2:
# 9 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_MasterChanneler_Text_2
# 10 "data/maps/ShadowClawArea/scripts.pory"
	checkitemspace ITEM_TM65
# 11 "data/maps/ShadowClawArea/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadowClawArea_EventScript_MasterChanneler_4
	goto ShadowClawArea_EventScript_MasterChanneler_1

ShadowClawArea_EventScript_MasterChanneler_4:
# 12 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_MasterChanneler_Text_3
# 13 "data/maps/ShadowClawArea/scripts.pory"
	release
	end


ShadowClawArea_EventScript_DefeatedMasterChanneler::
# 23 "data/maps/ShadowClawArea/scripts.pory"
	setflag FLAG_DEFEATED_MASTER_CHANNELER
# 24 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_MasterChanneler_Text_2
# 25 "data/maps/ShadowClawArea/scripts.pory"
	checkitemspace ITEM_TM65
# 26 "data/maps/ShadowClawArea/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadowClawArea_EventScript_DefeatedMasterChanneler_2
# 31 "data/maps/ShadowClawArea/scripts.pory"
	giveitem_msg ShadowClawArea_EventScript_DefeatedMasterChanneler_Text_0, ITEM_TM65
# 32 "data/maps/ShadowClawArea/scripts.pory"
	setflag FLAG_GOT_TM65
# 33 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_DefeatedMasterChanneler_Text_1
# 34 "data/maps/ShadowClawArea/scripts.pory"
	release
	end

ShadowClawArea_EventScript_DefeatedMasterChanneler_2:
# 27 "data/maps/ShadowClawArea/scripts.pory"
	msgbox ShadowClawArea_EventScript_MasterChanneler_Text_3
# 28 "data/maps/ShadowClawArea/scripts.pory"
	release
	end


ShadowClawArea_EventScript_MasterChanneler_Text_0:
# 5 "data/maps/ShadowClawArea/scripts.pory"
	.string "I have foreseen your arrival. Prove\n"
	.string "your worth, and you will be\l"
	.string "rewarded...$"

ShadowClawArea_EventScript_MasterChanneler_Text_1:
# 6 "data/maps/ShadowClawArea/scripts.pory"
	.string "As I had divined, your ferocity is\n"
	.string "unmatched!$"

ShadowClawArea_EventScript_MasterChanneler_Text_2:
# 9 "data/maps/ShadowClawArea/scripts.pory"
	.string "Here is your reward, as promised. I\n"
	.string "have foreseen that you will find\l"
	.string "it useful!$"

ShadowClawArea_EventScript_MasterChanneler_Text_3:
# 12 "data/maps/ShadowClawArea/scripts.pory"
	.string "You should make room for this.$"

ShadowClawArea_EventScript_MasterChanneler_Text_4:
# 17 "data/maps/ShadowClawArea/scripts.pory"
	.string "Continue to train your POKéMON, and\n"
	.string "you will become even stronger. I\l"
	.string "have had a vision of your\l"
	.string "impending dominance over all.$"

ShadowClawArea_EventScript_DefeatedMasterChanneler_Text_0:
# 31 "data/maps/ShadowClawArea/scripts.pory"
	.string "{PLAYER} received TM65 from the\n"
	.string "CHANNELER.$"

ShadowClawArea_EventScript_DefeatedMasterChanneler_Text_1:
# 33 "data/maps/ShadowClawArea/scripts.pory"
	.string "TM65 contains SHADOW CLAW. It is a\n"
	.string "powerful Ghost-type move with a\l"
	.string "high critical hit ratio.$"
