
CXX=g++
CXXFLAGS=-Wall

all: build

build: InfiniteInt.o
	$(CXX) $(CXX_FLAGS) demo.cpp InfiniteInt.o -o demo

demo: demo.cpp

InfiniteInt.o: InfiniteInt.h
	g++ -c InfiniteInt.cpp
clean:
	-rm InfiniteInt.o
	-rm demo

