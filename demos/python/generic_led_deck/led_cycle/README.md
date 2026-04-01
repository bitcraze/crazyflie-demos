# LED Cycle

Continuously cycles through all hues on any LED deck by converting HSV colors to RGB and writing them via the `led_deck_ctrl.rgb888` parameter.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck or LED-ring deck**

## Quick Start

```bash
uv run led_cycle.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Cycle colors** - Loops through hues 0–359 in HSV space, converting to RGB and writing each frame at ~100 FPS
3. **Stop** - Press Ctrl-C to turn off the LED and exit cleanly

The demo showcases:
- HSV-to-RGB conversion for perceptually smooth color cycling
- Controlling the Generic LED deck via the `led_deck_ctrl.rgb888` parameter

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
