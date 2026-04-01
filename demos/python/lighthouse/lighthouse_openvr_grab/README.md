# Lighthouse OpenVR Grab

Connects a Crazyflie to a SteamVR controller: the drone hovers 30 cm above the controller, and holding the trigger "grabs" it so you can move the drone by moving the controller.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse positioning system**
- **SteamVR-compatible controller or tracker** (e.g. Valve Index, HTC Vive)
- SteamVR running on the host

## Quick Start

```bash
uv run lighthouse_openvr_grab.py
```

## What Happens

When you run the demo:

1. **Init VR** - Opens SteamVR via `openvr` and finds the first controller or tracker
2. **Connect** - Connects to the Crazyflie and resets the Kalman estimator
3. **Arm** - Arms the Crazyflie
4. **Hover** - Continuously sends position setpoints; initial position is 30 cm above the controller
5. **Grab** - When the trigger is held, the Crazyflie follows the controller's movement
6. **Release** - Releasing the trigger freezes the setpoint at the current position

The demo showcases:
- Reading SteamVR controller pose and button state via `openvr`
- `send_position_setpoint` for real-time position control from external tracking data

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: openvr
