# LED Ring

Connects to a Crazyflie and sets individual LEDs on the LED-ring deck by writing directly to LED memory.

## What You Need

- **Crazyflie platform**
- **LED-ring deck**
- **Crazyradio**

## Quick Start

```bash
uv run led_mem_set.py
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
- Writing to LED memory via cflib
- Controlling individual LEDs on the LED-ring deck

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.30
