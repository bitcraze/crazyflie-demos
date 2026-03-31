# Autonomous Sequence

Flies a predefined sequence of absolute position setpoints using the low-level position commander.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- Positioning system (Lighthouse or Loco Positioning System)

## Quick Start

```bash
uv run autonomous_sequence.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie and resets the Kalman estimator
2. **Take off** - Ramps up velocity to reach the first position
3. **Fly sequence** - Visits each (x, y, z, yaw) waypoint, holding each for 5 seconds
4. **Land** - Returns to z=0 and stops

The demo showcases:
- Direct position setpoint commands via `send_position_setpoint`
- Logging of Kalman filter state estimates during flight

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
