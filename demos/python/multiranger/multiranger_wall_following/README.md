# Multiranger Wall Following

Flies the Crazyflie along a wall using a state-machine-based wall-following algorithm driven by the Multiranger deck's distance sensors.

## What You Need

- **Crazyflie 2.0**
- **Crazyradio**
- **Flow deck** (for hover stabilization)
- **Multiranger deck**
- A room with at least one straight wall

## Quick Start

```bash
uv run multiranger_wall_following.py
```

## What Happens

When you run the demo:

1. **Connect and arm** - Opens a radio link and arms the Crazyflie
2. **Take off** - The MotionCommander takes off to the default hover height
3. **Wall following loop** - Every iteration the script reads the yaw from the onboard log, reads the front and side range sensors, and calls the `WallFollowing` state machine
4. **State machine** - The `WallFollowing` class transitions through states (FORWARD, TURN_TO_FIND_WALL, TURN_TO_ALIGN_TO_WALL, FORWARD_ALONG_WALL, ROTATE_AROUND_WALL, ROTATE_IN_CORNER, FIND_CORNER) and outputs velocity and yaw-rate commands
5. **Stop condition** - Holding your hand above the Crazyflie (top sensor < 0.2 m) stops the demo
6. **Land** - The MotionCommander context manager lands automatically on exit

The demo showcases:
- A Python port of the C-based wall-following app from the Crazyflie firmware examples
- Using `SyncLogger` to read yaw data synchronously inside the control loop
- Combining `MotionCommander` velocity commands with yaw rate control

## Files

- `multiranger_wall_following.py` — main entry point
- `wall_following.py` — `WallFollowing` state machine class (helper module)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
