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

  layer arrA = {.rows = 4, .cols = 4};
  initialize_double_pointer(&arrA.values, arrA.rows, arrA.cols);             //allocates space in memory the size of rows and cols
  double arrA_vals[4][4] = { //3 = l.num_arrAs_per_neuron                      //Values set to this
    {2,3,5,1},
    {1,1,1,1},
    {1,0,1,1},
    {0,1,1,1}};
  arrA.values = (double **) assign_values(arrA.rows, arrA.cols, arrA_vals);


  layer arrB = {.rows = 4, .cols = 4};
  initialize_double_pointer(&arrB.values, arrB.rows, arrB.cols);             //allocates space in memory the size of rows and cols
  double arrB_vals[4][4] = { //3 = l.num_arrBs_per_neuron                      //Values set to this
    {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2}};
  arrB.values = (double **) assign_values(arrB.rows, arrB.cols, arrB_vals);

  layer output = {.rows = arrA.rows, .cols = arrB.cols};
  initialize_double_pointer(&output.values, output.rows , output.cols);

  matrix_multiply(output.values, arrA.rows, arrA.cols, arrA.values, arrB.rows, arrB.cols, arrB.values);

  printf("arrA\n");
  print_double_pointer(arrA.values, arrA.rows, arrA.cols);
  printf("arrB\n");
  print_double_pointer(arrB.values, arrB.rows, arrB.cols);
  printf("output\n");
  print_double_pointer(output.values, output.rows, output.cols);

}
