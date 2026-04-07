# Python Demos

Python examples using the cflib python library to control Crazyflie drones.

Each demo is self-contained with its own `pyproject.toml` declaring its dependencies.

## Running with uv (recommended)

[uv](https://docs.astral.sh/uv/) handles the virtual environment automatically:

```bash
cd demos/python/<category>/<demo>
uv run <script>.py
```

uv creates a `.venv` in the demo directory, installs dependencies, and runs the script. On subsequent runs it reuses the existing environment.

## Running with pip

```bash
cd demos/python/<category>/<demo>
python -m venv .venv
source .venv/bin/activate
pip install -e .
python <script>.py
```
