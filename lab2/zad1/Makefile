#plik makefile
#wpisz 'make' w celu skompilowania programu
#wpisz 'make clean' w celu usuniecia plikow binarnych

CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__slowo__:	slowo
		./slowo

slowo:	obj obj/main.o obj/Palindrom.o
	g++ -Wall -pedantic -std=c++11 -o slowo obj/main.o obj/Palindrom.o

obj:
	mkdir obj

obj/main.o:	src/main.cpp inc/Palindrom.hh
		g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Palindrom.o:src/Palindrom.cpp inc/Palindrom.hh
		g++ -c ${CXXFLAGS} -o obj/Palindrom.o src/Palindrom.cpp

clean:
	rm -f obj/*.o slowo
