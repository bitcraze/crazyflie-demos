# Mocap High Level Commander

Connects to a motion capture system and feeds pose data to a Crazyflie, then uploads and flies a figure-8 trajectory using the high level commander.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Motion capture system** (Vicon, OptiTrack, Qualisys, NOKOV, VRPN, or MotionAnalysis)
- Rigid body configured in the mocap system for the Crazyflie

## Quick Start

```bash
uv run mocap_hl_commander.py
```

## What Happens

When you run the demo:

1. **Connect to mocap** - Connects to the motion capture system using the `motioncapture` library
2. **Connect to Crazyflie** - Opens a radio link to the Crazyflie
3. **Configure estimator** - Enables the Kalman estimator and sets orientation noise parameters
4. **Upload trajectory** - Uploads a pre-defined figure-8 polynomial trajectory to the Crazyflie's memory
5. **Reset estimator** - Waits for the state estimator to converge using the incoming pose data
6. **Arm and fly** - Arms the Crazyflie, takes off to 1 m, executes the figure-8 trajectory, then lands
7. **Disconnect** - Closes the mocap and radio connections

The demo showcases:
- Using `motioncapture` as a generic interface to different mocap systems
- Feeding full pose (position + quaternion orientation) to the Crazyflie's external pose interface
- Uploading and executing polynomial trajectories via the high level commander

## Configuration

Edit the top of the script to match your setup:

- `host_name` — IP or hostname of the mocap system
- `mocap_system_type` — one of `vicon`, `optitrack`, `optitrack_closed_source`, `qualisys`, `nokov`, `vrpn`, `motionanalysis`
- `rigid_body_name` — name of the rigid body in the mocap software
- `send_full_pose` — set to `False` to send position only

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: motioncapture
