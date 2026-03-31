# Python Demos

Python examples using crazyflie-lib-python to control Crazyflie drones.

Each script declares its own dependencies using [PEP 723 inline metadata](https://peps.python.org/pep-0723/).

## Running with uv (recommended)

[uv](https://docs.astral.sh/uv/) handles the environment automatically:

```bash
uv run path/to/script.py
```

Scripts with identical dependencies share a cached environment - uv only installs once and reuses it. Scripts pinned to a different version get their own separate environment automatically.

## Running with pip

Check the dependency block at the top of the script, for example:

```python
# /// script
# dependencies = [
#   "cflib @ git+https://github.com/bitcraze/crazyflie-lib-python.git@0.1.31",
# ]
# ///
```

Then create a virtual environment and install the listed dependencies:

```bash
python -m venv .venv
source .venv/bin/activate
pip install "cflib @ git+https://github.com/bitcraze/crazyflie-lib-python.git@0.1.31"
python path/to/script.py
```

Replace the cflib ref with whatever version is specified in the script.
