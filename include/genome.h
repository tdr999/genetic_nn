#ifndef GENOMESH
#define GENOMESH
#include "maths.h"
#include "genome.h"
#include "params.h"
#include "connections.h"
#include "neurons.h"

typedef struct genome_t {
    uint32_t adjmat[NB_MAX_NEURONS][NB_MAX_NEURONS];
    connection_t conns[NB_MAX_CONNECTIONS];
    neuron_t neurons[NB_MAX_NEURONS];
    uint32_t free_conn_pos_index; // index of free spaces in the conns vector
    uint32_t neuro_stack_top;
    float_t fitness;
} genome_t;

#endif