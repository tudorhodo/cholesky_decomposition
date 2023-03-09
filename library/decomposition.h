#ifndef DECOMPOSITION_H
#define DECOMPOSITION_H

int check_prerequisites(double *matrix);
void mpi_cholesky_decomposition(double *matrix, double *lower, int n); 
void serial_cholesky_decomposition(double *matrix, double *lower,int n);
void openmp_cholesky_decomposition(double *matrix, double *lower,int n);


#endif /*DECOMPOSITION_H*/
