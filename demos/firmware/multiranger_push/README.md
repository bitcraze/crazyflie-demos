# Multiranger Push

Interactive hovering demo using the Multiranger and Flow deck v2. The Crazyflie hovers and reacts to hand proximity. Push it around by bringing your hands close to any of the four side sensors.

## What You Need

- **Crazyflie 2.x**
- **Multiranger deck**
- **Flow deck v2**

## How It Works

Activation and stopping are proximity-based using the top range sensor:

1. Place a hand close (< 10 cm) on **top** of the Crazyflie
2. Remove the hand - the Crazyflie takes off and hovers at 0.2 m
3. Place a hand close to the **top** again (or push it below 10 cm) to land

Once hovering, each side sensor repels the drone:
- **Left/right sensors**: push the Crazyflie sideways
- **Front/back sensors**: push it forward/backward
- **Both sides simultaneously** (< 10 cm): drone rises
- **Both front and back simultaneously** (< 10 cm), or obstacle above (< 30 cm): drone descends

## Dependencies

- firmware:
  - repo: https://github.com/bitcraze/crazyflie-firmware.git
  - ref: 2026.04
- cfclient:
  - repo: https://github.com/bitcraze/crazyflie-clients-python.git
  - ref: 2026.4
