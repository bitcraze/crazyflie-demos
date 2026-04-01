# Read L5 (Multiranger ToF Image)

Reads the 8x8 pixel ToF image from the Multi-ranger deck's VL53L5 sensor and displays it as a live grayscale heatmap using matplotlib.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Multi-ranger deck** (with VL53L5 sensor)

## Quick Start

```bash
uv run read_l5.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find sensor memory** - Locates the `TYPE_DECK_MULTIRANGER` memory element
3. **Display stream** - Reads 100 frames via `mem.read_data_sync()` and updates a live matplotlib `imshow` grayscale display (0–400 mm range)
4. **Print FPS** - Reports achieved frame rate after the 100-frame capture

The demo showcases:
- `MemoryElement.TYPE_DECK_MULTIRANGER` for reading VL53L5 depth image data
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
