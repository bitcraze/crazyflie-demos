# Radio Test

Scans all 126 radio channels (0–125), measures acknowledgement rate and RSSI for each, then plots the results and suggests the best channels to use.

## What You Need

- **Crazyflie platform** (must be using default address `0xE7E7E7E7E7`)
- **Crazyradio**
- Crazyflie nRF firmware built with `CFLAGS += -DRSSI_ACK_PACKET=1` in `config.mk` (for RSSI feedback)

## Quick Start

```bash
uv run radio_test.py
```

Optional arguments:

```bash
uv run radio_test.py --try 200 --channel 80 --rate 2 --fraction 0.25
```

## What Happens

When you run the demo:

1. **Scan channels** - For each channel 0–125, the script temporarily tunes both the Crazyradio and the Crazyflie to that channel, sends `TRY` packets, and records the acknowledgement rate and RSSI
2. **Restore channel** - After scanning, the Crazyflie is commanded back to its default channel
3. **Rank channels** - Channels are ranked by RSSI (lower is better) and ACK rate (higher is better); the intersection of the top `fraction` from each metric is the suggested set
4. **Plot** - Displays a dual-axis plot: ACK rate (blue) and RSSI with standard deviation (red/orange), with suggested channels marked in blue vertical lines

The demo showcases:
- Direct use of the low-level `crazyradio` driver
- Measuring 2.4 GHz channel quality to find interference-free channels

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: matplotlib, numpy
