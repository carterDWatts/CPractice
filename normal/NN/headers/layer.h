#ifndef LAYER_H_
#define LAYER_H_

#include <stdlib.h>

typedef struct{
  int num_neurons;
  int num_inputs_per_neuron;
  double **weights;
}layer;

void generate_weight_matrix(layer *L);

#endif /* LAYER_H_ */
