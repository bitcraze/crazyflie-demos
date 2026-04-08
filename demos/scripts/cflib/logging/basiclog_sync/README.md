# Basic Log Sync

Connects to the Crazyflie using `SyncCrazyflie` and `SyncLogger`, logs stabilizer roll/pitch/yaw at 10 ms intervals in a simple iterator loop for 10 seconds, then exits.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run basiclog_sync.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a `SyncCrazyflie` context
2. **Configure log** - Creates a `LogConfig` for `stabilizer.roll/pitch/yaw` at 10 ms
3. **Stream data** - Iterates the `SyncLogger` and prints each entry as `[timestamp][config_name]: data`
4. **Stop** - Exits after 10 seconds

The demo showcases:
- `SyncLogger` as a blocking iterator for log data — simpler than the async callback approach
- Combining `SyncCrazyflie` and `SyncLogger` context managers

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
