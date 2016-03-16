#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#ifndef BREAKOUT_H
#define BREAKOUT_H

struct Block {
    int y,x,colour;
    char symbol;
    Block(char _symbol);
};

class Ball : public Block {
    int direction=0;
    bool collison;
    public:
    Ball(int _x=0, int _y=0, int _direction=0);
};

class Box : public Block {
    int height, width;
    bool filled;

    public:
    Box(int _y=0, int _x=0, 
        int _height=1, int _width=1, 
        char _symbol=(char)219, bool _filled=1);

};

class Brick : public Box {
    public:
        Brick(int _y, int _x); 
};

class Panel : public Brick {
    public:
        Panel(int _x);
};

class BreakOut {
    int maxHeight, maxWidth, delay, points;
    signed int location;
    char foo;

    Ball ball;
    Box border;

    public:
        BreakOut();
        ~BreakOut();
        void start();
};

#endif
