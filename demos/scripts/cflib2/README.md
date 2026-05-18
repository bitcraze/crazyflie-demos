# cflib2 Demos

Python examples using [cflib2](https://github.com/bitcraze/crazyflie-lib-python-v2), the async Rust-powered Python library for Crazyflie drones.

cflib2 is a ground-up rewrite of the original cflib with an async-first API. It is not API-compatible with cflib. Building cflib2 from source requires a Rust toolchain.

Each demo is self-contained with its own `pyproject.toml` declaring its dependencies.

## Prerequisites

- [uv](https://docs.astral.sh/uv/) package manager
- [Rust toolchain](https://rustup.rs/) (required to build cflib2 from source)

## Running with uv (recommended)

```bash
cd demos/scripts/cflib2/<category>/<demo>
uv run <script>.py
```

uv creates a `.venv` in the demo directory, installs dependencies (compiling the Rust extension), and runs the script. On subsequent runs it reuses the existing environment.

## Running with pip

```bash
cd demos/scripts/cflib2/<category>/<demo>
python3 -m venv .venv
source .venv/bin/activate
pip install -e .
python3 <script>.py
```
