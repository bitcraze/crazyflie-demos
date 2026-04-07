# Color LED Cycle

Cycles the Color LED deck through smooth WRGB color transitions using a custom firmware app. The deck is automatically detected (top or bottom mount).

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck**

## Setup

Follow the general firmware demo instructions in the [firmware demos README](../README.md).

## What Happens

The application cycles through 4 distinct color phases, each with 256 steps for smooth transitions:

1. **Red → Green**: Red fades from 255 to 0 while green increases from 0 to 255
2. **Green → Blue**: Green fades from 255 to 0 while blue increases from 0 to 255
3. **Blue → White**: Blue fades from 255 to 0 while white increases from 0 to 255
4. **White → Red**: White fades from 255 to 0 while red increases from 0 to 255

Each color transition takes approximately 768ms (256 steps × 3ms per step), resulting in a complete cycle every ~3 seconds.

## Technical details

- Uses the `colorled.wrgb8888` parameter to control the Color LED deck
- Enables `colorled.brightnessCorr` for perceptually uniform colors by balancing luminance across W/R/G/B channels (disable for maximum brightness per channel)
- Updates colors every 3ms using `vTaskDelayUntil(&lastWakeTime, M2T(3))` for consistent timing
- Color values are packed into a 32-bit format: `0xWWRRGGBB`
- Monitors thermal throttling via the `colorled.deckTemp` and `colorled.throttlePct` log variables
- Prints warnings to the debug console if thermal throttling is detected (checked every 100ms)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2025.12.1
