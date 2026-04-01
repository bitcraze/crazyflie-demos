# Basic Parameters

Connects to a Crazyflie, downloads all parameters, prints their values, modifies one parameter, and reads it back — demonstrating the cflib parameter callback API.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run basicparam.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a radio link to the Crazyflie and downloads the parameter TOC
2. **Print TOC** - Prints all parameter group and parameter names
3. **Register callbacks** - Registers a generic callback for every group and a specific callback for `cpu.flash`
4. **Parameters downloaded** - Once all parameter values are fetched, prints a completion message and removes group callbacks
5. **Read a value** - Gets `pid_attitude.pitch_kd` directly with `get_value()`
6. **Set a value** - Sets `pid_attitude.pitch_kd` to 0.1234; the registered callback prints the readback value
7. **Disconnect** - Closes the link

The demo showcases:
- The difference between the `connected` callback (TOC ready) and `fully_connected` callback (all parameter values downloaded)
- Group-level and parameter-level callback registration and removal
- Direct parameter read with `get_value()` vs. callback-driven reads

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
