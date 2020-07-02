#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "matrix_utils.h"
#include "layer.h"
#include "network.h"
#include "network_math.h"


int main(void){

  //Creats, allocates, and sets values for input layer
  layer input = {.rows = 4, .cols = 3};
  initialize_double_pointer(&input.values, input.rows, input.cols);             //allocates space in memory the size of rows and cols
  double in_values[4][3] = { //3 = l.num_inputs_per_neuron                      //Values set to this
    {0,0,1},
    {1,1,1},
    {1,0,1},
    {0,1,1}};
  input.values = (double **) assign_values(input.rows, input.cols, in_values);

  layer answers = {.rows = 4, .cols = 1};
  initialize_double_pointer(&answers.values, answers.rows, answers.cols);       //allocates space in memory the size of rows and cols
  double answer_values[4][1] = { //1 = l.num_neurons                            //Values set to this
    {0},
    {1},
    {1},
    {0}};
  answers.values = (double **) assign_values(answers.rows, answers.cols, answer_values);

  hidden_layer hl = {.num_inputs_per_neuron = 3, .num_neurons = 1,  .rows = hl.num_inputs_per_neuron, .cols = hl.num_neurons, .weights = 0};
  generate_weight_matrix(&hl); //Sets values to random double between 0 & 1

  layer ol = {.rows = input.rows, .cols = hl.num_inputs_per_neuron};
  initialize_double_pointer(&ol.values, ol.rows, ol.cols);

  network net = {.l1 = hl, .output_layer = ol};

  train(net, input, answers, 10);

}
