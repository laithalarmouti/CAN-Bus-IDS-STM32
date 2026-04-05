#include "feature_extractor.h"

void Feature_Extract(const CAN_Frame_t *frame,
                     uint32_t prev_ts,
                     FeatureVector_t *out)
{
    // ── Step 1: Build raw feature values ──────────────────────────────────────

    // Raw feature array — same order as Python training
    float raw[FEATURE_COUNT];

    // Feature 0: CAN ID as integer
    // In Python: int(hex_string, 16)
    // Here the ID is already an integer from the CAN mailbox register
    raw[0] = (float)frame->can_id;

    // Feature 1: DLC
    // Already an integer 0-8, just cast to float
    raw[1] = (float)frame->dlc;

    // Features 2-9: payload bytes b0 to b7
    // Each byte is 0-255, cast to float
    raw[2]  = (float)frame->data[0];
    raw[3]  = (float)frame->data[1];
    raw[4]  = (float)frame->data[2];
    raw[5]  = (float)frame->data[3];
    raw[6]  = (float)frame->data[4];
    raw[7]  = (float)frame->data[5];
    raw[8]  = (float)frame->data[6];
    raw[9]  = (float)frame->data[7];

    // Feature 10: inter-arrival time in seconds
    // HAL_GetTick() returns milliseconds so we divide by 1000.0f
    // to convert to seconds — matching what Python used
    // If this is the first frame, prev_ts == 0 and delta will be large
    // we clip it to 0 to avoid garbage values
    float delta_ms = (float)(frame->timestamp - prev_ts);
    float delta_s  = delta_ms / 1000.0f;
    raw[10] = (delta_s > 0.0f) ? delta_s : 0.0f;

    // ── Step 2: Apply StandardScaler ──────────────────────────────────────────
    // Formula: scaled = (raw - mean) / scale
    // This is exactly what sklearn's StandardScaler.transform() does in Python
    // We apply it to every feature using the hardcoded constants from the header

    for (int i = 0; i < FEATURE_COUNT; i++)
    {
        out->features[i] = (raw[i] - SCALER_MEAN[i]) / SCALER_SCALE[i];
    }
}
