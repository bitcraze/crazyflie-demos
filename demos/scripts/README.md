# Scripts

Host-side scripts that communicate with a Crazyflie over radio. Each script runs on the computer and sends commands to the drone in real time with no custom firmware needed.

## Categories

| Category | Language / Library | Description |
|----------|--------------------|-------------|
| [cflib](cflib/) | Python / [crazyflie-lib-python](https://github.com/bitcraze/crazyflie-lib-python) | Broad Python library covering the full Crazyflie API with many examples |
| [rust](rust/) | Rust / [crazyflie-lib-rs](https://github.com/bitcraze/crazyflie-lib-rs) | High-performance Rust alternative with a focused API and async support |

## Firmware Prerequisite

Each script runs against a **Crazyflie firmware release** listed in its README under **Dependencies**. Flash the official release using [cfclient](https://github.com/bitcraze/crazyflie-clients-python) before running any script.
