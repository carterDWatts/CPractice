#include "layer.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generate_weight_matrix(layer *L){

    double **array = malloc(sizeof(*array) * L->num_neurons);
    if (array != 0){
        for (int i = 0; i < L->num_neurons; ++i){
             if ((array[i] = malloc(sizeof(**array) * L->num_inputs_per_neuron)) == 0){
                 for (int j = 0; j < i; j++)
                      free(array[j]);
                 free(array);
                 array = 0;
                 break;
             }
        }
    }

    srand(time(0));
    for(int i = 0; i < 100; i++) rand(); //Makes the numbers used in the weight less similar

    for(int i = 0; i < L->num_neurons; i++){
      for(int j = 0; j < L->num_inputs_per_neuron; j++){
        array[i][j] = (double)rand()/(double)RAND_MAX;
      }
    }

    L->weights = array;


}
