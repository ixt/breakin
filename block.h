#pragma once
#include "breakout.h"
#ifndef BLOCK_H
#define BLOCK_H

class Block {
    bool* filled;
    int* COLOR;
    int y;
    int x;
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

class Panel : public Block {
    int maxY,maxX;
public:
    int y;
    int x;
    int length;
    Panel(bool filled, int y, int x, int l);
    ~Panel();
    void left();
    void right();
    void draw();
};

class Ball : public Block {
    signed int direction;
    Panel * panel;
public:
    int y;
    int x;
    int moves;
    Ball(int _y, int _x, signed int d, Panel * player);
    ~Ball();
    bool started();
    void draw();
    void start();
    void reflectTop();
    void reflectBottom();
    void reflectLeft();
    void reflectRight();
};

#endif
