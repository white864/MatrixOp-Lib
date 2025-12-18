#include <stdio.h>
#include "matrix_op.h"

int main() {
    Matrix A = {{{1, 2, 3}, {0, 1, 4}, {5, 6, 0}}};
    Matrix B = {{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}};
    Matrix res;

    printf("--- Matrix Operations Test ---\n\n");

    
    add(A, B, &res);
    printf("A + B:\n");
    printMatrix(res);

    
    double det = determinant(A);
    printf("\nDeterminant of A: %.2f\n", det);

    
    if (inverse(A, &res)) {
        printf("\nInverse of Matrix A:\n");
        printMatrix(res);
    } else {
        printf("\nMatrix A has no inverse (Det = 0).\n");
    }

    return 0;
}
