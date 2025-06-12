# 1 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 2 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_MapScripts::
# 3 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.byte 0
# 4 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 5 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
# 6 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
# 7 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 8 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 9 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_EventScript_Lass::
# 10 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
# 11 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 12 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 13 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
# 14 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
# 15 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 16 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 17 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
# 18 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 19 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	lock
# 20 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 21 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	message Text_MayIHelpYou
# 22 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 23 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	pokemart CeladonCity_DepartmentStore_2F_Items
# 24 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 25 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	release
# 26 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 27 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 28 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 29 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_Items::
# 30 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 31 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 32 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ETHER
# 33 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ELIXIR
# 34 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 35 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 36 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REVIVE
# 37 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 38 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 39 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AWAKENING
# 40 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 41 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 42 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 43 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 44 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	release
# 45 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 46 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 47 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
# 48 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 49 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	lock
# 50 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 51 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	message Text_MayIHelpYou
# 52 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 53 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	pokemart CeladonCity_DepartmentStore_2F_TMs
# 54 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 55 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	release
# 56 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
# 57 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"

# 58 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 59 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
CeladonCity_DepartmentStore_2F_TMs::
# 60 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM05
# 61 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM07
# 62 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM09
# 63 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM11
# 64 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM12
# 65 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM15
# 66 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM18
# 67 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM28
# 68 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM31
# 69 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM37
# 70 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM41
# 71 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM42
# 72 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM43
# 73 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM45
# 74 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM46
# 75 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM49
# 76 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM54
# 77 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TM78
# 78 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NONE
# 79 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	release
# 80 "data/maps/CeladonCity_DepartmentStore_2F/scripts.pory"
	end
