#include "matrix_utils.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void initialize_double_arr(double ***A, int r, int c){
   *A = (double **)malloc(sizeof(double *)*r);
   for(int i = 0; i< r; i++) {
        (*A)[i] = (double *)malloc(sizeof(double) *c);
        for(int j = 0; j < c; j++) {
            (*A)[i][j] = 0.0;
        }
   }
}

void print_array(double **A, int r, int c){

  for(int i = 0; i < r; i++) {
     for(int j = 0; j < c; j++) {
         printf("%f ", A[i][j]);
     }
     printf("\n");
  }
  printf("\n");

}
