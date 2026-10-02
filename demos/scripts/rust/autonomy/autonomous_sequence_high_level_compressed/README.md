# Autonomous Sequence - High Level Commander (Compressed)

Demonstrates autonomous flight by uploading a compressed polynomial figure-8 trajectory to the Crazyflie and executing it with the high-level commander.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck v2 or Positioning system**

## Quick Start

Edit the URI in `autonomous_sequence_high_level_compressed.rs` to match your Crazyflie's radio address, then:

```bash
cargo run
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Uploads** a compressed figure-8 trajectory to trajectory memory
3. **Resets** the Kalman estimator
4. **Takes off** - Rises to 1.0 m
5. **Flies figure-8** - Executes the trajectory relative to the starting position
6. **Lands** - Returns to ground and stops motors

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04
- crazyflie-lib-rs:
  - repo: https://github.com/bitcraze/crazyflie-lib-rs.git
  - ref: 0.7.0
- crazyflie-link-rs:
  - repo: https://github.com/bitcraze/crazyflie-link-rs.git
  - ref: 0.4.3
