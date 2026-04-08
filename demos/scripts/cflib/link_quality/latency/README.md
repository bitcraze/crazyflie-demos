# Latency

Connects to the Crazyflie and prints real-time link latency estimates as they are reported by the radio driver.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run latency.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Stream latency** - Registers a callback on `cf.link_statistics.latency.latency_updated` and prints each new estimate in milliseconds
3. **Run** - Loops indefinitely until Ctrl-C

The demo showcases:
- `cf.link_statistics.latency.latency_updated` callback for monitoring link quality

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
