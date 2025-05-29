#!/usr/bin/env python3

import re
import os
import logging
from typing import Dict, List, Set
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

def write_reordered_trainers(filename: str, ordered_trainers: Dict[str, str]):
    """Write reordered trainers back to trainers.party."""
    logging.info(f"Writing {len(ordered_trainers)} trainers to {filename}")
    with open(filename, 'w') as f:
        for trainer, block in ordered_trainers.items():
            f.write(block)

def main():
    try:
        # Setup logging
        log_file = setup_logging()
        logging.info("Starting trainer reordering process")
        logging.info(f"Log file: {log_file}")
        
        # Parse progression tracking
        logging.info("Reading Progression Tracking.txt...")
        progression_order = parse_progression_tracking('Progression Tracking.txt')
        logging.info(f"Found {len(progression_order)} trainers in progression")
        
        # Parse trainers.party
        trainers = parse_trainers_party('src/data/trainers.party')
        
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
        
        # Write back to file
        write_reordered_trainers('src/data/updated_trainers.party', reordered)
        logging.info("Done!")
        
    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        logging.error(f"Current working directory: {os.getcwd()}")
        raise

if __name__ == '__main__':
    main() 