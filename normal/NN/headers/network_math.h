#ifndef NETWORK_MATH_H_
#define NETWORK_MATH_H_

#include <math.h>

double sigmoid(double x);
double sigmoid_derivative(double x);

void matrix_add(double** matrix, double** A, double** B, int rows, int cols);
void matrix_subtract(double** matrix, double** A, double** B, int rows, int cols);

void matrix_multiply(double** matrix, int rA, int cA, double **A, int rB, int cB, double **B);
void scalar_multiply(double** matrix, int rA, int cA, double **A, int rB, int cB, double **B);

void matrix_transpose(double** matrix, int r, int c);
void matrix_transpose_new(double** matrix, int r, int c, double** origional);

#endif /* NETWORK_MATH_H_ */
