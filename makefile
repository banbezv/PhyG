dependencies=""
flags="-std=c++14 -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -g"

all: main dependencies

main: dependencies
	g++ main.cpp -o main flags

