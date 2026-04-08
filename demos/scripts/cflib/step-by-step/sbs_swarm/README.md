# Step-by-Step: Swarm

A step-by-step tutorial demonstrating how to use the `Swarm` class to control four Crazyflies: LED check, take-off, per-drone relative sequences, and landing.

## What You Need

- **4 Crazyflie platforms**
- **Crazyradio**
- **Flow deck v2 or Positioning system**

## Quick Start

```bash
uv run sbs_swarm.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all four Crazyflies simultaneously using `CachedCfFactory`
2. **Light check** - Turns all LEDs on for 2 s then off as a visual connection confirmation
3. **Reset estimators** - Resets all Kalman filters in parallel
4. **Arm** - Arms all Crazyflies in parallel
5. **Take off** - All Crazyflies take off to 1 m in parallel
6. **Per-drone sequence** - Each Crazyflie flies its own 3-step relative sequence (defined in `sequence0`–`sequence3`)
7. **Land** - All Crazyflies land in parallel

The demo showcases:
- `Swarm.parallel_safe()` for running the same function on all Crazyflies in parallel
- `args_dict` for passing per-drone arguments to `parallel_safe()`
- LED control via the `led.bitmask` parameter
- Using the high level commander from within swarm callbacks

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
