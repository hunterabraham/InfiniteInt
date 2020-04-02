CXX=g++
CXXFLAGS=-Wall

all: build

InfiniteInt.o: InfiniteInt.h

clean:
	-rm InfiniteInt.o
	-rm demo

build: demo.cpp InfiniteInt.o
	$(CXX) $(CXX_FLAGS) -o demo demo.cpp InfiniteInt.o

