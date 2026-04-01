# Read Deck Memory

Reads and prints all deck memory entries from the Crazyflie, including deck capabilities (read/write support, firmware upgrade info) and the first 10 bytes of each readable deck memory.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- At least one deck attached

## Quick Start

```bash
uv run read_deck_mem.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Query decks** - Calls `mem.query_decks` to enumerate all deck memory entries
3. **Print info** - For each deck: prints name, started status, read/write support, and firmware upgrade details
4. **Read data** - For each readable deck, reads and prints the first 10 bytes

The demo showcases:
- `MemoryElement.TYPE_DECK_MEMORY` for deck memory access
- `deck_mem.supports_fw_upgrade`, `deck_mem.is_fw_upgrade_required`, `deck_mem.is_bootloader_active`
- `deck_mem.read` with async completion and failure callbacks

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
