#include "mpi.h"
#include "decomposition.h"

double *matrix;
double *lower;
int rank, rank_size;

void cholesky_decomposition_mpi(double *matrix, double *lower, int n)
{
    double sum;
    double *vect = malloc(n * sizeof(double));
    int start, end, i, j, k;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (k = 0; k < j; k++)
        {
            sum += lower[j * n + k] * lower[j * n + k];
        }
        lower[j * n + j] = sqrt(matrix[j * n + j] - sum);

        MPI_Barrier(MPI_COMM_WORLD);

        start = j + rank * (double)(n - j + 1) / rank_size;
        end = fmin(j + (rank + 1) * (double)(n - j + 1) / rank_size, n);

        for (i = start; i < end; i++)
        {
            sum = 0;

            for (k = 0; k < j; k++)
            {
                sum += lower[i * n + k] * lower[j * n + k];
            }

            lower[i * n + j] = (1.0 / lower[j * n + j] * (matrix[i * n + j] - sum));
            vect[i] = lower[i * n + j];
        }

        for (i = 0; i < rank_size; i++)
        {
            int start_2 = j + i * (double)(n - j + 1) / rank_size;
            int end_2 = fmin(j + (i + 1) * (double)(n - j + 1) / rank_size, n);
            MPI_Bcast((vect + start_2), end_2 - start_2, MPI_DOUBLE, i, MPI_COMM_WORLD);
        }
        for (i = j + 1; i < n; i++)
        {
            lower[i * n + j] = vect[i];
        }
    }
}
