# Console

Connects to the Crazyflie and prints all firmware `DEBUG_PRINT` console output to the terminal in real time.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run console.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Stream console** - Registers a callback on `cf.console.receivedChar` and prints all firmware console output as it arrives
3. **Run** - Loops indefinitely until you press Ctrl-C

You may need to restart your Crazyflie after connecting to see startup messages, as most `DEBUG_PRINT` output occurs early in the boot sequence.

The demo showcases:
- `cf.console.receivedChar` callback for receiving firmware debug output
- Using `SyncCrazyflie` with a pre-created `Crazyflie` object

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
