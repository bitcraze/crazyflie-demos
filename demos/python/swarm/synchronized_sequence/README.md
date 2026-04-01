# Synchronized Sequence

Flies 3 Crazyflies in a tightly synchronized choreography where a central control thread dispatches time-stepped commands (Arm, Takeoff, Goto, Land, Ring) to individual drones via per-drone queues.

## What You Need

- **3 Crazyflie platforms** (with LED ring deck for color commands)
- **Crazyradio** (all on channel 10)
- An absolute positioning system (e.g., Lighthouse, LPS)

## Quick Start

```bash
uv run synchronized_sequence.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all 3 Crazyflies
2. **Reset estimators** - Resets all Kalman filters
3. **Start control thread** - A background thread walks through the `sequence` list step-by-step at `STEP_TIME` (1 s) intervals, dispatching commands to per-drone queues
4. **Execute sequence**:
   - Step 0: Arm and takeoff for CF0 and CF2; CF1 waits
   - Step 1: CF1 takes off to 1.0 m
   - Steps 2–11: CF0 and CF2 fly a choreography of absolute Goto positions while CF1 holds center; LED ring colors are set at step 4
   - Step 13: All land
   - Step 15: LED rings fade to off
5. **Quit** - Each drone's control loop exits when it receives `Quit`

The demo showcases:
- A queue-based architecture for deterministic step-synchronized swarm control
- Mixing Arm, Takeoff, Goto, Land, and Ring commands in a single sequence table
- Using the LED ring `fadeColor` and `fadeTime` parameters for color effects

## Sequence Format

Each entry is `(step, cf_id, command)`. All entries with `step <= current_step` are dispatched before advancing to the next step.

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
