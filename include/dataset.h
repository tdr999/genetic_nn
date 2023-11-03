#ifndef DATASETH
#define DATASETH

#include "maths.h"


typedef struct datapoint_t {
    float_t f1;
    float_t f2;
    float_t f3;
    float_t f4;
    uint32_t type;
} datapoint_t;

void read_dataset(datapoint_t dataset[150]); 

#endif