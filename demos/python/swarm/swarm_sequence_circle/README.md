# Swarm Sequence Circle

Flies 5 Crazyflies in a formation where four drones orbit in a circle around a stationary center drone, using hover setpoints and a yaw rate to maintain circular flight.

## What You Need

- **5 Crazyflie platforms**
- **Crazyradio** (drones use different channels; see `uris`)
- **Flow deck** on each Crazyflie

## Starting Positions

Place the drones in a plus-sign pattern, facing outward from the center:

```
     >

^    +    v

     <
```

The distance from center to each perimeter drone should be about 0.5 m.

## Quick Start

```bash
uv run swarm_sequence_circle.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all 5 Crazyflies
2. **Reset estimators** - Resets all Kalman filters
3. **Arm and ramp up** - Each drone arms and ramps from 0.15 m to its assigned altitude
4. **Circle** - Four outer drones (d=1.0) fly 2 full circles using `send_hover_setpoint` with forward velocity and yaw rate; the center drone (d=0.0) hovers at 0.5 m
5. **Ramp down and stop** - Each drone ramps back to 0.15 m then stops

The demo showcases:
- Using `send_hover_setpoint` with nonzero velocity and yaw rate to trace circles
- Per-drone parameters (`d`, `z`) via `args_dict`
- Using `swarm.parallel()` (non-safe version) for simple flat sequences

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
