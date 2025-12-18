#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

typedef struct {
    double data[SIZE][SIZE];
} Matrix;

void add(Matrix A, Matrix B, Matrix *res);
void subtract(Matrix A, Matrix B, Matrix *res);
void elementWiseMultiply(Matrix A, Matrix B, Matrix *res);


void multiply(Matrix A, Matrix B, Matrix *res);
void transpose(Matrix A, Matrix *res);


double determinant(Matrix A);
void adjoint(Matrix A, Matrix *res);
int inverse(Matrix A, Matrix *res);

void printMatrix(Matrix A);

#endif
