# Autonomous Sequence - High Level Commander

Demonstrates autonomous flight using the high-level commander with trajectory planning to fly a figure-8 pattern.

## What You Need

- **Crazyflie platform**
- **Positioning System**
- **Crazyradio**

## Quick Start

```bash
uv run autonomous_sequence_high_level.py
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Resets estimator** - Clears position estimate
3. **Takes off** - Rises to 0.5m
4. **Flies figure-8** - Executes pre-programmed trajectory using polynomial coefficients
5. **Lands** - Returns to ground

The demo showcases:
- Using the high-level commander API
- Uploading trajectory data to the Crazyflie
- Position control in autonomous mode

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31


## Learn More

- [High Level Commander documentation](https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/functional-areas/high-level-commander/)
- [Autonomous flight tutorial](https://www.bitcraze.io/documentation/repository/crazyflie-lib-python/master/user-guides/sbs_motion_commander/)
