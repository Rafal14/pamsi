#plik makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__tablica__: 	tablica
		./tablica

tablica: obj obj/main.o obj/Tablica2D.o obj/Tablica.o obj/Potega_silnia.o
	g++ -Wall -pedantic -std=c++11 -o tablica obj/main.o\
		 obj/Tablica2D.o obj/Tablica.o obj/Potega_silnia.o

obj:
		mkdir obj

obj/main.o:	src/main.cpp inc/Tablica2D.hh inc/Tablica.hh\
		inc/Potega_silnia.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Tablica2D.o:src/Tablica2D.cpp inc/Tablica2D.hh
		g++ -c ${CXXFLAGS} -o obj/Tablica2D.o\
		 src/Tablica2D.cpp

obj/Tablica.o:	src/Tablica.cpp inc/Tablica.hh
		g++ -c ${CXXFLAGS} -o obj/Tablica.o src/Tablica.cpp

obj/Potega_silnia.o:src/Potega_silnia.cpp inc/Potega_silnia.hh
		g++ -c ${CXXFLAGS} -o obj/Potega_silnia.o src/Potega_silnia.cpp

clean:
	rm -f obj/*.o tablica
