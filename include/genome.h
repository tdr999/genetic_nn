#ifndef GENOMESH
#define GENOMESH
#include "maths.h"
#include "connections.h"
#include "params.h"
#include "neurons.h"

typedef struct genome_t {
    neuron_t neurons[NB_MAX_NEURONS];
    uint32_t adjmat[NB_MAX_NEURONS][NB_MAX_NEURONS];
    connection_t conns[NB_MAX_CONNECTIONS];
    uint32_t free_conn_pos_index; // index of free spaces in the conns vector
    uint32_t neuro_stack_top;
    float_t fitness;
} genome_t;


void find_next_free_connection_position(genome_t *genome);

// intodeauna se pune neuronu de strat mai mic primu
void add_connection(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2);

void delete_connection(genome_t *genome, connection_t *conn);

uint32_t get_connections_mutation();

void pick_random_disconnected_neurons(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2);

void change_connection_weight(connection_t *conn);

void mutate_connection(genome_t *genome);

#endif