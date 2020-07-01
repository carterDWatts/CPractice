#include "network_math.h"

#include <stdlib.h>
#include <stdio.h>
#include "matrix_utils.h"

double sigmoid(double x){
  return 1/(1+exp(-x));
}

double sigmoid_derivative(double x){
  return x * (1-x);
}

double**  matrix_add(double **A, double **B, int rows, int cols){

  double** result;
  initialize_double_pointer(&result, rows, cols);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      result[i][j] = A[i][j] + B[i][j];
    }
  }
  return result;
}

double** matrix_subtract(double **A, double **B, int rows, int cols){

  double** result;
  initialize_double_pointer(&result, rows, cols);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      result[i][j] = A[i][j] - B[i][j];
    }
  }
  return result;
}


double*** matrix_multiply(int rA, int cA, double **A, int rB, int cB, double **B){

  //printf("0\n");
  double **result;
  //printf("1\n");
  //printf("rA: %d, cB: %d\n", rA, cB);
  initialize_double_pointer(&result, rA, cB);
  //printf("2\n");

  if (cA!=rB){
    printf("Row column missmatch - cannot do matrix multiplication\n");
  }else{
    double sum;
    //printf("3\n");
    for (int i = 0; i < rA; i++){
        for (int j = 0; j < cB; j++){
          sum = 0;
          for (int k = 0; k < cB; k++){
            sum += A[i][k] * B[k][j];
          }
          result[i][j] = sum;
        }
      }
      //printf("4\n");
    }
    return *result;
}
