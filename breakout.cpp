#include "breakout.h"

BreakOut::BreakOut(){
    initscr();
    noecho();
    cbreak();
    timeout(0);
    keypad(stdscr,true);
    halfdelay(1);
    
    start_color();
    curs_set(0);
    init_pair(1,COLOR_BLACK,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_CYAN);
    init_pair(3,COLOR_BLACK,COLOR_YELLOW);
    init_pair(4,COLOR_BLACK,COLOR_GREEN);
    getmaxyx(stdscr, maxY, maxX);
    
    panel = new Panel(true, maxY - 4, (maxX/2)-10, 5);
    ball = new Ball(maxY-5, maxX/2, 0, panel);
    frameOut = new Brick(false,  0, 0, maxY, maxX , 2);
    frameIn = new Brick(true, 1, 1, maxY - 2 , maxX - 2 , 1);
}

void BreakOut::draw(){
    frameOut -> draw();
    frameIn -> draw(); 

    attron(COLOR_PAIR(4));
    panel -> draw();
    attroff(COLOR_PAIR(4));
    ball -> draw();
}

void BreakOut::update(){
    
}
