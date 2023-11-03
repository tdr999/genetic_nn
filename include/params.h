#ifndef PARAMSH
#define PARAMSH




#define NB_MAX_NODES 5
#define NB_MAX_CONNECTIONS 5
// let last layer the last layer of the nn and 0 the first layer
#define INPUT_LAYER 0
#define LAST_LAYER 3
#define NB_INPUT_NEURONS 4
#define NB_OUTPUT_NEURONS 3

#define NB_NEURONS_HIDDEN 1// max number of neurons per hidden layer
#define NB_NEURONS_PER_LAYER 1;
#define NB_MAX_NEURONS 5 // max neurons
// #define NB_MAX_CONNECTIONS 100

// this is a cdf, will change names later, this is NOT a PDF
#define ADD_CONNECTION_CHANCE 0.10f
#define DELETE_CONNECTION_CHANCE 0.20f
#define CHANGE_CONNECTION_WEIGHT_CHANCE 0.30f
#define DONT_MUTATE_CONNECTION_CHANCE 0.40f

#define MAX_WEIGHT_FLOAT -1.0f
#define MIN_WEIGHT_FLOAT 1.0f

#define ADD_NODE_CHANCE 0.10f
#define DELETE_NODE_CHANCE 0.20f
#define DO_NOTHING_TO_NODE_CHANCE 0.30f
#define NB_MAX_CON_INNO 500

#define POP_SIZE 100
#define GENERATIONS 100

#endif