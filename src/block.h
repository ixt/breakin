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
    ~Block() {delete filled; delete COLOR; filled = nullptr; COLOR = nullptr;};
    virtual void draw()=0;
    int getY() { return y; };
    int getX() { return x; };
    int getColor() { return *COLOR; };
    bool getFilled() { return *filled; };
};

class Brick : public Block {
    int width;
    int height;
public:
    Brick(bool fill, int y, int x, int w, int COLOR) : Block (fill, y, x, COLOR), width(w){};
    Brick(bool fill, int y, int x, int h, int w, int COLOR) : Block (fill, y, x, COLOR), width(w), height(h){};
    Brick(int y, int x, int COLOR) : Block(false, y, x, COLOR), width(10), height(2){};
    void draw();
};

class Circle : public Block {
    float radius;
public:
    Circle(bool fill, int y, int x, int r, int COLOR) : Block(fill, y, x, COLOR), radius(r){};
    void draw();
};

class Panel : public Block {
    int maxY,maxX;
public:
    int y;
    int x;
    int length;
    Panel(bool filled, int y, int x, int l) : Block(filled, 0, 0, 3), x(x), y(y), length(l){};
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
    Ball(int _y, int _x, signed int d, Panel * player,int * _frameX, int * _frameY, int color) : 
        Block(true, _y, _x, 3), direction(d), y(_y), frameX(_frameX), frameY(_frameY), panel(player), col(color){
        x = panel -> x + (rand()%panel->length);};
    bool started(){bool answer = direction!= 0 ? 1 : 0; return answer;};
    void draw();
    void start(){direction = -1; moves++;};
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
    bool gone=false;
    int fileNo;
    bool isThereEvenAFile=false;
    Tile(int _y=20, int _x=20, int color=1+(rand()%4),int fileNo=0,bool isThereEvenAFile=false) :
            Brick(_y, _x, color), col(color), x(_x), y(_y), isThereEvenAFile(isThereEvenAFile), fileNo(fileNo){};
    void draw();
    bool collision(int _y, int _x){bool answer = (_y == y && _x >= x && _x <= x +2 )? 1 : 0; return answer;};
    int previousDirection;
    int reflectDirection(int y, int x);
};

#endif
