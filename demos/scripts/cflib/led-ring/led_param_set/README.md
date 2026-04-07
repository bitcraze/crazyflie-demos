# LED Ring Parameter Set

Demonstrates controlling the LED-ring deck by setting `ring.*` parameters directly - including solid color and fade-to-color effects.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **LED-ring deck**

## Quick Start

```bash
uv run led_param_set.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Solid red** - Sets effect 7 (solid color) with red at value 100 for 2 seconds
3. **Off** - Sets effect 0 (off) for 1 second
4. **Fade** - Sets effect 14 (fade to color) with a 1-second fade time, cycling through blue, green, and red

The demo showcases:
- `ring.effect` parameter for selecting LED effects
- `ring.solidRed/Green/Blue` for solid color control
- `ring.fadeTime` and `ring.fadeColor` for smooth fade transitions

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
