Route13_MoveRelearnerHouse_MapScripts::
	.byte 0


Route13_MoveRelearnerHouse_EventScript_MoveTutor::
# 4 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	lock
# 5 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	faceplayer
	checkitem ITEM_STARDUST
# 0 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Route13_MoveRelearnerHouse_EventScript_MoveTutor_2
# 16 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_2
# 17 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

Route13_MoveRelearnerHouse_EventScript_MoveTutor_1:
# 20 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

Route13_MoveRelearnerHouse_EventScript_MoveTutor_2:
# 7 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_0, MSGBOX_YESNO
# 8 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route13_MoveRelearnerHouse_EventScript_MoveTutor_5
# 11 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_1
# 12 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end

Route13_MoveRelearnerHouse_EventScript_MoveTutor_5:
# 9 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor
	goto Route13_MoveRelearnerHouse_EventScript_MoveTutor_1


Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor::
# 25 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor_Text_0
# 26 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	special ChooseMonForMoveRelearner
# 27 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	waitstate
# 28 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route13_MoveRelearnerHouse_EventScript_EndTutorMove
# 29 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	special IsSelectedMonEgg
# 30 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route13_MoveRelearnerHouse_EventScript_CantTutorEgg
# 31 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_0x8005, 0, Route13_MoveRelearnerHouse_EventScript_NoMoveToTutorMon
# 32 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_Text_TeachWhichMove
# 33 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 34 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	waitstate
# 35 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto_if_eq VAR_0x8004, 0, Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor
# 36 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	removeitem ITEM_STARDUST, 1
# 37 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 38 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor_Text_1
# 39 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	call EventScript_RestorePrevTextColor
# 40 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end


Route13_MoveRelearnerHouse_EventScript_NoMoveToTutorMon::
# 45 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_Text_NoMoveICanTeachThatMon
# 46 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor
	return


Route13_MoveRelearnerHouse_EventScript_CantTutorEgg::
# 50 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_Text_CantTeachAnEgg
# 51 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	goto Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor
	return


Route13_MoveRelearnerHouse_EventScript_EndTutorMove::
# 55 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	msgbox Route13_MoveRelearnerHouse_Text_EndTutorMove
# 56 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	release
	end


Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_0:
# 7 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Ah, that is STARDUST you have!\n"
	.string "Would you like me to teach your\l"
	.string "POKéMON a move it has known\l"
	.string "before?$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_1:
# 11 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Understood. Come back if you change\n"
	.string "your mind.$"

Route13_MoveRelearnerHouse_EventScript_MoveTutor_Text_2:
# 16 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "I have studied the experts of the\n"
	.string "past. Now, I can teach your\l"
	.string "POKéMON any move it has known\l"
	.string "before. All I ask in return is\l"
	.string "some STARDUST.$"

Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor_Text_0:
# 25 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Which POKéMON should I teach?$"

Route13_MoveRelearnerHouse_EventScript_ChooseMonToTutor_Text_1:
# 38 "data/maps/Route13_MoveRelearnerHouse/scripts.pory"
	.string "Thank you. I hope your POKéMON\n"
	.string "remembers the importance of its\l"
	.string "past.$"
