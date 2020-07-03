#ifndef NETWORK_H_
#define NETWORK_H_

#include "layer.h"

typedef struct{
  hidden_layer l1;
  layer output_layer;
}network;

void generate_output_layer(network *N, int r, int c);
void process(network net, layer input);
void train(network net, layer input, layer answers, int training_iterations);

#endif /* NETWORK_H_ */
