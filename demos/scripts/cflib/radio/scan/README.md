# Scan

Scans all radio interfaces for Crazyflies with the default address and prints their URIs.

## What You Need

- **Crazyradio**
- One or more powered-on Crazyflies using the default address `E7E7E7E7E7`

## Quick Start

```bash
uv run scan.py
```

## What Happens

When you run the demo:

1. **Scan** - Scans all available interfaces (Crazyradio dongles) for Crazyflies at address `0xE7E7E7E7E7`
2. **Print results** - Prints the URI of every Crazyflie found (e.g., `radio://0/80/2M/E7E7E7E7E7`)

The demo showcases:
- Using `cflib.crtp.scan_interfaces()` as a discovery tool before connecting

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
