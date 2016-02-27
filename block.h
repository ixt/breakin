#pragma once
#include "breakout.h"
#ifndef BLOCK_H
#define BLOCK_H

class Block {
    bool* filled;
    int y;
    int x;
    int* COLOR;
public:
    Block(bool fill, float yi, float xi, int ci);
    ~Block();
    virtual void draw()=0;
    int getY();
    int getX();
    int getColor();
    bool getFilled();
};

class Brick : public Block {
    int width;
    int height;
    bool broken=false;
public:
    Brick(bool fill, int y, int x, int w, int COLOR);
    Brick(bool fill, int y, int x, int h, int w, int COLOR);
    ~Brick();
    void draw();
};

class Circle : public Block {
    float radius;
public:
    Circle(bool fill, int y, int x, int r, int COLOR);
    ~Circle();
    void draw();
};

#endif
