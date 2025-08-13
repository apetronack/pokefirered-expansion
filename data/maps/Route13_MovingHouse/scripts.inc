Route13_MovingHouse_MapScripts::
	.byte 0


Route13_MovingHouse_EventScript_ChoiceItem::
# 3 "data/maps/Route13_MovingHouse/scripts.pory"
	lock
# 4 "data/maps/Route13_MovingHouse/scripts.pory"
	faceplayer
# 5 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_SPECS_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_2
# 20 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_SCARF_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_3
# 35 "data/maps/Route13_MovingHouse/scripts.pory"
	goto_if_unset FLAG_CHOICE_BAND_TRADE, Route13_MovingHouse_EventScript_ChoiceItem_4
# 51 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_13
Route13_MovingHouse_EventScript_ChoiceItem_1:
# 53 "data/maps/Route13_MovingHouse/scripts.pory"
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
# 18 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_4
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_3:
# 21 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_5
# 22 "data/maps/Route13_MovingHouse/scripts.pory"
	waitmessage
	checkitem ITEM_WATER_STONE
# 0 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MovingHouse_EventScript_ChoiceItem_12
# 33 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_8
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_4:
# 36 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_9
# 37 "data/maps/Route13_MovingHouse/scripts.pory"
	waitmessage
	checkitem ITEM_THUNDER_STONE
# 0 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MovingHouse_EventScript_ChoiceItem_15
# 48 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_12
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_9:
# 9 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_1, MSGBOX_YESNO
# 10 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_18
# 15 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_12:
# 24 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_6, MSGBOX_YESNO
# 25 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_21
# 30 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_15:
# 39 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_10, MSGBOX_YESNO
# 40 "data/maps/Route13_MovingHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MovingHouse_EventScript_ChoiceItem_24
# 45 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_3
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_18:
# 11 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_FIRE_STONE, 1
# 12 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_SPECS, 1
# 13 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_2
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_21:
# 26 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_WATER_STONE, 1
# 27 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_SCARF, 1
# 28 "data/maps/Route13_MovingHouse/scripts.pory"
	msgbox Route13_MovingHouse_EventScript_ChoiceItem_Text_7
	goto Route13_MovingHouse_EventScript_ChoiceItem_1

Route13_MovingHouse_EventScript_ChoiceItem_24:
# 41 "data/maps/Route13_MovingHouse/scripts.pory"
	removeitem ITEM_THUNDER_STONE, 1
# 42 "data/maps/Route13_MovingHouse/scripts.pory"
	giveitem ITEM_CHOICE_BAND, 1
# 43 "data/maps/Route13_MovingHouse/scripts.pory"
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
# 13 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "SPECS.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_3:
# 15 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Oh, I see. Maybe another time then.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_4:
# 18 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a FIRE STONE.\n"
	.string "Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_5:
# 21 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I'm looking for a WATER STONE. If\n"
	.string "you have one, I'll trade you some\l"
	.string "CHOICE SCARF for it.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_6:
# 24 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Do you want to trade your WATER\n"
	.string "STONE for my CHOICE SCARF?$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_7:
# 28 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "SCARF.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_8:
# 33 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a WATER\n"
	.string "STONE. Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_9:
# 36 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I'm looking for a THUNDER STONE. If\n"
	.string "you have one, I'll trade you some\l"
	.string "CHOICE BAND for it.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_10:
# 39 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Do you want to trade your THUNDER\n"
	.string "STONE for my CHOICE BAND?$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_11:
# 43 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thank you! Here are your CHOICE\n"
	.string "BAND.$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_12:
# 48 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "I see you don't have a THUNDER\n"
	.string "STONE. Come back when you do!$"

Route13_MovingHouse_EventScript_ChoiceItem_Text_13:
# 51 "data/maps/Route13_MovingHouse/scripts.pory"
	.string "Thanks for trading with me!$"
