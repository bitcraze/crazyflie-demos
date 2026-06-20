const URI: &str = "radio://0/55/2M/BADC0DE013";

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let link_context = crazyflie_link::LinkContext::new();
    let cf = crazyflie_lib::Crazyflie::connect_from_uri(&link_context, URI, crazyflie_lib::NoTocCache).await?;

    // Solid red
    cf.param.set("ring.effect", 7u8).await?;
    cf.param.set("ring.solidRed", 100u8).await?;
    cf.param.set("ring.solidGreen", 0u8).await?;
    cf.param.set("ring.solidBlue", 0u8).await?;
    tokio::time::sleep(std::time::Duration::from_secs(2)).await;

    // Off
    cf.param.set("ring.effect", 0u8).await?;
    tokio::time::sleep(std::time::Duration::from_secs(1)).await;

    // Fade to color
    cf.param.set("ring.effect", 14u8).await?;
    cf.param.set("ring.fadeTime", 1.0f32).await?;
    cf.param.set("ring.fadeColor", 0x0000A0u32).await?; // blue
    tokio::time::sleep(std::time::Duration::from_secs(1)).await;
    cf.param.set("ring.fadeColor", 0x00A000u32).await?; // green
    tokio::time::sleep(std::time::Duration::from_secs(1)).await;
    cf.param.set("ring.fadeColor", 0xA00000u32).await?; // red
    tokio::time::sleep(std::time::Duration::from_secs(1)).await;

    cf.disconnect().await;

    Ok(())
}
