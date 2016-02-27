#include "breakout.h"

BreakOut::BreakOut(){
    initscr();
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_CYAN);
    init_pair(3,COLOR_BLACK,COLOR_YELLOW);
    getmaxyx(stdscr, maxY, maxX);

    Brick frameOut(false,  0, 0, maxY, maxX , 2);
    frameOut.draw();
    Brick frameIn(true, 1, 1, maxY - 2 , maxX - 2 , 1);
    frameIn.draw(); 

    Panel panel(true, maxY - 4, (maxX/2)-10, 20);
    
    refresh();  
    getch();
    endwin();
}
