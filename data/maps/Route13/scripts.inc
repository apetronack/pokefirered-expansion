# 1 "data/maps/Route13/scripts.pory"

# 2 "data/maps/Route13/scripts.pory"
Route13_MapScripts::
# 3 "data/maps/Route13/scripts.pory"
	.byte 0
# 4 "data/maps/Route13/scripts.pory"

# 5 "data/maps/Route13/scripts.pory"
Route13_EventScript_TrainerTips1::
# 6 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
# 7 "data/maps/Route13/scripts.pory"
	end
# 8 "data/maps/Route13/scripts.pory"

# 9 "data/maps/Route13/scripts.pory"
Route13_EventScript_TrainerTips2::
# 10 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
# 11 "data/maps/Route13/scripts.pory"
	end
# 12 "data/maps/Route13/scripts.pory"

# 13 "data/maps/Route13/scripts.pory"
Route13_EventScript_RouteSign::
# 14 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
# 15 "data/maps/Route13/scripts.pory"
	end
# 16 "data/maps/Route13/scripts.pory"

# 17 "data/maps/Route13/scripts.pory"
Route13_EventScript_BerryMart::
# 18 "data/maps/Route13/scripts.pory"
	lock
# 19 "data/maps/Route13/scripts.pory"
	faceplayer
# 20 "data/maps/Route13/scripts.pory"
	message Text_MayIHelpYou
# 21 "data/maps/Route13/scripts.pory"
	waitmessage
# 22 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Items
# 23 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 24 "data/maps/Route13/scripts.pory"
	release
# 25 "data/maps/Route13/scripts.pory"
	end
# 26 "data/maps/Route13/scripts.pory"

# 27 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Items::
# 28 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 29 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 30 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 31 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 32 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 33 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 34 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 35 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 36 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 37 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 38 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 39 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 40 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 41 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 42 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 43 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 44 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 45 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 46 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 47 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 48 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 49 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 50 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 51 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 52 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 53 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 54 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 55 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LIECHI_BERRY
# 56 "data/maps/Route13/scripts.pory"
	.2byte ITEM_GANLON_BERRY
# 57 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SALAC_BERRY
# 58 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PETAYA_BERRY
# 59 "data/maps/Route13/scripts.pory"
	.2byte ITEM_APICOT_BERRY
# 60 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LANSAT_BERRY
# 61 "data/maps/Route13/scripts.pory"
	.2byte ITEM_STARF_BERRY
# 62 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ENIGMA_BERRY
# 63 "data/maps/Route13/scripts.pory"
	.2byte ITEM_MICLE_BERRY
# 64 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 65 "data/maps/Route13/scripts.pory"
	.2byte ITEM_JABOCA_BERRY
# 66 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ROWAP_BERRY
# 67 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 68 "data/maps/Route13/scripts.pory"
	release
# 69 "data/maps/Route13/scripts.pory"
	end
