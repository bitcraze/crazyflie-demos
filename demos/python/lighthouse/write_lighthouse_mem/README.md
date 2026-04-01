# Write Lighthouse Memory

Writes example Lighthouse base station geometry and calibration data directly into the Crazyflie's memory using hardcoded values.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse deck**

## Quick Start

```bash
uv run write_lighthouse_mem.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Write geometry** - Writes geometry (origin + rotation matrix) for two base stations
3. **Write calibration** - Writes full sweep calibration data (phase, tilt, curve, gibmag, gibphase, ogeemag, ogeephase) for both sweeps of each base station

Edit the `bs1geo`, `bs2geo`, `bs1calib`, `bs2calib` values to match your actual system.

The demo showcases:
- `LighthouseBsGeometry` and `LighthouseBsCalibration` data structures
- `LighthouseMemHelper.write_geos` and `write_calibs` for asynchronous memory writes
- Using `threading.Event` to synchronize async callbacks

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
