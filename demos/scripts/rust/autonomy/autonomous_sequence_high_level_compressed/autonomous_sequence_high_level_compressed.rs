use crazyflie_lib::subsystems::memory::{MemoryType, CompressedStart, CompressedSegment, TrajectoryMemory};
use crazyflie_lib::subsystems::high_level_commander::TRAJECTORY_TYPE_POLY4D_COMPRESSED;
use crazyflie_link::LinkContext;
use crazyflie_lib::Crazyflie;
use tokio::time::{sleep, Duration};

const URI: &str = "radio://0/80/2M/E7E7E7E7E7";
const TRAJECTORY_ID: u8 = 1;
const TRAJECTORY_DURATION_S: u64 = 8;

const A: f32 = 0.9;
const B: f32 = 0.5;
const C: f32 = 0.5;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let context = LinkContext::new();
    let cf = Crazyflie::connect_from_uri(&context, URI, crazyflie_lib::NoTocCache).await?;

    // Upload compressed trajectory
    println!("Uploading trajectory...");
    let start = CompressedStart::new(0.0, 0.0, 0.0, 0.0);
    let segments = vec![
        CompressedSegment::new(2.0, vec![0.0, 1.0, 1.0], vec![0.0,  A,  0.0], vec![], vec![])?,
        CompressedSegment::new(2.0, vec![1.0, B,  0.0], vec![-A,  -C,  0.0], vec![], vec![])?,
        CompressedSegment::new(2.0, vec![-B, -1.0, -1.0], vec![C,   A,  0.0], vec![], vec![])?,
        CompressedSegment::new(2.0, vec![-1.0, 0.0, 0.0], vec![-A,  0.0, 0.0], vec![], vec![])?,
    ];
    let num_pieces = segments.len() as u8;
    let memories = cf.memory.get_memories(Some(MemoryType::Trajectory));
    match cf.memory.open_memory::<TrajectoryMemory>(memories[0].clone()).await {
        Some(Ok(traj_mem)) => {
            traj_mem.write_compressed(&start, &segments, 0).await?;
            cf.memory.close_memory(traj_mem).await?;
        }
        Some(Err(e)) => return Err(e.into()),
        None => return Err("Failed to open trajectory memory".into()),
    }
    cf.high_level_commander.define_trajectory(TRAJECTORY_ID, 0, num_pieces, Some(TRAJECTORY_TYPE_POLY4D_COMPRESSED)).await?;
    println!("Trajectory uploaded ({}s)", TRAJECTORY_DURATION_S);

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
    sleep(Duration::from_secs(TRAJECTORY_DURATION_S)).await;

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
