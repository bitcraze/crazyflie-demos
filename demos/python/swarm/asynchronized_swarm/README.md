# Asynchronized Swarm

Flies two Crazyflies in an asynchronous choreography using the `MotionCommander`, with each drone executing a different time-based sequence while their positions are logged and printed.

## What You Need

- **2 Crazyflie platforms**
- **Crazyradio** (both must be on the same channel)
- **Flow deck v2** or **Lighthouse positioning system**

## Quick Start

```bash
uv run asynchronized_swarm.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to both Crazyflies
2. **Reset estimators** - Resets both Kalman filters
3. **Wait for parameters** - Waits until all parameters are downloaded on each drone
4. **Start position logging** - Streams `stateEstimate.x/y/z` at 2 Hz from each Crazyflie and prints positions
5. **Arm** - Arms both Crazyflies
6. **Async flight (12 s)** - Both drones execute independent time-based sequences in parallel:
   - URI1: ascends for 5 s, stops for 2 s, then descends for 5 s
   - URI2: alternates left/right every 2 s for 12 s
7. **Land** - Each drone lands when its sequence ends

The demo showcases:
- Per-drone branching inside a shared `parallel_safe` function using the link URI
- Continuous position logging during flight
- `MotionCommander` for relative velocity-based motion in a swarm context

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
