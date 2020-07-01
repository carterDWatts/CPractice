#include "network.h"

#include <stdio.h>
#include "layer.h"
#include "network_math.h"
#include "matrix_utils.h"

void process(network net, layer input){

  printf("start\n");
  *net.output_layer.values = (double ***) matrix_multiply(input.rows, input.cols, input.values, net.l1.rows, net.l1.cols, net.l1.weights);

  print_double_pointer(net.output_layer.values, net.output_layer.rows, net.output_layer.cols);

  for(int i = 0; i < net.output_layer.rows; i++){
    for(int j = 0; j < net.output_layer.cols; j++){
      net.output_layer.values[i][j] = sigmoid(net.output_layer.values[i][j]);
    }
  }
  printf("end\n");

}

void train(network net, layer input, layer answers, int training_iterations){

  for(int i = 0; i < training_iterations; i++){
    process(net, input);
    printf("iter %d/10\n", i+1);
  }

}
