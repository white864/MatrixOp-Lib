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
