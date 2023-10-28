#ifndef PARAMSH
#define PARAMSH




#define NB_MAX_NODES 100
#define NB_MAX_CONNECTIONS 100
// let last layer the last layer of the nn and 0 the first layer
#define INPUT_LAYER 0
#define LAST_LAYER 3
#define NB_INPUT_NEURONS 4
#define NB_OUTPUT_NEURONS 1
#define NB_NEURONS_HIDDEN 3// max number of neurons per hidden layer
#define HIDDEN_LAYERS LAST_LAYER - INPUT_LAYER + 1 //hidden layers
#define NB_MAX_NEURONS NB_INPUT_NEURONS + NB_OUTPUT_NEURONS + HIDDEN_LAYERS * NB_NEURONS_HIDDEN // max neurons
#define NB_MAX_CONNECTIONS NB_INPUT_NEURONS * NB_NEURONS_HIDDEN + NB_OUTPUT_NEURONS * NB_NEURONS_HIDDEN + (HIDDEN_LAYERS - 1) * NB_NEURONS_HIDDEN * NB_NEURONS_HIDDEN // max number of connections

#endif