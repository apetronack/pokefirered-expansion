import re
import csv

def parse_families_file(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        data = file.read()
    
    # Regular expression pattern to match each Pokémon species entry
    species_pattern = re.compile(r'\[SPECIES_(\w+)\]\s*=\s*{(.*?),\n\s*},\n', re.DOTALL)
    
    # Regular expression patterns to extract specific attributes
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
    evolution_pattern = re.compile(r'\.evolutions\s*=\s*EVOLUTION\({(EVO_\w+),\s*(\w+),\s*SPECIES_(\w+)}\)')
    name_pattern = re.compile(r'\.speciesName\s*=\s*\_\("(.*?)"\)')
    
    parsed_data = []
    
    for match in species_pattern.finditer(data):
        species_name = match.group(1)
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
        evolution_method, evolution_level, evolution_species = evo_match.groups() if evo_match else ('NONE', '0', 'NONE')
        
        name_match = name_pattern.search(attributes)
        display_name = name_match.group(1) if name_match else species_name.capitalize()
        
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
    input_filename = "src/data/pokemon/species_info/gen_4_families.h"  # Update this if necessary
    output_filename = "gen_4_pokemon_families.csv"
    
    parsed_data = parse_families_file(input_filename)
    write_to_csv(parsed_data, output_filename)
    print(f"Data successfully written to {output_filename}")
