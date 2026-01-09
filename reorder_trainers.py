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
        pattern = r'static const u32 sLevelCapFlagMap\[\]\[2\]\s*=\s*\{(.*?)\};'
        match = re.search(pattern, content, re.DOTALL)
        
        if match:
            array_content = match.group(1)
            # Parse each line with flag and level
            line_pattern = r'\{([^,]+),\s*([^}]+)\}'
            for line_match in re.finditer(line_pattern, array_content):
                flag = line_match.group(1).strip()
                level_raw = line_match.group(2).strip()
                
                # Handle MAX_LEVEL constant
                if level_raw == 'MAX_LEVEL':
                    level = 100  # MAX_LEVEL is defined as 100
                else:
                    try:
                        level = int(level_raw)
                    except ValueError:
                        logging.warning(f"Could not parse level value '{level_raw}', skipping entry")
                        continue
                
                level_caps.append((flag, level))
        else:
            logging.warning("Could not parse sLevelCapFlagMap from caps.c")
            return parse_level_caps('')  # Return default values
    
    logging.info(f"Parsed {len(level_caps)} level caps from {caps_file}")
    return level_caps

def get_trainer_milestone_info(trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> Tuple[int, int, int, float]:
    """Get milestone information for a trainer: (current_milestone, current_cap, next_cap, progression_percentage)"""
    try:
        trainer_index = progression_order.index(trainer_name)
    except ValueError:
        # Trainer not in progression, assume late game
        return len(level_caps) - 1, level_caps[-1][1], level_caps[-1][1], 1.0
    
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
        'TRAINER_CHAMPION_REMATCH': 20
    }
    
    # Find milestone boundary indices in progression order
    milestone_indices = []
    for milestone_trainer, milestone_idx in sorted(milestone_trainers.items(), key=lambda x: x[1]):
        if milestone_trainer in progression_order:
            milestone_trainer_idx = progression_order.index(milestone_trainer)
            milestone_indices.append((milestone_idx, milestone_trainer_idx))
    
    # Find the current milestone based on trainer position
    current_milestone = 0
    section_start_idx = 0
    section_end_idx = len(progression_order) - 1
    
    for i, (milestone_idx, milestone_trainer_idx) in enumerate(milestone_indices):
        if trainer_index <= milestone_trainer_idx:
            current_milestone = milestone_idx
            section_end_idx = milestone_trainer_idx
            # Find start of this section (previous milestone or beginning)
            if i > 0:
                section_start_idx = milestone_indices[i-1][1] + 1
            else:
                section_start_idx = 0
            break
        else:
            # Trainer is after this milestone
            section_start_idx = milestone_trainer_idx + 1
            current_milestone = milestone_idx + 1
    
    # Special handling for post-Champion trainers
    # If trainer comes after TRAINER_CHAMPION_FIRST but we haven't hit the final milestone,
    # they should be assigned to the final milestone (FLAG_SYS_GAME_CLEAR = level 100)
    champion_first_trainers = [name for name in progression_order if 'TRAINER_CHAMPION_FIRST' in name]
    if champion_first_trainers:
        champion_first_idx = max([progression_order.index(name) for name in champion_first_trainers])
        if trainer_index > champion_first_idx and current_milestone < len(level_caps) - 1:
            current_milestone = len(level_caps) - 1  # Final milestone
            section_start_idx = champion_first_idx + 1
            section_end_idx = len(progression_order) - 1
    
    # Ensure we don't exceed bounds
    current_milestone = min(current_milestone, len(level_caps) - 1)
    
    # Calculate progression percentage within current section
    if section_end_idx > section_start_idx:
        progression_percentage = (trainer_index - section_start_idx) / (section_end_idx - section_start_idx)
    else:
        progression_percentage = 1.0
    
    # Clamp percentage between 0 and 1
    progression_percentage = max(0.0, min(1.0, progression_percentage))
    
    current_cap = level_caps[current_milestone][1]
    next_cap = level_caps[min(current_milestone + 1, len(level_caps) - 1)][1]
    
    return current_milestone, current_cap, next_cap, progression_percentage

def get_party_size(trainer_name: str) -> int:
    """ Read trainers.party and return the party size for a trainer."""
    trainers_party_file = 'src/data/trainers.party'
    
    if not os.path.exists(trainers_party_file):
        logging.warning(f"Could not find {trainers_party_file}, returning default party size of 6")
        return 6  # Default party size
    
    with open(trainers_party_file, 'r') as f:
        content = f.read()
        
    # Find the trainer block
    pattern = rf'=== {trainer_name} ===\n(.*?)\n==='
    match = re.search(pattern, content, re.DOTALL)
    
    if match:
        trainer_block = match.group(1)
        # Count the number of Level: lines
        level_lines = re.findall(r'Level: \d+', trainer_block)
        return len(level_lines)

    logging.warning(f"Trainer {trainer_name} not found in {trainers_party_file}, returning default party size of 6")
    return 6  # Default party size

def is_milestone_trainer(trainer_name: str) -> bool:
    """Check if a trainer is a milestone trainer (gym leader, rival, elite four, champion)."""
    milestone_keywords = ['LEADER_', 'RIVAL_', 'ELITE_FOUR_', 'CHAMPION_', 'BOSS_GIOVANNI']
    return any(keyword in trainer_name for keyword in milestone_keywords)

def get_milestone_level_pattern(party_size: int, level_cap: int, pokemon_index: int) -> int:
    BELOW_CAP_FACTOR = 0.975
    ABOVE_CAP_FACTOR_MID = 1.025
    ABOVE_CAP_FACTOR_HIGH = 1.05
    """Get the level for a specific Pokemon in a milestone trainer's team based on position and team size."""
    if party_size == 1:
        return level_cap
    elif party_size == 2:
        # Both Pokemon at same level (level cap)
        return level_cap
    elif party_size == 3:
        # 1st: 90%, 2nd: 100%, 3rd: 110%
        if pokemon_index == 0:
            return int(level_cap * BELOW_CAP_FACTOR)  # 90% rounded down
        elif pokemon_index == 1:
            return level_cap  # 100%
        else:
            return int(level_cap * ABOVE_CAP_FACTOR_MID + 0.9)  # 110% rounded up
    elif party_size == 4:
        # 1st-2nd: 90%, 3rd: 100%, 4th: 110%
        if pokemon_index <= 1:
            return int(level_cap * BELOW_CAP_FACTOR)  # 90% rounded down
        elif pokemon_index == 2:
            return level_cap  # 100%
        else:
            return int(level_cap * ABOVE_CAP_FACTOR_MID + 0.9)  # 110% rounded up
    elif party_size == 5:
        # 1st-2nd: 90%, 3rd-4th: 100%, 5th: 110%
        if pokemon_index <= 1:
            return int(level_cap * BELOW_CAP_FACTOR)  # 90% rounded down
        elif pokemon_index <= 3:
            return level_cap  # 100%
        else:
            return int(level_cap * ABOVE_CAP_FACTOR_MID + 0.9)  # 110% rounded up
    elif party_size == 6:
        # 1st: 90%, 2nd-3rd: 100%, 4th-5th: 110%, 6th: 120%
        if pokemon_index == 0:
            return int(level_cap * BELOW_CAP_FACTOR)  # 90% rounded down
        elif pokemon_index <= 2:
            return level_cap  # 100%
        elif pokemon_index <= 4:
            return int(level_cap * ABOVE_CAP_FACTOR_MID + 0.9)  # 110% rounded up
        else:
            return int(level_cap * ABOVE_CAP_FACTOR_HIGH + 0.9)  # 120% rounded up
    else:
        # Default to level cap for unexpected team sizes
        return level_cap

def scale_trainer_level(original_level: int, trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]], pokemon_index: int = 0) -> int:
    """Scale trainer level based on their position in progression and level caps."""
    MIN_TRAINER_LEVEL = 5
    SECOND_RIVAL_LEVEL = 9
    AFTER_GYM_SCALE_DOWN = 0.15
    FIRST_TRAINER_SUBSTRING = 'TRAINER_RIVAL_OAKS_LAB'
    SECOND_RIVAL_SUBSTRING = 'TRAINER_RIVAL_ROUTE22_EARLY'
    
    milestone, current_cap, next_cap, progression_percentage = get_trainer_milestone_info(trainer_name, progression_order, level_caps)
    
    # Special handling for Oak's Lab rival - always level 5
    if FIRST_TRAINER_SUBSTRING in trainer_name:
        logging.debug(f"{trainer_name}: Oak's Lab trainer level {original_level} -> {MIN_TRAINER_LEVEL}")
        return MIN_TRAINER_LEVEL

    # Special handling for Route 22 rival - always level 9
    if SECOND_RIVAL_SUBSTRING in trainer_name:
        logging.debug(f"{trainer_name}: Route 22 rival level {original_level} -> {SECOND_RIVAL_LEVEL}")
        return SECOND_RIVAL_LEVEL

    # Check if this is a milestone trainer
    if is_milestone_trainer(trainer_name):
        party_size = get_party_size(trainer_name)
        milestone_level = get_milestone_level_pattern(party_size, current_cap, pokemon_index)
        logging.debug(f"{trainer_name}: Milestone level {original_level} -> {milestone_level} (Pokemon {pokemon_index + 1}/{party_size})")
        return milestone_level
    
    # Get party size of this trainer for non-milestone trainers
    party_size = get_party_size(trainer_name)

    # If under first milestone, don't consider previous milestone level in level scaling
    if milestone == 0:
        # Scale level based on progression percentage
        scaled_level = int(current_cap * progression_percentage)
        if scaled_level < MIN_TRAINER_LEVEL:
            scaled_level = MIN_TRAINER_LEVEL
        if party_size == 1:
            # If single Pokemon, increase level by 2
            scaled_level += 2
        logging.debug(f"{trainer_name}: Level {original_level} -> {scaled_level} (progression: {progression_percentage:.2f})")
        return scaled_level
    else:
        # Scale level based on current cap, previous cap, and progression
        previous_cap = level_caps[milestone - 1][1] if milestone > 0 else 0
        
        # Special handling for final milestone (post-Champion, level 100)
        if milestone == len(level_caps) - 1 and current_cap == 100:
            # For post-Champion trainers, scale from 75 to 85 instead of scaling all the way to 100
            lowest_level = 75
            highest_level = 85
            scaled_level = lowest_level + int((highest_level - lowest_level) * progression_percentage)
        else:
            # Normal scaling logic for other milestones
            lowest_level = previous_cap - int(AFTER_GYM_SCALE_DOWN*(current_cap - previous_cap))
            scaled_level = lowest_level + int((current_cap - lowest_level) * progression_percentage)
        
        # If party size is 1, increase level by 2
        if party_size == 1:
            scaled_level += 2
        logging.debug(f"{trainer_name}: Level {original_level} -> {scaled_level} (progression: {progression_percentage:.2f})")
        return scaled_level

def scale_trainer_ivs(original_ivs: List[int], trainer_name: str, progression_order: List[str], level_caps: List[Tuple[str, int]]) -> List[int]:
    """Scale trainer IVs based on their position in progression."""
    milestone, current_cap, next_cap, progression_percentage = get_trainer_milestone_info(trainer_name, progression_order, level_caps)
    
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
    base_max_iv = max_iv_by_milestone[milestone_idx]
    
    # Use progression percentage to gradually increase IVs throughout the section
    next_milestone_idx = min(milestone_idx + 1, len(max_iv_by_milestone) - 1)
    next_max_iv = max_iv_by_milestone[next_milestone_idx]
    
    # Interpolate between current and next milestone IV caps based on progression
    max_iv = base_max_iv + int((next_max_iv - base_max_iv) * progression_percentage)
    
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
    pokemon_index = 0
    
    for line in lines:
        if line.startswith('Level: '):
            # Parse and scale level
            original_level = int(line.split('Level: ')[1])
            scaled_level = scale_trainer_level(original_level, trainer_name, progression_order, level_caps, pokemon_index)
            if scaled_level != original_level:
                logging.debug(f"{trainer_name}: Level {original_level} -> {scaled_level}")
            output_lines.append(f'Level: {scaled_level}')
            pokemon_index += 1
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

def get_base_trainer_name(trainer_name: str) -> str:
    """Get the base trainer name without starter variant (e.g., TRAINER_RIVAL_OAKS_LAB from TRAINER_RIVAL_OAKS_LAB_SQUIRTLE)"""
    variants = ['_SQUIRTLE', '_BULBASAUR', '_CHARMANDER']
    for variant in variants:
        if trainer_name.endswith(variant):
            return trainer_name[:-len(variant)]
    return trainer_name

def get_trainer_levels_from_block(trainer_block: str) -> List[int]:
    """Extract all level values from a trainer block."""
    lines = trainer_block.split('\n')
    levels = []
    for line in lines:
        if line.startswith('Level: '):
            level = int(line.split('Level: ')[1])
            levels.append(level)
    return levels

def apply_uniform_levels_to_variants(ordered_trainers: Dict[str, str], progression_order: List[str], level_caps: List[Tuple[str, int]]) -> Dict[str, str]:
    """Ensure RIVAL and CHAMPION trainer variants have consistent level patterns."""
    FIRST_TRAINER_SUBSTRING = 'TRAINER_RIVAL_OAKS_LAB'
    SECOND_RIVAL_SUBSTRING = 'TRAINER_RIVAL_ROUTE22_EARLY'
    # Group trainers by base name
    trainer_groups = {}
    
    for trainer_name in ordered_trainers.keys():
        if 'RIVAL' in trainer_name or 'CHAMPION' in trainer_name:
            base_name = get_base_trainer_name(trainer_name)
            if base_name not in trainer_groups:
                trainer_groups[base_name] = []
            trainer_groups[base_name].append(trainer_name)
    
    # For each group with variants, establish uniform levels
    for base_name, variant_list in trainer_groups.items():
        if len(variant_list) > 1:  # Only process groups with multiple variants
            logging.info(f"Synchronizing levels for {base_name} variants: {variant_list}")
            
            # Get first variant to determine the uniform level pattern
            first_variant = variant_list[0]
            milestone, current_cap, next_cap, progression_percentage = get_trainer_milestone_info(first_variant, progression_order, level_caps)
            
            # Check if this is a milestone trainer
            if is_milestone_trainer(first_variant):
                party_size = get_party_size(first_variant)
                # Create uniform level pattern based on milestone trainer rules
                uniform_levels = []
                for pokemon_index in range(party_size):
                    if FIRST_TRAINER_SUBSTRING in first_variant:
                        # Oak's Lab rival is always level 5
                        level = 5
                    elif SECOND_RIVAL_SUBSTRING in first_variant:
                        # Route 22 rival is always level 9
                        level = 9
                    else:
                        level = get_milestone_level_pattern(party_size, current_cap, pokemon_index)
                    uniform_levels.append(level)
                logging.debug(f"  Milestone uniform levels for {base_name}: {uniform_levels}")
            else:
                # For non-milestone RIVAL/CHAMPION trainers, use original logic
                original_levels = get_trainer_levels_from_block(ordered_trainers[first_variant])
                if original_levels:
                    base_scaled_level = scale_trainer_level(original_levels[0], first_variant, progression_order, level_caps, 0)
                    
                    # Create consistent level pattern: first Pokemon at base level, others may vary slightly
                    uniform_levels = []
                    for i, original_level in enumerate(original_levels):
                        if i == 0:
                            uniform_levels.append(base_scaled_level)
                        else:
                            # Keep relative level differences but scale to new base
                            level_diff = original_levels[i] - original_levels[0]
                            uniform_levels.append(base_scaled_level + level_diff)
                    logging.debug(f"  Non-milestone uniform levels for {base_name}: {uniform_levels}")
                else:
                    continue
            
            # Apply uniform levels to all variants
            for variant_name in variant_list:
                variant_block = ordered_trainers[variant_name]
                lines = variant_block.split('\n')
                output_lines = []
                level_index = 0
                
                for line in lines:
                    if line.startswith('Level: '):
                        if level_index < len(uniform_levels):
                            new_level = uniform_levels[level_index]
                            original_level = int(line.split('Level: ')[1])
                            if new_level != original_level:
                                logging.debug(f"  {variant_name}: Level {original_level} -> {new_level} (Pokemon {level_index + 1})")
                            output_lines.append(f'Level: {new_level}')
                            level_index += 1
                        else:
                            output_lines.append(line)
                    elif line.startswith('IVs: '):
                        # Still apply IV scaling
                        iv_part = line.split('IVs: ')[1]
                        iv_matches = re.findall(r'(\d+) \w+', iv_part)
                        original_ivs = [int(iv) for iv in iv_matches]
                        scaled_ivs = scale_trainer_ivs(original_ivs, variant_name, progression_order, level_caps)
                        
                        iv_labels = ['HP', 'Atk', 'Def', 'SpA', 'SpD', 'Spe']
                        iv_string = ' / '.join([f'{iv} {label}' for iv, label in zip(scaled_ivs, iv_labels)])
                        if scaled_ivs != original_ivs:
                            logging.debug(f"  {variant_name}: IVs {original_ivs} -> {scaled_ivs}")
                        output_lines.append(f'IVs: {iv_string}')
                    else:
                        output_lines.append(line)
                
                ordered_trainers[variant_name] = '\n'.join(output_lines)
    
    return ordered_trainers

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
        
        # First, apply uniform levels to RIVAL and CHAMPION variants
        ordered_trainers = apply_uniform_levels_to_variants(ordered_trainers, progression_order, level_caps)
    
    with open(filename, 'w') as f:
        for trainer_name, trainer_block in ordered_trainers.items():
            if scale_levels and trainer_name != 'TRAINER_NONE' and 'RIVAL' not in trainer_name and 'CHAMPION' not in trainer_name:
                # Scale non-rival/champion trainers normally
                scaled_block = parse_and_scale_trainer_block(trainer_block, trainer_name, progression_order, level_caps)
                f.write(scaled_block)
            else:
                # RIVAL/CHAMPION trainers already processed, or scaling disabled
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