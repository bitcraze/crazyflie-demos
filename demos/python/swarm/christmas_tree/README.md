# Christmas Tree

Flies 8 Crazyflies in a coordinated spiral choreography that traces the outline of a Christmas tree (cone) in 3D space, with each drone orbiting at a different altitude and radius.

## What You Need

- **8 Crazyflie platforms** (fewer can be used by removing URIs from the list)
- **3 Crazyradio dongles** (URIs are split across 3 radios on channels 30, 55, and 70)
- **Lighthouse positioning system**

## Quick Start

```bash
uv run christmas_tree.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all 8 Crazyflies
2. **Arm** - Arms all drones in parallel
3. **Take off** - Each drone takes off to its assigned altitude (0.5–2.5 m range)
4. **Move to start** - Each drone flies to its starting X/Y position on the cone surface
5. **Spiral sequence** - Each drone executes four spiral segments:
   - Full circle at constant altitude
   - Half circle descending 0.25 m with shrinking radius
   - Full circle ascending 0.5 m with growing radius
   - Half circle descending back to start altitude
6. **Land** - All drones land

The cone geometry is defined by `x_from_z(z)`: radius decreases linearly from base to tip. Alternating drones rotate clockwise vs. counter-clockwise.

The demo showcases:
- Using `high_level_commander.spiral()` for smooth circular/helical motion
- Assigning per-drone parameters (starting height, radius, yaw, rotation direction) via URI-keyed dicts
- Operating a swarm across multiple Crazyradio dongles

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
