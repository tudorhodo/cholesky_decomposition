LIBRARIES=-fopenmp
CFLAGS=-lm

build:
	$(MAKE) -C ./library
	mpicc -o cholesky_decomposition $(LIBRARIES) main.c library/mpi.o $(CFLAGS)

run:
	echo "" > out.txt
	mpirun -np 4 cholesky_decomposition 5000 troll.txt out.txt
clean:
	$(MAKE) -C ./library clean
	rm -rf cholesky_decomposition
