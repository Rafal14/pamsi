#plik Makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__graph__:	graph
		./graph

graph:		obj obj/main.o obj/Heap.o obj/Graph.o\
		obj/Krawedz.o obj/Dijkstra.o
		g++ -Wall -pedantic -std=c++11 -o graph obj/main.o\
		obj/Heap.o obj/Graph.o obj/Krawedz.o obj/Dijkstra.o

obj:
		mkdir obj

obj/main.o:	src/main.cpp inc/Heap.hh inc/Graph.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Heap.o:	src/Heap.cpp inc/Heap.hh inc/Krawedz.hh
		g++ -c ${CXXFLAGS} -o obj/Heap.o src/Heap.cpp

obj/Krawedz.o:	src/Krawedz.cpp inc/Krawedz.hh 
		g++ -c ${CXXFLAGS} -o obj/Krawedz.o src/Krawedz.cpp

obj/Graph.o:	src/Graph.cpp inc/Graph.hh inc/Heap.hh inc/Krawedz.hh
		g++ -c ${CXXFLAGS} -o obj/Graph.o src/Graph.cpp

obj/Dijkstra.o:	src/Dijkstra.cpp inc/Dijkstra.hh inc/Heap.hh inc/Krawedz.hh\
		inc/Graph.hh
		g++ -c ${CXXFLAGS} -o obj/Dijkstra.o src/Dijkstra.cpp

clean:
	rm -f obj/*.o graph
