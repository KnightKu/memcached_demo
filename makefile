all: main.c memc_connector.c 
	gcc  -g -Wall -o run_mc_demo  main.c memc_connector.c  -lmemcached 
clean:
	rm -rf *.o *.dSYM *.out *.dylib *.so
