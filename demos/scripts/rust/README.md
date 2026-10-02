# Rust Demos

Rust examples using [crazyflie-lib-rs](https://github.com/bitcraze/crazyflie-lib-rs) to control Crazyflie drones.

Each demo is a self-contained Cargo package with its own `Cargo.toml` declaring its dependencies.

## Prerequisites

Install the Rust toolchain via [rustup](https://rustup.rs/):

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

## Running a Demo

```bash
cd demos/scripts/rust/<category>/<demo>
cargo run
```

Cargo fetches dependencies, compiles, and runs the binary. On subsequent runs it reuses the build cache.
