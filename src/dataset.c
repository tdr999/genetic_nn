#include "dataset.h"
#include <stdio.h>

// 3 outputs
void read_dataset(datapoint_t dataset[150]) {
    FILE *in = fopen("../iris.data", "r");
    uint32_t i = 0;
    char flower[30];
    while (i++ < 150) {
        fscanf(in, "%f,%f,%f,%f,%29s\n", &dataset[i].f1, &dataset[i].f2, &dataset[i].f3, &dataset[i].f4, flower);
        if (strcmp(flower, "Iris-setosa") == 0) dataset[i].type = 1;
        if (strcmp(flower, "Iris-versicolor") == 0) dataset[i].type = 2;
        if (strcmp(flower, "Iris-virginica") == 0) dataset[i].type = 3;
    }
}