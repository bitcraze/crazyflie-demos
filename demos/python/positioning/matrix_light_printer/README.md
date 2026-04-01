# Matrix Light Printer

Flies the Crazyflie in a grid pattern while changing its LED ring color to match pixels from an image, creating a light-painting photograph when captured with a long-exposure camera in a dark room.

## What You Need

- **Crazyflie platform** with LED ring deck
- **Crazyradio**
- An absolute positioning system (e.g., Lighthouse)
- A camera capable of long-exposure shots
- A dark room

## Quick Start

```bash
uv run matrix_light_printer.py
```

## What Happens

When you run the demo:

1. **Connect and arm** - Opens a radio link and arms the Crazyflie
2. **Load image** - Reads `monalisa.png` from the same directory using matplotlib
3. **Scan rows** - For each pixel row the Crazyflie flies to the start of that row, then moves pixel-by-pixel setting the LED ring to the corresponding RGB color
4. **Black between rows** - The LED ring is turned off between rows to avoid blending
5. **Land** - The `PositionHlCommander` context manager lands automatically on exit

The demo showcases:
- Using `PositionHlCommander` for precise absolute position control
- Setting LED ring color in real-time via the `ring.solidRed/Green/Blue` parameters
- Light-painting photography with a Crazyflie

## Files

- `matrix_light_printer.py` — main script
- `monalisa.png` — sample source image

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: matplotlib
