all: exe

exe: 161044068_main.o Collection.o Set.o  List.o Queue.o ArrayList.o HashSet.o Iterator.o  ArrayListItr.o HashSetItr.o 
	g++ 161044068_main.o Collection.o Set.o  List.o Queue.o ArrayList.o HashSet.o Iterator.o ArrayListItr.o HashSetItr.o -o exe

161044068_main.o: 161044068_main.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 161044068_main.cpp

Collection.o: Collection.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Collection.cpp
	
Set.o: Set.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Set.cpp
	
List.o: List.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 List.cpp
	
Queue.o: Queue.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Queue.cpp

ArrayList.o: ArrayList.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 ArrayList.cpp

HashSet.o: HashSet.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 HashSet.cpp

Iterator.o: Iterator.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 Iterator.cpp

ArrayListItr.o: ArrayListItr.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 ArrayListItr.cpp

HashSetItr.o: HashSetItr.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 HashSetItr.cpp

LinkedList.o: LinkedList.cpp
	g++ -c -ansi -pedantic -errors --std=c++11 LinkedList.cpp

clean:
	rm *.o exe
