# LED Ring - Parameter Set

Demonstrates controlling the LED-ring deck by setting `ring.*` parameters directly - including solid color and fade-to-color effects.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **LED-ring deck**

## Quick Start

Edit the URI in `led_param_set.rs` to match your Crazyflie's radio address, then:

```bash
cargo run
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Solid red** - Sets effect 7 (solid color) with red at value 100 for 2 seconds
3. **Off** - Sets effect 0 (off) for 1 second
4. **Fade** - Sets effect 14 (fade to color) with a 1-second fade time, cycling through blue, green, and red

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
