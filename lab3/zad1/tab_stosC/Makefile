#plik Makefile
#wpisz 'make' w celu skompilowania programu implementacji stosu w oparciu o STL
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__stos__:	stos
		./stos

stos:	obj obj/main.o obj/Stos.o
	g++ -Wall -pedantic -std=c++11 -o stos obj/main.o obj/Stos.o

obj:
	mkdir obj

obj/main.o:	src/main.cpp inc/Stos.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Stos.o:	src/Stos.cpp inc/Stos.hh
		g++ -c ${CXXFLAGS} -o obj/Stos.o src/Stos.cpp

clean:
	rm -f obj/*.o stos
