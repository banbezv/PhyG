cppflags=-std=c++14 -g

oflags=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

all: main

dependencies: Engine.hpp Body.hpp Vector.hpp Double.hpp

OBJS=Double.o

main: main.o $(OBJS) dependencies
	g++ main.o $(OBJS) -o main $(oflags)

%.o: %.cpp
	g++ -c $< -o $@ $(cppflags)

