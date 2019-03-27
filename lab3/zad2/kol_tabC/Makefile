#plik Makefile
#wpisz 'make' w celu skompilowania programu kolejki w oparciu o STL
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__kolejka__:	kolejka
		./kolejka

kolejka:	obj obj/main.o obj/Kolejka.o
		g++ -Wall -pedantic -std=c++11 -o kolejka obj/main.o\
		obj/Kolejka.o

obj:
	mkdir obj

obj/main.o:	src/main.cpp inc/Kolejka.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Kolejka.o:	src/Kolejka.cpp inc/Kolejka.hh
		g++ -c ${CXXFLAGS} -o obj/Kolejka.o src/Kolejka.cpp

clean:
	rm -f obj/*.o kolejka
