#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "app.h"

#include "FreeRTOS.h"
#include "task.h"

#include "debug.h"

#include "log.h"
#include "param.h"

// Center of the tree
#define X0 0.0f
#define Y0 0.0f

#define DEBUG_MODULE "LEDCHRISTMAS"
#define M_PI_F 3.14159265358979323846f

// Pack WRGB into 0xWWRRGGBB
#define WRGB(w, r, g, b)  ( ((uint32_t)(w) << 24) | ((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(b) )

#define COLOR_OFF    WRGB(0, 0, 0,   0)
#define COLOR_CH_RED    WRGB(0, 255, 0,   6)
#define COLOR_CH_GREEN  WRGB(1, 20,   251, 0)

#define VZ_NEG_LIMIT  -0.6f   // stop effect if below this
#define VZ_POS_LIMIT   0.6f   // restart effect if above this

static uint32_t wrgb_value = 0;

// ----------------------------
// Sphere definition
// ----------------------------
typedef struct {
    float cx;
    float cy;
    float cz;
    float radius;
} Sphere;

// Maximum number of spheres supported
#define MAX_SPHERES 60

static float sphereCx[MAX_SPHERES];
static float sphereCy[MAX_SPHERES];
static float sphereCz[MAX_SPHERES];
static int sphereCount = 0;

// radius of each sphere
static float sphereRadius = 0.15f;   // christmas ball size

static bool effectStarted = false;
static bool effectBlocked = false;

void generateSphereCenters(float height, float trajRadius, int numSpheres, float angleOffsetDeg)
{
    if (sphereCount + numSpheres > MAX_SPHERES) {
        numSpheres = MAX_SPHERES - sphereCount;
    }

    // Convert degrees → radians once
    float angleOffsetRad = angleOffsetDeg * (M_PI_F / 180.0f);

    DEBUG_PRINT(
        "Generating %d spheres with offset=%.3f deg for trajectory (height=%.2f, radius=%.2f)\n",
        numSpheres,
        (double)angleOffsetDeg,
        (double)height,
        (double)trajRadius
    );

    for (int i = 0; i < numSpheres; i++) {

        // Add angular offset (radians)
        float theta = angleOffsetRad + (2.0f * M_PI_F * i) / numSpheres;

        int idx = sphereCount + i;

        sphereCx[idx] = trajRadius * cosf(theta);
        sphereCy[idx] = trajRadius * sinf(theta);
        sphereCz[idx] = height;
    }

    sphereCount += numSpheres;
}
bool isInsideAnySphere(float x, float y, float z)
{
    float r2 = sphereRadius * sphereRadius;

    for (int i = 0; i < sphereCount; i++) {
        float dx = x - sphereCx[i];
        float dy = y - sphereCy[i];
        float dz = z - sphereCz[i];

        float distSq = dx*dx + dy*dy + dz*dz;

        if (distSq <= r2) {
            return true;  // inside at least one sphere
        }
    }

    return false;
}

// ----------------------------
// Helper: get position
// ----------------------------
static logVarId_t logIdX;
static logVarId_t logIdY;
static logVarId_t logIdZ;
static logVarId_t logIdVz;

static float getX() { return logGetFloat(logIdX); }
static float getY() { return logGetFloat(logIdY); }
static float getZ() { return logGetFloat(logIdZ); }
static float getVz() { return logGetFloat(logIdVz); }

// ----------------------------
// App main
// ----------------------------
void appMain()
{
    DEBUG_PRINT("Starting Christmas LED sphere app...\n");

    paramVarId_t xVelMax = paramGetVarId("posCtlPid", "xVelMax");
    paramVarId_t yVelMax = paramGetVarId("posCtlPid", "yVelMax");
    paramVarId_t zVelMax = paramGetVarId("posCtlPid", "zVelMax");
    paramSetFloat(xVelMax, 5.0f);
    paramSetFloat(yVelMax, 5.0f);
    paramSetFloat(zVelMax, 5.0f);

    // Get WRGB param ID
    paramVarId_t idWrgb = paramGetVarId("colorLedBot", "wrgb8888");
    // Enable brightness correction
    paramVarId_t idBrightnessCorr = paramGetVarId("colorLedBot", "brightCorr");
    paramSetInt(idBrightnessCorr, 1);

    // Subscribe to position logs
    logIdX = logGetVarId("stateEstimate", "x");
    logIdY = logGetVarId("stateEstimate", "y");
    logIdZ = logGetVarId("stateEstimate", "z");
    logIdVz = logGetVarId("stateEstimate", "vz");


    TickType_t lastWakeTime = xTaskGetTickCount();
    const TickType_t loopInterval = M2T(10); // 10ms

    // Circle 1:
    //   Height = 2.0
    //   Radius = 0.4
    //
    // Circle 2:
    //   Height (z) = 1.5
    //   Radius (x) = 0.8
    //
    // Circle 3:
    //   Height (z) = 1.0
    //   Radius (x) = 1.2
    //
    // Circle 4:
    //   Height (z) = 0.5
    //   Radius (x) = 1.6

    // Create spheres at two different heights
    generateSphereCenters(2.0f, 0.4f, 4,  45.0f);
    generateSphereCenters(1.5f, 0.8f, 8,  22.5f);
    generateSphereCenters(1.0f, 1.2f, 12, 45.0f);
    generateSphereCenters(0.5f, 1.6f, 16, 22.5f);

    DEBUG_PRINT("Total spheres created: %d\n", sphereCount);

    while(1) {
        float x = getX();
        float y = getY();
        float z = getZ();
        float vz = getVz();

        // Hysteresis: block when vz <= negative limit
        if (!effectBlocked && vz <= VZ_NEG_LIMIT) {
            effectBlocked = true;
            DEBUG_PRINT("Effect BLOCKED (vz=%.3f)\n", (double)vz);
        }

        // Unblock when vz >= positive limit
        if (effectBlocked && vz >= VZ_POS_LIMIT) {
            effectBlocked = false;
            DEBUG_PRINT("Effect UNBLOCKED (vz=%.3f)\n", (double)vz);
        }

        // Stop LEDs when blocked
        if (effectBlocked) {
            wrgb_value = COLOR_OFF;
            paramSetInt(idWrgb, wrgb_value);
            vTaskDelayUntil(&lastWakeTime, loopInterval);
            continue;
        }

        // Activation condition (only if not started yet)
        if (!effectStarted) {
            if (fabsf(y-Y0) <= 0.04f && z > 0.2f) {
                effectStarted = true;
                DEBUG_PRINT("Christmas LED effect ACTIVATED at y=%.3f\n", (double)y);
            } else {
                paramSetInt(idWrgb, COLOR_OFF);
                vTaskDelayUntil(&lastWakeTime, loopInterval);
                continue;
            }
        }

        // Effect runs normally
        bool inside = isInsideAnySphere(x, y, z);
        wrgb_value = inside ? COLOR_CH_RED : COLOR_CH_GREEN;
        paramSetInt(idWrgb, wrgb_value);

        vTaskDelayUntil(&lastWakeTime, loopInterval);
    }
}