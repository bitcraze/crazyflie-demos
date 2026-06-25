# Color LED Tilt

Maps the Crazyflie's tilt angle to a color on the Color LED deck. The direction you tilt the drone selects a hue from the HSV color wheel; how far you tilt it sets the brightness. Both top and bottom decks are supported simultaneously.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck** (top or bottom mount, or both)

## Setup

Follow the general firmware demo instructions in the [firmware demos README](../README.md).

## What Happens

Roll and pitch angles are combined into a 2D tilt vector. The direction of that vector selects a hue from the HSV color wheel, and the magnitude (capped at 45°) sets brightness. A 2° deadband suppresses sensor noise when the drone is held still.

Approximate color wheel orientation:

| Tilt direction | Color |
|----------------|-------|
| Right | Red |
| Forward-right | Orange |
| Forward-left | Green |
| Left | Cyan |
| Back | Purple |

When the drone is still, the last active color stays latched at full brightness. The displayed color smoothly interpolates toward the target each tick (~60 ms settling time), giving soft transitions between hues.

On startup the LED shows dim white until the first tilt is detected.

## Technical Details

- Reads `stabilizer.roll` and `stabilizer.pitch` log variables at 10 ms intervals
- Deadband of ±2° suppresses noise when stationary
- Tilt scaled to 0–255 over 45°, clamped; roll and pitch form an (x, y) vector for `atan2`
- Hue derived from tilt direction, saturation fixed at 1, value set by tilt magnitude
- Color normalized to full brightness when moving, latched when still
- Display color lerped toward target at ~15% per tick (10 ms) — ~60 ms settle time
- Enables `brightCorr` on detected decks for perceptually uniform colors
- Color packed as `0x00RRGGBB` (white channel always 0) via the `wrgb8888` parameter
- Monitors thermal throttling every 100 ms and prints warnings to the debug console

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2025.12.1
