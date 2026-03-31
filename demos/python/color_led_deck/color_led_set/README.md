# Color LED Set

Sets a static color on the Color LED deck using the WRGB `wrgb8888` parameter, with optional auto white-channel extraction.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck(s)**

## Quick Start

```bash
uv run color_led_set.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Detect deck** - Auto-detects whether a bottom or top Color LED deck is attached
3. **Monitor thermals** - Sets up a log callback to warn if thermal throttling activates
4. **Set color** - Writes the configured WRGB color to the deck and holds it
5. **Stop** - Press Ctrl-C to turn off the LED and exit cleanly

Edit the `color = wrgb(...)` line near the bottom of the script to choose your color. The `rgb` helper class automatically extracts a white component for maximum efficiency.

The demo showcases:
- `wrgb` and `rgb` helper classes for specifying colors
- Auto white-channel extraction via the `rgb` class
- Auto-detection of bottom vs. top Color LED deck
- Thermal monitoring via `LogConfig` callbacks

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
