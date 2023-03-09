#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <omp.h>
#include "decomposition.h"

#define NO_THREADS 6

int check_prerequisites(double *matrix) {
	return 1;
}

void openmp_cholesky_decomposition(double *matrix, double *lower, int n) {
    double s;
    int i, j, k;
    omp_set_num_threads(NO_THREADS);

    for (j = 0; j < n; j++) {
        s = 0;

        //elementele de pe diagonala principala
        #pragma omp parallel for reduction(+:s) private(k) shared(lower, j) schedule(guided, 430)
        for (k = 0; k < j; k++) {
            s += lower[j * n + k] * lower[j * n + k];
        }

        lower[j * n + j] = sqrt(matrix[j * n + j] - s);

        //elementele de sub diagonala principala
        #pragma omp parallel for private(i, k, s) shared(lower, j) schedule(guided, 430)
        for (i = j + 1; i < n; i++) {
            s = 0;

            for (k = 0; k < j; k++) {
                s += lower[i * n + k] * lower[j * n + k];
            }

            lower[i * n + j] = (1.0 / lower[j * n + j] * (matrix[i * n + j] - s));
        }
    }
}
