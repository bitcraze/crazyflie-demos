/**
 * ,---------,       ____  _ __
 * |  ,-^-,  |      / __ )(_) /_______________ _____  ___
 * | (  O  ) |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * | / ,--´  |    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *    +------`   /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2025 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "app.h"

#include "FreeRTOS.h"
#include "task.h"

#include "debug.h"

#include "log.h"
#include "param.h"

#define DEBUG_MODULE "LEDSHAKE"

// Pack WRGB into 0xWWRRGGBB
#define WRGB(w, r, g, b)  ( ((uint32_t)(w) << 24) | ((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(b) )

// Tilt angle (degrees) that maps to full brightness
#define MAX_ANGLE 45
// Ignore tilt below this threshold (degrees) to suppress sensor noise
#define DEADBAND 2

static uint32_t prevWrgbBot = 0xFFFFFFFF;
static uint32_t prevWrgbTop = 0xFFFFFFFF;

static void updateDeckParamIfChanged(paramVarId_t id, uint32_t newValue, uint32_t *prevValue)
{
    if (id.id != 0xffffu && newValue != *prevValue) {
        paramSetInt(id, newValue);
        *prevValue = newValue;
    }
}

void appMain()
{
    DEBUG_PRINT("Starting shake LED app...\n");

    // Detect LED decks
    paramVarId_t idBottomDetect = paramGetVarId("deck", "bcColorLedBot");
    paramVarId_t idTopDetect    = paramGetVarId("deck", "bcColorLedTop");

    uint8_t bottomAttached = paramGetUint(idBottomDetect);
    uint8_t topAttached    = paramGetUint(idTopDetect);

    if (!bottomAttached && !topAttached) {
        DEBUG_PRINT("ERROR: No Color LED deck detected!\n");
        return;
    }

    paramVarId_t idWrgbBot   = {0};
    paramVarId_t idWrgbTop   = {0};
    logVarId_t idDeckTemp    = {0};
    logVarId_t idThrottlePct = {0};

    if (bottomAttached) {
        idWrgbBot     = paramGetVarId("colorLedBot", "wrgb8888");
        idDeckTemp    = logGetVarId("colorLedBot", "deckTemp");
        idThrottlePct = logGetVarId("colorLedBot", "throttlePct");
        paramSetInt(paramGetVarId("colorLedBot", "brightCorr"), 1);
        DEBUG_PRINT("Color LED Bottom deck detected\n");
    }
    if (topAttached) {
        idWrgbTop     = paramGetVarId("colorLedTop", "wrgb8888");
        idDeckTemp    = logGetVarId("colorLedTop", "deckTemp");
        idThrottlePct = logGetVarId("colorLedTop", "throttlePct");
        paramSetInt(paramGetVarId("colorLedTop", "brightCorr"), 1);
        DEBUG_PRINT("Color LED Top deck detected\n");
    }

    logVarId_t idRoll  = logGetVarId("stabilizer", "roll");
    logVarId_t idPitch = logGetVarId("stabilizer", "pitch");

    TickType_t lastWakeTime = xTaskGetTickCount();
    uint32_t lastThermalCheck = xTaskGetTickCount();
    const uint32_t thermalCheckInterval = M2T(100);

    // Hold the last active color; dim white on startup
    uint32_t lastColor = WRGB(0, 60, 60, 60);

    // Smoothed display color — lerps toward lastColor each tick
    float dispR = 60.0f, dispG = 60.0f, dispB = 60.0f;

    while (1) {
        int roll  = (int)logGetFloat(idRoll);
        int pitch = (int)logGetFloat(idPitch);

        // Deadband on signed degrees
        if (roll  > -DEADBAND && roll  < DEADBAND) roll  = 0;
        if (pitch > -DEADBAND && pitch < DEADBAND) pitch = 0;

        // Scale to ±255 over MAX_ANGLE degrees, clamp
        roll  = roll  * 255 / MAX_ANGLE;
        pitch = pitch * 255 / MAX_ANGLE;
        if (roll  >  255) roll  =  255;
        if (roll  < -255) roll  = -255;
        if (pitch >  255) pitch =  255;
        if (pitch < -255) pitch = -255;

        // Map tilt direction to hue, magnitude to brightness (HSV, S=1)
        // Wheel orientation: right=Red, forward-left=Green, left=Cyan,
        //                    back=Purple, forward-right=Orange
        float rf = (float)roll  / 255.0f;
        float fwd = -(float)pitch / 255.0f;  // forward is negative pitch
        float mag = sqrtf(rf * rf + fwd * fwd);
        if (mag > 1.0f) mag = 1.0f;

        int r = 0, g = 0, b = 0;
        if (mag > 0.01f) {
            float angle = atan2f(fwd, rf);
            if (angle < 0.0f) angle += 2.0f * 3.14159265f;
            float hue = angle / (2.0f * 3.14159265f) * 6.0f - 1.0f;
            if (hue < 0.0f) hue += 6.0f;
            int sector = (int)hue;
            float f = hue - (float)sector;
            float v = mag;
            float q = v * (1.0f - f);
            float t = v * f;
            switch (sector % 6) {
            case 0: r=(int)(v*255); g=(int)(t*255);           break;
            case 1: r=(int)(q*255); g=(int)(v*255);           break;
            case 2:                 g=(int)(v*255); b=(int)(t*255); break;
            case 3:                 g=(int)(q*255); b=(int)(v*255); break;
            case 4: r=(int)(t*255);                b=(int)(v*255); break;
            case 5: r=(int)(v*255);                b=(int)(q*255); break;
            }
        }

        uint32_t wrgb_value = WRGB(0, (uint8_t)r, (uint8_t)g, (uint8_t)b);

        // When moving, latch the color at full brightness; when still, hold it
        if (wrgb_value != 0) {
            uint8_t r = (wrgb_value >> 16) & 0xFF;
            uint8_t g = (wrgb_value >>  8) & 0xFF;
            uint8_t b =  wrgb_value        & 0xFF;
            uint8_t mx = r > g ? (r > b ? r : b) : (g > b ? g : b);
            if (mx > 0) {
                r = (uint8_t)((uint16_t)r * 255 / mx);
                g = (uint8_t)((uint16_t)g * 255 / mx);
                b = (uint8_t)((uint16_t)b * 255 / mx);
            }
            lastColor = WRGB(0, r, g, b);
        }
        // Lerp display toward target (~15% per tick at 10ms = ~60ms to settle)
        float tR = (float)((lastColor >> 16) & 0xFF);
        float tG = (float)((lastColor >>  8) & 0xFF);
        float tB = (float)( lastColor        & 0xFF);
        dispR += (tR - dispR) * 0.15f;
        dispG += (tG - dispG) * 0.15f;
        dispB += (tB - dispB) * 0.15f;
        wrgb_value = WRGB(0, (uint8_t)dispR, (uint8_t)dispG, (uint8_t)dispB);

        if (bottomAttached) updateDeckParamIfChanged(idWrgbBot, wrgb_value, &prevWrgbBot);
        if (topAttached)    updateDeckParamIfChanged(idWrgbTop, wrgb_value, &prevWrgbTop);

        if (xTaskGetTickCount() - lastThermalCheck >= thermalCheckInterval) {
            uint8_t throttlePct = logGetUint(idThrottlePct);
            if (throttlePct) {
                uint8_t deckTemp = logGetUint(idDeckTemp);
                DEBUG_PRINT("WARNING: Thermal throttling active! Temp: %d°C, Throttle: %d%%\n",
                            deckTemp, throttlePct);
            }
            lastThermalCheck = xTaskGetTickCount();
        }

        vTaskDelayUntil(&lastWakeTime, M2T(10));
    }
}
