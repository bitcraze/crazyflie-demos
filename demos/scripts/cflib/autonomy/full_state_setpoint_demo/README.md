# Full State Setpoint Demo

Demonstrates sending full state control setpoints (position, velocity, acceleration, and orientation as a quaternion) to the Crazyflie.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- Positioning system (Lighthouse or similar)

## Quick Start

```bash
uv run full_state_setpoint_demo.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie and resets the Kalman estimator
2. **Takeoff** - Sends full-state setpoints commanding 1.0 m altitude for 4 seconds
3. **Yaw** - Holds altitude while commanding a 0.7 rad yaw offset for 2 seconds
4. **Land** - Commands descent to 0.1 m then stops motors

The demo showcases:
- `send_full_state_setpoint` with position, velocity, acceleration, and quaternion orientation
- Converting Euler angles to quaternion using scipy

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
