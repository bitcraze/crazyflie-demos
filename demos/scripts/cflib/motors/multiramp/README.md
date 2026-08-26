# Motor Ramp - Multiple Crazyflies

Connects to two Crazyflies simultaneously, ramps the motors up and down on both, then disconnects.

## What You Need

- **2x Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run multiramp.py
```

## What Happens

When you run the demo:

1. **Connects** to both Crazyflies
2. **Arms** each Crazyflie
3. **Ramps up** motors on both simultaneously (each in its own thread)
4. **Ramps down**
5. **disconnects**

The demo showcases:
- Managing multiple Crazyflie connections at once
- Running motor ramp sequences in parallel threads

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
