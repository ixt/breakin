#include <vector>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <ncurses.h>
#include "block.h"

#ifndef BREAKOUT_H
#define BREAKOUT_H

class Brick;
class Panel;
class Ball;

class BreakOut{
    int maxX;
    int maxY;
public:
    void start();
    void draw();
    void update();
    BreakOut();
    Brick * frameIn;
    Brick * frameOut;
    Panel * panel;
    Ball * ball;
};

#endif
