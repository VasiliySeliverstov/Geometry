all: Geometry.o


Geometry.o: main.cpp
	g++ -o Geometry.o -std=c++11 main.cpp