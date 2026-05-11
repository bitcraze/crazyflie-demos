# Hybrid Demos

Hybrid demos combine a custom out-of-tree firmware app with a host-side script. The firmware app runs on the Crazyflie itself, while the script runs on your computer and communicates with it over radio.

## How It Works

Each hybrid demo contains:

- A host-side script
- A `pyproject.toml` for dependencies
- An `app/` directory with the out-of-tree firmware app
- A `crazyflie-firmware` git submodule inside `app/` — the firmware release used as the build base
- A `README.md` containing details about the demo

The submodule is **not cloned automatically** when you clone the repo. You initialize it per-demo, so you only download what you need.

## General Workflow

### 1. Navigate to the demo folder

```bash
cd demos/hybrid/<demo_name>
```

### 2. Flash the release firmware (if needed)

Flash the required firmware release using the [Crazyflie client](https://www.bitcraze.io/documentation/repository/crazyflie-clients-python/master/userguides/userguide_client/#firmware-upgrade) to ensure the nRF and deck firmwares are up to date. The required release version is listed in each demo's README under **Dependencies**.

### 3. Initialize the firmware submodule

```bash
git submodule update --init --recursive --depth 1 app/crazyflie-firmware
```

### 4. Set up the environment

```bash
uv sync
```

This creates a `.venv` with cfloader (needed for flashing) and, for Python demos, the script's dependencies.

### 5. Build the custom firmware app

```bash
cd app
make <defconfig>
make -j$(nproc)
```

The required defconfig depends on your platform (e.g. `cf2_defconfig` for Crazyflie 2.x, `cf21bl_defconfig` for Crazyflie 2.1 Brushless). The correct one is listed in each demo's README. For a full list of available targets and platform details, see the [Crazyflie firmware build documentation](https://github.com/bitcraze/crazyflie-firmware/blob/master/docs/building-and-flashing/build.md).

### 6. Flash the custom firmware app

Activate the venv so `make cload` can find cfloader, then flash:

```bash
source ../.venv/bin/activate
CLOAD_CMDS="-w [CRAZYFLIE_URI]" make cload
```

Replace `[CRAZYFLIE_URI]` with your Crazyflie's URI (e.g. `radio://0/80/2M/E7E7E7E7E7`). For more details on flashing, see the [Crazyflie firmware flashing documentation](https://github.com/bitcraze/crazyflie-firmware/blob/master/docs/building-and-flashing/build.md#flashing).

### 7. Run the script

For Python demos:

```bash
cd ..
uv run <script>.py
```

## Available Demos

| Demo | Description |
|------|-------------|
| [appchannel_test](appchannel_test/README.md) | Sends three floats to the Crazyflie over the appchannel and receives their sum back |
| [christmas_tree](christmas_tree/README.md) | 8 Crazyflies flying a spiral Christmas tree choreography with position-based LED effects |
