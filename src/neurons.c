

// each layer should have a set number of neurons
// for example, if we have a max number of neurons of 9
// and max neurons per layer of 3
// then, neurons with ids/indexes 0, 1, 2 are layer input
// neurons 3 4 5 are layer 1
// neurons 6 7 8 are layer output
// void add_neuron(genome_t *genome, uint32_t layer) {
//     // neuron_t *new_neuron = (neuron_t *) malloc(sizeof(neuron_t));
//     neuron_t *new_neuron = &genome->neurons[genome->neuro_stack_top];
//     memset(new_neuron, 0, sizeof(neuron_t));
//     new_neuron->neuron_id = genome->neuro_stack_top;
//     new_neuron->layer = layer;
//     genome->neuro_stack_top++
// }