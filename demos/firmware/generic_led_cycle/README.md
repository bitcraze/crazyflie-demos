# Generic LED Cycle

Cycles any attached LED deck through smooth RGB color transitions using a custom firmware app. Works with the LED ring, Color LED deck, and future LED decks via the generic LED API.

For most use cases, the deck-specific APIs are recommended as they expose the full capabilities of the hardware. See [color_led_cycle](../color_led_cycle/) for an example.

## What You Need

- **Crazyflie platform**
- **Any LED deck** (LED ring, Color LED deck, etc.)

## Setup

Follow the general firmware demo instructions in the [firmware demos README](../README.md).

## What it does

The application cycles through 3 color phases using the generic RGB888 interface, each with 256 steps for smooth transitions:

1. **Red → Green**: Red fades from 255 to 0 while green increases from 0 to 255
2. **Green → Blue**: Green fades from 255 to 0 while blue increases from 0 to 255
3. **Blue → Red**: Blue fades from 255 to 0 while red increases from 0 to 255

Each color transition takes approximately 768ms (256 steps × 3ms per step), resulting in a complete cycle every ~2.3 seconds.

## Generic LED API vs Deck-Specific APIs

The **generic LED API** (`led_deck_ctrl.rgb888` parameter):

- Works with any LED deck (LED ring, Color LED deck, future LED decks)
- Single parameter controls all attached LED decks simultaneously
- Basic RGB888 color control: `0x00RRGGBB`
- No access to deck-specific features

**Deck-specific APIs** (e.g., `colorled.wrgb8888` for the Color LED deck):

- Access to all hardware-specific features (e.g., thermal feedback for the Color LED deck)
- Individual deck control when multiple decks are attached

**Deck-specific APIs are generally recommended** as they expose the full capabilities of your hardware.

**Note:** You can also check which deck is attached at runtime and use the appropriate deck-specific API. This gives you full hardware control while maintaining flexibility.

## Technical Details

- Uses the `led_deck_ctrl.rgb888` parameter to control any attached LED deck
- Updates colors every 3ms using `vTaskDelayUntil(&lastWakeTime, M2T(3))` for consistent timing
- Color values are packed into a 32-bit format: `0x00RRGGBB` (RGB888 standard)

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2026.4