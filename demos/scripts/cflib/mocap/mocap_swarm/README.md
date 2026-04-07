# Mocap Swarm

Connects to a motion capture system and feeds positions to multiple Crazyflies, then flies a synchronized square choreography using the high level commander and the Swarm class.

## What You Need

- **Crazyflie platform** (one or more)
- **Crazyradio**
- **Motion capture system** (Vicon, OptiTrack, Qualisys, NOKOV, VRPN, or MotionAnalysis)
- Rigid bodies configured in the mocap system for each Crazyflie

## Quick Start

```bash
uv run mocap_swarm.py
```

## What Happens

When you run the demo:

1. **Connect to Crazyflies** - Opens radio links to all Crazyflies listed in `swarm_config`
2. **Start mocap thread** - Connects to the mocap system and starts streaming positions to each Crazyflie
3. **Configure estimators** - Enables the Kalman estimator on all Crazyflies in parallel
4. **Reset estimators** - Waits for all state estimators to converge
5. **Arm** - Arms all Crazyflies in parallel
6. **Fly square** - All Crazyflies take off to 1 m, fly a 1 m square, then land synchronously
7. **Disconnect** - Closes the mocap thread and radio connections

The demo showcases:
- Feeding position-only (no orientation) external pose data to the Crazyflie
- Using the `Swarm` class to run parallel operations on multiple Crazyflies
- Relative trajectories that work from any starting position on the floor

## Configuration

Edit the top of the script to match your setup:

- `mocap_system_type` — one of `vicon`, `optitrack`, `optitrack_closed_source`, `qualisys`, `nokov`, `vrpn`, `motionanalysis`
- `host_name` — IP or hostname of the mocap system
- `swarm_config` — list of `(radio_uri, rigid_body_name)` pairs for each Crazyflie

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: motioncapture
