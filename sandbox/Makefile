sdlfun.out: main.o sdlfun.o
	g++ main.o sdlfun.o -lSDL -lSDL_image -lm -o sdlfun.out
main.o: main.cpp ../cpp/sdlfun.h
	g++ -c main.cpp
sdlfun.o: ../cpp/sdlfun.cpp ../cpp/sdlfun.h
	g++ -c ../cpp/sdlfun.cpp

