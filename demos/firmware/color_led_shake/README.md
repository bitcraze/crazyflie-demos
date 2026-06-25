# Color LED Shake

Maps the Crazyflie's gyroscope rotation rates to RGB color on the Color LED deck. Rotating or shaking the drone along each axis lights up a different color — pitch lights blue, roll lights green, yaw lights red. Both top and bottom decks are supported simultaneously.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck** (top or bottom mount, or both)

## Setup

Follow the general firmware demo instructions in the [firmware demos README](../README.md).

## What Happens

The gyroscope measures rotation rate (deg/s) on three axes. Each axis is mapped to a color channel:

| Axis | Color |
|------|-------|
| Yaw (Z) | Red |
| Roll (Y) | Green |
| Pitch (X) | Blue |

The raw gyro rate is clamped to ±512 deg/s, converted to an absolute value, halved to fit in the 0–255 range, and a small deadband (5) suppresses idle sensor noise. Holding the drone still produces no light; shaking or spinning it along an axis increases that channel's brightness.

## Technical Details

- Reads `gyro.x`, `gyro.y`, `gyro.z` log variables at 10ms intervals
- Enables `brightCorr` on detected decks for perceptually uniform colors
- Gyro rate mapping: `|rate| / 2` → channel value (0–255)
- Deadband of 5 suppresses noise when the drone is stationary
- Color packed as `0xWWRRGGBB` via the `wrgb8888` parameter
- Monitors thermal throttling every 100ms and prints warnings to the debug console

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2025.12.1
