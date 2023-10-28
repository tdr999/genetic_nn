#ifndef MATHSC
#define MATHSC

#include "maths.h"
#include "params.h"

// scoate un numar random intr un interval
uint32_t get_random_int(uint32_t lower, uint32_t upper) {
    return ((rand() % (upper - lower)) + lower);
}

float_t get_random_weight() {
    return MIN_WEIGHT_FLOAT + (MAX_WEIGHT_FLOAT - MIN_WEIGHT_FLOAT) * ((float_t)rand()/RAND_MAX);
}

#endif