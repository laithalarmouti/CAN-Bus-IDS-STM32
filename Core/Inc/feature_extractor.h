#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include "can_driver.h"
#include <stdint.h>

#define FEATURE_COUNT 11

typedef struct {
    float features[FEATURE_COUNT];
} FeatureVector_t;

static const float SCALER_MEAN[FEATURE_COUNT] = {
    720.494676f, 7.957059f, 54.488674f, 58.878468f,
    59.843296f, 140.869133f, 67.392157f, 44.662513f,
    30.610555f, 86.297398f, 0.003127f
};

static const float SCALER_SCALE[FEATURE_COUNT] = {
    496.743112f, 0.404682f, 72.945047f, 61.348985f,
    62.606099f, 114.584493f, 68.544737f, 66.871259f,
    64.732805f, 106.618242f, 0.061588f
};

#ifdef __cplusplus
extern "C" {
#endif

void Feature_Extract(const CAN_Frame_t *frame,
                     uint32_t prev_ts,
                     FeatureVector_t *out);

#ifdef __cplusplus
}
#endif

#endif // FEATURE_EXTRACTOR_H
