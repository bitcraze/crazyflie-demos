# Multiranger Point Cloud

Flies the Crazyflie in a hover and renders a live 3D point cloud from the Multiranger deck's distance sensors in a PyQt6/VisPy window.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck**
- **Multiranger deck**

## Quick Start

```bash
uv run multiranger_pointcloud.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens a radio link and arms the Crazyflie
2. **Hover** - The Crazyflie takes off and hovers at 0.3 m
3. **Stream data** - Position and range measurements are logged at 10 Hz
4. **Render** - Each range reading is converted to a 3D point (rotated by the current attitude) and drawn in the VisPy canvas
5. **Keyboard control** - Use arrow keys to move, W/S to change height, A/D/Z/X to yaw
6. **Close window** - Closes the link and lands

The demo showcases:
- Real-time 3D visualization of ranging sensor data using VisPy
- Rotation of sensor readings into the world frame using roll/pitch/yaw
- Keyboard-controlled hover using the `send_hover_setpoint` commander

## Controls

| Key | Action |
|-----|--------|
| Arrow keys | Move forward/back/left/right |
| W / S | Increase / decrease height (0.1 m steps) |
| A / D | Yaw slowly CCW / CW |
| Z / X | Yaw fast CCW / CW |

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: numpy, vispy, PyQt6
