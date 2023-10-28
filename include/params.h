#ifndef PARAMSH
#define PARAMSH




#define NB_MAX_NODES 100
#define NB_MAX_CONNECTIONS 100
// let last layer the last layer of the nn and 0 the first layer
#define INPUT_LAYER 0
#define LAST_LAYER 3
#define NB_NEURONS_HIDDEN 3// max number of neurons per hidden layer
#define NB_NEURONS_PER_LAYER 3;
#define HIDDEN_LAYERS LAST_LAYER - INPUT_LAYER + 1 //hidden layers
#define NB_MAX_NEURONS 200 // max neurons
#define NB_MAX_CONNECTIONS 100

// this is a cdf, will change names later
#define ADD_CONNECTION_CHANCE 0.10f
#define DELETE_CONNECTION_CHANCE 0.10f
#define CHANGE_CONNECTION_WEIGHT_CHANCE 0.20f
#define DONT_MUTATE_CONNECTION_CHANCE (1 - ADD_CONNECTION_CHANCE - DELETE_CONNECTION_CHANCE - CHANGE_CONNECTION_WEIGHT_CHANCE)

#define MAX_WEIGHT_FLOAT -1.0f
#define MIN_WEIGHT_FLOAT 1.0f

#endif