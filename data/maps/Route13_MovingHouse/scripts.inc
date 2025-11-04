Route13_MovingHouse_MapScripts::
	.byte 0


Route13_MovingHouse_EventScript_ChoiceItem::
# 3 "data/maps/Route13_MovingHouse/scripts.pory"
	lock
# 4 "data/maps/Route13_MovingHouse/scripts.pory"
	faceplayer
# 5 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_2
# 21 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_SCARF_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_3
# 37 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_BAND_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_4
# 54 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_13
Route13_MovingHouse_EventScript_ChoiceItem_1:
# 56 "data/maps/Route13_MovingHouse/scripts.pory"
	release
	end

Route13_MovingHouse_EventScript_ChoiceItem_2:
# 6 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_0
# 7 "data/maps/Route13_MovingHouse/scripts.pory"
	waitmessage
	checkitem ITEM_FIRE_STONE
# 0 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MovingHouse_EventScript_ChoiceItem_9
# 19 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_4
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_3:
# 22 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_5
# 23 "data/maps/Route13_MovingHouse/scripts.pory"
	waitmessage
	checkitem ITEM_WATER_STONE
# 0 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MovingHouse_EventScript_ChoiceItem_12
# 35 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_8
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_4:
# 38 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_9
# 39 "data/maps/Route13_MovingHouse/scripts.pory"
	waitmessage
	checkitem ITEM_THUNDER_STONE
# 0 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MovingHouse_EventScript_ChoiceItem_15
# 51 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_12
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_9:
# 9 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_1, MSGBOX_YESNO
# 10 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_18
# 16 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_12:
# 25 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_6, MSGBOX_YESNO
# 26 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_21
# 32 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_15:
# 41 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_10, MSGBOX_YESNO
# 42 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_24
# 48 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_18:
# 11 "data/maps/Route13_MovingHouse/scripts.pory"
	setflag FLAG_CHOICE_SPECS_TRADE
# 12 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_FIRE_STONE, 1
# 13 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_SPECS, 1
# 14 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_2
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_21:
# 27 "data/maps/Route13_MovingHouse/scripts.pory"
	setflag FLAG_CHOICE_SCARF_TRADE
# 28 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_WATER_STONE, 1
# 29 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_SCARF, 1
# 30 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_7
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_24:
# 43 "data/maps/Route13_MovingHouse/scripts.pory"
	setflag FLAG_CHOICE_BAND_TRADE
# 44 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_THUNDER_STONE, 1
# 45 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_BAND, 1
# 46 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_11
	goto Route13_MovingHouse_EventScript_ChoiceItem_1


Route13_MovingHouse_EventScript_ChoiceItem_Text_0:
# 6 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I'm looking for a FIRE STONE. If\n"
	.string "you have one, I'll trade you some\l"
	.string "CHOICE SPECS for it.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_1:
# 9 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Do you want to trade your FIRE\n"
	.string "STONE for my CHOICE SPECS?$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_2:
# 14 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "SPECS.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_3:
# 16 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Oh, I see. Maybe another time then.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_4:
# 19 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a FIRE STONE.\n"
	.string "Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_5:
# 22 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I'm looking for a WATER STONE. If\n"
	.string "you have one, I'll trade you some\l"
	.string "CHOICE SCARF for it.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_6:
# 25 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Do you want to trade your WATER\n"
	.string "STONE for my CHOICE SCARF?$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_7:
# 30 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "SCARF.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_8:
# 35 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a WATER\n"
	.string "STONE. Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_9:
# 38 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I'm looking for a THUNDER STONE. If\n"
	.string "you have one, I'll trade you some\l"
	.string "CHOICE BAND for it.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_10:
# 41 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Do you want to trade your THUNDER\n"
	.string "STONE for my CHOICE BAND?$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_11:
# 46 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "BAND.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_12:
# 51 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a THUNDER\n"
	.string "STONE. Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_13:
# 54 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thanks for trading with me!$"
