# Initial Position

Demonstrates how to set the Crazyflie's initial position and yaw in the Kalman estimator before take-off, then fly a trajectory relative to that starting pose.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- An absolute positioning system (e.g., Lighthouse, LPS, or motion capture)

## Quick Start

```bash
uv run initial_position.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a synchronized radio link to the Crazyflie
2. **Set initial pose** - Writes the configured `initial_x`, `initial_y`, `initial_z`, and `initial_yaw` to the `kalman.initial*` parameters so the estimator starts at the correct world position
3. **Reset estimator** - Waits for the Kalman filter to converge from the given initial state
4. **Arm and fly** - Arms the Crazyflie and sends position setpoints from the `sequence` list (each held for 5 seconds)
5. **Stop** - Sends a stop setpoint and notifies the high level commander

The demo showcases:
- Setting initial Kalman estimator state via parameters before flight
- Flying with a non-zero initial yaw (e.g., 90 degrees)
- Using `send_position_setpoint` to command absolute world-frame positions

## Configuration

Edit the variables at the bottom of the script:

- `initial_x`, `initial_y`, `initial_z` — where the Crazyflie is placed on the floor (in meters)
- `initial_yaw` — the heading the Crazyflie is facing (0 = +X, 90 = +Y, 180 = -X, 270 = -Y)
- `sequence` — list of `(x, y, z)` waypoints relative to the initial position

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
