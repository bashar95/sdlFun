sdlfun.out: minimal.o sdlfun.o
	g++ minimal.o sdlfun.o -lSDL -lSDL_image -lm -o sdlfun.out
minimal.o: minimal.cpp ../cpp/sdlfun.h
	g++ -c minimal.cpp
sdlfun.o: ../cpp/sdlfun.cpp ../cpp/sdlfun.h
	g++ -c ../cpp/sdlfun.cpp

