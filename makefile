
#//////////////////////////////////////////////////////////////////////////////
#/
#/ Copyright 2020 Jim Skrentny
#/ Posting or sharing this file is prohibited, including any changes/additions.
#/
#///////////////////////////////////////////////////////////////////////////////
#/ Main File:        demo.cpp
#/ Semester:         CS 368 Spring 2020
#/
#/ Author:           Hunter Abraham
#/ Email:            hjabraham@wisc.edu
#/ CS Login:         habraham
#/ Student ID:       9079608908
#///////////////////////////////////////////////////////////////////////////////


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

