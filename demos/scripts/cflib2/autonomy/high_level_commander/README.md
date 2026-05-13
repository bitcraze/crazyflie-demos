# High-Level Commander

Demonstrates autonomous flight using the high-level commander: take off, move to positions, fly a spiral, and land.

Uses the async [cflib2](https://github.com/bitcraze/crazyflie-lib-python-v2) library.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck v2 or Positioning system**

## Quick Start

```bash
uv run high_level_commander.py --uri radio://0/80/2M/E7E7E7E7E7
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Takes off** - Rises to 0.5 m
3. **Moves** to two waypoints
4. **Spiral** - Flies a full 360° spiral
5. **Lands** - Returns to ground and stops motors

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04
- cflib2:
  - repo: https://github.com/bitcraze/crazyflie-lib-python-v2.git
  - ref: 329bd2cb6b21ccecce0396926887743c148a6bd6
