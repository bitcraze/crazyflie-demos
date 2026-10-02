# Autonomous Sequence High Level Compressed

Flies a figure-8 trajectory using the high level commander with a compressed polynomial trajectory uploaded to the Crazyflie's memory.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- Positioning system (Lighthouse, LPS, or similar)

## Quick Start

```bash
uv run autonomous_sequence_high_level_compressed.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie at the configured URI
2. **Upload** - Uploads a compressed Bezier curve trajectory representing a figure 8
3. **Reset estimator** - Resets the Kalman filter estimator
4. **Takeoff** - Takes off to 1.0 m altitude
5. **Fly** - Executes the figure-8 trajectory relative to the starting position
6. **Land** - Lands and stops the motors

The demo showcases:
- Compressed polynomial trajectory format (`CompressedSegment`, `CompressedStart`)
- High level commander trajectory API
- Uploading trajectories to the Crazyflie's trajectory memory

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
