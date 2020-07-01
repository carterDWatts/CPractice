#include "matrix_utils.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void initialize_double_pointer(double ***A, int r, int c){
   *A = (double **)malloc(sizeof(double *)*r);
   for(int i = 0; i< r; i++) {
        (*A)[i] = (double *)malloc(sizeof(double) *c);
        for(int j = 0; j < c; j++) {
            (*A)[i][j] = 0.0;
        }
   }
}

void print_double_pointer(double **A, int r, int c){

  for(int i = 0; i < r; i++) {
    printf("[");
    for(int j = 0; j < c; j++) {
      printf("%f ", A[i][j]);
    }
    printf("]\n");
  }
  printf("\n");

}

double** assign_values(int r, int c, double values[r][c]){

  double** result;
  initialize_double_pointer(&result, r, c);

  for(int i = 0; i < r; i++){
    for (int j = 0; j < c; j++) {
      result[i][j] = values[i][j];
    }
  }
  return result;

}
