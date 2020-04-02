#///////////////////////////////////////////////////////////////////////////////
#// Main File:        demo.cpp
#// This File:        InfiniteInt.cpp
#// Semester:         CS 368 Spring 2020
#//
#// Author:           Hunter Abraham
#// Email:            hjabraham@wisc.edu
#// CS Login:         habraham
#// Student ID:       9079608908
#////////////////////////////////////////////////////////////////////////////////



CXX=g++
CXXFLAGS=-Wall

all: build

InfiniteInt.o: InfiniteInt.h

clean:
	-rm InfiniteInt.o
	-rm demo

build: demo.cpp InfiniteInt.o
	$(CXX) $(CXX_FLAGS) -o demo demo.cpp InfiniteInt.o

