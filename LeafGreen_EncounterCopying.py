import json
import copy

with open("src/data/wild_encounters.json", "r") as f:
    full_data = json.load(f)
    data = full_data["wild_encounter_groups"][0]["encounters"]


# Build lookup map by base_label
entries_by_label = {entry["base_label"]: entry for entry in data}

new_data = []
labels_to_skip = set()
processed_labels = set()  # Track all labels we've already added

for entry in data:
    label = entry["base_label"]
    
    # Skip if we've already processed this label (removes duplicates)
    if label in processed_labels:
        continue
    
    if label.endswith("_FireRed"):
        # Compute FireRed label
        leaf_label = label.replace("_FireRed", "_LeafGreen")

        # Create the replacement LeafGreen entry
        replacement = copy.deepcopy(entry)
        replacement["base_label"] = leaf_label

        # Mark the LeafGreen label to skip later (to avoid duplicates)
        labels_to_skip.add(leaf_label)

        # Save the replacement (it will overwrite old ones)
        if leaf_label not in processed_labels:
            new_data.append(replacement)
            processed_labels.add(leaf_label)

        # Also keep the FireRed entry
        new_data.append(entry)
        processed_labels.add(label)

    # For non-FireRed entries:
    else:
        # Skip existing LeafGreen entries only if replaced
        if entry["base_label"] in labels_to_skip:
            continue

        # new_data.append(entry)
        # processed_labels.add(label)

# Save result
full_data["wild_encounter_groups"][0]["encounters"] = new_data
with open("encounters_updated.json", "w") as f:
    json.dump(full_data, f, indent=2)

print("LeafGreen entries overwritten using FireRed counterparts.")
