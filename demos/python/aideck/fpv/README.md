# FPV Demo

Fly the Crazyflie in first-person view using the AI deck camera with keyboard control, displaying live grayscale video and position telemetry in a GUI window.

## What You Need

- **Crazyflie 2.1**
- **Crazyradio**
- **Flow v2 deck**
- **AI deck 1.1**

## Quick Start

```bash
uv run fpv.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie over WiFi via the AI deck TCP interface
2. **Hover** - The Crazyflie arms and hovers at 0.3 m
3. **Stream** - Live camera frames from the AI deck are displayed in a GUI window
4. **Control** - Use keyboard to fly: arrow keys to move, W/S for altitude, A/D/Z/X for yaw
5. **Telemetry** - Position (X/Y/Z) and attitude (roll/pitch/yaw) are shown alongside the video

The demo showcases:
- WiFi-based CPX communication with the AI deck
- Simultaneous CRTP flight control over the same WiFi link
- Real-time camera streaming from the AI deck

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
