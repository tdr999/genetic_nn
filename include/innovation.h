#ifndef INNOVATIONH
#define INNOVATIONH
#include "params.h"
#include "maths.h"

typedef struct global_neuron_innovation_t {
    uint32_t node_id;
    uint32_t innov;
} global_neuron_innovation_t;

typedef struct conn_innovation_t {
    uint32_t start_node_id;
    uint32_t end_node_id;
    uint32_t innov;
} conn_innovation_t;

typedef struct global_conn_innovation_t {
    uint32_t n;
    conn_innovation_t inno[NB_MAX_CON_INNO];
}

uint32_t get_conn_inno(uint32_t start_id, uint32_t end_id);


#endif