#include <stdio.h>
#include "matrix_op.h"


void add(Matrix A, Matrix B, Matrix *res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) res->data[i][j] = A.data[i][j] + B.data[i][j];
}

void subtract(Matrix A, Matrix B, Matrix *res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) res->data[i][j] = A.data[i][j] - B.data[i][j];
}


void elementWiseMultiply(Matrix A, Matrix B, Matrix *res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) res->data[i][j] = A.data[i][j] * B.data[i][j];
}


void transpose(Matrix A, Matrix *res) {
	int i,j;
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) res->data[j][i] = A.data[i][j];
}


void multiply(Matrix A, Matrix B, Matrix *res) {
	int i,j,k;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            res->data[i][j] = 0;
            for(k=0; k<SIZE; k++) res->data[i][j] += A.data[i][k] * B.data[k][j];
        }
    }
}

double determinant(Matrix A) {
    return A.data[0][0]*(A.data[1][1]*A.data[2][2] - A.data[1][2]*A.data[2][1]) -
           A.data[0][1]*(A.data[1][0]*A.data[2][2] - A.data[1][2]*A.data[2][0]) +
           A.data[0][2]*(A.data[1][0]*A.data[2][1] - A.data[1][1]*A.data[2][0]);
}


void adjoint(Matrix A, Matrix *res) {
    res->data[0][0] = (A.data[1][1]*A.data[2][2] - A.data[1][2]*A.data[2][1]);
    res->data[0][1] = -(A.data[0][1]*A.data[2][2] - A.data[0][2]*A.data[2][1]);
    res->data[0][2] = (A.data[0][1]*A.data[1][2] - A.data[0][2]*A.data[1][1]);
    res->data[1][0] = -(A.data[1][0]*A.data[2][2] - A.data[1][2]*A.data[2][0]);
    res->data[1][1] = (A.data[0][0]*A.data[2][2] - A.data[0][2]*A.data[2][0]);
    res->data[1][2] = -(A.data[0][0]*A.data[1][2] - A.data[0][2]*A.data[1][0]);
    res->data[2][0] = (A.data[1][0]*A.data[2][1] - A.data[1][1]*A.data[2][0]);
    res->data[2][1] = -(A.data[0][0]*A.data[2][1] - A.data[0][1]*A.data[2][0]);
    res->data[2][2] = (A.data[0][0]*A.data[1][1] - A.data[0][1]*A.data[1][0]);
}


int inverse(Matrix A, Matrix *res) {
	int i,j;
    double det = determinant(A);
    if (det == 0) return 0; 
    Matrix adj;
    adjoint(A, &adj);
    for(i=0; i<SIZE; i++)
        for(j=0; j<SIZE; j++) res->data[i][j] = adj.data[i][j] / det;
    return 1;
}

void printMatrix(Matrix A) {
	int i,j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) printf("%.2f\t", A.data[i][j]);
        printf("\n");
    }
}
