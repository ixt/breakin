CXXFLAGS = --std=c++11
LFLAGS = -lncurses
CXX = g++
OUTFILE = bin/breakout
FILES = src/block.cpp src/breakout.cpp src/main.cpp 

all: 
	$(CXX) $(CXXFLAGS) $(FILES) $(LFLAGS) -o ./$(OUTFILE) 

run:
	./$(OUTFILE)
