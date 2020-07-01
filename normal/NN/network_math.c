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
  initialize_double_arr(&result, rows, cols);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      result[i][j] = A[i][j] + B[i][j];
    }
  }
  return result;

}

double** matrix_subtract(double **A, double **B, int rows, int cols){

  double** result;
  initialize_double_arr(&result, rows, cols);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      result[i][j] = A[i][j] - B[i][j];
    }
  }
  return result;

}


double** matrix_multiply(int rA, int cA, double **A, int rB, int cB, double **B){

  if (!((cA==rB)&&(rA==cB))){
    printf("Row column miss matching so cannot do matrix multiplication");
  }else{

    double **result;
    initialize_double_arr(&result, rA, cB);

    printf("test2\n");

    double sum;
    for (int i = 0; i < rA; i++){
        for (int j = 0; j < cB; j++){

            printf("test2\n");
            sum = 0;
            /*
             * Find sum of product of each elements of
             * rows of first matrix and columns of second
             * matrix.
             */
            for (int k = 0; k < cB; k++){
                sum += (*(*(A + rA) + i)) * (*(*(B + i) + cB));
            }
            result[i][j] = sum; //*(*(res + row) + col)
        }
      }
    }

}
