#include <stdio.h>
#include "dataset.h"
#include "genome.h"
#include "population.h"

int main(){

    datapoint_t dataset[150];
    read_dataset(dataset);
    population_t pop;

    // for good measure
    memset(&pop, 0, sizeof(population_t));
    init_population(&pop);


    uint32_t ii, jj;
    for (ii = 0; ii < GENERATIONS; ii++) {
        float_t current_pop_fit = 0.0f;
        for (jj = 0; jj < POP_SIZE; jj++) {
            genome_t *genome = &pop.genomes[jj];
            evaluate_genome(genome, dataset);
            current_pop_fit += genome->fitness / POP_SIZE;
        }

        // sort by fitness
        qsort(&pop.genomes, POP_SIZE, sizeof(genome_t), comp_genomes);
        // crossover

        // mutate
    }
}