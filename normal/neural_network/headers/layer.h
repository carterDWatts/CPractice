#ifndef LAYER_H_
#define LAYER_H_

#include <stdlib.h>


typedef struct{
  int rows;
  int cols;
  double **values;
}layer;

typedef struct{
  int num_neurons;
  int num_inputs_per_neuron;
  int rows;
  int cols;
  double **weights;
}hidden_layer;

void generate_weight_matrix(hidden_layer *L);

#endif /* LAYER_H_ */
