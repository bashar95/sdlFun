sdlfun.out: minimal.o sdlfun.o
	gcc minimal.o sdlfun.o -lSDL -lSDL_image -lm -o sdlfun.out
minimal.o: minimal.c sdlfun.h
	gcc -c minimal.c
sdlfun.o: sdlfun.c sdlfun.h
	gcc -c sdlfun.c

