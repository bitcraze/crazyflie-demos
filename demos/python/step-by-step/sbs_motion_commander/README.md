# Step-by-Step: Motion Commander

A step-by-step tutorial demonstrating three flight modes with the `MotionCommander`: simple take-off/hover, linear movement, and position-bounded flight.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck v2** (required — the script checks for deck attachment before flying)

## Quick Start

```bash
uv run sbs_motion_commander.py
```

## What Happens

When you run the demo (as configured — `take_off_simple` is active):

1. **Connect** - Opens a radio link and waits up to 5 seconds for the Flow deck to be detected
2. **Start logging** - Streams `stateEstimate.x` and `stateEstimate.y` at 100 Hz
3. **Arm** - Arms the Crazyflie
4. **Take off and hover** - Takes off to 0.5 m, hovers for 3 seconds, then lands automatically when the `MotionCommander` context exits
5. **Stop logging** - Stops the position log

The script contains three flight functions; uncomment the desired one in `__main__`:

- `take_off_simple(scf)` — take off, hover 3 s, land (active by default)
- `move_linear_simple(scf)` — take off, fly 0.5 m forward, turn 180°, fly back, land
- `move_box_limit(scf)` — fly indefinitely, bouncing within a ±0.5 m box using live position feedback

The demo showcases:
- Detecting deck attachment via the `deck.bcFlow2` parameter callback
- Using `MotionCommander` as a context manager for automatic take-off/landing
- Reading position via async logging to feed closed-loop position bounds

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
