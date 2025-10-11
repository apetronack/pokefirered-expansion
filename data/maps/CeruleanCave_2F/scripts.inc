CeruleanCave_2F_MapScripts::
	.byte 0


CeruleanCave_2F_EventScript_MysticGuardian::
# 4 "data/maps/CeruleanCave_2F/scripts.pory"
	trainerbattle_single TRAINER_MYSTIC_GUARDIAN, CeruleanCave_2F_EventScript_MysticGuardian_Text_0, CeruleanCave_2F_EventScript_MysticGuardian_Text_1, CeruleanCave_2F_EventScript_DefeatedMysticGuardian, NO_MUSIC
# 8 "data/maps/CeruleanCave_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, CeruleanCave_2F_EventScript_MysticGuardian_2
CeruleanCave_2F_EventScript_MysticGuardian_1:
# 18 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_4
# 19 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end

CeruleanCave_2F_EventScript_MysticGuardian_2:
# 9 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 10 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_2
# 11 "data/maps/CeruleanCave_2F/scripts.pory"
	checkitemspace ITEM_MYSTIC_TICKET
# 12 "data/maps/CeruleanCave_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CeruleanCave_2F_EventScript_MysticGuardian_4
	goto CeruleanCave_2F_EventScript_MysticGuardian_1

CeruleanCave_2F_EventScript_MysticGuardian_4:
# 13 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_3
# 14 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end


CeruleanCave_2F_EventScript_DefeatedMysticGuardian::
# 24 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_BEAT_MYSTIC_GUARDIAN
# 25 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_2
# 26 "data/maps/CeruleanCave_2F/scripts.pory"
	checkitemspace ITEM_MYSTIC_TICKET
# 27 "data/maps/CeruleanCave_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CeruleanCave_2F_EventScript_DefeatedMysticGuardian_2
# 32 "data/maps/CeruleanCave_2F/scripts.pory"
	giveitem_msg CeruleanCave_2F_EventScript_DefeatedMysticGuardian_Text_0, ITEM_MYSTIC_TICKET
# 33 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 34 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_DefeatedMysticGuardian_Text_1
# 35 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end

CeruleanCave_2F_EventScript_DefeatedMysticGuardian_2:
# 28 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_3
# 29 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end


CeruleanCave_2F_EventScript_MysticGuardian_Text_0:
# 5 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "...$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_1:
# 6 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Superb, it should be said.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_2:
# 10 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "You have demonstrated immense skill.\n"
	.string "This is your well-earned reward.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_3:
# 13 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "You should make room for this.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_4:
# 18 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Safe travels, skilled one.$"

CeruleanCave_2F_EventScript_DefeatedMysticGuardian_Text_0:
# 32 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "{PLAYER} received a MYSTIC\n"
	.string "TICKET from the MYSTIC GUARDIAN.$"

CeruleanCave_2F_EventScript_DefeatedMysticGuardian_Text_1:
# 34 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Travel to Vermillion City and\n"
	.string "present this ticket to the\l"
	.string "dockmaster. He will take you to a\l"
	.string "special place only a select few\l"
	.string "are worthy of visiting.$"
