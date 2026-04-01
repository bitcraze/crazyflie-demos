# Flow Sequence Sync

Flies a figure-8 pattern using hover setpoints with the Flow deck or Lighthouse positioning system.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck v2 or Lighthouse positioning system**

## Quick Start

```bash
uv run flowsequence_sync.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a synchronized radio link to the Crazyflie
2. **Reset estimator** - Waits for the state estimator to converge
3. **Arm** - Arms the Crazyflie
4. **Ramp up** - Gradually increases height to 0.4 m over 10 setpoints
5. **Hover** - Holds position at 0.4 m for 2 seconds
6. **Figure-8 legs** - Flies two arcs at 0.5 m/s with opposing yaw rates (72 deg/s), tracing a figure-8
7. **Settle** - Returns to stationary hover at 0.4 m
8. **Ramp down** - Gradually lowers to ground and stops

The demo showcases:
- Using the low-level hover setpoint commander (`send_hover_setpoint`)
- Combining forward velocity and yaw rate to trace curved paths

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
