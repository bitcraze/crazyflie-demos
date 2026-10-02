# Color LED Effects

Multiple WRGB LED effects for the Color LED deck, switchable at runtime via a parameter. Supports both top- and bottom-mounted decks.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Color LED deck** (top or bottom mount, or both)

## Setup

Follow the general firmware demo instructions in the [firmware demos README](../README.md).

## Effects

Switch between effects using the `colorLED.effect` parameter (e.g. via cfclient or cflib):

| Value | Effect |
|-------|--------|
| 0 | **Off / Default** — LEDs left under normal deck control |
| 1 | **LED Cycle** — smooth WRGB color cycle (Red → Green → Blue → White) |
| 2 | **XYZ Color Mapping** — drone position mapped to RGB (X→Red, Y→Green, Z→Blue) |
| 3 | **Velocity Indicator** — speed shown as Blue (slow) → Green → Red (fast) |
| 4 | **Snowflake** — white LEDs pulse sinusoidally, brightness scales with height |
| 5 | **Flicker** — both decks flicker independently in gold, simulating a flame |

## Technical Details

- Uses `colorLedBot.wrgb8888` / `colorLedTop.wrgb8888` parameters to control whichever decks are attached
- Enables `brightCorr` on startup for perceptually uniform colors
- Monitors thermal throttling every 100ms and prints warnings to the debug console
- Color mapping bounds and velocity scale are compile-time constants in [app/src/led_effects.c](app/src/led_effects.c)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2026.8
