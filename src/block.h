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
public:
    Brick(bool fill, int y, int x, int w, int COLOR);
    Brick(bool fill, int y, int x, int h, int w, int COLOR);
    Brick(int y, int x, int COLOR);
    void draw();
};

class Circle : public Block {
    float radius;
public:
    Circle(bool fill, int y, int x, int r, int COLOR);
    void draw();
};

class Panel : public Block {
    int maxY,maxX;
public:
    int y;
    int x;
    int length;
    Panel(bool filled, int y, int x, int l);
    void right();
    void left();
    void draw();
};

class Ball : public Block {
    signed int direction;
    Panel * panel;
    int * frameX;
    int * frameY;
public:
    int y;
    int x;
    int col;
    int moves;
    Ball(int _y, int _x, signed int d, Panel * player,int * _frameX, int * _frameY, int color);
    bool started();
    void draw();
    void start();
    void reflect(int side);
    void reflectTop();
    void reflectBottom();
    void reflectLeft();
    void reflectRight();
};

class Tile : public Brick {
public:
    int x;
    int y;
    int col;
    int fileNo;
    bool isThereEvenAFile;
    Tile(int _y=20, int _x=20, int col=1+(rand()%4),int fileNo=0,bool isThereEvenAFile=false);
    void draw();
    bool collision(int y, int x);
    int previousDirection;
    int reflectDirection(int y, int x);
};

#endif
