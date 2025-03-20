import json
import csv

def load_json(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        return json.load(f)

def extract_encounters(data):
    encounter_groups = data.get("wild_encounter_groups", [])
    extracted_data = []
    
    for group in encounter_groups:
        encounter_headers = {field["type"]: field["encounter_rates"] for field in group.get("fields", [])}
        fishing_groups = next((field.get("groups", {}) for field in group.get("fields", []) if field["type"] == "fishing_mons"), {})
        
        for encounter in group.get("encounters", []):
            map_name = encounter.get("map", "Unknown")
            base_label = encounter.get("base_label", "Unknown")
            # Check if "LeafGreen" is in the base_label. If so, skip this encounter
            if "LeafGreen" in base_label:
                continue
            
            for encounter_type, header_rates in encounter_headers.items():
                if encounter_type in encounter:
                    encounter_rate = encounter[encounter_type].get("encounter_rate", 0)
                    mons = encounter[encounter_type].get("mons", [])
                    
                    if encounter_type == "fishing_mons":
                        for rod_type, indices in fishing_groups.items():
                            for i in indices:
                                if i < len(mons):
                                    mon = mons[i]
                                    species = mon.get("species", "Unknown")
                                    min_level = mon.get("min_level", "?")
                                    max_level = mon.get("max_level", "?")
                                    rate = header_rates[i] if i < len(header_rates) else "Unknown"
                                    
                                    extracted_data.append({
                                        "map": map_name,
                                        "species": species,
                                        "min_level": min_level,
                                        "max_level": max_level,
                                        "encounter_type": f"{encounter_type}_{rod_type}",
                                        "encounter_rate": rate
                                    })
                    else:
                        for i, mon in enumerate(mons):
                            species = mon.get("species", "Unknown")
                            min_level = mon.get("min_level", "?")
                            max_level = mon.get("max_level", "?")
                            rate = header_rates[i] if i < len(header_rates) else "Unknown"
                            
                            extracted_data.append({
                                "map": map_name,
                                "species": species,
                                "min_level": min_level,
                                "max_level": max_level,
                                "encounter_type": encounter_type,
                                "encounter_rate": rate
                            })

    # Now that we have all the data, join any duplicate species per map, min level, max level, and encounter type for encounter rate
    combined_data = {}
    for entry in extracted_data:
        key = (entry["map"], entry["species"], entry["min_level"], entry["max_level"], entry["encounter_type"])
        if key not in combined_data:
            combined_data[key] = entry["encounter_rate"]
        else:
            combined_data[key] = str(int(combined_data[key]) + int(entry["encounter_rate"]))

    # Convert combined data back to list of dictionaries
    extracted_data = []
    for (map_name, species, min_level, max_level, encounter_type), encounter_rate in combined_data.items():
        extracted_data.append({
            "map": map_name,
            "species": species,
            "min_level": min_level,
            "max_level": max_level,
            "encounter_type": encounter_type,
            "encounter_rate": encounter_rate
        })
        
    return extracted_data

def save_to_csv(encounters, output_file):
    fieldnames = ["map", "species", "min_level", "max_level", "encounter_type", "encounter_rate"]
    with open(output_file, "w", newline="", encoding="utf-8") as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(encounters)

def main():
    file_path = "src/data/wild_encounters.json"  # Change this to the actual JSON file path
    output_file = "pokemon_encounters.csv"  # Output CSV file
    
    data = load_json(file_path)
    encounters = extract_encounters(data)
    save_to_csv(encounters, output_file)
    
    print(f"Encounters saved to {output_file}")

if __name__ == "__main__":
    main()
