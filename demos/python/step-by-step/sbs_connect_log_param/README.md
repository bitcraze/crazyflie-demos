# Step-by-Step: Connect, Log, and Parameters

A step-by-step tutorial script demonstrating the three most fundamental cflib operations: connecting to a Crazyflie, reading log data, and setting parameters.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run sbs_connect_log_param.py
```

## What Happens

When you run the demo (as configured — `simple_param_async` is active):

1. **Connect** - Opens a synchronized radio link to the Crazyflie
2. **Register callback** - Registers a callback for the `stabilizer.estimator` parameter
3. **Set parameter** - Sets `stabilizer.estimator` to 2, callback fires and prints the value
4. **Set again** - Sets `stabilizer.estimator` back to 1, callback fires again
5. **Disconnect** - Closes the link

The script contains four functions that can be enabled by uncommenting them in `__main__`:

- `simple_connect()` — just connect and wait
- `simple_log(scf, lg_stab)` — read one log packet synchronously with `SyncLogger`
- `simple_log_async(scf, lg_stab)` — stream stabilizer roll/pitch/yaw for 5 seconds via callback
- `simple_param_async(scf, group, name)` — set a parameter and observe the callback (active by default)

The demo showcases:
- `SyncCrazyflie` as a context manager for automatic connect/disconnect
- `SyncLogger` for synchronous log consumption
- Async logging with `data_received_cb`
- Parameter callbacks with `add_update_callback` and `set_value`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
