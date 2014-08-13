all: main.c memc_connector.c 
	gcc  -g -Wall -o run.o  main.c memc_connector.c  -lmemcached 
clean:
	rm -rf *.o *.dSYM *.out *.dylib *.so
