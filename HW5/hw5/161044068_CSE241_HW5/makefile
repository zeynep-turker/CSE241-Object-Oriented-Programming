all: exe

exe: 161044068_main.o Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonDyn.o PolygonVect.o
	g++ 161044068_main.o Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonDyn.o PolygonVect.o -o exe

161044068_main.o: 161044068_main.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 161044068_main.cpp
Shape.o: Shape.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Shape.cpp
Rectangle.o: Rectangle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Rectangle.cpp
	
Circle.o: Circle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Circle.cpp
	
Triangle.o: Triangle.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Triangle.cpp
	
ComposedShape.o: ComposedShape.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 ComposedShape.cpp
Polygon.o: Polygon.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Polygon.cpp
PolygonDyn.o: PolygonDyn.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 PolygonDyn.cpp
PolygonVect.o: PolygonVect.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 PolygonVect.cpp


clean:
	rm *.o exe
