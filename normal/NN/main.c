#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "matrix_utils.h"
#include "layer.h"
#include "network.h"
#include "network_math.h"

void predict(layer test_input, layer answers, network net);

int main(void){

  /* CURRENT SETUP
      a row that adds up to 2 is a 1
      any other row is a 0
  */

  //Creats, allocates, and sets values for input layer
  layer input = {.rows = 4, .cols = 3};
  initialize_double_pointer(&input.values, input.rows, input.cols);             //allocates space in memory the size of rows and cols
  double in_values[4][3] = { //3 = l.num_inputs_per_neuron                      //Values set to this
    {1,0,1},
    {1,1,1},
    {0,1,1},
    {0,1,0}};
  assign_values(input.values, input.rows, input.cols, in_values);

  layer answers = {.rows = 4, .cols = 1};
  initialize_double_pointer(&answers.values, answers.rows, answers.cols);       //allocates space in memory the size of rows and cols
  double answer_values[4][1] = { //1 = l.num_neurons                            //Values set to this
    {1},
    {0},
    {1},
    {0}};
  assign_values(answers.values, answers.rows, answers.cols, answer_values);

  hidden_layer hl = {.num_inputs_per_neuron = 3, .num_neurons = 1,  .rows = hl.num_inputs_per_neuron, .cols = hl.num_neurons, .weights = 0};
  generate_weight_matrix(&hl); //Sets values to random double between 0 & 1

  layer ol = {.rows = answers.rows, .cols = answers.cols};//{.rows = input.rows, .cols = hl.num_inputs_per_neuron};
  initialize_double_pointer(&ol.values, ol.rows, ol.cols);

  network net = {.l1 = hl, .output_layer = ol};

  train(net, input, answers, 100000);

  //Predctions
  layer test_input = {.rows = 4, .cols = 3};
  initialize_double_pointer(&test_input.values, test_input.rows, test_input.cols);             //allocates space in memory the size of rows and cols
  double test_in_values[4][3] = { //3 = l.num_test_inputs_per_neuron                      //Values set to this
    {1,0,1},
    {0,1,0},
    {1,0,1},
    {1,1,1}};
  assign_values(test_input.values, test_input.rows, test_input.cols, test_in_values);

  layer correct_answers = {.rows = 4, .cols = 1};
  initialize_double_pointer(&correct_answers.values, correct_answers.rows, correct_answers.cols);             //allocates space in memory the size of rows and cols
  double correct_values[4][1] = { //3 = l.num_correct_answerss_per_neuron                      //Values set to this
    {1},
    {0},
    {1},
    {0}};
  assign_values(correct_answers.values, correct_answers.rows, correct_answers.cols, correct_values);

  predict(test_input, correct_answers, net);

}

void predict(layer test_input, layer answers, network net){

  process(net, test_input);

  printf("Predicted Answers:\n");
  for(int i = 0; i < net.output_layer.rows; i++){
    printf("[");
    for(int j = 0; j < net.output_layer.cols; j++){
      printf("%f ", net.output_layer.values[i][j]);
    }
    printf("]\n");
  }


  printf("Actual Answers:\n");
  for(int i = 0; i < answers.rows; i++){
    printf("[");
    printf("%f ", answers.values[i][0]);
    printf("]\n");
  }


}
