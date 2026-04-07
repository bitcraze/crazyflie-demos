# Mocap Swarm Multi Commander

Connects to a motion capture system and feeds positions to multiple Crazyflies, each flying a different trajectory using either the PositionHlCommander or the MotionCommander.

## What You Need

- **Crazyflie platform** (one or more, up to three to exercise all trajectory types)
- **Crazyradio**
- **Motion capture system** (Vicon, OptiTrack, Qualisys, NOKOV, VRPN, or MotionAnalysis)
- Rigid bodies configured in the mocap system for each Crazyflie

## Quick Start

```bash
uv run mocap_swarm_multi_commander.py
```

## What Happens

When you run the demo:

1. **Connect to Crazyflies** - Opens radio links to all Crazyflies listed in `swarm_config`
2. **Start mocap thread** - Connects to the mocap system and starts streaming positions to each Crazyflie
3. **Configure estimators** - Enables the Kalman estimator on all Crazyflies
4. **Reset estimators** - Waits for all state estimators to converge
5. **Fly per-drone sequences** - Each Crazyflie executes a different trajectory in parallel:
   - `cf1`: flies a triangle shape at varying altitudes using `PositionHlCommander`
   - `cf2`: flies back-and-forth at fixed altitude using `PositionHlCommander`
   - `cf3`: performs circular loops using `MotionCommander`
6. **Land** - Each Crazyflie lands when its sequence completes

The demo showcases:
- Mixing `PositionHlCommander` and `MotionCommander` within the same swarm
- Assigning per-drone trajectories based on rigid body name
- Using the `Swarm` class with parallel execution of heterogeneous flight tasks

## Configuration

Edit the top of the script to match your setup:

- `mocap_system_type` — one of `vicon`, `optitrack`, `optitrack_closed_source`, `qualisys`, `nokov`, `vrpn`, `motionanalysis`
- `host_name` — IP or hostname of the mocap system
- `swarm_config` — list of `(radio_uri, rigid_body_name)` pairs; names must match what `run_sequence` branches on (`cf1`, `cf2`, `cf3`)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: motioncapture
