# Circling Square Demo

Flies 8 Crazyflies in circular Bezier-curve trajectories arranged in a square formation, with synchronized color-shifting LED ring effects.

## What You Need

- **Crazyflie platform** (8 units recommended)
- **Crazyradio**
- Positioning system (Lighthouse or LPS)
- **LED-ring deck** on each Crazyflie

## Quick Start

```bash
uv run circling_square_demo.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to all 8 Crazyflies simultaneously via the Swarm class
2. **Reset** - Resets estimators and turns off LEDs on all drones
3. **Upload** - Uploads a compressed circular Bezier trajectory to each drone at its designated position angle and radius
4. **Takeoff** - All drones take off to 1.0 m and move to their starting positions on the circle
5. **Fly** - Each drone flies 2 full circular loops while LEDs cycle through colors based on each drone's angular position
6. **Land** - All drones land in unison

The demo showcases:
- Compressed Bezier trajectory upload to a swarm
- Synchronized LED color animation across multiple drones
- Parallel swarm control with per-drone parameters

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
