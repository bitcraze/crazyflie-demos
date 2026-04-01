# Lighthouse Config Visualization

Reads a `lighthouse.yaml` configuration file and renders a 3D matplotlib visualization of all base station positions, orientations, and coverage sectors.

## What You Need

- A `lighthouse.yaml` file (exported from the Crazyflie client)

No Crazyflie or radio hardware is required - this script is purely offline.

## Quick Start

```bash
uv run lighthouse_config_visualization.py
```

Edit the `config_file` variable at the top of the script to point to your `lighthouse.yaml`.

## What Happens

When you run the demo:

1. **Load** - Reads the lighthouse geometry from `lighthouse.yaml`
2. **Draw global frame** - Plots the world coordinate frame at the origin
3. **Draw base stations** - For each base station: draws its local XYZ coordinate frame, a horizontal coverage sector (150 deg), and a vertical coverage sector (110 deg)
4. **Display** - Opens a 3D matplotlib window with equal-aspect axes

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: matplotlib, numpy, pyyaml
