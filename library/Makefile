CFLAGS=-fopenmp

all: mpi.o
	
mpi.o:
	mpicc -c -o mpi.o mpi_decomposition.c

clean:
	rm -rf mpi.o
