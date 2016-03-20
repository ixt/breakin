#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iostream>
#include <ncurses.h>
#include "block.h"
#include "file.h"

#ifndef BREAKOUT_H
#define BREAKOUT_H

class Brick;
class Panel;
class Ball;
class Tile;
class File;

class BreakOut{
    int maxX;
    int maxY;
    time_t rawTime;
    struct tm * timeInfo;
public:
    void start();
    void draw();
    void update();
    BreakOut();
    Brick * frameIn;
    Brick * frameOut;
    Panel * panel;
    Ball * ball;
    File * fileSystem;
    std::vector<Tile *> tiles;
    void addTile();
    void startScreen();
    bool end;
};

#endif
