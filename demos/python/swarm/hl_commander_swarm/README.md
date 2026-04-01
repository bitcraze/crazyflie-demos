# High Level Commander Swarm

Flies a swarm of Crazyflies in a synchronous square choreography using the high level commander — all drones execute the same relative sequence in parallel.

## What You Need

- **2+ Crazyflie platforms** (URIs must be on the same radio channel)
- **Crazyradio**
- An absolute positioning system (e.g., Lighthouse, LPS)

## Quick Start

```bash
uv run hl_commander_swarm.py
```

## What Happens

When you run the demo:

1. **Connect** - Opens radio links to all Crazyflies listed in `uris`
2. **Reset estimators** - Resets all Kalman filters
3. **Arm** - Arms all Crazyflies in parallel
4. **Fly square** - All drones simultaneously:
   - Take off to 1.0 m
   - Fly a 1 m square (four `go_to` commands, each 2 s)
   - Land
5. **Stop** - Sends stop command

The demo showcases:
- Sharing the same flight function across all drones with `parallel_safe()`
- Relative `go_to` commands so any starting floor position works
- Optionally switching to the Mellinger controller (uncomment in `run_shared_sequence`)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
