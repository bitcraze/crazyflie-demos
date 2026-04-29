# Multiranger Wall Following

Autonomous wall-following demo using the Multiranger and Flow deck v2. The Crazyflie flies alongside walls, navigates corners, and can be stopped by placing a hand above it.

Based on the minimal navigation solution described in:
> McGuire et al., *Minimal navigation solution for a swarm of tiny flying robots to explore an unknown environment*, Science Robotics, 2019.

## What You Need

- **Crazyflie 2.x**
- **Multiranger deck**
- **Flow deck v2**

## How It Works

Activation and stopping are proximity-based using the top range sensor:

1. Place a hand close (< 10 cm) on **top** of the Crazyflie
2. Remove the hand - the Crazyflie takes off and begins wall following
3. Place a hand close to the **top** again to land

While flying, the Crazyflie maintains a set distance from the nearest wall and navigates corners automatically. Height is adjusted to avoid obstacles detected above.

## Parameters

| Parameter | Type | Default | Description |
|-----------|------|---------|-------------|
| `app.goLeft` | uint8 | 0 | Follow wall on the left (1) or right (0) |
| `app.distanceWall` | float | 0.5 m | Target distance from wall |
| `app.maxSpeed` | float | 0.5 m/s | Maximum forward speed |

## Log Variables

| Variable | Description |
|----------|-------------|
| `app.cmdVelX` | Commanded forward velocity |
| `app.cmdVelY` | Commanded side velocity |
| `app.cmdAngWRad` | Commanded yaw rate (rad/s) |
| `app.stateInnerLoop` | Wall-following state machine state |
| `app.stateOuterLoop` | Outer loop state (idle/unlocked/stopping) |

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2026.4
