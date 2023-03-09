LIBRARIES=-fopenmp
CFLAGS=-lm

build:
	$(MAKE) -C ./library
	gcc -o cholesky_decomposition $(LIBRARIES) main.c library/serial.o $(CFLAGS)

clean:
	$(MAKE) -C ./library clean
	rm -rf cholesky_decomposition
