program: minimal.o sdl_helper.o
	g++ minimal.o sdl_helper.o -lSDL -lSDL_image -lm -o sdlfun.out
minimal.o: minimal.cpp sdl_helper.h
	g++ -c minimal.cpp
sdl_helper.o: sdl_helper.cpp sdl_helper.h
	g++ -c sdl_helper.cpp

