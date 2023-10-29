#include "connections.h"
#include "genome.h"
#include "maths.h"
#include "params.h"


global_neuron_innovation_t neur_inno;
global_conn_innovation_t conn_innov;

uint32_t get_conn_inno(uint32_t id1, uint32_t id2) {
    uint32_t ii;
    for (ii = 0; ii < conn_innov.n; ii++) {
        conn_innovation_t *conn_inno = &conn_innov.inno[ii];
        if ((conn_inno->start_node_id == id1) && (conn_inno->end_node_id == id2)) {
            return conn_inno->innov;
        }
    }

    // if it was not found, add new inno
    conn_innovation_t *conn_inno = &conn_innov.inno[conn_innov.n];
    conn_inno->start_node_id = id1;
    conn_inno->end_node_id = id2;
    conn_inno->innov = conn_innov.n;
    conn_innov.n++;
}

uint32_t get_neur_inno(uint32_t id) {
    uint32_t ii;
    for (ii = 0; ii < neur_inno.n; ii++) {
        neuron_innovation_t *ino = &neur_inno.inno[ii];
        if (ino->node_id == id) {
            return ino->innov;
        }
    }

    // nodul e nou
    neuron_innovation_t *ino = &neur_inno.inno[neur_inno.n];
    ino->node_id = id;
    ino->innov = neur_inno.n;
    neur_inno.n++;
}

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
    genome->conn_counter++;
}

void delete_connection(genome_t *genome, connection_t *conn) {
    genome->adjmat[conn->start_neuron->neuron_id][conn->end_neuron->neuron_id] = 0;
    memset(conn, 0, sizeof(connection_t));
    find_next_free_connection_position(genome);
}

uint32_t get_connection_mutation() {
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

    switch (get_connection_mutation()) { 
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

void add_node(genome_t *genome) {
    // pick a possible node that does not exist yet
    uint32_t i;
    while(1) {
        i = get_random_int(0, NB_MAX_NEURONS); //get a number between max neurons and start neurons
        uint32_t layer = i / NB_NEURONS_PER_LAYER;
        if (layer != INPUT_LAYER && layer != LAST_LAYER) {
            if (genome->neurons[i].neuron_id == 0) {
                break;
            }
        }
    }

    // found elligible new neuron position
    uint32_t inno = get_neur_inno(i);
    genome->neurons[i].neuron_id = i;
    genome->neurons[i].layer = i / NB_NEURONS_PER_LAYER;
    genome->neuro_stack_top++;
}

// delete_node() {

// }

uint32_t get_neuron_mutation() {
    float_t value = (float_t)rand()/RAND_MAX;
    if (value < ADD_NODE_CHANCE) {
        return ADD_NODE;
    }
    if ((value >= ADD_NODE_CHANCE) && (value < DELETE_NODE_CHANCE)) {
        return DELETE_NODE;
    }
    return DO_NOTHING_TO_NODE_CHANCE;
}

void mutate_neurons(genome_t *genome) {
    // pick random connection
    neuron_t *neuron;
    while (1) {
        uint32_t random_index = get_random_int(0, NB_MAX_NEURONS);
        // dont touch input and output layer
        if (genome->neurons[random_index].layer != INPUT_LAYER && genome->neurons[random_index].layer != LAST_LAYER) {
            neuron = &genome->neurons[random_index];
            break;
        }
    }

    switch (get_neuron_mutation()){
        case ADD_NODE:
            add_node(genome);
            break;
        // case DELETE_NODE:
        //     delete_node(genome);
        //     break;
        case DO_NOTHING_TO_NODE:
            break;
    }
}
