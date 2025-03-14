import re
import csv

def parse_families_file(filename):
    EXCLUDE_MEGAS = True  # Update this if necessary
    EXCLUDE_GMAX = True  # Update this if necessary
    EXCLUDE_TOTEMS = True # Update this if necessary
    EXCLUDE_PIKACHUS = True  # Update this if necessary

    with open(filename, 'r', encoding='utf-8') as file:
        data = file.read()
    
    # Regular expression pattern to match each Pokémon species entry
    species_pattern = re.compile(r'\[SPECIES_(\w+)\]\s*=\s*{(.*?),\n\s*},\n', re.DOTALL)

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
    evolution_entry_pattern = re.compile(r'\{(EVO_\w+),\s*(\w+),\s*SPECIES_(\w+)\}')
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
        
        for evolution in evolutions:
            evolution_method, evolution_level, evolution_species = evolution
            parsed_data.append([
                display_name, species_name, stats['baseHP'], stats['baseAttack'], stats['baseDefense'],
                stats['baseSpeed'], stats['baseSpAttack'], stats['baseSpDefense'], stats['baseTotal'],
                type1, type2, growth_rate, evolution_species, evolution_method, evolution_level
            ])
    
    return parsed_data

def write_to_csv(data, output_filename):
    headers = ["Display Name", "Species ID", "HP", "Attack", "Defense", "Speed", "Sp. Attack", "Sp. Defense", "Total Stats", "Type 1", "Type 2", "Growth Rate", "Evolution Species", "Evolution Method", "Evolution Level"]
    
    with open(output_filename, 'w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(headers)
        writer.writerows(data)

if __name__ == "__main__":
    NUM_GENS = 4  # Update this if necessary

    # Loop through each generation's files. Store individual .csvs for each generation
    for gen in range(1, NUM_GENS + 1):
        # Assuming the file naming convention is consistent
        input_filename = f"src/data/pokemon/species_info/gen_{gen}_families.h"  # Update this if necessary
        output_filename = f"gen_{gen}_pokemon_families.csv"
    
        parsed_data = parse_families_file(input_filename)
        write_to_csv(parsed_data, output_filename)
        print(f"Data successfully written to {output_filename}")

    # Join all matching output files to a unified .csv file with a single header
    with open('all_generations_pokemon_families.csv', 'w', newline='', encoding='utf-8') as outfile:
        headers = ["Display Name", "Species ID", "HP", "Attack", "Defense", "Speed", "Sp. Attack", "Sp. Defense", "Total Stats", "Type 1", "Type 2", "Growth Rate", "Evolution Species", "Evolution Method", "Evolution Level"]
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
