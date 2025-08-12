Route13_MoveRelearnerHouse_MapScripts::
	.byte 0


Route13_MoveRelearnerHouse_EventScript_MoveTutor::
# 3 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	lock
# 4 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	faceplayer
	checkitem ITEM_STARDUST
# 0 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MoveRelearnerHouse_EventScript_MoveTutor_2
# 30 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_4
# 31 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

# 34 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

Route13_MoveRelearnerHouse_EventScript_MoveTutor_2:
# 6 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_0, MSGBOX_YESNO
# 7 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MoveRelearnerHouse_EventScript_MoveTutor_5
# 25 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_3
# 26 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

Route13_MoveRelearnerHouse_EventScript_MoveTutor_5:
# 8 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_1
# 9 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	special ChooseMonForMoveRelearner
# 10 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	waitstate
# 11 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
# 12 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
# 13 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_0x8005, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
# 14 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox TwoIsland_House_Text_TeachWhichMove
# 15 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 16 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	waitstate
# 17 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
# 18 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	removeitem ITEM_STARDUST, 1
# 19 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 20 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_2
# 21 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	call EventScript_RestorePrevTextColor
# 22 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end


Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_0:
# 6 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Ah, that is STARDUST you have!\n"
	.string "Would you like me to teach your\l"
	.string "POKéMON a move it has known\l"
	.string "before?$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_1:
# 8 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Which POKéMON should I teach?$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_2:
# 20 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Thank you. I hope your POKéMON\n"
	.string "remembers the importance of its\l"
	.string "past.$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_3:
# 25 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Understood. Come back if you change\n"
	.string "your mind.$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_4:
# 30 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "I have studied the experts of the\n"
	.string "past. Now, I can teach your\l"
	.string "POKéMON any move it has known\l"
	.string "before. All I ask in return is\l"
	.string "some STARDUST.$"
