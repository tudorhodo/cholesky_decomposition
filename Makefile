LIBRARIES=-fopenmp
CFLAGS=-lm

build:
	$(MAKE) -C ./library
	# gcc -o serial_cholesky_decomposition $(LIBRARIES) main.c library/serial.o $(CFLAGS)
	gcc -o openmp_cholesky_decomposition $(LIBRARIES) library/openmp.o main.c $(CFLAGS)


clean:
	$(MAKE) -C ./library clean
	rm -rf *cholesky_decomposition
