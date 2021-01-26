#BAURBERG Sharon Mini_Projet C++ 2020-2021 Makefile

all: clean perso main test

perso: *.hpp
	g++ -c *.cpp

main: *.hpp *.cpp *.o
	g++ main_essai_sfml.o perso.o plateformer.o obstacle.o ennemis.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

test: *.hpp *.cpp *.o
	g++ test.o perso.o plateformer.o obstacle.o ennemis.o -o test -lsfml-graphics -lsfml-window -lsfml-system

clean: *.hpp *.cpp *.o
	rm -f *.o sfml-app test