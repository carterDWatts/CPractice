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

void matrix_add(double** matrix, double** A, double** B, int rows, int cols){

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      matrix[i][j] = A[i][j] + B[i][j];
    }
  }
}
void matrix_subtract(double** matrix, double** A, double** B, int rows, int cols){

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      matrix[i][j] = A[i][j] - B[i][j];
    }
  }
}

void matrix_multiply(double** matrix, int rA, int cA, double **A, int rB, int cB, double **B){

  if (cA!=rB){
    printf("Row column missmatch - cannot do matrix multiplication\n");
    return;
  }else{

    double sum;
    //printf("3\n");
    for (int i = 0; i < rA; i++){
      for (int j = 0; j < cB; j++){
        sum = 0;
        for (int k = 0; k < cB; k++){
          sum += A[i][k] * B[k][j];
        }
        matrix[i][j] = sum;
      }
    }
  }
}
void scalar_multiply(double** matrix, int rA, int cA, double **A, int rB, int cB, double **B){

  if (rA!=rB){
    printf("size missmatch - cannot do matrix multiplication\n");
  }else{

    for(int i = 0; i < rA; i++){
      for(int j = 0; j < cA; j++){
        matrix[i][j] = A[i][j] * B[i][j];
      }
    }
  }
}
