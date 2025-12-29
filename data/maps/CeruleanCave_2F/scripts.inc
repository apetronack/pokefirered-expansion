CeruleanCave_2F_MapScripts::
	.byte 0


CeruleanCave_2F_EventScript_MysticGuardian::
# 4 "data/maps/CeruleanCave_2F/scripts.pory"
	trainerbattle_single TRAINER_MYSTIC_GUARDIAN, CeruleanCave_2F_EventScript_MysticGuardian_Text_0, CeruleanCave_2F_EventScript_MysticGuardian_Text_1, CeruleanCave_2F_EventScript_DefeatedMysticGuardian, NO_MUSIC
# 8 "data/maps/CeruleanCave_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, CeruleanCave_2F_EventScript_MysticGuardian_2
CeruleanCave_2F_EventScript_MysticGuardian_1:
# 20 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_6
# 21 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end

CeruleanCave_2F_EventScript_MysticGuardian_2:
# 9 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_2
# 10 "data/maps/CeruleanCave_2F/scripts.pory"
	checkitemspace ITEM_MYSTIC_TICKET
# 11 "data/maps/CeruleanCave_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CeruleanCave_2F_EventScript_MysticGuardian_5
# 16 "data/maps/CeruleanCave_2F/scripts.pory"
	giveitem_msg CeruleanCave_2F_EventScript_MysticGuardian_Text_4, ITEM_MYSTIC_TICKET
# 17 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 18 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_5
	goto CeruleanCave_2F_EventScript_MysticGuardian_1

CeruleanCave_2F_EventScript_MysticGuardian_5:
# 12 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_3
# 13 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end


CeruleanCave_2F_EventScript_DefeatedMysticGuardian::
# 26 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_BEAT_MYSTIC_GUARDIAN
# 27 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 28 "data/maps/CeruleanCave_2F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MYSTIC_TICKET, CeruleanCave_2F_EventScript_DefeatedMysticGuardian_2
CeruleanCave_2F_EventScript_DefeatedMysticGuardian_1:
# 40 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end

CeruleanCave_2F_EventScript_DefeatedMysticGuardian_2:
# 29 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_2
# 30 "data/maps/CeruleanCave_2F/scripts.pory"
	checkitemspace ITEM_MYSTIC_TICKET
# 31 "data/maps/CeruleanCave_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CeruleanCave_2F_EventScript_DefeatedMysticGuardian_5
# 36 "data/maps/CeruleanCave_2F/scripts.pory"
	giveitem_msg CeruleanCave_2F_EventScript_MysticGuardian_Text_4, ITEM_MYSTIC_TICKET
# 37 "data/maps/CeruleanCave_2F/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 38 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_5
	goto CeruleanCave_2F_EventScript_DefeatedMysticGuardian_1

CeruleanCave_2F_EventScript_DefeatedMysticGuardian_5:
# 32 "data/maps/CeruleanCave_2F/scripts.pory"
	msgbox CeruleanCave_2F_EventScript_MysticGuardian_Text_3
# 33 "data/maps/CeruleanCave_2F/scripts.pory"
	release
	end


CeruleanCave_2F_EventScript_MysticGuardian_Text_0:
# 5 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "...$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_1:
# 6 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Superb, it should be said.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_2:
# 9 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "You have demonstrated immense skill.\n"
	.string "This is your well-earned reward.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_3:
# 12 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "You should make room for this.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_4:
# 16 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "{PLAYER} received a MYSTIC\n"
	.string "TICKET from the MYSTIC GUARDIAN.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_5:
# 18 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Travel to Vermilion City and present\n"
	.string "this ticket to the dockmaster. He\l"
	.string "will take you to a special place\l"
	.string "only a select few are worthy of\l"
	.string "visiting.$"

CeruleanCave_2F_EventScript_MysticGuardian_Text_6:
# 20 "data/maps/CeruleanCave_2F/scripts.pory"
	.string "Safe travels, skilled one.$"
