#ifndef CONNECTIONSH
#define CONNECTIONSH

#include "maths.h"
#include "neurons.h"
#include "genome.h"

typedef struct connection_t {
    uint32_t connection_id;
    float_t weight;
    neuron_t *start_neuron;
    neuron_t *end_neuron;
    uint32_t enabled;
    uint32_t exists;
    uint32_t innov_id;
} connection_t;

enum connections_mutations
{
    ADD_CONNECTION,
    DELETE_CONNECTION,
    CHANGE_WEIGHT,
    DO_NOTHING_TO_CONNECTION
};

void find_next_free_connection_position(genome_t *genome);

// intodeauna se pune neuronu de strat mai mic primu
void add_connection(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2);

void delete_connection(genome_t *genome, connection_t *conn);

uint32_t get_connections_mutations();

void pick_random_disconnected_neurons(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2);

void change_connection_weight(connection_t *conn);

void mutate_connection(genome_t *genome);

#endif
