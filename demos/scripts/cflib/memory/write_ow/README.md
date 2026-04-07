# Write 1-Wire Memory

Connects to the Crazyflie, writes test board name and revision values to the first 1-wire memory found, then reads them back to verify.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Any deck that has a 1-wire memory**

## Quick Start

```bash
uv run write_ow.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Find memory** - Enumerates memories of type `TYPE_1W`
3. **Write** - Sets VID:PID to `0x00:0x00` and writes `board_name = 'Hello deck'`, `board_rev = 'A'`
4. **Read back** - Calls `mem.update` to verify the written values and prints all fields
5. **Disconnect** - Closes the link after verification

Setting VID:PID to `0x00:0x00` instructs the Crazyflie to match the driver by board name rather than by vendor/product IDs.

The demo showcases:
- `MemoryElement.TYPE_1W` and `OWElement.element_mapping` for 1-wire memory write access
- `mem.write_data` followed by `mem.update` for write-then-verify

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
