all: exe

exe: 161044068_main.o Rectangle.o Circle.o  Triangle.o ComposedShape.o
	g++ 161044068_main.o Rectangle.o Circle.o Triangle.o ComposedShape.o -o exe

161044068_main.o: 161044068_main.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 161044068_main.cpp

Rectangle.o: Rectangle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Rectangle.cpp
	
Circle.o: Circle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Circle.cpp
	
Triangle.o: Triangle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Triangle.cpp
	
ComposedShape.o: ComposedShape.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 ComposedShape.cpp
	
clean:
	rm *.o exe
