#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "library/decomposition.h"

double *matrix;
double *lower;
static int n;
/*
    Alocare matrice
 */
int init()
{
	matrix = (double*)calloc(n * n, sizeof(double));
	if (matrix == NULL)
        exit(EXIT_FAILURE);


	lower = (double*)calloc(n * n, sizeof(double));
	if (lower == NULL)
        exit(EXIT_FAILURE);

	return 0;
}

/*
    Dezalocare matrice
 */
int destroy()
{
	free(matrix);

	free(lower);

	return 0;
}

/*
    Citire din fisier
 */ 
int read_from_file(const char *file_in)
{
	FILE *fp;
	fp = fopen(file_in, "r");
	if (!fp) {
		printf("Cannot open file\n");
		return -1;
	}
	if (!matrix) {
		return -1;
	}

	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(fp, "%lf", &matrix[i * n + j]) < 0)
            {
                return -1;
            }
        }
    }

	fclose(fp);
	return 0;
}

/*
    Scriere in fisier
 */ 
int write_matrix(const char *file_out)
{
	FILE *fp;
	fp = fopen(file_out, "w+");
	if (!fp) {
		printf("Cannot open file\n");
		return -1;
	}
	if (!matrix) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (fprintf(fp, "%lf\t", lower[i * n + j]) < 0) {
				return -1;
			}
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		printf("Usage: ./cholesky_decomposition SIZE file.in file.out\n");
		printf("Num of arguments expected: 3, got: %d\n", argc - 1);
		return -1;
	}

	n = atoi(argv[1]);
	char *file_in = argv[2];
	char *file_out = argv[3];

	int ret;
	double time1, time2, time_read1, time_read2;

	time_read1 = omp_get_wtime();
	ret = init();
	if (ret == 1){
		return EXIT_FAILURE;
	}

	ret = read_from_file(file_in);
	if (ret == -1){
		return EXIT_FAILURE;
	}

 	time_read2 = omp_get_wtime();

 	time1 = omp_get_wtime();
    serial_cholesky_decomposition(matrix, lower, n);
	time2 = omp_get_wtime();
    printf("[SERIAL] Time elapsed: %lf seconds\n", (time2-time1));
    
    write_matrix(file_out);

	ret = destroy();
	return ret;
}
