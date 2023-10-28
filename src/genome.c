#include "connections.h"
#include "genome.h"
#include "maths.h"
#include "params.h"

void find_next_free_connection_position(genome_t *genome) {
    // dam si noi o rulare prin vectoru de conexiuni pana gasim una cu start neuroni setati la null
    uint32_t ii;
    for (ii = 0; ii < NB_MAX_CONNECTIONS; ii++) {
        if (genome->conns[ii].exists == 0) {
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
    conn->weight = get_random_weight(); // random number betwee -1 and 1

    // add the link in adjency matrix
    genome->adjmat[neuron1->neuron_id][neuron2->neuron_id] = 1;
    find_next_free_connection_position(genome);
}

void delete_connection(genome_t *genome, connection_t *conn) {
    genome->adjmat[conn->start_neuron->neuron_id][conn->end_neuron->neuron_id] = 0;
    memset(conn, 0, sizeof(connection_t));
    find_next_free_connection_position(genome);
}

uint32_t get_connections_mutations() {
    float_t value = (float_t)rand()/RAND_MAX;
    if (value < ADD_CONNECTION_CHANCE) {
        return ADD_CONNECTION;
    }
    if ((value >= ADD_CONNECTION_CHANCE) && (value < DELETE_CONNECTION_CHANCE)) {
        return DELETE_CONNECTION;
    }
    if ((value >= DELETE_CONNECTION_CHANCE) && (value < CHANGE_CONNECTION_WEIGHT_CHANCE)) {
        return CHANGE_WEIGHT;
    }
    return DO_NOTHING_TO_CONNECTION;
}

void pick_random_disconnected_neurons(genome_t *genome, neuron_t *neuron1, neuron_t *neuron2) {
    while(1) {
        uint32_t idx1, idx2;
        idx1 = get_random_int(0, NB_MAX_NEURONS);
        idx2 = get_random_int(0, NB_MAX_NEURONS);

        // daca neuronu 1 e intr un layer inferior neuronului 2
        // si nu sunt deja conectati, blana bomba
        //pas cu pas:

        uint32_t layer_idx_1 = idx1 / NB_NEURONS_PER_LAYER;
        uint32_t layer_idx_2 = idx2 / NB_NEURONS_PER_LAYER;

        if (layer_idx_1 < layer_idx_2) {
            if (layer_idx_1 != INPUT_LAYER && layer_idx_2 != LAST_LAYER) {
                neuron1 = &genome->neurons[idx1];
                neuron2 = &genome->neurons[idx2];
                break;
            }
        }

    }    
}

void change_connection_weight(connection_t *conn) {
    conn->weight = get_random_weight();
}

void mutate_connection(genome_t *genome) {

    // pick random connection
    connection_t *conn;
    while (1) {
        uint32_t random_index = get_random_int(0, NB_MAX_CONNECTIONS);
        // daca conexiunea exista
        if (genome->conns[random_index].exists == 1) {
            conn = &genome->conns[random_index];
            break;
        }
    }

    switch (get_connections_mutation()) { 
    // delete connection
        case DELETE_CONNECTION:
            delete_connection(genome, conn);
            break;
    // add connection
        case ADD_CONNECTION:
            neuron_t *neuron1, *neuron2;
            pick_random_disconnected_neurons(genome, neuron1, neuron2);
            add_connection(genome, neuron1, neuron2);
            break;
    // change connection weight
        case CHANGE_WEIGHT:
            change_connection_weight(conn);
            break;
    // do nothing
        case DO_NOTHING_TO_CONNECTION:
            break;
    }
}
