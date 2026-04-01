# Swarm Sequence

Flies 10 Crazyflies in a grid formation where each drone follows its own absolute position sequence — ascending to 1 m, hovering for 30 s, then descending.

## What You Need

- **10 Crazyflie platforms** (fewer can be used by commenting out URIs)
- **Crazyradio** (all on channel 70)
- An absolute positioning system (e.g., Lighthouse, LPS)

## Starting Layout

Place the drones in the following grid (positions in meters):

```
    x2      x1      x0

y3  10              4

y2   9       6      3

y1   8       5      2

y0   7               1
```

## Quick Start

```bash
uv run swarm_sequence.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all 10 Crazyflies
2. **Wait for parameters** - Waits until all parameter downloads complete (important for large swarms)
3. **Arm** - Arms all Crazyflies
4. **Fly sequences** - Each Crazyflie follows its own 3-step sequence: rise to 0.4 m, hold 1 m for 30 s, descend to 0.4 m — using `send_position_setpoint` with velocity-based take-off and landing
5. **Land** - Each drone lands using velocity world setpoints

The demo showcases:
- Scaling swarm connections to 10 Crazyflies on a single Crazyradio
- Waiting for parameter downloads before commanding flight in a large swarm
- Per-drone absolute position sequences via `args_dict`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
