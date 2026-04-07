# Lighthouse OpenVR Grab Color

Extends the OpenVR grab demo with LED ring color control: the controller touchpad maps its angle to a hue, allowing the user to change the LED ring color while flying.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Lighthouse positioning system**
- **LED-ring deck**
- **SteamVR-compatible controller** (e.g. Valve Index, HTC Vive)
- SteamVR running on the host

## Quick Start

```bash
uv run lighthouse_openvr_grab_color.py
```

## What Happens

When you run the demo:

1. **Init VR** - Opens SteamVR and finds the first controller
2. **Connect** - Connects to the Crazyflie, resets the estimator, sets LED ring to solid effect
3. **Arm** - Arms the Crazyflie
4. **Hover and grab** - Same grab mechanic as the base demo: trigger holds, controller moves drone
5. **Color control** - Touching the trackpad maps its angular position to a hue, updating `ring.solidRed/Green/Blue` in real time

The demo showcases:
- Reading trackpad axis state via `openvr.k_eControllerAxis_TrackPad`
- `colorsys.hsv_to_rgb` for hue-to-RGB conversion
- Combining position control and LED ring parameter updates in a single loop

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: openvr
