# Write EEPROM

Connects to the Crazyflie, writes default configuration values to the first I2C EEPROM memory found, then reads them back to verify.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run write_eeprom.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find EEPROM** - Enumerates memories of type `TYPE_I2C`
3. **Write defaults** - Sets `version=1`, `pitch_trim=0`, `roll_trim=0`, `radio_channel=80`, `radio_speed=2`, `radio_address=0xE7E7E7E7E7`
4. **Read back** - Calls `mem.update` to verify the written values and prints them
5. **Disconnect** - Closes the link after verification

The demo showcases:
- `MemoryElement.TYPE_I2C` for I2C EEPROM write access
- `mem.write_data` followed by `mem.update` for write-then-verify

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.8
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
