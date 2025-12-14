import re
import csv

def load_species_enabled_config(config_filename):
    """Parse the species_enabled.h file to get family enable/disable status"""
    enabled_families = {}
    
    # Generation settings
    generation_settings = {
        'P_GEN_1_POKEMON': True,
        'P_GEN_2_POKEMON': True,
        'P_GEN_3_POKEMON': True,
        'P_GEN_4_POKEMON': True,
        'P_GEN_5_POKEMON': False,
        'P_GEN_6_POKEMON': False,
        'P_GEN_7_POKEMON': False,
        'P_GEN_8_POKEMON': False,
        'P_GEN_9_POKEMON': False,
        'P_REGIONAL_FORMS': True,
        'P_ALOLAN_FORMS': True,
        'P_GALARIAN_FORMS': True,
        'P_HISUIAN_FORMS': True,
        'P_PALDEAN_FORMS': True
    }
    
    try:
        with open(config_filename, 'r', encoding='utf-8') as file:
            content = file.read()
        
        # Find all P_FAMILY_ definitions and other relevant settings
        family_pattern = re.compile(r'#define\s+(P_FAMILY_\w+)\s+(\w+)')
        form_pattern = re.compile(r'#define\s+(P_\w+_FORMS?)\s+(\w+)')
        
        for match in family_pattern.finditer(content):
            family_name = match.group(1)
            family_value = match.group(2)
            
            # If the value is a generation setting, look it up
            if family_value in generation_settings:
                enabled_families[family_name] = generation_settings[family_value]
            elif family_value == 'TRUE':
                enabled_families[family_name] = True
            elif family_value == 'FALSE':
                enabled_families[family_name] = False
            else:
                # Default to False for unknown values
                enabled_families[family_name] = False
        
        # Process form settings (P_ALOLAN_FORMS, P_GALARIAN_FORMS, etc.)
        for match in form_pattern.finditer(content):
            form_name = match.group(1)
            form_value = match.group(2)
            
            # If the value is a generation setting, look it up
            if form_value in generation_settings:
                enabled_families[form_name] = generation_settings[form_value]
            elif form_value == 'TRUE':
                enabled_families[form_name] = True
            elif form_value == 'FALSE':
                enabled_families[form_name] = False
            elif form_value in enabled_families:
                # Handle cases like P_ALOLAN_FORMS = P_REGIONAL_FORMS
                enabled_families[form_name] = enabled_families[form_value]
            else:
                # Default to False for unknown values
                enabled_families[form_name] = False
                
    except FileNotFoundError:
        print(f"Warning: Could not find {config_filename}. All families will be marked as Unknown.")
    
    return enabled_families

def get_species_family_status(species_name, enabled_families):
    """Determine if a species family is enabled based on species name"""
    
    # Check if this is a regional form
    regional_forms = {
        '_ALOLA': 'P_ALOLAN_FORMS',
        '_GALAR': 'P_GALARIAN_FORMS', 
        '_HISUI': 'P_HISUIAN_FORMS',
        '_PALDEA': 'P_PALDEAN_FORMS'
    }
    
    base_species_name = species_name
    regional_form_key = None
    
    # Check if this is a regional form and extract the base species name
    for form_suffix, form_key in regional_forms.items():
        if form_suffix in species_name:
            # For Paldean forms, they might have additional suffixes like _COMBAT, _AQUA, etc.
            # We need to extract everything up to the regional form identifier
            base_species_name = species_name.split(form_suffix)[0]
            regional_form_key = form_key
            break
    
    # Get the base family status
    base_family_enabled = get_base_family_status(base_species_name, enabled_families)
    
    # If it's a regional form, check if both base family and regional form are enabled
    if regional_form_key:
        regional_form_enabled = enabled_families.get(regional_form_key, False)
        # Regional form is enabled only if both base family and regional forms are enabled
        if base_family_enabled == True and regional_form_enabled == True:
            return True
        elif base_family_enabled == False or regional_form_enabled == False:
            return False
        else:
            return "Unknown"
    
    # For non-regional forms, return the base family status
    return base_family_enabled

def get_base_family_status(species_name, enabled_families):
    """Get the enabled status for the base family (without regional form considerations)"""
    # Try to find the family by looking for a matching pattern
    # Most families are named after the first Pokemon in the evolution line
    
    # Create a mapping of possible species names to family keys
    for family_key in enabled_families:
        family_base = family_key.replace('P_FAMILY_', '')
        
        # Handle special cases
        if family_base == 'NIDORAN' and ('NIDORAN' in species_name or 'NIDORINA' in species_name or 'NIDOQUEEN' in species_name or 'NIDORINO' in species_name or 'NIDOKING' in species_name):
            return enabled_families[family_key]
        elif family_base == 'HITMONS' and ('HITMON' in species_name or 'TYROGUE' in species_name):
            return enabled_families[family_key]
        elif family_base == 'MR_MIME' and ('MR_MIME' in species_name or 'MIME_JR' in species_name or 'MR_RIME' in species_name):
            return enabled_families[family_key]
        elif family_base == 'VOLBEAT_ILLUMISE' and ('VOLBEAT' in species_name or 'ILLUMISE' in species_name):
            return enabled_families[family_key]
        elif family_base == 'HO_OH' and ('HO_OH' in species_name):
            return enabled_families[family_key]
        elif family_base == 'JANGMO_O' and ('JANGMO' in species_name or 'HAKAMO' in species_name or 'KOMMO' in species_name):
            return enabled_families[family_key]
        elif family_base == 'TAPU_KOKO' and ('TAPU_KOKO' in species_name):
            return enabled_families[family_key]
        elif family_base == 'TAPU_LELE' and ('TAPU_LELE' in species_name):
            return enabled_families[family_key]
        elif family_base == 'TAPU_BULU' and ('TAPU_BULU' in species_name):
            return enabled_families[family_key]
        elif family_base == 'TAPU_FINI' and ('TAPU_FINI' in species_name):
            return enabled_families[family_key]
        elif family_base == 'TYPE_NULL' and ('TYPE_NULL' in species_name or 'SILVALLY' in species_name):
            return enabled_families[family_key]
        # Handle evolution families by checking if species starts with family base name or contains it
        elif (species_name.startswith(family_base) or 
              family_base in species_name or
              # Handle common evolution patterns
              (family_base == 'BULBASAUR' and species_name in ['IVYSAUR', 'VENUSAUR']) or
              (family_base == 'CHARMANDER' and species_name in ['CHARMELEON', 'CHARIZARD']) or
              (family_base == 'SQUIRTLE' and species_name in ['WARTORTLE', 'BLASTOISE']) or
              (family_base == 'CATERPIE' and species_name in ['METAPOD', 'BUTTERFREE']) or
              (family_base == 'WEEDLE' and species_name in ['KAKUNA', 'BEEDRILL']) or
              (family_base == 'PIDGEY' and species_name in ['PIDGEOTTO', 'PIDGEOT']) or
              (family_base == 'RATTATA' and species_name in ['RATICATE']) or
              (family_base == 'SPEAROW' and species_name in ['FEAROW']) or
              (family_base == 'EKANS' and species_name in ['ARBOK']) or
              (family_base == 'PIKACHU' and species_name in ['PICHU', 'RAICHU']) or
              (family_base == 'SANDSHREW' and species_name in ['SANDSLASH']) or
              (family_base == 'CLEFAIRY' and species_name in ['CLEFFA', 'CLEFABLE']) or
              (family_base == 'VULPIX' and species_name in ['NINETALES']) or
              (family_base == 'JIGGLYPUFF' and species_name in ['IGGLYBUFF', 'WIGGLYTUFF']) or
              (family_base == 'ZUBAT' and species_name in ['GOLBAT', 'CROBAT']) or
              (family_base == 'ODDISH' and species_name in ['GLOOM', 'VILEPLUME', 'BELLOSSOM']) or
              (family_base == 'PARAS' and species_name in ['PARASECT']) or
              (family_base == 'VENONAT' and species_name in ['VENOMOTH']) or
              (family_base == 'DIGLETT' and species_name in ['DUGTRIO']) or
              (family_base == 'MEOWTH' and species_name in ['PERSIAN']) or
              (family_base == 'PSYDUCK' and species_name in ['GOLDUCK']) or
              (family_base == 'MANKEY' and species_name in ['PRIMEAPE', 'ANNIHILAPE']) or
              (family_base == 'GROWLITHE' and species_name in ['ARCANINE']) or
              (family_base == 'POLIWAG' and species_name in ['POLIWHIRL', 'POLIWRATH', 'POLITOED']) or
              (family_base == 'ABRA' and species_name in ['KADABRA', 'ALAKAZAM']) or
              (family_base == 'MACHOP' and species_name in ['MACHOKE', 'MACHAMP']) or
              (family_base == 'BELLSPROUT' and species_name in ['WEEPINBELL', 'VICTREEBEL']) or
              (family_base == 'TENTACOOL' and species_name in ['TENTACRUEL']) or
              (family_base == 'GEODUDE' and species_name in ['GRAVELER', 'GOLEM']) or
              (family_base == 'PONYTA' and species_name in ['RAPIDASH']) or
              (family_base == 'SLOWPOKE' and species_name in ['SLOWBRO', 'SLOWKING']) or
              (family_base == 'MAGNEMITE' and species_name in ['MAGNETON', 'MAGNEZONE']) or
              (family_base == 'FARFETCHD' and species_name in ['SIRFETCHD']) or
              (family_base == 'DODUO' and species_name in ['DODRIO']) or
              (family_base == 'SEEL' and species_name in ['DEWGONG']) or
              (family_base == 'GRIMER' and species_name in ['MUK']) or
              (family_base == 'SHELLDER' and species_name in ['CLOYSTER']) or
              (family_base == 'GASTLY' and species_name in ['HAUNTER', 'GENGAR']) or
              (family_base == 'ONIX' and species_name in ['STEELIX']) or
              (family_base == 'DROWZEE' and species_name in ['HYPNO']) or
              (family_base == 'KRABBY' and species_name in ['KINGLER']) or
              (family_base == 'VOLTORB' and species_name in ['ELECTRODE']) or
              (family_base == 'EXEGGCUTE' and species_name in ['EXEGGUTOR']) or
              (family_base == 'CUBONE' and species_name in ['MAROWAK']) or
              (family_base == 'LICKITUNG' and species_name in ['LICKILICKY']) or
              (family_base == 'KOFFING' and species_name in ['WEEZING']) or
              (family_base == 'RHYHORN' and species_name in ['RHYDON', 'RHYPERIOR']) or
              (family_base == 'CHANSEY' and species_name in ['HAPPINY', 'BLISSEY']) or
              (family_base == 'TANGELA' and species_name in ['TANGROWTH']) or
              (family_base == 'HORSEA' and species_name in ['SEADRA', 'KINGDRA']) or
              (family_base == 'GOLDEEN' and species_name in ['SEAKING']) or
              (family_base == 'STARYU' and species_name in ['STARMIE']) or
              (family_base == 'SCYTHER' and species_name in ['SCIZOR', 'KLEAVOR']) or
              (family_base == 'JYNX' and species_name in ['SMOOCHUM']) or
              (family_base == 'ELECTABUZZ' and species_name in ['ELEKID', 'ELECTIVIRE']) or
              (family_base == 'MAGMAR' and species_name in ['MAGBY', 'MAGMORTAR']) or
              (family_base == 'MAGIKARP' and species_name in ['GYARADOS']) or
              (family_base == 'EEVEE' and species_name in ['VAPOREON', 'JOLTEON', 'FLAREON', 'ESPEON', 'UMBREON', 'LEAFEON', 'GLACEON', 'SYLVEON']) or
              (family_base == 'PORYGON' and species_name in ['PORYGON2', 'PORYGON_Z']) or
              (family_base == 'OMANYTE' and species_name in ['OMASTAR']) or
              (family_base == 'KABUTO' and species_name in ['KABUTOPS']) or
              (family_base == 'SNORLAX' and species_name in ['MUNCHLAX']) or
              (family_base == 'DRATINI' and species_name in ['DRAGONAIR', 'DRAGONITE']) or
              # Gen 2 evolutions
              (family_base == 'CHIKORITA' and species_name in ['BAYLEEF', 'MEGANIUM']) or
              (family_base == 'CYNDAQUIL' and species_name in ['QUILAVA', 'TYPHLOSION']) or
              (family_base == 'TOTODILE' and species_name in ['CROCONAW', 'FERALIGATR']) or
              (family_base == 'SENTRET' and species_name in ['FURRET']) or
              (family_base == 'HOOTHOOT' and species_name in ['NOCTOWL']) or
              (family_base == 'LEDYBA' and species_name in ['LEDIAN']) or
              (family_base == 'SPINARAK' and species_name in ['ARIADOS']) or
              (family_base == 'CHINCHOU' and species_name in ['LANTURN']) or
              (family_base == 'TOGEPI' and species_name in ['TOGETIC', 'TOGEKISS']) or
              (family_base == 'NATU' and species_name in ['XATU']) or
              (family_base == 'MAREEP' and species_name in ['FLAAFFY', 'AMPHAROS']) or
              (family_base == 'MARILL' and species_name in ['AZURILL', 'AZUMARILL']) or
              (family_base == 'SUNKERN' and species_name in ['SUNFLORA']) or
              (family_base == 'YANMA' and species_name in ['YANMEGA']) or
              (family_base == 'WOOPER' and species_name in ['QUAGSIRE', 'CLODSIRE']) or
              (family_base == 'MURKROW' and species_name in ['HONCHKROW']) or
              (family_base == 'MISDREAVUS' and species_name in ['MISMAGIUS']) or
              (family_base == 'WOBBUFFET' and species_name in ['WYNAUT']) or
              (family_base == 'GIRAFARIG' and species_name in ['FARIGIRAF']) or
              (family_base == 'PINECO' and species_name in ['FORRETRESS']) or
              (family_base == 'DUNSPARCE' and species_name in ['DUDUNSPARCE']) or
              (family_base == 'GLIGAR' and species_name in ['GLISCOR']) or
              (family_base == 'SNUBBULL' and species_name in ['GRANBULL']) or
              (family_base == 'QWILFISH' and species_name in ['OVERQWIL']) or
              (family_base == 'SNEASEL' and species_name in ['WEAVILE', 'SNEASLER']) or
              (family_base == 'TEDDIURSA' and species_name in ['URSARING', 'URSALUNA']) or
              (family_base == 'SLUGMA' and species_name in ['MAGCARGO']) or
              (family_base == 'SWINUB' and species_name in ['PILOSWINE', 'MAMOSWINE']) or
              (family_base == 'CORSOLA' and species_name in ['CURSOLA']) or
              (family_base == 'REMORAID' and species_name in ['OCTILLERY']) or
              (family_base == 'MANTINE' and species_name in ['MANTYKE']) or
              (family_base == 'HOUNDOUR' and species_name in ['HOUNDOOM']) or
              (family_base == 'PHANPY' and species_name in ['DONPHAN']) or
              (family_base == 'STANTLER' and species_name in ['WYRDEER']) or
              (family_base == 'LARVITAR' and species_name in ['PUPITAR', 'TYRANITAR']) or
              # Gen 3 evolutions
              (family_base == 'TREECKO' and species_name in ['GROVYLE', 'SCEPTILE']) or
              (family_base == 'TORCHIC' and species_name in ['COMBUSKEN', 'BLAZIKEN']) or
              (family_base == 'MUDKIP' and species_name in ['MARSHTOMP', 'SWAMPERT']) or
              (family_base == 'POOCHYENA' and species_name in ['MIGHTYENA']) or
              (family_base == 'ZIGZAGOON' and species_name in ['LINOONE', 'OBSTAGOON']) or
              (family_base == 'WURMPLE' and species_name in ['SILCOON', 'BEAUTIFLY', 'CASCOON', 'DUSTOX']) or
              (family_base == 'LOTAD' and species_name in ['LOMBRE', 'LUDICOLO']) or
              (family_base == 'SEEDOT' and species_name in ['NUZLEAF', 'SHIFTRY']) or
              (family_base == 'TAILLOW' and species_name in ['SWELLOW']) or
              (family_base == 'WINGULL' and species_name in ['PELIPPER']) or
              (family_base == 'RALTS' and species_name in ['KIRLIA', 'GARDEVOIR', 'GALLADE']) or
              (family_base == 'SURSKIT' and species_name in ['MASQUERAIN']) or
              (family_base == 'SHROOMISH' and species_name in ['BRELOOM']) or
              (family_base == 'SLAKOTH' and species_name in ['VIGOROTH', 'SLAKING']) or
              (family_base == 'NINCADA' and species_name in ['NINJASK', 'SHEDINJA']) or
              (family_base == 'WHISMUR' and species_name in ['LOUDRED', 'EXPLOUD']) or
              (family_base == 'MAKUHITA' and species_name in ['HARIYAMA']) or
              (family_base == 'NOSEPASS' and species_name in ['PROBOPASS']) or
              (family_base == 'SKITTY' and species_name in ['DELCATTY']) or
              (family_base == 'ARON' and species_name in ['LAIRON', 'AGGRON']) or
              (family_base == 'MEDITITE' and species_name in ['MEDICHAM']) or
              (family_base == 'ELECTRIKE' and species_name in ['MANECTRIC']) or
              (family_base == 'ROSELIA' and species_name in ['BUDEW', 'ROSERADE']) or
              (family_base == 'GULPIN' and species_name in ['SWALOT']) or
              (family_base == 'CARVANHA' and species_name in ['SHARPEDO']) or
              (family_base == 'WAILMER' and species_name in ['WAILORD']) or
              (family_base == 'NUMEL' and species_name in ['CAMERUPT']) or
              (family_base == 'SPOINK' and species_name in ['GRUMPIG']) or
              (family_base == 'TRAPINCH' and species_name in ['VIBRAVA', 'FLYGON']) or
              (family_base == 'CACNEA' and species_name in ['CACTURNE']) or
              (family_base == 'SWABLU' and species_name in ['ALTARIA']) or
              (family_base == 'BARBOACH' and species_name in ['WHISCASH']) or
              (family_base == 'CORPHISH' and species_name in ['CRAWDAUNT']) or
              (family_base == 'BALTOY' and species_name in ['CLAYDOL']) or
              (family_base == 'LILEEP' and species_name in ['CRADILY']) or
              (family_base == 'ANORITH' and species_name in ['ARMALDO']) or
              (family_base == 'FEEBAS' and species_name in ['MILOTIC']) or
              (family_base == 'SHUPPET' and species_name in ['BANETTE']) or
              (family_base == 'DUSKULL' and species_name in ['DUSCLOPS', 'DUSKNOIR']) or
              (family_base == 'SNORUNT' and species_name in ['GLALIE', 'FROSLASS']) or
              (family_base == 'SPHEAL' and species_name in ['SEALEO', 'WALREIN']) or
              (family_base == 'CLAMPERL' and species_name in ['HUNTAIL', 'GOREBYSS']) or
              (family_base == 'BAGON' and species_name in ['SHELGON', 'SALAMENCE']) or
              (family_base == 'BELDUM' and species_name in ['METANG', 'METAGROSS']) or
              # Gen 4 evolutions
              (family_base == 'TURTWIG' and species_name in ['GROTLE', 'TORTERRA']) or
              (family_base == 'CHIMCHAR' and species_name in ['MONFERNO', 'INFERNAPE']) or
              (family_base == 'PIPLUP' and species_name in ['PRINPLUP', 'EMPOLEON']) or
              (family_base == 'STARLY' and species_name in ['STARAVIA', 'STARAPTOR']) or
              (family_base == 'BIDOOF' and species_name in ['BIBAREL']) or
              (family_base == 'KRICKETOT' and species_name in ['KRICKETUNE']) or
              (family_base == 'SHINX' and species_name in ['LUXIO', 'LUXRAY']) or
              (family_base == 'CRANIDOS' and species_name in ['RAMPARDOS']) or
              (family_base == 'SHIELDON' and species_name in ['BASTIODON']) or
              (family_base == 'BURMY' and species_name in ['WORMADAM', 'MOTHIM']) or
              (family_base == 'COMBEE' and species_name in ['VESPIQUEN']) or
              (family_base == 'BUIZEL' and species_name in ['FLOATZEL']) or
              (family_base == 'CHERUBI' and species_name in ['CHERRIM']) or
              (family_base == 'SHELLOS' and species_name in ['GASTRODON']) or
              (family_base == 'DRIFLOON' and species_name in ['DRIFBLIM']) or
              (family_base == 'BUNEARY' and species_name in ['LOPUNNY']) or
              (family_base == 'GLAMEOW' and species_name in ['PURUGLY']) or
              (family_base == 'STUNKY' and species_name in ['SKUNTANK']) or
              (family_base == 'BRONZOR' and species_name in ['BRONZONG']) or
              (family_base == 'GIBLE' and species_name in ['GABITE', 'GARCHOMP']) or
              (family_base == 'RIOLU' and species_name in ['LUCARIO']) or
              (family_base == 'HIPPOPOTAS' and species_name in ['HIPPOWDON']) or
              (family_base == 'SKORUPI' and species_name in ['DRAPION']) or
              (family_base == 'CROAGUNK' and species_name in ['TOXICROAK']) or
              (family_base == 'FINNEON' and species_name in ['LUMINEON']) or
              (family_base == 'SNOVER' and species_name in ['ABOMASNOW']) or
              (family_base == 'MANAPHY' and species_name in ['PHIONE'])
              ):
            return enabled_families[family_key]
    
    return "Unknown"

def parse_families_file(filename, enabled_families):
    EXCLUDE_MEGAS = True  # Update this if necessary
    EXCLUDE_GMAX = True  # Update this if necessary
    EXCLUDE_TOTEMS = True # Update this if necessary
    EXCLUDE_PIKACHUS = True  # Update this if necessary

    with open(filename, 'r', encoding='utf-8') as file:
        data = file.read()
    
    # Regular expression pattern to match each Pokémon species entry
    # This pattern now handles complex species definitions with conditional compilation
    species_pattern = re.compile(r'\[SPECIES_(\w+)\]\s*=\s*\{(.*?)\},\s*(?=\n\s*(?:\[SPECIES_|\#endif|\#if))', re.DOTALL)

    # Regular expression pattern to match mega and G-Max forms if needed
    stat_patterns = {
        'baseHP': re.compile(r'\.baseHP\s*=\s*(\d+)'),
        'baseAttack': re.compile(r'\.baseAttack\s*=\s*(\d+)'),
        'baseDefense': re.compile(r'\.baseDefense\s*=\s*(\d+)'),
        'baseSpeed': re.compile(r'\.baseSpeed\s*=\s*(\d+)'),
        'baseSpAttack': re.compile(r'\.baseSpAttack\s*=\s*(\d+)'),
        'baseSpDefense': re.compile(r'\.baseSpDefense\s*=\s*(\d+)')
    }
    type_pattern = re.compile(r'\.types\s*=\s*MON_TYPES\((TYPE_\w+)(?:,\s*(TYPE_\w+))?\)')
    growth_pattern = re.compile(r'\.growthRate\s*=\s*(GROWTH_\w+)')
    evolution_pattern = re.compile(r'\.evolutions\s*=\s*EVOLUTION\((.*?)\)', re.DOTALL)
    evolution_entry_pattern = re.compile(r'\{(EVO_\w+),\s*(\w+),\s*SPECIES_(\w+)(?:,\s*[^}]*)?\}')
    name_pattern = re.compile(r'\.speciesName\s*=\s*\_\("(.*?)"\)')
    
    parsed_data = []
    
    for match in species_pattern.finditer(data):
        species_name = match.group(1)

        if EXCLUDE_MEGAS and '_MEGA' in species_name:
            continue
        if EXCLUDE_MEGAS and '_PRIMAL' in species_name:
            continue
        if EXCLUDE_GMAX and '_GMAX' in species_name:
            continue
        if EXCLUDE_TOTEMS and '_TOTEM' in species_name:
            continue
        if EXCLUDE_PIKACHUS and 'PIKACHU_' in species_name: 
            continue
        if EXCLUDE_PIKACHUS and 'PICHU_' in species_name:
            continue

        attributes = match.group(2)
        
        stats = {key: int(stat_patterns[key].search(attributes).group(1)) if stat_patterns[key].search(attributes) else 0 for key in stat_patterns}
        stats['baseTotal'] = sum(stats.values())
        
        type_match = type_pattern.search(attributes)
        type1, type2 = type_match.groups() if type_match else ('UNKNOWN', 'UNKNOWN')
        if type2 is None:
            type2 = type1
        
        growth_match = growth_pattern.search(attributes)
        growth_rate = growth_match.group(1) if growth_match else 'UNKNOWN'
        
        evo_match = evolution_pattern.search(attributes)
        evolutions = []
        if evo_match:
            evo_entries = evo_match.group(1)
            for evo_entry in evolution_entry_pattern.finditer(evo_entries):
                evolution_method, evolution_level, evolution_species = evo_entry.groups()
                evolutions.append((evolution_method, evolution_level, evolution_species))
        else:
            evolutions.append(('NONE', '0', 'NONE'))
        
        name_match = name_pattern.search(attributes)
        display_name = name_match.group(1) if name_match else species_name.capitalize()
        
        # Get the enabled status for this species family
        enabled_status = get_species_family_status(species_name, enabled_families)
        
        for evolution in evolutions:
            evolution_method, evolution_level, evolution_species = evolution
            parsed_data.append([
                display_name, species_name, stats['baseHP'], stats['baseAttack'], stats['baseDefense'],
                stats['baseSpeed'], stats['baseSpAttack'], stats['baseSpDefense'], stats['baseTotal'],
                type1, type2, growth_rate, evolution_species, evolution_method, evolution_level, enabled_status
            ])
    
    return parsed_data

def write_to_csv(data, output_filename):
    headers = ["Display Name", "Species ID", "HP", "Attack", "Defense", "Speed", "Sp. Attack", "Sp. Defense", "Total Stats", "Type 1", "Type 2", "Growth Rate", "Evolution Species", "Evolution Method", "Evolution Level", "Enabled"]
    
    with open(output_filename, 'w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(headers)
        writer.writerows(data)

if __name__ == "__main__":
    NUM_GENS = 4  # Update this if necessary

    # Load the species enabled configuration
    config_filename = "include/config/species_enabled.h"
    enabled_families = load_species_enabled_config(config_filename)

    # Loop through each generation's files. Store individual .csvs for each generation
    for gen in range(1, NUM_GENS + 1):
        # Assuming the file naming convention is consistent
        input_filename = f"src/data/pokemon/species_info/gen_{gen}_families.h"  # Update this if necessary
        output_filename = f"gen_{gen}_pokemon_families.csv"
    
        parsed_data = parse_families_file(input_filename, enabled_families)
        write_to_csv(parsed_data, output_filename)
        print(f"Data successfully written to {output_filename}")

    # Join all matching output files to a unified .csv file with a single header
    with open('all_generations_pokemon_families.csv', 'w', newline='', encoding='utf-8') as outfile:
        headers = ["Display Name", "Species ID", "HP", "Attack", "Defense", "Speed", "Sp. Attack", "Sp. Defense", "Total Stats", "Type 1", "Type 2", "Growth Rate", "Evolution Species", "Evolution Method", "Evolution Level", "Enabled"]
        writer = csv.writer(outfile)
        writer.writerow(headers)
        
        for gen in range(1, NUM_GENS + 1):
            input_filename = f"gen_{gen}_pokemon_families.csv"
            with open(input_filename, 'r', encoding='utf-8') as infile:
                reader = csv.reader(infile)
                next(reader)  # Skip header
                for row in reader:
                    writer.writerow(row)
        print("All generations data successfully written to all_generations_pokemon_families.csv")
