# Motion Commander Demo

Demonstrates velocity-based flight control using the `MotionCommander` class, including directional moves, circles, turns, and continuous motion.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- Positioning system (Flow deck or Lighthouse)

## Quick Start

```bash
uv run motion_commander_demo.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie and arms it
2. **Takeoff** - The `MotionCommander` context manager triggers automatic takeoff
3. **Move** - Executes forward/back, up/down, left/right moves at various velocities
4. **Circle** - Flies a 180-degree arc to the right
5. **Turn** - Turns left 90 degrees
6. **3D move** - Moves along a diagonal line in 3D space
7. **Continuous motion** - Starts a continuous leftward drift while doing other work, then stops
8. **Land** - The `MotionCommander` lands automatically on context exit

The demo showcases:
- `MotionCommander` distance-based and velocity-based movement commands
- `circle_right`, `turn_left`, and `move_distance` for complex maneuvers
- `start_left` / `stop` for non-blocking continuous motion

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
