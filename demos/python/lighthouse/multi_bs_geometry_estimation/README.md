# Multi Base Station Geometry Estimation

Interactive script that guides you through recording Lighthouse sweep angle measurements from a hand-held Crazyflie and solves for the 3D geometry of 2 or more Lighthouse v2 base stations.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse deck** (v2 base stations required)
- Lighthouse v2 base stations with calibration data already received by the Crazyflie

## Quick Start

```bash
uv run multi_bs_geometry_estimation.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie and sets lighthouse mode to v2
2. **Origin** - You place the Crazyflie at the desired coordinate origin and press Enter to record
3. **X-axis** - You place the Crazyflie exactly 1 m along the positive X-axis; this fixes scale
4. **XY-plane** - You record one or more positions in the XY-plane to define the Z-up direction
5. **Coverage sweep** - You move the Crazyflie freely around the flight space for a configurable number of seconds
6. **Solve** - The script runs a full geometry optimization (initial estimate + nonlinear solver)
7. **Upload** - Presses Enter to write the solved geometry back to the Crazyflie

Optionally set `file_name` to save raw measurements to a pickle file for offline re-estimation.

The demo showcases:
- `LighthouseSweepAngleAverageReader` and `LighthouseSweepAngleReader` for angle collection
- `LighthouseInitialEstimator`, `LighthouseGeometrySolver`, `LighthouseSystemAligner`, `LighthouseSystemScaler`
- `LighthouseConfigWriter.write_and_store_config` for uploading the final geometry

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: matplotlib, numpy
