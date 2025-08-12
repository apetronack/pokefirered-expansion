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
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, Route13_BerryMart_EventScript_GiovanniMart
# 23 "data/maps/Route13/scripts.pory"
	goto_if_set FLAG_DEFEATED_KOGA, Route13_BerryMart_EventScript_KogaMart
# 24 "data/maps/Route13/scripts.pory"
	goto_if_set FLAG_DEFEATED_ERIKA, Route13_BerryMart_EventScript_ErikaMart
# 25 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Default_Items
# 26 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 27 "data/maps/Route13/scripts.pory"
	release
# 28 "data/maps/Route13/scripts.pory"
	end
# 29 "data/maps/Route13/scripts.pory"

# 30 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_GiovanniMart::
# 31 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Giovanni_Items
# 32 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 33 "data/maps/Route13/scripts.pory"
	release
# 34 "data/maps/Route13/scripts.pory"
	end
# 35 "data/maps/Route13/scripts.pory"

# 36 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_KogaMart::
# 37 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Koga_Items
# 38 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 39 "data/maps/Route13/scripts.pory"
	release
# 40 "data/maps/Route13/scripts.pory"
	end
# 41 "data/maps/Route13/scripts.pory"

# 42 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_ErikaMart::
# 43 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Erika_Items
# 44 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 45 "data/maps/Route13/scripts.pory"
	release
# 46 "data/maps/Route13/scripts.pory"
	end
# 47 "data/maps/Route13/scripts.pory"

# 48 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Default_Items::
# 49 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 50 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 51 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 52 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 53 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 54 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 55 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 56 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 57 "data/maps/Route13/scripts.pory"
	release
# 58 "data/maps/Route13/scripts.pory"
	end
# 59 "data/maps/Route13/scripts.pory"

# 60 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Erika_Items::
# 61 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 62 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 63 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 64 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 65 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 66 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 67 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 68 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 69 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 70 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 71 "data/maps/Route13/scripts.pory"
	release
# 72 "data/maps/Route13/scripts.pory"
	end
# 73 "data/maps/Route13/scripts.pory"

# 74 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Koga_Items::
# 75 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 76 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 77 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 78 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 79 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 80 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 81 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 82 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 83 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 84 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 85 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 86 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 87 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 88 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 89 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 90 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 91 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 92 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 93 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 94 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 95 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 96 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 97 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 98 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 99 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 100 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 101 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 102 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 103 "data/maps/Route13/scripts.pory"
	release
# 104 "data/maps/Route13/scripts.pory"
	end
# 105 "data/maps/Route13/scripts.pory"

# 106 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Giovanni_Items::
# 107 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 108 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 109 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 110 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 111 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 112 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 113 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 114 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 115 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 116 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 117 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 118 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 119 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 120 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 121 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 122 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 123 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 124 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 125 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 126 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 127 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 128 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 129 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 130 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 131 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 132 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 133 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 134 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LIECHI_BERRY
# 135 "data/maps/Route13/scripts.pory"
	.2byte ITEM_GANLON_BERRY
# 136 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SALAC_BERRY
# 137 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PETAYA_BERRY
# 138 "data/maps/Route13/scripts.pory"
	.2byte ITEM_APICOT_BERRY
# 139 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LANSAT_BERRY
# 140 "data/maps/Route13/scripts.pory"
	.2byte ITEM_STARF_BERRY
# 141 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ENIGMA_BERRY
# 142 "data/maps/Route13/scripts.pory"
	.2byte ITEM_MICLE_BERRY
# 143 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 144 "data/maps/Route13/scripts.pory"
	.2byte ITEM_JABOCA_BERRY
# 145 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ROWAP_BERRY
# 146 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 147 "data/maps/Route13/scripts.pory"
	release
# 148 "data/maps/Route13/scripts.pory"
	end
