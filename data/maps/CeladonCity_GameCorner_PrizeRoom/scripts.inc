# 1 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 2 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_MapScripts::
# 3 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.byte 0
# 4 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 5 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
# 6 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon, MSGBOX_NPC
# 7 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 8 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 9 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
# 10 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday, MSGBOX_NPC
# 11 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 12 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 13 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
# 14 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	lock
# 15 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	faceplayer
# 16 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
# 17 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 18 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	showcoinsbox 0, 0
# 19 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
# 20 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
# 21 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 22 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 23 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
# 24 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
# 25 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitmessage
# 26 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	multichoice 11, 0, MULTICHOICE_GAME_CORNER_POKEMON_PRIZES, FALSE
# 27 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	switch VAR_RESULT
# 28 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_Abra
# 29 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_Clefairy
# 30 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_DratiniPinsir
# 31 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_ScytherDratini
# 32 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon
# 33 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 34 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 35 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 36 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 37 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
# 38 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	hidecoinsbox 0, 0
# 39 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	release
# 40 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 41 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 42 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_Abra::
# 43 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 44 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ABRA
# 45 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 180
# 46 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 47 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 48 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ABRA
# 49 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 120
# 50 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 51 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 52 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 53 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 54 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 55 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_Clefairy::
# 56 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 57 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
# 58 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 500
# 59 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 60 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 61 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
# 62 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 750
# 63 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 64 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 65 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 66 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 67 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 68 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_DratiniPinsir::
# 69 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 70 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_DRATINI
# 71 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 2800
# 72 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 73 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 74 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PINSIR
# 75 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 2500
# 76 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 77 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 78 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 79 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 80 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 81 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ScytherDratini::
# 82 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 83 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SCYTHER
# 84 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 5500
# 85 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 86 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 87 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_DRATINI
# 88 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 4600
# 89 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 90 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 91 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 92 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 93 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 94 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_Porygon::
# 95 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 96 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PORYGON
# 97 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 9999
# 98 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 99 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 100 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_PORYGON
# 101 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 6500
# 102 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 103 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 104 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
# 105 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 106 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 107 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
# 108 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 109 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
# 110 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 111 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	checkcoins VAR_RESULT
# 112 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
# 113 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 114 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	switch VAR_TEMP_1
# 115 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_ABRA,     CeladonCity_GameCorner_PrizeRoom_EventScript_GiveAbra
# 116 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_CLEFAIRY, CeladonCity_GameCorner_PrizeRoom_EventScript_GiveClefairy
# 117 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_DRATINI,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini
# 118 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_SCYTHER,  CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther
# 119 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_PORYGON,  CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon
# 120 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case SPECIES_PINSIR,   CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir
# 121 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 122 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 123 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GiveAbra::
# 124 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 125 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 9
# 126 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 127 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 128 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 7
# 129 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 130 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 131 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 132 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 133 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 134 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GiveClefairy::
# 135 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 136 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 8
# 137 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 138 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 139 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 12
# 140 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 141 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 142 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 143 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 144 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 145 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GiveDratini::
# 146 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 147 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 18
# 148 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 149 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 150 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 24
# 151 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 152 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 153 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 154 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 155 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 156 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GiveScyther::
# 157 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 25
# 158 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 159 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 160 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 161 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
# 162 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef FIRERED
# 163 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 26
# 164 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.else
# 165 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.ifdef LEAFGREEN
# 166 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 18
# 167 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 168 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	.endif
# 169 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 170 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 171 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 172 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
# 173 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	givemon VAR_TEMP_1, 18
# 174 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
# 175 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 176 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 177 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
# 178 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
# 179 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
# 180 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull
# 181 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 182 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 183 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_PartyFull::
# 184 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 185 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox Text_NoMoreRoomForPokemon
# 186 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	hidecoinsbox 0, 0
# 187 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	release
# 188 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 189 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 190 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon::
# 191 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	getpartysize
# 192 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	subvar VAR_RESULT, 1
# 193 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 194 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	call EventScript_ChangePokemonNickname
# 195 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 196 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 197 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 198 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
# 199 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 200 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired
# 201 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	release
# 202 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 203 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 204 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
# 205 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins
# 206 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 207 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 208 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 209 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
# 210 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	removecoins VAR_TEMP_2
# 211 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	updatecoinsbox 0, 5
# 212 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 213 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 214 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	message Text_PlayerObtainedTheMon
# 215 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitmessage
# 216 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitfanfare
# 217 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 218 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, YES, CeladonCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon
# 219 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 220 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 221 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 222 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
# 223 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	removecoins VAR_TEMP_2
# 224 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	updatecoinsbox 0, 5
# 225 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 226 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 227 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	message Text_PlayerObtainedTheMon
# 228 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitmessage
# 229 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitfanfare
# 230 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 231 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
# 232 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 233 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
# 234 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 235 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 236 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
# 237 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	call EventScript_TransferredToPC
# 238 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 239 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 240 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 241 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
# 242 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	lock
# 243 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	faceplayer
# 244 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
# 245 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 246 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	showcoinsbox 0, 0
# 247 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
# 248 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM
# 249 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 250 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 251 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM::
# 252 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
# 253 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitmessage
# 254 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	multichoice 11, 0, MULTICHOICE_GAME_CORNER_TMPRIZES, FALSE
# 255 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	switch VAR_RESULT
# 256 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TM13
# 257 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TM23
# 258 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TM24
# 259 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TM30
# 260 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TM35
# 261 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_TM53
# 262 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 6, CeladonCity_GameCorner_PrizeRoom_EventScript_TM79
# 263 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 7, CeladonCity_GameCorner_PrizeRoom_EventScript_TM84
# 264 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 8, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 265 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 266 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 267 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 268 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM13::
# 269 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM13
# 270 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 4000
# 271 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_ICE_BEAM
# 272 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 273 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 274 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 275 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM23::
# 276 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM23
# 277 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 3500
# 278 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_IRON_TAIL
# 279 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 280 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 281 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 282 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM24::
# 283 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM24
# 284 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 4000
# 285 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_THUNDERBOLT
# 286 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 287 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 288 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 289 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM30::
# 290 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM30
# 291 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 4000
# 292 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_SHADOW_BALL
# 293 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 294 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 295 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 296 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM35::
# 297 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM35
# 298 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 4000
# 299 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_FLAMETHROWER
# 300 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 301 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 302 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 303 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM53::
# 304 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM53
# 305 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 3750
# 306 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_ENERGY_BALL
# 307 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 308 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 309 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 310 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM79::
# 311 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM79
# 312 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 3750
# 313 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_DARK_PULSE
# 314 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 315 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 316 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 317 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TM84::
# 318 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_TM84
# 319 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 3750
# 320 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	buffermovename STR_VAR_2, MOVE_POISON_JAB
# 321 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
# 322 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 323 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 324 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM::
# 325 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM, MSGBOX_YESNO
# 326 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 327 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
# 328 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 329 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 330 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem::
# 331 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	bufferitemname STR_VAR_1, VAR_TEMP_1
# 332 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
# 333 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 334 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
# 335 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 336 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 337 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize::
# 338 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	bufferitemname STR_VAR_1, VAR_TEMP_1
# 339 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	checkcoins VAR_RESULT
# 340 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
# 341 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	checkitemspace VAR_TEMP_1
# 342 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull
# 343 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	removecoins VAR_TEMP_2
# 344 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	updatecoinsbox 0, 5
# 345 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	giveitem VAR_TEMP_1
# 346 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 347 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 348 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 349 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull::
# 350 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 351 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox Text_TooBadBagFull
# 352 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	hidecoinsbox 0, 0
# 353 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	release
# 354 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 355 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 356 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
# 357 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	lock
# 358 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	faceplayer
# 359 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
# 360 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 361 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	showcoinsbox 0, 0
# 362 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
# 363 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem
# 364 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 365 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 366 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem::
# 367 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
# 368 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	waitmessage
# 369 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	multichoice 10, 0, MULTICHOICE_GAME_CORNER_BATTLE_ITEM_PRIZES, FALSE
# 370 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	switch VAR_RESULT
# 371 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall
# 372 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed
# 373 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal
# 374 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater
# 375 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute
# 376 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 377 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
# 378 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 379 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 380 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall::
# 381 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_SMOKE_BALL
# 382 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 800
# 383 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
# 384 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 385 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 386 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed::
# 387 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_MIRACLE_SEED
# 388 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 1000
# 389 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
# 390 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 391 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 392 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal::
# 393 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_CHARCOAL
# 394 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 1000
# 395 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
# 396 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 397 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 398 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater::
# 399 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_MYSTIC_WATER
# 400 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 1000
# 401 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
# 402 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
# 403 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"

# 404 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute::
# 405 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_1, ITEM_YELLOW_FLUTE
# 406 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	setvar VAR_TEMP_2, 1600
# 407 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
# 408 "data/maps/CeladonCity_GameCorner_PrizeRoom/scripts.pory"
	end
