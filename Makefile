cc=g++
//compiler
CFLAGS=-c -Wall
//compile flags

LDFLAGS=-lxerces-c
//list of sources

SOURCES=xml_reader.cpp
OBJECTS=$(SOURCES:.cpp=.o)
//list of object files generated from source files
EXECUTABLE=xml_reader
