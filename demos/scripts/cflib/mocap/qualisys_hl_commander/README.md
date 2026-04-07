# Qualisys High Level Commander

Connects to a Qualisys QTM motion capture system and feeds pose data to a Crazyflie, then uploads and flies a figure-8 trajectory using the high level commander.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Qualisys QTM system** on the same network

## Quick Start

```bash
uv run qualisys_hl_commander.py
```

## What Happens

When you run the demo:

1. **Discover QTM** - Auto-discovers the QTM instance on the local network
2. **Connect to QTM** - Opens an async connection and starts streaming 6DoF data
3. **Connect to Crazyflie** - Opens a radio link to the Crazyflie
4. **Configure estimator** - Enables the Kalman estimator and sets orientation noise parameters
5. **Upload trajectory** - Uploads a pre-defined figure-8 polynomial trajectory to the Crazyflie's memory
6. **Reset estimator** - Waits for the state estimator to converge using incoming pose data
7. **Arm and fly** - Arms the Crazyflie, takes off to 1 m, executes the figure-8 trajectory, then lands
8. **Disconnect** - Stops streaming and closes all connections

The demo showcases:
- Using `qtm-rt` to connect to Qualisys QTM via its real-time protocol
- Converting a QTM rotation matrix to a quaternion via `scipy` for the Crazyflie's external pose interface
- Feeding full pose (position + orientation) to the Kalman estimator
- Uploading and executing polynomial trajectories via the high level commander

## Configuration

Edit the top of the script to match your setup:

- `rigid_body_name` — name of the rigid body in QTM that represents the Crazyflie
- `send_full_pose` — set to `False` to send position only
- The URI is read from the `CRAZYFLIE_URI` environment variable, defaulting to `radio://0/80/2M/E7E7E7E7E7`

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: qtm-rt, scipy
