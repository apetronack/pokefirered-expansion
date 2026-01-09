import pandas as pd

# Import .csv files
pokemon_families = pd.read_csv('all_generations_pokemon_families.csv')
pokemon_encounters = pd.read_csv('pokemon_encounters.csv')

# pokemon_encounters should have a column for 'species'
# pokemon_families should have columns 'Species ID' and 'Enabled'

# First, find all species in pokemon_encounters that are not in pokemon_families
encountered_species = set(pokemon_encounters['species'].unique())
family_species = set(pokemon_families['Species ID'].unique())
# Cherrim has two forms in family_species that look like CHERRIM_XXX and CHERRIM_YYY. Only care about the "CHERRIM" part. Only applies to Cherrim, not others.
family_species = {species if not species.startswith('CHERRIM_') else 'CHERRIM' for species in family_species}
# encountered_species has 'SPECIES_' prefix, so we need to strip that for comparison
encountered_species = {species.replace('SPECIES_', '') for species in encountered_species}
missing_species = encountered_species - family_species
print(f"Missing species IDs: {missing_species}")

# Next, find any species in pokemon_encounters that are marked as not enabled in pokemon_families
disabled_species = pokemon_families[pokemon_families['Enabled'] == 'False']['Species ID'].unique()
disabled_in_encounters = encountered_species.intersection(disabled_species)
print(f"Disabled species IDs in encounters: {disabled_in_encounters}")

# Next, find species in pokemon_families that are enabled but not in pokemon_encounters
enabled_species = pokemon_families[pokemon_families['Enabled'] == 'True']['Species ID'].unique()
enabled_not_in_encounters = set(enabled_species) - encountered_species
print(f"Enabled species IDs not in encounters: {enabled_not_in_encounters}")

# Summary of findings
print(f"Total missing species: {len(missing_species)}")
print(f"Total disabled species in encounters: {len(disabled_in_encounters)}")
print(f"Total enabled species not in encounters: {len(enabled_not_in_encounters)}")

# Export results to CSV for further analysis if needed
pd.DataFrame(list(missing_species), columns=['Missing Species ID']).to_csv('missing_species.csv', index=False)
pd.DataFrame(list(disabled_in_encounters), columns=['Disabled Species ID in Encounters']).to_csv('disabled_species_in_encounters.csv', index=False)
pd.DataFrame(list(enabled_not_in_encounters), columns=['Enabled Species ID not in Encounters']).to_csv('enabled_species_not_in_encounters.csv', index=False)