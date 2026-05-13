# High-Level Commander

Demonstrates autonomous flight using the high-level commander: take off, move to positions, fly a spiral, and land.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Flow deck v2 or Positioning system**

## Quick Start

Edit the URI in `high_level_commander.rs` to match your Crazyflie's radio address, then:

```bash
cargo run
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Takes off** - Rises to 0.5 m
3. **Moves** to two waypoints
4. **Spiral** - Flies a full 360° spiral
5. **Lands** - Returns to ground and stops motors

The demo shows a resilient error-handling pattern: individual command failures are logged but do not crash the program, leaving the drone in a controlled state.

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
