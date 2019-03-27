#plik Makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__graph__:	graph
		./graph

graph:		obj obj/main.o obj/Wezel.o obj/Lista.o obj/Zbior.o obj/Graph.o\
		obj/Krawedz.o
		g++ -Wall -pedantic -std=c++11 -o graph obj/main.o obj/Wezel.o\
		obj/Lista.o obj/Zbior.o obj/Graph.o obj/Krawedz.o

obj:
		mkdir obj

obj/main.o:	src/main.cpp inc/Wezel.hh inc/Lista.hh inc/Graph.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Wezel.o:	src/Wezel.cpp inc/Wezel.hh inc/Lista.hh
		g++ -c ${CXXFLAGS} -o obj/Wezel.o src/Wezel.cpp

obj/Lista.o:	src/Lista.cpp inc/Lista.hh inc/Wezel.hh
		g++ -c ${CXXFLAGS} -o obj/Lista.o src/Lista.cpp

obj/Krawedz.o:	src/Krawedz.cpp inc/Krawedz.hh 
		g++ -c ${CXXFLAGS} -o obj/Krawedz.o src/Krawedz.cpp

obj/Zbior.o:	src/Zbior.cpp inc/Zbior.hh
		g++ -c ${CXXFLAGS} -o obj/Zbior.o src/Zbior.cpp

obj/Graph.o:	src/Graph.cpp inc/Graph.hh inc/Lista.hh inc/Krawedz.hh\
		inc/Zbior.hh
		g++ -c ${CXXFLAGS} -o obj/Graph.o src/Graph.cpp

clean:
	rm -f obj/*.o graph
