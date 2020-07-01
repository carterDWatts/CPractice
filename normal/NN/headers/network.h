#ifndef NETWORK_H_
#define NETWORK_H_

#include "layer.h"

typedef struct{
  layer l1;
  double **output_layer;
}network;


void generate_output_layer(network *N);
void process(network net, int in_c, double inputs[][in_c]);
void train(network net, int in_c, double inputs[][in_c], int out_c, double outputs[][out_c], int training_iterations);

#endif /* NETWORK_H_ */
