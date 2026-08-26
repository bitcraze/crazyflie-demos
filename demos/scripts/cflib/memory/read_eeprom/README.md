# Read EEPROM

Connects to the Crazyflie, reads all I2C EEPROM memories, and prints their contents (type, size, valid flag, and all elements).

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run read_eeprom.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find EEPROMs** - Enumerates all memories of type `TYPE_I2C`
3. **Update and print** - Calls `mem.update` for each EEPROM; on completion prints type, size, validity, and all key-value elements
4. **Disconnect** - Closes the link after all memories have been read

The demo showcases:
- `MemoryElement.TYPE_I2C` for I2C EEPROM enumeration
- `mem.update` with async completion callback

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
