.PHONY: clean

cppflags=-std=c++14 -g

oflags=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

all: main

DEPENDENCIES=Double.hpp Vector.hpp utils.hpp Section.hpp Body.hpp World.hpp Physics.hpp Geometry.hpp

OBJS=Double.o Vector.o utils.o Section.o Body.o World.o Physics.o Geometry.o

main: main.o $(OBJS) $(DEPENDENCIES)
	g++ main.o $(OBJS) -o main $(oflags)

%.o: %.cpp
	g++ -c $< $(cppflags)

clean:
	rm *.o

