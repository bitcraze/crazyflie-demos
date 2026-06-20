use crazyflie_lib::subsystems::memory::{MemoryType, Poly4D, Poly, TrajectoryMemory};
use crazyflie_link::LinkContext;
use crazyflie_lib::Crazyflie;
use tokio::time::{sleep, Duration};

const URI: &str = "radio://0/80/2M/E7E7E7E7E7";
const TRAJECTORY_ID: u8 = 1;
const TRAJECTORY_DURATION_S: f64 = 7.3;

// Figure-8 trajectory. Each row: [duration, x0..x7, y0..y7, z0..z7, yaw0..yaw7]
// Generated with https://github.com/whoenig/uav_trajectories
#[rustfmt::skip]
const FIGURE8: &[[f32; 33]] = &[
    [1.050000,  0.000000, -0.000000,  0.000000, -0.000000,  0.830443, -0.276140, -0.384219,  0.180493, -0.000000,  0.000000, -0.000000,  0.000000, -1.356107,  0.688430,  0.587426, -0.329106,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.710000,  0.396058,  0.918033,  0.128965, -0.773546,  0.339704,  0.034310, -0.026417, -0.030049, -0.445604, -0.684403,  0.888433,  1.493630, -1.361618, -0.139316,  0.158875,  0.095799,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.620000,  0.922409,  0.405715, -0.582968, -0.092188, -0.114670,  0.101046,  0.075834, -0.037926, -0.291165,  0.967514,  0.421451, -1.086348,  0.545211,  0.030109, -0.050046, -0.068177,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.700000,  0.923174, -0.431533, -0.682975,  0.177173,  0.319468, -0.043852, -0.111269,  0.023166,  0.289869,  0.724722, -0.512011, -0.209623, -0.218710,  0.108797,  0.128756, -0.055461,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.560000,  0.405364, -0.834716,  0.158939,  0.288175, -0.373738, -0.054995,  0.036090,  0.078627,  0.450742, -0.385534, -0.954089,  0.128288,  0.442620,  0.055630, -0.060142, -0.076163,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.560000,  0.001062, -0.646270, -0.012560, -0.324065,  0.125327,  0.119738,  0.034567, -0.063130,  0.001593, -1.031457,  0.015159,  0.820816, -0.152665, -0.130729, -0.045679,  0.080444,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.700000, -0.402804, -0.820508, -0.132914,  0.236278,  0.235164, -0.053551, -0.088687,  0.031253, -0.449354, -0.411507,  0.902946,  0.185335, -0.239125, -0.041696,  0.016857,  0.016709,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.620000, -0.921641, -0.464596,  0.661875,  0.286582, -0.228921, -0.051987,  0.004669,  0.038463, -0.292459,  0.777682,  0.565788, -0.432472, -0.060568, -0.082048, -0.009439,  0.041158,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [0.710000, -0.923935,  0.447832,  0.627381, -0.259808, -0.042325, -0.032258,  0.001420,  0.005294,  0.288570,  0.873350, -0.515586, -0.730207, -0.026023,  0.288755,  0.215678, -0.148061,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
    [1.053185, -0.398611,  0.850510, -0.144007, -0.485368, -0.079781,  0.176330,  0.234482, -0.153567,  0.447039, -0.532729, -0.855023,  0.878509,  0.775168, -0.391051, -0.713519,  0.391628,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
];

fn figure8_segments() -> Vec<Poly4D> {
    FIGURE8.iter().map(|row| {
        Poly4D::new(
            row[0],
            Poly::from_slice(&row[1..9]),
            Poly::from_slice(&row[9..17]),
            Poly::from_slice(&row[17..25]),
            Poly::from_slice(&row[25..33]),
        )
    }).collect()
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let context = LinkContext::new();
    let cf = Crazyflie::connect_from_uri(&context, URI, crazyflie_lib::NoTocCache).await?;

    // Upload trajectory
    println!("Uploading trajectory...");
    let segments = figure8_segments();
    let num_pieces = segments.len() as u8;
    let memories = cf.memory.get_memories(Some(MemoryType::Trajectory));
    match cf.memory.open_memory::<TrajectoryMemory>(memories[0].clone()).await {
        Some(Ok(traj_mem)) => {
            traj_mem.write_uncompressed(&segments, 0).await?;
            cf.memory.close_memory(traj_mem).await?;
        }
        Some(Err(e)) => return Err(e.into()),
        None => return Err("Failed to open trajectory memory".into()),
    }
    cf.high_level_commander.define_trajectory(TRAJECTORY_ID, 0, num_pieces, None).await?;
    println!("Trajectory uploaded ({:.1}s)", TRAJECTORY_DURATION_S);

    // Reset estimator
    cf.param.set("kalman.resetEstimation", 1u8).await?;
    sleep(Duration::from_millis(100)).await;
    cf.param.set("kalman.resetEstimation", 0u8).await?;
    sleep(Duration::from_secs(1)).await;

    // Arm and fly
    cf.platform.send_arming_request(true).await?;
    sleep(Duration::from_secs(1)).await;

    println!("Taking off...");
    if let Err(e) = cf.high_level_commander.take_off(1.0, None, 2.0, None).await {
        eprintln!("Take-off failed: {e}");
    }
    sleep(Duration::from_secs(3)).await;

    println!("Starting trajectory...");
    if let Err(e) = cf.high_level_commander.start_trajectory(TRAJECTORY_ID, 1.0, true, false, false, None).await {
        eprintln!("Start trajectory failed: {e}");
    }
    sleep(Duration::from_secs_f64(TRAJECTORY_DURATION_S)).await;

    println!("Landing...");
    if let Err(e) = cf.high_level_commander.land(0.0, None, 2.0, None).await {
        eprintln!("Land failed: {e}");
    }
    sleep(Duration::from_secs(2)).await;

    cf.high_level_commander.stop(None).await?;
    println!("Done");

    cf.disconnect().await;
    Ok(())
}
