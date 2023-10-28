#ifndef NEURONSH
#define NEURONSH
#include "maths.h"

typedef struct neuron_t {
    uint32_t layer;
    uint32_t neuron_id;
    uint32_t activation;
    float_t sum_in;
    float_t sum_out;
} neuron_t;

#endif