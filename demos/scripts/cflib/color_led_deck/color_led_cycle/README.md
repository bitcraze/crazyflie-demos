# Color LED Cycle

Continuously cycles through all hues on the Color LED deck by converting HSV colors to WRGB and writing them via the `wrgb8888` parameter.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck(s)**

## Quick Start

```bash
uv run color_led_cycle.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Detect deck** - Auto-detects whether a bottom or top Color LED deck is attached
3. **Monitor thermals** - Sets up a log callback to warn if thermal throttling activates
4. **Cycle colors** - Loops through hues 0–359 in HSV space, converting to WRGB and writing each frame at ~100 FPS
5. **Stop** - Press Ctrl-C to turn off the LED and exit cleanly

The demo showcases:
- Auto-detection of bottom vs. top Color LED deck via `deck.bcColorLedBot` / `deck.bcColorLedTop`
- HSV-to-WRGB conversion for perceptually smooth color cycling
- Thermal monitoring via `LogConfig` callbacks
- `brightCorr` parameter for luminance-balanced output

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
