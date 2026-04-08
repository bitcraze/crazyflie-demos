# Lighthouse Mass Upload

Connects to multiple Crazyflies in sequence and uploads a shared `lighthouse.yaml` configuration file to each, then powers down each drone after a successful upload.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse positioning deck**
- A `lighthouse.yaml` file (exported from the Crazyflie client)

## Quick Start

```bash
uv run lighthouse_mass_upload.py
```

Edit the `uris` list and `file_path` at the top of the script to match your setup.

## What Happens

When you run the demo:

1. **Check file** - Verifies that `lighthouse.yaml` exists
2. **Connect** - Connects to each Crazyflie in the `uris` list in sequence
3. **Upload** - Writes the lighthouse configuration to each drone using `LighthouseConfigWriter`
4. **Power down** - Powers off each drone after a successful upload via `PowerSwitch`
5. **Continue** - Skips any drone that cannot be connected to

This makes it easy to configure a large swarm: drones that have been configured turn off, drones that failed remain on.

The demo showcases:
- `LighthouseConfigWriter.write_and_store_config_from_file` for bulk configuration
- `PowerSwitch.platform_power_down` for remote power management

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
-extra: pyyaml
