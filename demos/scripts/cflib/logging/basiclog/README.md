# Basic Log

Connects to the Crazyflie using the asynchronous callback API, logs stabilizer and position estimates at 100 ms intervals, prints them to the console, and automatically disconnects after 5 seconds.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run basiclog.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie and waits for the TOC download
2. **Configure log** - Sets up a `LogConfig` for `stateEstimate.x/y/z`, `stabilizer.roll/pitch/yaw`, and `pm.vbat` at 100 ms
3. **Stream data** - Prints each log packet to the console with timestamp and variable values
4. **Disconnect** - A 5-second timer fires `close_link` automatically

The demo showcases:
- Asynchronous cflib connection and callback pattern (`connected`, `disconnected`, etc.)
- `LogConfig` with multiple variable types including `FP16` for compact battery voltage

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
