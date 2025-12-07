# 1 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 2 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
.equ LOCALID_ARMOR_FOSSIL,  1
# 3 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 4 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
FiveIsland_LostCave_Room6_MapScripts::
# 5 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_LostCave_Room6_OnTransition
# 6 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	.byte 0
# 7 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 8 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
FiveIsland_LostCave_Room6_OnTransition::
# 9 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	call_if_unset FLAG_GOT_ARMOR_FOSSIL, FiveIsland_LostCave_Room6_EventScript_ShowArmorFossil
# 10 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	end
# 11 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 12 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
FiveIsland_LostCave_Room6_EventScript_ShowArmorFossil::
# 13 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	clearflag FLAG_HIDE_ARMOR_FOSSIL
# 14 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	return
# 15 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 16 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
FiveIsland_LostCave_Room6_EventScript_ArmorFossil::
# 17 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	lock
# 18 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	faceplayer
# 19 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	msgbox FiveIsland_LostCave_Room6_Text_YouWantArmorFossil, MSGBOX_YESNO
# 20 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FiveIsland_LostCave_Room6_EventScript_DontTakeFossil
# 21 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	removeobject LOCALID_ARMOR_FOSSIL
# 22 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	giveitem_msg FiveIsland_LostCave_Room6_Text_Taken_Armor_Fossil, ITEM_ARMOR_FOSSIL, 1, MUS_OBTAIN_KEY_ITEM
# 23 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	closemessage
# 24 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	special QuestLog_CutRecording
# 25 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	setflag FLAG_GOT_ARMOR_FOSSIL
# 26 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	release
# 27 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	end
# 28 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"

# 29 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
FiveIsland_LostCave_Room6_EventScript_DontTakeFossil::
# 30 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	release
# 31 "data/maps/FiveIsland_LostCave_Room6/scripts.pory"
	end
