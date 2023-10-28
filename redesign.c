#include "neat.h"


void find_next_free_connection_position(genome_t *genome) {
    // dam si noi o rulare prin vectoru de conexiuni pana gasim una cu start neuroni setati la null
    uint32_t ii;
    for (ii = 0; ii < NB_MAX_CONNECTIONS; ii++) {
        if (genome->conns[ii].start_neuron == NULL) {
            genome->free_conn_pos_index = ii;
            break;
        }
    }
}


// intodeauna se pune neuronu de strat mai mic primu
void add_connection(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2) {
    // connection_t *conn = (connection_t *)malloc(sizeof(connection_t));
    connection_t *conn = &genome->conns[genome->free_conn_pos_index];
    memset(conn, 0, sizeof(connection_t));
    conn->connection_id = genome->free_conn_pos_index;
    conn->start_neuron = neuron1;
    conn->end_neuron = neuron2;
    conn->weight = ((((float_t)rand() / RAND_MAX) - 0.5f) * 2.0f); // random number betwee -1 and 1

    // add the link in adjency matrix
    genome->adjmat[neuron1->neuron_id][neuron2->neuron_id] = 1;
    find_next_free_connection_position(genome);
}

void delete_connection(genome_t *genome, connection_t *conn) {
    genome->adjmat[conn->start_neuron->neuron_id][conn->end_neuron->neuron_id] = 0;
    memset(conn, 0, sizeof(connection_t));
    find_next_free_connection_position(genome);
}

void add_neuron(genome_t *genome, uint32_t layer) {
    // neuron_t *new_neuron = (neuron_t *) malloc(sizeof(neuron_t));
    neuron_t *new_neuron = &genome->neurons[genome->neuro_stack_top];
    memset(new_neuron, 0, sizeof(neuron_t));
    new_neuron->neuron_id = genome->neuro_stack_top;
    new_neuron->layer = layer;
    genome->neuro_stack_top++
}

