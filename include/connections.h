#ifndef CONNECTIONSH
#define CONNECTIONSH

#include "maths.h"
#include "neurons.h"
#include "connections.h"
#include <maths.h>

typedef struct connection_t {
    uint32_t connection_id;
    float_t weight;
    neuron_t *start_neuron;
    neuron_t *end_neuron;
    uint32_t enabled;
    uint32_t exists;
    uint32_t innov_id;
} connection_t;

enum
{
    ADD_CONNECTION,
    DELETE_CONNECTION,
    CHANGE_WEIGHT,
    DO_NOTHING_TO_CONNECTION
};


#endif
