# LED Timing

Programs a pre-defined LED animation sequence into the Crazyflie's LEDTIMING memory and plays it back autonomously using effect 17.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **LED-ring deck**

## Quick Start

```bash
uv run led_timing.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Write sequence** - Writes a multi-step LEDTIMING sequence into the LED ring memory (red, green with rotation, blue with fade, purple, etc.)
3. **Play** - Switches to effect 17 (virtual memory effect) to play back the uploaded sequence autonomously
4. **Wait** - Holds for 2 seconds then exits

The demo showcases:
- `MemoryElement.TYPE_DRIVER_LEDTIMING` for programming autonomous LED sequences
- `mem.add()` with duration, color, `leds`, `rotate`, and `fade` parameters
- Switching between LED effects via `ring.effect`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
