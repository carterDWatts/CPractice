#include "network.h"

#include <stdio.h>
#include "layer.h"
#include "network_math.h"

/*
void generate_output_layer(network *N)
{
    double **array = malloc(sizeof(*array) * N->r);
    if (array != 0){
        for (int i = 0; i < N->r; ++i){
             if ((array[i] = malloc(sizeof(**array) * N->c)) == 0){
                 for (int j = 0; j < i; j++)
                      free(array[j]);
                 free(array);
                 array = 0;
                 break;
             }
        }
    }
    N->output_layer = array;
}
*/

void process(network net, int in_c, double inputs[][in_c]){
  //net.output_layer = apply( matrix_multiply(inputs, net.layer1_weights))
}

void train(network net, int in_c, double inputs[][in_c], int out_c, double outputs[][out_c], int training_iterations){

  for(int i = 0; i < training_iterations; i++){
    process(net, in_c, inputs);
  }
}
