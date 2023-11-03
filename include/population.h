#ifndef POPULATIONH
#define POPULATIONH
#include "maths.h"
#include "genome.h"


typedef struct population_t {
    genome_t genomes[POP_SIZE];
    int size;
    float_t avg_acc;
} population_t;

void init_population(population_t *pop); 

#endif