#include "arr.h"

#include <stdlib.h>
#include <stdio.h>

void initalize_arr_0(arr A){
  A.vals = (int *)malloc(sizeof(int) *A.length);
  for(int i = 0; i < A.length; i++){
    A.vals[i] = 0;
  }
}

void print_arr(arr A){
  for(int i = 0; i < A.length; i++){
    printf("%d ",A.vals[i]);
  }
}

/*
void initialize_double_pointer(double ***A, int r, int c){
   *A = (double **)malloc(sizeof(double *)*r);
   for(int i = 0; i< r; i++) {
        (*A)[i] = (double *)malloc(sizeof(double) *c);
        for(int j = 0; j < c; j++) {
            (*A)[i][j] = 0.0;
        }
   }
}
*/
