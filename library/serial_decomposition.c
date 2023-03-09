#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "decomposition.h"

int check_prerequisites(double *matrix) {
	return 1;
}

void serial_cholesky_decomposition(double *matrix, double *lower, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (i+1); j++) {
            double s = 0;

            for (int k = 0; k < j; k++) {
                s += lower[i * n + k] * lower[j * n + k];
            }

            if (i == j && matrix[i * n + i] - s < 0)
                printf("Matrix is not positive definite.");

            lower[i * n + j] = (i == j) ?
                           sqrt(matrix[i * n + i] - s) :
                           (1.0 / lower[j * n + j] * (matrix[i * n + j] - s));
            
            
        }
    }
}
