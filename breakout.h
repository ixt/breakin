#include <vector>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <ncurses.h>
#include "block.h"
#include "panel.h"

#ifndef BREAKOUT_H
#define BREAKOUT_H

class BreakOut{
    int maxX;
    int maxY;
public:
    void start();
    BreakOut();
};

#endif
