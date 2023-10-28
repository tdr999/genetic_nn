// this code implements a not fully connected neural net
// forward propagation algo
// intended to be used in a genetic algo
// kind of like neat but not full neat because i don't get the innovation number shit and is kinda hard
#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>



// reimplement array using linked list


connection_t global_conn_stack[NB_MAX_NODES];
neuron_t global_neuron_stack[NB_MAX_CONNECTIONS]; // some will be used by input output layyer neurons
uint32_t fixed_neurons_idx; // neurons at these indexes cannont be deleted
uint32_t neuron_stack_top;
uint32_t conn_stack_top;
// also, neurons on the same levels cannont be connected


// neurons cannont be connected to neurons on the same layer, because it will cause cyclical graphs
neuron_t *pick_neuron_to_connect_to(neuron_t *n) {
    while (1) {
        // pick random neuron from nn
        uint32_t random_neuron_idx = (int32_t)(rand() / RAND_MAX) * NB_MAX_neuronS;
        if (random_neuron_idx != NB_MAX_neuronS && random_neuron_idx < neuron_stack_top) {
            if (global_neuron_stack[random_neuron_idx].layer_idx != n->layer_idx) {
                return &global_neuron_stack[random_neuron_idx];
            }
        }
    }
}

// add connection between 2 neurons when we know neurons are not on the same layer
void add_connection(neuron_t *neuron1, neuron_t *neuron2) {
    connection_t *conn = (connection_t *)malloc(sizeof(connection_t));

    // to ensure there are no backward connections
    if (neuron1->layer_idx < neuron2->layer_idx) {
        conn->start_neuron = neuron1;
        conn->end_neuron = neuron2;
    } else {
        conn->start_neuron = neuron2;
        conn->end_neuron = neuron1;
    }
    conn->weight = ((((float_t)rand() / RAND_MAX) - 0.5f) * 2.0f); // random number betwee -1 and 1
    global_conn_stack[conn_stack_top++];
}

// add new hidden neuron as mutation
void add_neuron() {
    neuron_t *new_neuron = (neuron_t *) malloc(sizeof(neuron_t));

    // pick neuron level, between start and end, but not, start and end
    new_neuron->layer_idx = ((uint32_t)rand() / RAND_MAX) * (LAST_LAYER - 2) + 1; // this should generate integers in the interval (0, LAST_LAYER)

    // pick two random neurons to connect this neuron to
    neuron_t *neuron1 = pick_neuron_to_connect_to(new_neuron);
    neuron_t *neuron2 = pick_neuron_to_connect_to(new_neuron);
    add_connection(neuron1, new_neuron);
    add_connection(neuron2, new_neuron);

    new_neuron->neuron_id = neuron_stack_top;
    global_neuron_stack[neuron_stack_top++];
}

void delete_connections_to_this_neuron(connection_t *conn) {
    free(conn);
}

// delete hidden neuron as mutation
void delete_neuron() {

    neuron_t *neuron_to_delete;

    while (1) {
        // pick random neuron from nn
        uint32_t random_neuron_idx = (int32_t)(rand() / RAND_MAX) * NB_MAX_neuronS;
        if (random_neuron_idx != NB_MAX_neuronS && random_neuron_idx < neuron_stack_top) {
            if (global_neuron_stack[random_neuron_idx].layer_idx != n->layer_idx) {
                neuron_to_delete = &global_neuron_stack[random_neuron_idx];
                break;
            }
        }
    }
    // pick neuron level, between start and end, but not, start and end
    new_neuron->layer_idx = ((uint32_t)rand() / RAND_MAX) * (LAST_LAYER - 2) + 1; // this should generate integers in the interval (0, LAST_LAYER)

    // pick two random neurons to connect this neuron to
    neuron_t *neuron1 = pick_neuron_to_connect_to(new_neuron);
    neuron_t *neuron2 = pick_neuron_to_connect_to(new_neuron);
    add_connection(neuron1, new_neuron);
    add_connection(neuron2, new_neuron);

    global_neuron_stack[neuron_stack_top--];
}


void pick_2_random_neurons(neuron_t *neuron1, neuron_t *neuron2) {

}

connection_t *pick_2_random_neurons(neuron_t *neuron1, neuron_t *neuron2) {

}

void mutate_connections() {
    // either change a connection's weight
    uint32_t random_connection_index = (int32_t)(rand() / RAND_MAX) * conn_stack_top;
    global_conn_stack[random_connection_index].weight = ((((float_t)rand() / RAND_MAX) - 0.5f) * 2.0f);
    

    // or add/delete a connection between two neurons

    neuron_t *neuron1;
    neuron_t *neuron2;
    connection_t conn;

    // add connection between two random neurons
    pick_2_random_disconnected_neurons(neuron1, neuron2);
    add_connection(neuron1, neuron2);

    // delete connection
    conn = pick_2_random_connected_neurons(neuron1, neuron2);
    conn.enabled = FALSE;
}


void mutate_neurons() {

    // add neuron

    // delete neuron
}