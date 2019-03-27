#plik Makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__lista__:	lista
		./lista

lista:		obj obj/main.o obj/Wezel.o obj/Lista.o
		g++ -Wall -pedantic -std=c++11 -o lista obj/main.o obj/Wezel.o\
		obj/Lista.o

obj:
		mkdir obj

obj/main.o:	src/main.cpp inc/Wezel.hh inc/Lista.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Wezel.o:	src/Wezel.cpp inc/Wezel.hh inc/Lista.hh
		g++ -c ${CXXFLAGS} -o obj/Wezel.o src/Wezel.cpp

obj/Lista.o:	src/Lista.cpp inc/Lista.hh inc/Wezel.hh
		g++ -c ${CXXFLAGS} -o obj/Lista.o src/Lista.cpp

clean:
	rm -f obj/*.o lista
