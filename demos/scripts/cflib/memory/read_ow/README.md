# Read 1-Wire Memory

Connects to the Crazyflie, enumerates all 1-wire memories, and prints their contents (address, type, size, valid, name, VID, PID, pins, and all elements).

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Any deck that has a 1-wire memory**

## Quick Start

```bash
uv run read_ow.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find memories** - Enumerates all memories of type `TYPE_1W`
3. **Read each** - Calls `mem.update` for each 1-wire memory, waits up to 5 seconds, then prints all fields
4. **Exit** - Closes the link after all memories are read

The demo showcases:
- `MemoryElement.TYPE_1W` for 1-wire memory enumeration
- `mem.update` with a timeout-guarded async callback pattern

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
