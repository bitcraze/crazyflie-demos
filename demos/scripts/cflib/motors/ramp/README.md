# Motor Ramp

Connects to a Crazyflie, ramps the motors up and down, then disconnects.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Quick Start

```bash
uv run ramp.py
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Arms** the Crazyflie
3. **Ramps up** motors from thrust 20000 to 25000
4. **Ramps down** back to 20000
5. **Disconnects**

The demo showcases:
- Basic cflib connection and callback setup
- Sending raw thrust setpoints via the commander

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
