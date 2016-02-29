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
    
    panel = new Panel(true, maxY - 4, (maxX/2)-10, 4);
    ball = new Ball(maxY-5, maxX/2, 0, panel, 3);
    frameOut = new Brick(false,  0, 0, maxY, maxX , 2);
    frameIn = new Brick(true, 1, 1, maxY - 2 , maxX - 2 , 3);

}

void BreakOut::draw(){
    frameOut -> draw();
    frameIn -> draw(); 
    panel -> draw();
    if (tiles.size() != 0)
    for (int i = 0; i > tiles.size(); i++){
        if ( tiles[i] -> collision(ball -> y, ball -> x)){
            tiles.erase(tiles.begin()+i);
            continue;
        }
        tiles[i] -> draw();
    }
    ball -> draw();
}

void BreakOut::update(){
    
}
