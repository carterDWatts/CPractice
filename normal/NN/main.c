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

  int r = 2, c = 2;
  double** arrA;
  initialize_double_arr(&arrA, r, c);
  double** arrB;
  initialize_double_arr(&arrB, r, c);

  for(int i = 0; i < r; i++){
    for (int j = 0; j < c; j++) {
      arrA[i][j] = 2;
      arrB[i][j] = 2;
    }
  }

  print_array(arrA, r, c);
  print_array(arrB, r, c);



  double** arrC;
  initialize_double_arr(&arrC, r, c);
  printf("test0\n");
  arrC = matrix_multiply(r, c, arrA, r, c, arrB);
  printf("test1\n");
  //print_array(arrC, r, c);
  /*
  layer l = {.num_neurons = 1, .num_inputs_per_neuron = 3, .weights = 0};
  generate_weight_matrix(&l);

  /*
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("%f ", c[i][j]);
    }
    printf("\n");
  }
  */

  /*
  network net = {.l1 = l};
  double inputs[][3] = {
    {0,0,1},
    {1,1,1},
    {1,0,1},
    {0,1,1}};
  double outputs[][1] = {
    {0},
    {1},
    {1},
    {0}};



  train(net, sizeof(inputs[0])/sizeof(inputs[0][0]), inputs, sizeof(outputs[0])/sizeof(outputs[0][0]), outputs, 1);
  */
}
