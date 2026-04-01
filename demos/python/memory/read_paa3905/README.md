# Read PAA3905 (Flow Sensor Image)

Reads the 35x35 pixel optical flow image from the PAA3905 sensor (Flow deck v2) and displays it as a live grayscale image using matplotlib.

## What You Need

- **Crazyflie platform**
- **USB connection** (default: `usb://0`)
- **Flow deck v2** (with PAA3905 sensor)

## Quick Start

```bash
uv run read_paa3905.py
```

The default URI is `usb://0` (direct USB connection). Edit the URI variable at the bottom of the script to use radio instead.

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find sensor memory** - Locates the `TYPE_DECK_PAA3905` memory element
3. **Display stream** - Reads 100 frames via `mem.read_data_sync()` and updates a live matplotlib `imshow` grayscale display (0–255)
4. **Print FPS** - Reports achieved frame rate after the 100-frame capture
5. **Wait** - Holds the window open for 5 seconds

The demo showcases:
- `MemoryElement.TYPE_DECK_PAA3905` for reading PAA3905 flow sensor images
- `mem.read_data_sync` for synchronous frame reads
- Live matplotlib display with `plt.pause`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: matplotlib
