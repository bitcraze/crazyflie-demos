use crazyflie_lib::subsystems::memory::{LedDriverMemory, MemoryType};

const URI: &str = "radio://0/80/2M/E7E7E7E7E7";

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let link_context = crazyflie_link::LinkContext::new();
    let cf = crazyflie_lib::Crazyflie::connect_from_uri(&link_context, URI, crazyflie_lib::NoTocCache).await?;

    cf.param.set("ring.effect", 13u8).await?;

    let memories = cf.memory.get_memories(Some(MemoryType::DriverLed));

    if memories.is_empty() {
        println!("No LED driver memory found. Is the LED ring deck attached?");
    } else {
        match cf
            .memory
            .open_memory::<LedDriverMemory>(memories[0].clone())
            .await
        {
            Some(Ok(mut leds)) => {
                leds.leds[0].set(0, 100, 0, None);    // green
                leds.leds[3].set(0, 0, 100, None);    // blue
                leds.leds[6].set(100, 0, 0, None);    // red
                leds.leds[9].set(100, 100, 100, None); // white

                leds.write_leds().await?;
                tokio::time::sleep(std::time::Duration::from_secs(2)).await;

                cf.memory.close_memory(leds).await?;
            }
            Some(Err(e)) => {
                println!("Could not access LED driver memory: {}", e);
            }
            None => {
                println!("LED driver memory not found");
            }
        };
    }

    cf.disconnect().await;

    Ok(())
}
