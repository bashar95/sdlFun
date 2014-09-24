program: minimal.o sdl_helper.o
	gcc minimal.o sdl_helper.o -lSDL -lSDL_image -lm -o sdlfun.out
minimal.o: minimal.c sdl_helper.h
	gcc -c minimal.c
sdl_helper.o: sdl_helper.c sdl_helper.h
	gcc -c sdl_helper.c

