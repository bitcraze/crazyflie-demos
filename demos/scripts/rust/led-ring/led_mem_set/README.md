# LED Ring - Memory Set

Connects to a Crazyflie and sets individual LEDs on the LED-ring deck by writing directly to LED memory.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **LED-ring deck**

## Quick Start

Edit the URI in `led_mem_set.rs` to match your Crazyflie's radio address, then:

```bash
cargo run
```

## What Happens

When you run the demo:

1. **Connects** to the Crazyflie at the specified URI
2. **Sets** the ring effect to memory-controlled mode
3. **Writes** RGB values to four individual LEDs:
   - LED 0: green
   - LED 3: blue
   - LED 6: red
   - LED 9: white
4. **Waits** 2 seconds, then disconnects

The demo showcases:
- Writing to LED memory via crazyflie-lib-rs
- Controlling individual LEDs on the LED-ring deck

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
