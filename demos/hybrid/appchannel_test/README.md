# Appchannel Test

Demonstrates the appchannel API: the host script sends packets containing three floats (x, y, z) to the Crazyflie, and the firmware replies with their sum as a single float.

## What You Need

- **Crazyflie platform**
- **Crazyradio**

## Setup

Follow the general hybrid demo instructions in the [hybrid demos README](../README.md).

## Running

Edit the `URI` variable at the top of `appchannel_test.py` to match your Crazyflie's address, then run:

```bash
uv run appchannel_test.py
```

## What Happens

When you run the demo:

1. **Connect** - The script connects to the Crazyflie
2. **Send** - Sends 10 packets, each containing three floats (x, y, z) spaced 1 second apart
3. **Receive** - Prints the sum (x + y + z) returned by the Crazyflie for each packet
4. **Disconnect** - Closes the link after all packets have been sent

The custom firmware runs on the Crazyflie and waits for incoming appchannel packets. For each received packet it computes the sum of the three floats and sends it back.

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04 (base release + `app/` out-of-tree app built on top)
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.32
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2026.4
