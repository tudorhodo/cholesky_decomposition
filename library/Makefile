CFLAGS=-c -o

all: serial.o openmp.o

openmp.o:
	gcc $(CFLAGS) openmp.o openmp_decomposition.c -fopenmp

serial.o:
	gcc $(CFLAGS) serial.o serial_decomposition.c -fopenmp

clean:
	rm -rf serial.o openmp.o
