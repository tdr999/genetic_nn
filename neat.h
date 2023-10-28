#ifndef NEATH
#define NEATH

#include <stdint.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include "params.h"

typedef struct node_t {
    union {
        neuron_t *neuron;
        connection_t *conn;
    };
    node_t *next;
} node_t;


typedef struct connection {
    uint32_t connection_id;
    float_t weight;
    neuron_t *start_neuron;
    neuron_t *end_neuron;
    uint32_t enabled;
    uint32_t innov_id;
} connection_t;

typedef struct neuron_t {
    uint32_t layer_idx;
    uint32_t neuron_id;
    uint32_t activation;
    float_t sum_in;
    float_t sum_out;
} neuron_t;

typedef struct genome_t {
    uint32_t adjmat[NB_MAX_NEURONS][NB_MAX_NEURONS];
    connection_t conns[NB_MAX_CONNECTIONS];
    neuron_t neurons[NB_MAX_NEURONS];
    uint32_t con_stack_top;
    uint32_t neuro_stack_top;
    float_t fitness;
} genome_t;









#endif