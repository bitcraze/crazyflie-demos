# Read Lighthouse Memory

Reads and prints the Lighthouse base station geometry and calibration data stored in the Crazyflie's memory.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse deck**

## Quick Start

```bash
uv run read_lighthouse_mem.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Read geometry** - Reads all base station geometry entries and prints each one
3. **Read calibration** - Reads all base station calibration entries and prints each one

The demo showcases:
- `LighthouseMemHelper.read_all_geos` and `read_all_calibs` for asynchronous memory reads
- Using `threading.Event` to synchronize async callbacks

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
