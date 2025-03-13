import re
import csv

def preprocess_description(description_lines):
    """Handles multi-line descriptions and #if/#else directives."""
    description = " ".join(description_lines).replace('\n', ' ')
    # Handling #if and #else within descriptions
    description = re.sub(r'#if .*?\n(.*?)#else\n(.*?)#endif', r'\1/\2', description, flags=re.DOTALL)
    return description.strip()

def parse_moves_info(header_file, output_csv):
    with open(header_file, 'r', encoding='utf-8') as file:
        content = file.read()
    
    # Regex pattern to match move entries
    move_pattern = re.compile(r'\[MOVE_(\w+)]\s*=\s*{(.*?)}', re.DOTALL)
    field_pattern = re.compile(r'\.(\w+)\s*=\s*(.*?),\n', re.DOTALL)
    
    moves = []
    for match in move_pattern.finditer(content):
        move_name = match.group(1)
        fields_text = match.group(2)
        fields = dict(field_pattern.findall(fields_text))
        
        move_data = {
            'name': re.sub(r'COMPOUND_STRING\("(.*?)"\)', r'\1', fields.get('name', '')),  # Extract name
            'effect': fields.get('effect', ''),
            'power': fields.get('power', '0'),
            'type': fields.get('type', ''),
            'accuracy': fields.get('accuracy', '0'),
            'pp': fields.get('pp', '0'),
            'target': fields.get('target', ''),
            'priority': fields.get('priority', '0'),
            'category': fields.get('category', ''),
            'additional_effects': fields.get('additionalEffects', '').strip(),
        }
        
        # Extract multi-line description handling #if/#else
        description_match = re.findall(r'\.description\s*=\s*COMPOUND_STRING\((.*?)\),\n', fields_text, re.DOTALL)
        if description_match:
            move_data['description'] = preprocess_description(description_match)
        else:
            move_data['description'] = ''
        
        moves.append(move_data)
    
    # Write to CSV
    with open(output_csv, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['name', 'effect', 'power', 'type', 'accuracy', 'pp', 'target', 'priority', 'category', 'additional_effects', 'description']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(moves)

# Example usage
parse_moves_info('src/data/moves_info.h', 'moves_data.csv')
