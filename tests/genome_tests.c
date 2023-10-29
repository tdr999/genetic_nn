#include "genome.h"
#include <string.h>
#include <assert.h>

int main() {

    // yay primul test de evolutie
    // o sa batem neuronul sa evolueze pana prezice 1
    genome_t genome;
    neuron_t *in = (neuron_t*)malloc(sizeof(neuron_t));
    neuron_t *out = (neuron_t*)malloc(sizeof(neuron_t));
    in->layer = 0;
    in->neuron_id = 1;
    out->layer = 2;
    out->neuron_id = 3;
    genome.neuro_stack_top = 2;

    //primul test o sa fie sa vedem daca adauga noduri
    add_node(&genome);
    assert(genome.neuro_stack_top == 3);

    // sa vedem daca adauga conexiuni
    add_connection(&genome, in, out);
    assert(genome.conn_counter == 1);

    return 0;

}