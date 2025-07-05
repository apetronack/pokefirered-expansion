import re
import textwrap

INPUT_FILE = "src/data/moves_info.h"
OUTPUT_FILE = "updated_moves_info.h"
FLAGGED_FILE = "flagged_moves.txt"
MAX_LINE_LEN = 19
MAX_LINES = 4

def reflow_description(desc):
    # Remove existing line breaks and extra spaces
    desc = desc.replace('\n', ' ').replace('\r', ' ')
    desc = re.sub(r'\s+', ' ', desc).strip()
    # Try to wrap
    wrapped = textwrap.wrap(desc, width=MAX_LINE_LEN)
    if len(wrapped) <= MAX_LINES:
        # Pad to at least 2 lines for aesthetics
        while len(wrapped) < 2:
            wrapped.append("")
        return wrapped
    else:
        return None

def process_file():
    with open(INPUT_FILE, encoding="utf-8") as f:
        lines = f.readlines()

    out_lines = []
    flagged = []

    i = 0
    while i < len(lines):
        line = lines[i]
        # Look for .description = COMPOUND_STRING(
        m = re.match(r'(\s*)\.description = COMPOUND_STRING\((.*)', line)
        if m:
            indent = m.group(1)
            desc_lines = []
            # Check if description is all on one line
            if line.rstrip().endswith('),'):
                # Single-line description
                desc = m.group(2).rstrip('),').strip()
                desc = desc.strip('"')
                reformatted = reflow_description(desc)
                if reformatted:
                    out_lines.append(f'{indent}.description = COMPOUND_STRING(\n')
                    for l in reformatted:
                        out_lines.append(f'{indent}    "{l}\\n"\n')
                    out_lines[-1] = out_lines[-1].rstrip('\\n"\n') + '"\n'
                    out_lines.append(f'{indent}),\n')
                else:
                    out_lines.append(line)
                    flagged.append((None, desc))
                i += 1
            else:
                # Multi-line description
                desc = ""
                i += 1
                while i < len(lines):
                    l = lines[i]
                    if l.strip().endswith('),'):
                        # Last line
                        desc += l.strip().rstrip('),').strip().strip('"')
                        break
                    else:
                        desc += l.strip().strip('"')
                    i += 1
                reformatted = reflow_description(desc)
                if reformatted:
                    out_lines.append(f'{indent}.description = COMPOUND_STRING(\n')
                    for l in reformatted:
                        out_lines.append(f'{indent}    "{l}\\n"\n')
                    out_lines[-1] = out_lines[-1].rstrip('\\n"\n') + '"\n'
                    out_lines.append(f'{indent}),\n')
                else:
                    # Find the move name for easier manual review
                    move_name = None
                    # Look back for the move name
                    for j in range(len(out_lines)-1, -1, -1):
                        m2 = re.match(r'\s*\[(MOVE_[A-Z0-9_]+)\]\s*=', out_lines[j])
                        if m2:
                            move_name = m2.group(1)
                            break
                    # Re-add the original lines
                    out_lines.append(f'{indent}.description = COMPOUND_STRING(\n')
                    # Reconstruct original lines for output
                    for l in desc.split('\n'):
                        if l.strip():
                            out_lines.append(f'{indent}    "{l}\\n"\n')
                    out_lines[-1] = out_lines[-1].rstrip('\\n"\n') + '"\n'
                    out_lines.append(f'{indent}),\n')
                    flagged.append((move_name, desc))
                i += 1
        else:
            out_lines.append(line)
            i += 1

    # Write updated file
    with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
        f.writelines(out_lines)

    # Print and write flagged moves
    with open(FLAGGED_FILE, "w", encoding="utf-8") as f:
        for move_name, desc in flagged:
            move_str = move_name if move_name else "(unknown move)"
            msg = f"FLAGGED: {move_str}\nDescription: {desc}\n{'-'*40}\n"
            print(msg)
            f.write(msg)

if __name__ == "__main__":
    process_file()