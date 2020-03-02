all: exe

exe: 161044068_main.o
	g++ 161044068_main.o -o exe -lm

161044068_main.o: 161044068_main.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 161044068_main.cpp
	
clean:
	rm *.o exe
