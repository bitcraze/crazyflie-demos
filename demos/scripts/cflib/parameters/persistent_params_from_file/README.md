# Persistent Parameters from File

Reads a YAML file containing persistent parameter values and writes them all to the Crazyflie in one operation.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- A YAML parameter file (see format below)

## Quick Start

```bash
uv run persistent_params_from_file.py -f params.yaml
```

## YAML File Format

```yaml
params:
  activeMarker.back:
    default_value: 3
    is_stored: true
    stored_value: 30
type: persistent_param_state
version: '1'
```

Each entry under `params` is a parameter name (`group.name`) with its desired `stored_value`. The file format matches what Bitcraze tools export when saving parameter configurations.

## What Happens

When you run the demo:

1. **Connect** - Opens a synchronized radio link to the Crazyflie
2. **Read file** - Parses the YAML file passed with `-f`
3. **Store parameters** - Writes each parameter's stored value to the Crazyflie's persistent memory using `ParamFileHelper`
4. **Disconnect** - Closes the link

The demo showcases:
- Using `ParamFileHelper.store_params_from_file()` as a batch persistent-parameter writer
- A practical workflow for deploying known parameter configurations to Crazyflies

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
