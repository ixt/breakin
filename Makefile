CXXFLAGS = --std=c++11 -fpermissive
LFLAGS = -lncurses
CXX = g++
OUTFILE = bin/breakout
FILES = src/*.cpp

all: 
	$(CXX) $(CXXFLAGS) $(FILES) $(LFLAGS) -o ./$(OUTFILE) 

run:
	./$(OUTFILE)
