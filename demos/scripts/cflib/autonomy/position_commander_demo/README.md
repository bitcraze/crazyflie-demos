# Position Commander Demo

Demonstrates position-based flight control using the `PositionHlCommander` class, including going to coordinates, relative moves, and landing on elevated surfaces.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- Positioning system (Lighthouse or Loco Positioning System)

## Quick Start

```bash
uv run position_commander_demo.py
```

## What Happens

When you run the demo (default: `simple_sequence`):

1. **Connect** - Connects to the Crazyflie and arms it
2. **Takeoff** - `PositionHlCommander` takes off to the default height
3. **Fly sequence** - Moves forward, left, and back, then flies to an absolute 3D coordinate
4. **Land** - `PositionHlCommander` lands automatically on context exit

The script also contains two additional functions (commented out in `__main__`):
- `slightly_more_complex_usage` — demonstrates `go_to`, `right`, and changing default velocity/height
- `land_on_elevated_surface` — demonstrates landing at a non-zero height (e.g. on a desk)

The demo showcases:
- `PositionHlCommander` absolute and relative position commands
- `go_to` with optional velocity override
- `set_default_velocity` and `set_default_height`
- `default_landing_height` for elevated landing surfaces

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.08
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.33
