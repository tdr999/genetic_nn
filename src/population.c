#include "genome.h"
#include "maths.h"
#include "population.h"

void init_population(population_t *pop) {

    for (jj = 0; jj < POP_SIZE; jj++) {
        genome_t *genome = &pop->genomes[jj];
        init_genome(genome);
    }
}