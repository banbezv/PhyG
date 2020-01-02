.PHONY: clean

cppflags=-std=c++14 -g

oflags=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

all: main

dependencies: World.hpp Body.hpp Vector.hpp Double.hpp utils.hpp

OBJS=Double.o Vector.o Body.o World.o utils.o

main: main.o $(OBJS) dependencies
	g++ main.o $(OBJS) -o main $(oflags)

%.o: %.cpp
	g++ -c $< $(cppflags)

clean:
	rm *.o

