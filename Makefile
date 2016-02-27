CXXFLAGS = --std=c++0x
LFLAGS = -lncurses
CXX = g++
OUTFILE = breakout
FILES = block.cpp breakout.cpp panel.cpp main.cpp 

all: 
	$(CXX) $(CXXFLAGS) $(FILES) $(LFLAGS) -o $(OUTFILE) 

run:
	./$(OUTFILE)
