# Lighthouse OpenVR Multigrab

Controls two Crazyflies simultaneously with a single SteamVR controller: the trigger grabs the nearest drone and moves it, while the other holds its position.

## What You Need

- **2 x Crazyflie platform**
- **Crazyradio**
- **Lighthouse positioning system**
- **SteamVR-compatible controller or tracker**
- SteamVR running on the host

## Quick Start

```bash
uv run lighthouse_openvr_multigrab.py
```

Edit `uri0` and `uri1` at the top of the script to match your drone addresses.

## What Happens

When you run the demo:

1. **Init VR** - Opens SteamVR and finds the first controller
2. **Connect** - Connects to both Crazyflies and resets their Kalman estimators
3. **Arm** - Arms both drones
4. **Hover** - Both drones hover at initial positions offset to either side of the controller
5. **Grab nearest** - Pressing the trigger grabs whichever drone is closest to the controller at that moment; moving the controller moves only that drone
6. **Release** - Releasing the trigger freezes the grabbed drone's setpoint

The demo showcases:
- Multi-drone simultaneous control with independent position setpoints
- Distance-based grab selection using `vector_norm`
- SteamVR controller tracking with `openvr`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: openvr
