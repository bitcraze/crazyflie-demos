# Flash Memory

Interactive script to read and overwrite vendor ID and memory ID fields in a DS28E05 1-wire EEPROM attached to the Crazyflie.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- A deck or board with a DS28E05 1-wire EEPROM

## Quick Start

```bash
uv run flash_memory.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Scan** - Lists all available 1-wire memories
3. **Select** - Prompts you to choose which memory to flash
4. **Display** - Prints the current name, VID, PID, pins, and elements of the selected memory
5. **Edit** - Prompts for new VID and PID values (press Enter to keep the existing value)
6. **Confirm and write** - Asks for confirmation then writes the data
7. **Disconnect** - Closes the link after the write completes

The demo showcases:
- `MemoryElement.TYPE_1W` for 1-wire memory enumeration
- `mem.write_data` with an async completion callback

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
