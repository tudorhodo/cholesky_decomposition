#ifndef DECOMPOSITION_H
#define DECOMPOSITION_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int rank, rank_size;

int check_prerequisites(double *matrix);
void cholesky_decomposition_mpi(double *matrix, double *lower, int n);
void serial_cholesky_decomposition(double *matrix, double *lower, int n);
void openmp_cholesky_decomposition(double *matrix, double *lower, int n);

#endif /*DECOMPOSITION_H*/
