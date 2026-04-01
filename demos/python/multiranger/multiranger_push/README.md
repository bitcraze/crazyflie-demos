# Multiranger Push

Hover the Crazyflie and push it around with your hands — the Multiranger deck detects objects closer than 0.2 m and commands velocity away from them.

## What You Need

- **Crazyflie 2.0**
- **Crazyradio**
- **Flow deck** (for hover stabilization)
- **Multiranger deck**

## Quick Start

```bash
uv run multiranger_push.py
```

## What Happens

When you run the demo:

1. **Connect and arm** - Opens a radio link, arms the Crazyflie
2. **Take off** - The MotionCommander takes off to the default hover height
3. **React to proximity** - Every 100 ms the script reads the front, back, left, and right sensors; if any object is within 0.2 m it commands a velocity away from it at 0.5 m/s
4. **Stop condition** - Holding your hand above the Crazyflie (top sensor < 0.2 m) sets `keep_flying = False`
5. **Land** - The MotionCommander context manager lands automatically on exit

The demo showcases:
- Using the `Multiranger` helper class to read all six range sensors
- Reactive hover control using the `MotionCommander`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
