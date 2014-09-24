sdlfun.out: minimal.o sdlfun.o
	g++ minimal.o sdlfun.o -lSDL -lSDL_image -lm -o sdlfun.out
minimal.o: minimal.cpp sdlfun.h
	g++ -c minimal.cpp
sdlfun.o: sdlfun.cpp sdlfun.h
	g++ -c sdlfun.cpp

