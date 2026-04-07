# Firmware Demos

Firmware demos are custom out-of-tree firmware apps that run directly on the Crazyflie. Flashing is done via cfclient's cfloader, which is managed through a per-demo Python environment.

## How It Works

Each firmware demo contains:

- An `app/` directory with the out-of-tree firmware app
- A `crazyflie-firmware` git submodule inside `app/` — the firmware release used as the build base
- A `pyproject.toml` for the flashing environment (cfclient/cfloader)
- A `README.md` containing details about the demo

The submodule is **not cloned automatically** when you clone the repo. You initialize it per-demo, so you only download what you need.

## General Workflow

### 1. Navigate to the demo folder

```bash
cd demos/firmware/<demo_name>
```

### 2. Flash the release firmware (if needed)

Flash the required firmware release using the [Crazyflie client](https://www.bitcraze.io/documentation/repository/crazyflie-clients-python/master/userguides/userguide_client/#firmware-upgrade) to ensure the nRF and deck firmwares are up to date. The required release version is listed in each demo's README under **Dependencies**.

### 3. Initialize the firmware submodule

```bash
git submodule update --init --recursive --depth 1 app/crazyflie-firmware
```

### 4. Set up the Python environment

```bash
uv sync
```

This creates a `.venv` with cfclient installed, which provides the cfloader used for flashing.

### 5. Build the custom firmware app

```bash
cd app
make <defconfig>
make -j$(nproc)
```

The required defconfig depends on your platform (e.g. `cf2_defconfig` for Crazyflie 2.x, `cf21bl_defconfig` for Crazyflie 2.1 Brushless). For a full list of available targets and platform details, see the [Crazyflie firmware build documentation](https://github.com/bitcraze/crazyflie-firmware/blob/master/docs/building-and-flashing/build.md).

### 6. Flash the custom firmware app

Activate the venv so `make cload` can find cfloader, then flash:

```bash
source ../.venv/bin/activate
CLOAD_CMDS="-w [CRAZYFLIE_URI]" make cload
```

Replace `[CRAZYFLIE_URI]` with your Crazyflie's URI (e.g. `radio://0/80/2M/E7E7E7E7E7`). For more details on flashing, see the [Crazyflie firmware flashing documentation](https://github.com/bitcraze/crazyflie-firmware/blob/master/docs/building-and-flashing/build.md#flashing).

## Available Demos

| Demo | Description |
|------|-------------|
| [color_led_cycle](color_led_cycle/README.md) | Cycles the Color LED deck through smooth WRGB color transitions |
