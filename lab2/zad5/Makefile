#plik Makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__deque__:	deque
		./deque

deque:	obj obj/main.o obj/Wezel.o obj/Deque.o
	g++ -Wall -pedantic -std=c++11 -o deque obj/main.o obj/Wezel.o obj/Deque.o

obj:
	mkdir obj

obj/main.o:	src/main.cpp inc/Wezel.hh inc/Deque.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Wezel.o:	src/Wezel.cpp inc/Wezel.hh inc/Deque.hh
		g++ -c ${CXXFLAGS} -o obj/Wezel.o src/Wezel.cpp

obj/Deque.o:	src/Deque.cpp inc/Deque.hh inc/Wezel.hh
		g++ -c ${CXXFLAGS} -o obj/Deque.o src/Deque.cpp

clean:
	rm -f obj/*.o deque
