#ifndef NETWORK_MATH_H_
#define NETWORK_MATH_H_

#include <math.h>

double sigmoid(double x);
double sigmoid_derivative(double x);

double**  matrix_add(double** a, double** b, int rows, int cols);
double**  matrix_subtract(double** a, double** b, int rows, int cols);

//double** matrix_multiply(int rA, int cA, double **A, int rB, int cB, double **B){

#endif /* NETWORK_MATH_H_ */
