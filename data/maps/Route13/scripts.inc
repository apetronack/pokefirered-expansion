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
Route13_EventScript_NurseHeal::
# 14 "data/maps/Route13/scripts.pory"
	lock
# 15 "data/maps/Route13/scripts.pory"
	faceplayer
# 16 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_NurseHeal, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route13/scripts.pory"
	special HealPlayerParty
# 18 "data/maps/Route13/scripts.pory"
	release
# 19 "data/maps/Route13/scripts.pory"
	end
# 20 "data/maps/Route13/scripts.pory"

# 21 "data/maps/Route13/scripts.pory"
Route13_EventScript_RouteSign::
# 22 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
# 23 "data/maps/Route13/scripts.pory"
	end
# 24 "data/maps/Route13/scripts.pory"

# 25 "data/maps/Route13/scripts.pory"
Route13_EventScript_BerryMart::
# 26 "data/maps/Route13/scripts.pory"
	lock
# 27 "data/maps/Route13/scripts.pory"
	faceplayer
# 28 "data/maps/Route13/scripts.pory"
	message Text_MayIHelpYou
# 29 "data/maps/Route13/scripts.pory"
	waitmessage
# 30 "data/maps/Route13/scripts.pory"
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, Route13_BerryMart_EventScript_GiovanniMart
# 31 "data/maps/Route13/scripts.pory"
	goto_if_set FLAG_DEFEATED_KOGA, Route13_BerryMart_EventScript_KogaMart
# 32 "data/maps/Route13/scripts.pory"
	goto_if_set FLAG_DEFEATED_ERIKA, Route13_BerryMart_EventScript_ErikaMart
# 33 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Default_Items
# 34 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 35 "data/maps/Route13/scripts.pory"
	release
# 36 "data/maps/Route13/scripts.pory"
	end
# 37 "data/maps/Route13/scripts.pory"

# 38 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_GiovanniMart::
# 39 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Giovanni_Items
# 40 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 41 "data/maps/Route13/scripts.pory"
	release
# 42 "data/maps/Route13/scripts.pory"
	end
# 43 "data/maps/Route13/scripts.pory"

# 44 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_KogaMart::
# 45 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Koga_Items
# 46 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 47 "data/maps/Route13/scripts.pory"
	release
# 48 "data/maps/Route13/scripts.pory"
	end
# 49 "data/maps/Route13/scripts.pory"

# 50 "data/maps/Route13/scripts.pory"
Route13_BerryMart_EventScript_ErikaMart::
# 51 "data/maps/Route13/scripts.pory"
	pokemart Route13_BerryMart_Erika_Items
# 52 "data/maps/Route13/scripts.pory"
	msgbox Text_PleaseComeAgain
# 53 "data/maps/Route13/scripts.pory"
	release
# 54 "data/maps/Route13/scripts.pory"
	end
# 55 "data/maps/Route13/scripts.pory"

# 56 "data/maps/Route13/scripts.pory"
	.align 2
# 57 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Default_Items::
# 58 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 59 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 60 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 61 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 62 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 63 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 64 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 65 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 66 "data/maps/Route13/scripts.pory"
	release
# 67 "data/maps/Route13/scripts.pory"
	end
# 68 "data/maps/Route13/scripts.pory"

# 69 "data/maps/Route13/scripts.pory"
	.align 2
# 70 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Erika_Items::
# 71 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 72 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 73 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 74 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 75 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 76 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 77 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 78 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 79 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 80 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 81 "data/maps/Route13/scripts.pory"
	release
# 82 "data/maps/Route13/scripts.pory"
	end
# 83 "data/maps/Route13/scripts.pory"

# 84 "data/maps/Route13/scripts.pory"
	.align 2
# 85 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Koga_Items::
# 86 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 87 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 88 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 89 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 90 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 91 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 92 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 93 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 94 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 95 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 96 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 97 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 98 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 99 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 100 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 101 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 102 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 103 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 104 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 105 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 106 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 107 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 108 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 109 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 110 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 111 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 112 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 113 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 114 "data/maps/Route13/scripts.pory"
	release
# 115 "data/maps/Route13/scripts.pory"
	end
# 116 "data/maps/Route13/scripts.pory"

# 117 "data/maps/Route13/scripts.pory"
	.align 2
# 118 "data/maps/Route13/scripts.pory"
Route13_BerryMart_Giovanni_Items::
# 119 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHERI_BERRY
# 120 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHESTO_BERRY
# 121 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PECHA_BERRY
# 122 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RAWST_BERRY
# 123 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ASPEAR_BERRY
# 124 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LEPPA_BERRY
# 125 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ORAN_BERRY
# 126 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PERSIM_BERRY
# 127 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LUM_BERRY
# 128 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SITRUS_BERRY
# 129 "data/maps/Route13/scripts.pory"
	.2byte ITEM_OCCA_BERRY
# 130 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PASSHO_BERRY
# 131 "data/maps/Route13/scripts.pory"
	.2byte ITEM_WACAN_BERRY
# 132 "data/maps/Route13/scripts.pory"
	.2byte ITEM_RINDO_BERRY
# 133 "data/maps/Route13/scripts.pory"
	.2byte ITEM_YACHE_BERRY
# 134 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHOPLE_BERRY
# 135 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KEBIA_BERRY
# 136 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SHUCA_BERRY
# 137 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COBA_BERRY
# 138 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PAYAPA_BERRY
# 139 "data/maps/Route13/scripts.pory"
	.2byte ITEM_TANGA_BERRY
# 140 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHARTI_BERRY
# 141 "data/maps/Route13/scripts.pory"
	.2byte ITEM_KASIB_BERRY
# 142 "data/maps/Route13/scripts.pory"
	.2byte ITEM_HABAN_BERRY
# 143 "data/maps/Route13/scripts.pory"
	.2byte ITEM_COLBUR_BERRY
# 144 "data/maps/Route13/scripts.pory"
	.2byte ITEM_BABIRI_BERRY
# 145 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CHILAN_BERRY
# 146 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LIECHI_BERRY
# 147 "data/maps/Route13/scripts.pory"
	.2byte ITEM_GANLON_BERRY
# 148 "data/maps/Route13/scripts.pory"
	.2byte ITEM_SALAC_BERRY
# 149 "data/maps/Route13/scripts.pory"
	.2byte ITEM_PETAYA_BERRY
# 150 "data/maps/Route13/scripts.pory"
	.2byte ITEM_APICOT_BERRY
# 151 "data/maps/Route13/scripts.pory"
	.2byte ITEM_LANSAT_BERRY
# 152 "data/maps/Route13/scripts.pory"
	.2byte ITEM_STARF_BERRY
# 153 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ENIGMA_BERRY
# 154 "data/maps/Route13/scripts.pory"
	.2byte ITEM_MICLE_BERRY
# 155 "data/maps/Route13/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 156 "data/maps/Route13/scripts.pory"
	.2byte ITEM_JABOCA_BERRY
# 157 "data/maps/Route13/scripts.pory"
	.2byte ITEM_ROWAP_BERRY
# 158 "data/maps/Route13/scripts.pory"
	.2byte ITEM_NONE
# 159 "data/maps/Route13/scripts.pory"
	release
# 160 "data/maps/Route13/scripts.pory"
	end
