#plik Makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__queue__:	queue
		./queue

queue:		obj obj/main.o obj/Node.o obj/Queue.o
		g++ -Wall -pedantic -std=c++11 -o queue obj/main.o obj/Node.o\
		obj/Queue.o

obj:
	mkdir obj

obj/main.o:	src/main.cpp inc/Node.hh inc/Queue.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Node.o:	src/Node.cpp inc/Node.hh inc/Node.hh
		g++ -c ${CXXFLAGS} -o obj/Node.o src/Node.cpp

obj/Queue.o:	src/Queue.cpp inc/Queue.hh inc/Node.hh
		g++ -c ${CXXFLAGS} -o obj/Queue.o src/Queue.cpp

clean:
	rm -f obj/*.o queue
