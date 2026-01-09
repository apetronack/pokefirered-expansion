#!/usr/bin/env python3
import re
import os

def parse_trainers_party(filename):
    """Parse trainers.party and return a list of (trainer_name, block_lines)."""
    trainers = []
    current_trainer = None
    current_block = []
    with open(filename, 'r', encoding='utf-8') as f:
        for line in f:
            if line.startswith('=== ') and line.rstrip().endswith(' ==='):
                if current_trainer is not None:
                    trainers.append((current_trainer, current_block))
                current_trainer = line.replace('===', '').strip()
                current_block = [line]
            else:
                if current_trainer is not None:
                    current_block.append(line)
        if current_trainer is not None:
            trainers.append((current_trainer, current_block))
    return trainers

def adjust_ivs(trainers):
    """Adjust IVs for each trainer's party members, scaling from 0 to 31 uniformly."""
    n = len(trainers)
    adjusted_trainers = []
    for idx, (trainer_name, block_lines) in enumerate(trainers):
        # Calculate IV value for this trainer
        if n == 1:
            iv = 0
        else:
            iv = round(idx * 31 / (n - 1))
        new_block = []
        for line in block_lines:
            if re.match(r'IVs: ', line):
                new_block.append(f'IVs: {iv} HP / {iv} Atk / {iv} Def / {iv} SpA / {iv} SpD / {iv} Spe\n')
            else:
                new_block.append(line)
        adjusted_trainers.append((trainer_name, new_block))
    return adjusted_trainers

def write_adjusted_trainers(filename, adjusted_trainers):
    with open(filename, 'w', encoding='utf-8') as f:
        for trainer_name, block_lines in adjusted_trainers:
            for line in block_lines:
                f.write(line)

def main():
    input_file = 'src/data/trainers.party'
    output_file = 'IV_adjusted_trainers.party'
    trainers = parse_trainers_party(input_file)

    # Only consider trainers up to and including TRAINER_CHAMPION_REMATCH_CHARMANDER for IV scaling
    cutoff_name = 'TRAINER_CHAMPION_REMATCH_CHARMANDER'
    cutoff_index = None
    for idx, (trainer_name, _) in enumerate(trainers):
        if cutoff_name in trainer_name:
            cutoff_index = idx
            break
    if cutoff_index is not None:
        trainers_to_scale = trainers[:cutoff_index + 1]
        trainers_to_leave = trainers[cutoff_index + 1:]
    else:
        trainers_to_scale = trainers
        trainers_to_leave = []

    adjusted_trainers = adjust_ivs(trainers_to_scale)
    # Append the unmodified trainers after the cutoff
    adjusted_trainers.extend(trainers_to_leave)
    write_adjusted_trainers(output_file, adjusted_trainers)
    print(f'Wrote adjusted trainers to {output_file}')

if __name__ == '__main__':
    main()
