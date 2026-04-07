# Leader Follower

Flies two Crazyflies in a leader-follower scenario: the leader executes a pre-defined trajectory while the follower uses real-time position data to maintain a fixed distance from the leader.

## What You Need

- **2 Crazyflie platforms**
- **Crazyradio**
- **Lighthouse positioning system**

## Quick Start

```bash
uv run leader_follower.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to both Crazyflies (URI1 = follower, URI2 = leader)
2. **Reset estimators and arm** - Resets Kalman filters and arms both drones
3. **Start position logging** - Streams position and yaw from both drones at 100 Hz into shared lists
4. **Take off** - Both drones take off to 0.75 m using `MotionCommander`
5. **Alignment phase** - The follower rotates until its yaw is within 2° of zero (aligned with global frame); the leader hovers
6. **Leader-follower phase (20 s)**:
   - Leader: flies forward 3 s, back 3 s, then circles right for the remainder
   - Follower: continuously computes velocity toward the leader if `d > r_max` (1.0 m), stays still if within `[r_min, r_max]` (0.8–1.0 m), or moves away if `d < r_min` (0.8 m)
7. **Land** - Both drones land when the 20 s window ends

The demo showcases:
- Using shared global state (position lists) to coordinate drones across parallel `parallel_safe` threads
- Real-time velocity computation from position data
- Mixing pre-defined leader trajectories with reactive follower control

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
