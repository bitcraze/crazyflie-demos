# Persistent Parameters

Demonstrates reading, writing, and clearing persistent parameters on the Crazyflie — values stored in flash that survive a power cycle.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run persistent_params.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a synchronized radio link to the Crazyflie
2. **List persistent params** - Scans the parameter TOC and prints all parameters that support persistence
3. **Print current state** - Fetches and prints the current persistent state of each parameter
4. **Set and persist** - Sets `ring.effect` to 10 and stores it to flash
5. **Verify** - Reads back the new persistent state of `ring.effect`
6. **Clear** - Clears the persisted value of `ring.effect` (reverts to default on next boot)
7. **Verify** - Reads back the cleared state

The demo showcases:
- Using `persistent_get_state`, `persistent_store`, and `persistent_clear` from the cflib parameter API
- Blocking on async callbacks with `threading.Event`

Note: This script changes the `ring.effect` parameter value on the connected Crazyflie.

Note: You don't need the LED-ring deck to be attached for this example to work.

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
