CXXFLAGS = --std=c++11
LFLAGS = -lncurses
CXX = g++
OUTFILE = breakout
FILES = block.cpp breakout.cpp main.cpp 

all: 
	$(CXX) $(CXXFLAGS) $(FILES) $(LFLAGS) -o $(OUTFILE) 

run:
	./$(OUTFILE)
