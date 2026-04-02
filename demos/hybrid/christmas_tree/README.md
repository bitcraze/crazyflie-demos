# Christmas Tree

Flies 8 Crazyflies in a coordinated spiral choreography that traces the outline of a Christmas tree (cone) in 3D space, with each drone orbiting at a different altitude and radius. The custom firmware lights up the LED ring in red when the drone passes through a virtual "christmas ball" sphere, and green otherwise.

## What You Need

- **8 Crazyflie platforms** (fewer can be used by removing URIs from the list)
- **3 Crazyradios** (URIs are split across 3 radios on channels 30, 55, and 70)
- **Lighthouse positioning system**
- **Color LED deck (bottom-mounted)**

## Setup

Follow the general hybrid demo instructions in the [hybrid demos README](../README.md).

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all 8 Crazyflies
2. **Arm** - Arms all drones in parallel
3. **Take off** - Each drone takes off to its assigned altitude (0.5–2.5 m range)
4. **Move to start** - Each drone flies to its starting X/Y position on the cone surface
5. **Spiral sequence** - Each drone executes four spiral segments:
   - Full circle at constant altitude
   - Half circle descending with shrinking radius
   - Full circle ascending with growing radius
   - Half circle descending back to start altitude
6. **Land** - All drones land

The custom firmware runs on each Crazyflie and controls the Color LED deck: red inside a virtual christmas ball sphere, green outside. The spheres are arranged in 4 concentric rings at heights 0.5, 1.0, 1.5, and 2.0 m.

The demo showcases:
- `high_level_commander.spiral()` for smooth circular/helical motion
- Per-drone parameters (starting height, radius, yaw, rotation direction) via URI-keyed dicts
- Operating a swarm across multiple Crazyradios
- Out-of-tree firmware app controlling LEDs based on estimated position

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1 (base release + `app/` out-of-tree app built on top)
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
