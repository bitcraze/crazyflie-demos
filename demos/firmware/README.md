# Firmware Demos

Firmware demos run directly on the Crazyflie, no host-side script needed. Flashing is done via cfloader, which is managed through a per-demo Python environment.

## How It Works

Each firmware demo contains:

- An `app/` directory with the out-of-tree firmware app
- A `crazyflie-firmware` git submodule inside `app/` — the firmware release used as the build base
- A `pyproject.toml` for the flashing environment (cfloader)
- A `README.md` containing details about the demo

The submodule is **not cloned automatically** when you clone the repo. You initialize it per-demo, so you only download what you need.

## General Workflow

### 1. Navigate to the demo folder

```bash
cd demos/firmware/<demo_name>
```

### 2. Flash the release firmware (if needed)

Flash the required firmware release using the [Crazyflie client](https://www.bitcraze.io/documentation/repository/crazyflie-clients-python/master/userguides/userguide_client/#firmware-upgrade) to ensure the nRF and deck firmwares match the version required by the demo. The required release version is listed in each demo's README under **Dependencies**.

### 3. Initialize the firmware submodule

Each demo includes the crazyflie-firmware as a submodule, which provides the build system and platform support needed to compile the app. Run this from the demo's root directory to fetch it:

```bash
git submodule update --init --recursive --depth 1 app/crazyflie-firmware
```

### 4. Set up the Python environment

This project uses [uv](https://docs.astral.sh/uv/) for Python dependency management. If you don't have it installed, follow the [installation instructions](https://docs.astral.sh/uv/getting-started/installation/).

```bash
uv sync
```

This creates a `.venv` with cfloader installed, which is used for flashing.

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

Once flashing is complete, the Crazyflie will reboot and the app will start running automatically.

## Available Demos

| Demo | Description |
|------|-------------|
| [color_led_cycle](color_led_cycle/README.md) | Cycles the Color LED deck through smooth WRGB color transitions |
| [color_led_effects](color_led_effects/README.md) |  Introduces multiple WRGB LED effects for the Color LED deck |
| [color_led_tilt](color_led_tilt/README.md) | Maps gyroscope rotation to Color LED deck colors — shake or spin the drone to change the light |
| [generic_led_cycle](generic_led_cycle/README.md) | Cycles any LED deck through smooth WRGB color transitions |
| [multiranger_push](multiranger_push/README.md) | Hover and react to hand proximity - push the Crazyflie around using the Multiranger deck |
| [multiranger_wall_following](multiranger_wall_following/README.md) | Autonomous wall following using the Multiranger and Flow deck |
