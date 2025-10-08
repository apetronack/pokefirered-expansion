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
	.align 2
# 49 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Default_Items::
# 50 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 51 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 52 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 53 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 54 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 55 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 56 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 57 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 58 "data/maps/Route13/scripts.pory"
	release
# 59 "data/maps/Route13/scripts.pory"
	end
# 60 "data/maps/Route13/scripts.pory"

# 61 "data/maps/Route13/scripts.pory"
	.align 2
# 62 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Erika_Items::
# 63 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 64 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 65 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 66 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 67 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 68 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 69 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 70 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 71 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 72 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 73 "data/maps/Route13/scripts.pory"
	release
# 74 "data/maps/Route13/scripts.pory"
	end
# 75 "data/maps/Route13/scripts.pory"

# 76 "data/maps/Route13/scripts.pory"
	.align 2
# 77 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Koga_Items::
# 78 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 79 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 80 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 81 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 82 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 83 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 84 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 85 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 86 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 87 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 88 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 89 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 90 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 91 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 92 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 93 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 94 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 95 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 96 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 97 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 98 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 99 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 100 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 101 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 102 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 103 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 104 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 105 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 106 "data/maps/Route13/scripts.pory"
	release
# 107 "data/maps/Route13/scripts.pory"
	end
# 108 "data/maps/Route13/scripts.pory"

# 109 "data/maps/Route13/scripts.pory"
	.align 2
# 110 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Giovanni_Items::
# 111 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 112 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 113 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 114 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 115 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 116 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 117 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 118 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 119 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 120 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 121 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 122 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 123 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 124 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 125 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 126 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 127 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 128 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 129 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 130 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 131 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 132 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 133 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 134 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 135 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 136 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 137 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 138 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LIECHI_BERRY
# 139 "data/maps/Route13/scripts.pory"
	.2byte ITEM_GANLON_BERRY
# 140 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SALAC_BERRY
# 141 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PETAYA_BERRY
# 142 "data/maps/Route13/scripts.pory"
	.2byte ITEM_APICOT_BERRY
# 143 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LANSAT_BERRY
# 144 "data/maps/Route13/scripts.pory"
	.2byte ITEM_STARF_BERRY
# 145 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ENIGMA_BERRY
# 146 "data/maps/Route13/scripts.pory"
	.2byte ITEM_MICLE_BERRY
# 147 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 148 "data/maps/Route13/scripts.pory"
	.2byte ITEM_JABOCA_BERRY
# 149 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ROWAP_BERRY
# 150 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 151 "data/maps/Route13/scripts.pory"
	release
# 152 "data/maps/Route13/scripts.pory"
	end
