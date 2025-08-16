#!/usr/bin/env python3

import re
import os
import logging
import math
import argparse
from typing import Dict, List, Set, Tuple, Optional
from datetime import datetime

def setup_logging():
    """Setup logging configuration"""
    timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
    log_file = f'reorder_trainers_{timestamp}.log'
    
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s - %(levelname)s - %(message)s',
        handlers=[
            logging.FileHandler(log_file),
            logging.StreamHandler()  # Also keep console output
        ]
    )
    return log_file

def parse_level_caps(caps_file: str = 'src/caps.c') -> List[Tuple[str, int]]:
    """Parse level caps from caps.c sLevelCapFlagMap."""
    if not os.path.exists(caps_file):
        logging.warning(f"Could not find {caps_file}, using default level caps")
        return [
            ('FLAG_BADGE01_GET', 13),
            ('FLAG_GOT_FAME_CHECKER', 20),
            ('FLAG_BADGE02_GET', 23),
            ('FLAG_BEAT_RIVAL_3', 25),
            ('FLAG_BADGE03_GET', 27),
            ('FLAG_HIDE_CELADON_ROCKETS', 33),
            ('FLAG_BEAT_RIVAL_4', 35),
            ('FLAG_BADGE04_GET', 38),
            ('FLAG_BEAT_RIVAL_5', 43),
            ('FLAG_HIDE_SAFFRON_ROCKETS', 47),
            ('FLAG_BADGE05_GET', 52),
            ('FLAG_BADGE06_GET', 55),
            ('FLAG_BADGE07_GET', 59),
            ('FLAG_BADGE08_GET', 62),
            ('FLAG_BEAT_RIVAL_6', 65),
            ('FLAG_DEFEATED_LORELEI_1X', 72),
            ('FLAG_DEFEATED_BRUNO_1X', 73),
            ('FLAG_DEFEATED_AGATHA_1X', 74),
            ('FLAG_DEFEATED_LANCE_1X', 75),
            ('FLAG_DEFEATED_CHAMP_1X', 78),
            ('FLAG_SYS_GAME_CLEAR', 100)
        ]
    
    level_caps = []
    
    with open(caps_file, 'r') as f:
        content = f.read()
        
        # Find the sLevelCapFlagMap array
        pattern = r'static const u32 sLevelCapFlagMap\[\]\[2\]\s*=\s*\{([^}]+)\}\;'
        match = re.search(pattern, content, re.DOTALL)
        
        if match:
            array_content = match.group(1)
            # Parse each line with flag and level
            line_pattern = r'\{([^,]+),\s*(\d+)\}'
            for line_match in re.finditer(line_pattern, array_content):
                flag = line_match.group(1).strip()
                level = int(line_match.group(2))
                level_caps.append((flag, level))
        else:
            logging.warning("Could not parse sLevelCapFlagMap from caps.c")
            return parse_level_caps('')  # Return default values
    
    logging.info(f"Parsed {len(level_caps)} level caps from {caps_file}")
    return level_caps

def get_trainer_milestone_info(trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> Tuple[int, int, int]:
    """Get milestone information for a trainer: (current_milestone, current_cap, next_cap)"""
    try:
        trainer_index = progression_order.index(trainer_name)
    except ValueError:
        # Trainer not in progression, assume late game
        return len(level_caps) - 1, level_caps[-1][1], level_caps[-1][1]
    
    # Map gym leaders and key trainers to milestone indices
    milestone_trainers = {
        'TRAINER_LEADER_BROCK': 0,
        'TRAINER_RIVAL_CERULEAN_SQUIRTLE': 1,
        'TRAINER_RIVAL_CERULEAN_BULBASAUR': 1,
        'TRAINER_RIVAL_CERULEAN_CHARMANDER': 1,
        'TRAINER_LEADER_MISTY': 2,
        'TRAINER_RIVAL_SS_ANNE_SQUIRTLE': 3,
        'TRAINER_RIVAL_SS_ANNE_BULBASAUR': 3,
        'TRAINER_RIVAL_SS_ANNE_CHARMANDER': 3,
        'TRAINER_LEADER_LT_SURGE': 4,
        'TRAINER_BOSS_GIOVANNI': 5,
        'TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE': 6,
        'TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR': 6,
        'TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER': 6,
        'TRAINER_LEADER_ERIKA': 7,
        'TRAINER_RIVAL_SILPH_SQUIRTLE': 8,
        'TRAINER_RIVAL_SILPH_BULBASAUR': 8,
        'TRAINER_RIVAL_SILPH_CHARMANDER': 8,
        'TRAINER_BOSS_GIOVANNI_2': 9,
        'TRAINER_LEADER_SABRINA': 10,
        'TRAINER_LEADER_KOGA': 11,
        'TRAINER_LEADER_BLAINE': 12,
        'TRAINER_LEADER_GIOVANNI': 13,
        'TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE': 14,
        'TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR': 14,
        'TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER': 14,
        'TRAINER_ELITE_FOUR_LORELEI': 15,
        'TRAINER_ELITE_FOUR_BRUNO': 16,
        'TRAINER_ELITE_FOUR_AGATHA': 17,
        'TRAINER_ELITE_FOUR_LANCE': 18,
        'TRAINER_CHAMPION_FIRST': 19,
    }
    
    # Find the current milestone
    current_milestone = 0
    for milestone_trainer, milestone_idx in milestone_trainers.items():
        if milestone_trainer in progression_order:
            milestone_trainer_idx = progression_order.index(milestone_trainer)
            if trainer_index <= milestone_trainer_idx:
                current_milestone = milestone_idx
                break
        if milestone_idx > current_milestone:
            current_milestone = milestone_idx
    
    # Ensure we don't exceed bounds
    current_milestone = min(current_milestone, len(level_caps) - 1)
    
    current_cap = level_caps[current_milestone][1]
    next_cap = level_caps[min(current_milestone + 1, len(level_caps) - 1)][1]
    
    return current_milestone, current_cap, next_cap

def scale_trainer_level(original_level: int, trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> int:
    """Scale trainer level based on their position in progression and level caps."""
    milestone, current_cap, next_cap = get_trainer_milestone_info(trainer_name, progression_order, level_caps)
    
    # If trainer is already within current cap, don't change
    if original_level <= current_cap:
        return original_level
    
    # Scale down to current cap, with some variance
    if original_level > current_cap + 5:
        # Significantly over cap, scale to cap
        return current_cap
    else:
        # Slightly over cap, scale proportionally
        return min(original_level, current_cap + 2)

def scale_trainer_ivs(original_ivs: List[int], trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> List[int]:
    """Scale trainer IVs based on their position in progression."""
    milestone, current_cap, next_cap = get_trainer_milestone_info(trainer_name, progression_order, level_caps)
    
    # IV scaling based on progression
    # Early game: 0-5 IVs
    # Mid game: 5-15 IVs  
    # Late game: 15-31 IVs
    
    max_iv_by_milestone = [
        5,   # Brock
        5,   # Rival Cerulean
        7,   # Misty
        7,   # Rival SS Anne
        10,  # Lt. Surge
        12,  # Giovanni 1
        12,  # Rival Pokemon Tower
        15,  # Erika
        18,  # Rival Silph
        18,  # Giovanni 2
        20,  # Sabrina
        22,  # Koga
        25,  # Blaine
        25,  # Giovanni 3
        27,  # Rival Route 22 Late
        30,  # Elite Four Lorelei
        30,  # Elite Four Bruno
        30,  # Elite Four Agatha
        31,  # Elite Four Lance
        31,  # Champion
        31   # Post-game
    ]
    
    milestone_idx = min(milestone, len(max_iv_by_milestone) - 1)
    max_iv = max_iv_by_milestone[milestone_idx]
    
    # Scale existing IVs proportionally, but don't reduce them below current values
    scaled_ivs = []
    for iv in original_ivs:
        scaled_iv = max(iv, min(max_iv, iv + (milestone_idx * 2)))
        scaled_ivs.append(scaled_iv)
    
    return scaled_ivs

def parse_and_scale_trainer_block(trainer_block: str, trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> str:
    """Parse a trainer block and scale levels and IVs appropriately."""
    lines = trainer_block.split('\n')
    output_lines = []
    
    for line in lines:
        if line.startswith('Level: '):
            # Parse and scale level
            original_level = int(line.split('Level: ')[1])
            scaled_level = scale_trainer_level(original_level, trainer_name, progression_order, level_caps)
            if scaled_level != original_level:
                logging.debug(f"{trainer_name}: Level {original_level} -> {scaled_level}")
            output_lines.append(f'Level: {scaled_level}')
        elif line.startswith('IVs: '):
            # Parse and scale IVs
            iv_part = line.split('IVs: ')[1]
            # Parse IVs like "1 HP / 1 Atk / 1 Def / 1 SpA / 1 SpD / 1 Spe"
            iv_matches = re.findall(r'(\d+) \w+', iv_part)
            original_ivs = [int(iv) for iv in iv_matches]
            scaled_ivs = scale_trainer_ivs(original_ivs, trainer_name, progression_order, level_caps)
            
            # Reconstruct IV line
            iv_labels = ['HP', 'Atk', 'Def', 'SpA', 'SpD', 'Spe']
            iv_string = ' / '.join([f'{iv} {label}' for iv, label in zip(scaled_ivs, iv_labels)])
            if scaled_ivs != original_ivs:
                logging.debug(f"{trainer_name}: IVs {original_ivs} -> {scaled_ivs}")
            output_lines.append(f'IVs: {iv_string}')
        else:
            output_lines.append(line)
    
    return '\n'.join(output_lines)

def parse_progression_tracking(filename: str) -> List[str]:
    """Parse Progression Tracking.txt and return ordered list of trainer constants."""
    if not os.path.exists(filename):
        raise FileNotFoundError(f"Could not find {filename}")
        
    trainer_order = []
    with open(filename, 'r') as f:
        for line in f:
            # Look for TRAINER_ constants
            if 'TRAINER_' in line:
                # Handle trainer variants (e.g. SQUIRTLE/BULBASAUR/CHARMANDER)
                # Grab just the trainer portion of the name (contains TRAINER_ and no newline characters)   
                line_contents = line.strip().split(' ')
                # Find the portion of the line that contains TRAINER_
                trainer = [item for item in line_contents if 'TRAINER_' in item][0]
                if '/' in trainer:
                    base_trainer = trainer.strip().split('/')[0].strip()
                    # First variant defined by last portion of trainer name separated by underscore
                    # ex: TRAINER_RIVAL_OAKS_LAB_SQUIRTLE -> base is TRAINER_RIVAL_OAKS_LAB, variant is SQUIRTLE
                    base_trainer_parts = base_trainer.strip().split('_')
                    base_trainer = '_'.join(base_trainer_parts[:-1])
                    first_variant = base_trainer_parts[-1]
                    other_variants = trainer.strip().split('/')[1:]
                    variants = [base_trainer + '_' + first_variant]
                    variants.extend([base_trainer + '_' + variant for variant in other_variants])
                    trainer_order.extend(variants)
                else:
                    trainer = line.strip()
                    trainer_order.append(trainer)
    
    # Remove any duplicates while preserving order
    seen = set()
    return [x for x in trainer_order if not (x in seen or seen.add(x))]

def parse_trainers_party(filename: str) -> Dict[str, str]:
    """Parse trainers.party and return dict of trainer constant to trainer block."""
    if not os.path.exists(filename):
        raise FileNotFoundError(f"Could not find {filename}")
        
    trainers = {}
    current_trainer = None
    current_block = []
    
    logging.info(f"Reading trainers from {filename}")
    with open(filename, 'r') as f:
        for line_num, line in enumerate(f, 1):
            if line.startswith('=== ') and line.endswith(' ===\n'):
                # Save previous trainer block if exists
                if current_trainer:
                    trainers[current_trainer] = ''.join(current_block)
                
                # Start new trainer block
                current_trainer = line.replace('===', '').strip()
                current_block = [line]
                logging.debug(f"Found trainer at line {line_num}: {current_trainer}")
            else:
                if current_trainer:
                    current_block.append(line)
    
    # Save last trainer block
    if current_trainer:
        trainers[current_trainer] = ''.join(current_block)
    
    logging.info(f"Found {len(trainers)} trainers total")
    return trainers

def write_reordered_trainers(filename: str, ordered_trainers: Dict[str, str], progression_order: List[str], level_caps: List[Tuple[str, int]], scale_levels: bool = True):
    """Write reordered trainers back to trainers.party, optionally scaling levels and IVs."""
    logging.info(f"Writing {len(ordered_trainers)} trainers to {filename}")
    
    if scale_levels:
        logging.info("Scaling trainer levels and IVs based on progression")
    
    with open(filename, 'w') as f:
        for trainer_name, trainer_block in ordered_trainers.items():
            if scale_levels and trainer_name != 'TRAINER_NONE':
                # Scale the trainer's levels and IVs
                scaled_block = parse_and_scale_trainer_block(trainer_block, trainer_name, progression_order, level_caps)
                f.write(scaled_block)
            else:
                f.write(trainer_block)

def main():
    parser = argparse.ArgumentParser(description='Reorder trainers and optionally scale levels/IVs based on progression')
    parser.add_argument('--no-scaling', action='store_true', help='Disable level and IV scaling')
    parser.add_argument('--output', default='src/data/updated_trainers.party', help='Output file path')
    parser.add_argument('--progression', default='Progression Tracking.txt', help='Progression tracking file')
    parser.add_argument('--trainers', default='src/data/trainers.party', help='Trainers party file')
    parser.add_argument('--caps', default='src/caps.c', help='Caps file with level cap definitions')
    
    args = parser.parse_args()
    
    try:
        # Setup logging
        log_file = setup_logging()
        logging.info("Starting trainer reordering and scaling process")
        logging.info(f"Log file: {log_file}")
        logging.info(f"Level/IV scaling: {'Disabled' if args.no_scaling else 'Enabled'}")
        
        # Parse level caps from caps.c
        if not args.no_scaling:
            logging.info(f"Parsing level caps from {args.caps}...")
            level_caps = parse_level_caps(args.caps)
            logging.info(f"Using {len(level_caps)} level cap milestones")
            for flag, cap in level_caps:
                logging.debug(f"  {flag}: Level {cap}")
        else:
            level_caps = []
        
        # Parse progression tracking
        logging.info(f"Reading {args.progression}...")
        progression_order = parse_progression_tracking(args.progression)
        logging.info(f"Found {len(progression_order)} trainers in progression")
        
        # Parse trainers.party
        trainers = parse_trainers_party(args.trainers)
        
        # Create reordered dict
        reordered = {}
        
        # Always put TRAINER_NONE first if it exists
        if 'TRAINER_NONE' in trainers:
            logging.info("Found TRAINER_NONE, placing at start")
            reordered['TRAINER_NONE'] = trainers.pop('TRAINER_NONE')
        else:
            logging.warning("TRAINER_NONE not found in trainers.party")
        
        # Add trainers in progression order
        logging.info("Reordering trainers based on progression...")
        for trainer in progression_order:
            if trainer in trainers:
                reordered[trainer] = trainers.pop(trainer)
                logging.debug(f"Placed {trainer}")
            else:
                logging.warning(f"{trainer} from progression not found in trainers.party")
        
        # Add remaining trainers at the end
        logging.info(f"Adding {len(trainers)} remaining trainers at the end")
        for trainer in sorted(trainers.keys()):
            reordered[trainer] = trainers[trainer]
        
        # Write back to file with optional scaling
        scale_levels = not args.no_scaling
        write_reordered_trainers(args.output, reordered, progression_order, level_caps, scale_levels=scale_levels)
        logging.info("Done!")
        
    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        logging.error(f"Current working directory: {os.getcwd()}")
        raise

if __name__ == '__main__':
    main() 