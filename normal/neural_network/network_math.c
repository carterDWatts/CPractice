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

    for (int i = 0; i < rA; ++i) {
      for (int j = 0; j < cB; ++j) {
        matrix[i][j] = 0;
      }
    }

    for (int i = 0; i < rA; i++){
      for (int j = 0; j < cB; j++){
        for (int k = 0; k < cA; k++){
          matrix[i][j] += A[i][k] * B[k][j];
        }
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

void matrix_transpose(double** matrix, int r, int c){

  double** temp;
  initialize_double_pointer(&temp, r, c);

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      temp[i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++){
      matrix[j][i] = temp[i][j];
    }
  }

  for(int i = 0; i < r; i++){
    free(temp[i]);
  }
  free(temp);

}
void matrix_transpose_new(double** matrix, int r, int c, double** origional){

  for (int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      matrix[i][j] = origional[j][i];
    }
  }
}
