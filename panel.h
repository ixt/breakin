#pragma once
#include "breakout.h"
#include "block.h"
#ifndef PANEL_H
#define PANEL_H

class Panel : public Block {
    int length;
public:
    void draw();
    ~Panel();
    Panel(bool filled, int y, int x, int l);
};

#endif
