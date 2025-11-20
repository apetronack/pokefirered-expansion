static const struct InGameTrade sInGameTrades[] = {
    [INGAME_TRADE_SPOINK] = 
    {
        .nickname = _("BABE"),
        .species = SPECIES_SPOINK,
        .ivs = {20, 21, 19, 24, 23, 22},
        .abilityNum = 0,
        .otId = 1985,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x00009cae,
        .heldItem = ITEM_LIGHT_CLAY,
        .mailNum = 255,
        .otName = _("REYLEY"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RALTS
    }, 
    [INGAME_TRADE_SNEASEL] = 
    {
        .nickname = _("ZORRO"),
        .species = SPECIES_SNEASEL,
        .ivs = {18, 17, 18, 22, 25, 21},
        .abilityNum = 0,
        .otId = 36728,
        .conditions = {5, 30, 5, 5, 5},
        .personality = 0x498a2e1d,
        .heldItem = ITEM_FAB_MAIL,
        .mailNum = 0,
        .otName = _("DONTAE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_POLIWHIRL
    }, 
    [INGAME_TRADE_NIDORAN] = 
    {
#if defined(FIRERED)
        .nickname = _("MS. NIDO"),
        .species = SPECIES_NIDORAN_F,
        .ivs = {22, 18, 25, 19, 15, 22},
        .abilityNum = 0,
        .otId = 63184,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x4c970b89,
        .heldItem = ITEM_TINY_MUSHROOM,
        .mailNum = 255,
        .otName = _("SAIGE"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORAN_M
#elif defined(LEAFGREEN)
        .nickname = _("MR. NIDO"),
        .species = SPECIES_NIDORAN_M,
        .ivs = {19, 25, 18, 22, 22, 15},
        .abilityNum = 0,
        .otId = 63184,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x4c970b9e,
        .heldItem = ITEM_TINY_MUSHROOM,
        .mailNum = 255,
        .otName = _("SAIGE"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORAN_F
#endif
    }, 
    [INGAME_TRADE_DODUO] = 
    {
        .nickname = _("P'CKIK"),
        .species = SPECIES_DODUO,
        .ivs = {20, 25, 21, 20, 15, 24},
        .abilityNum = 1,
        .otId = 8810,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x151943d7,
        .heldItem = ITEM_RAZOR_CLAW,
        .mailNum = 255,
        .otName = _("ELYSSA"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_STARLY
    }, 
    [INGAME_TRADE_NIDORINOA] = 
    {
#if defined(FIRERED)
        .nickname = _("NINA"),
        .species = SPECIES_NIDORINA,
        .ivs = {22, 25, 18, 19, 22, 15},
        .abilityNum = 0,
        .otId = 13637,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00eeca15,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("TURNER"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORINO
#elif defined(LEAFGREEN)
        .nickname = _("NINO"),
        .species = SPECIES_NIDORINO,
        .ivs = {19, 18, 25, 22, 15, 22},
        .abilityNum = 0,
        .otId = 13637,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x00eeca19,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("TURNER"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORINA
#endif
    }, 
    [INGAME_TRADE_MILTANK] = 
    {
        .nickname = _("OTIS"),
        .species = SPECIES_MILTANK,
        .ivs = {24, 26, 21, 15, 23, 21},
        .abilityNum = 0,
        .otId = 1239,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x451308ab,
        .heldItem = ITEM_CHOICE_SCARF,
        .mailNum = 255,
        .otName = _("HADEN"),
        .otGender = MALE,
        .sheen = 10,
#if defined(FIRERED)
        .requestedSpecies = SPECIES_GOLDUCK
#elif defined(LEAFGREEN)
        .requestedSpecies = SPECIES_SLOWBRO
#endif
    }, 
    [INGAME_TRADE_ELECTABUZZ] = 
    {
        .nickname = _("LIGHTYEAR"),
        .species = SPECIES_ELECTABUZZ,
        .ivs = {19, 16, 18, 25, 25, 19},
        .abilityNum = 1,
        .otId = 50298,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x06341016,
        .heldItem = ITEM_MAGNET,
        .mailNum = 255,
        .otName = _("CLIFTON"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RAICHU
    }, 
    [INGAME_TRADE_MAWILE] = 
    {
        .nickname = _("TWO-TOOTH"),
        .species = SPECIES_MAWILE,
        .ivs = {22, 24, 25, 16, 23, 20},
        .abilityNum = 0,
        .otId = 60042,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_METAL_COAT,
        .mailNum = 255,
        .otName = _("NORMA"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_VENONAT
    },
    [INGAME_TRADE_SPHEAL] = 
    {
        .nickname = _("SEELOR"),
        .species = SPECIES_SPHEAL,
        .ivs = {24, 15, 22, 16, 23, 22},
        .abilityNum = 0,
        .otId = 9853,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_NEVERMELTICE,
        .mailNum = 255,
        .otName = _("GARETT"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NUMEL
    },
    [INGAME_TRADE_TOTODILE] =
    {
        .nickname = _("IRWIN"),
        .species = SPECIES_TOTODILE,
        .ivs = {20, 28, 21, 25, 15, 23},
        .abilityNum = 0,
        .otId = 1097,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x06341016,
        .heldItem = ITEM_POISON_BARB,
        .mailNum = 255,
        .otName = _("ROBERT"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_MANTINE,
    },
    [INGAME_TRADE_CHIKORITA] =
    {
        .nickname = _("LITLFOOT"),
        .species = SPECIES_CHIKORITA,
        .ivs = {29, 15, 27, 22, 28, 24},
        .abilityNum = 0,
        .otId = 3219,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_HARD_STONE,
        .mailNum = 255,
        .otName = _("RUBY"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_GEODUDE,
    },
    [INGAME_TRADE_CYNDAQUIL] =
    {
        .nickname = _("CINNAMON"),
        .species = SPECIES_CYNDAQUIL,
        .ivs = {25, 26, 20, 28, 17, 24},
        .abilityNum = 0,
        .otId = 8031,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_SOFT_SAND,
        .mailNum = 255,
        .otName = _("TREVOR"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_CUBONE,
    },
    [INGAME_TRADE_MUDKIP] =
    {
        .nickname = _("TOADETTE"),
        .species = SPECIES_MUDKIP,
        .ivs = {25, 28, 30, 24, 19, 22},
        .abilityNum = 0,
        .otId = 1027,
        .conditions = {5, 30, 5, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_BLACK_BELT,
        .mailNum = 255,
        .otName = _("SIOBHAN"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_MEDITITE,
    },
    [INGAME_TRADE_TREECKO] =
    {
        .nickname = _("STU"),
        .species = SPECIES_TREECKO,
        .ivs = {19, 31, 22, 25, 19, 27},
        .abilityNum = 0,
        .otId = 9109,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_SHARP_BEAK,
        .mailNum = 255,
        .otName = _("KEN"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_MURKROW,
    },
    [INGAME_TRADE_TORCHIC] =
    {
        .nickname = _("CHICKLET"),
        .species = SPECIES_TORCHIC,
        .ivs = {22, 30, 25, 27, 18, 24},
        .abilityNum = 0,
        .otId = 5309,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_METAL_COAT,
        .mailNum = 255,
        .otName = _("ALAINA"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_MAGNEMITE,
    }
};

static const u16 sInGameTradeMailMessages[][10] = {
    {
        EC_WORD_THAT_S,
        EC_WORD_A,
        EC_WORD_HEALTHY,
        EC_POKEMON(SNEASEL),
        EC_WORD_EXCL,
        EC_WORD_BE,
        EC_WORD_KIND,
        EC_WORD_TO,
        EC_WORD_IT
    }
};
