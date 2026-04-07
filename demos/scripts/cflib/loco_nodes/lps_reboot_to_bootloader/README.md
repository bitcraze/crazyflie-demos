# LPS Reboot to Bootloader

Connects to a Crazyflie and uses it as a bridge to send reboot-to-bootloader commands to 6 Loco Positioning System anchors (IDs 0–5), repeating each command 10 times for reliability.

## What You Need

- **Crazyflie platform**
- **Crazyradio**
- **Loco Positioning deck**
- **Loco Positioning System anchors**

## Quick Start

```bash
uv run lps_reboot_to_bootloader.py
```

## What Happens

When you run the demo:

1. **Connect** - Connects to the Crazyflie
2. **Reboot anchors** - Sends `REBOOT_TO_BOOTLOADER` to anchor IDs 0–5, 10 times each, via the `LoPoAnchor` class
3. **Disconnect** - Closes the link after all commands are sent

This is useful for putting LPS anchors into bootloader mode for firmware updates.

The demo showcases:
- `LoPoAnchor.reboot` with `REBOOT_TO_BOOTLOADER` for remote anchor management via the Crazyflie link

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2025.12.1
- cflib:
  - repo: https://github.com/bitcraze/crazyflie-lib-python.git
  - ref: 0.1.31
- extra: lpslib
