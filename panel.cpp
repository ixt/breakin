#include "panel.h"

Panel::Panel(bool fill, int y, int x, int l): Block(fill,y,x,3), length(l) {}

void Panel::draw(){ 
    int locY = getY();
    int locX = getX();
    int col = getColor();
    int maxY,maxX;
    attron(COLOR_PAIR(col));
    getmaxyx( stdscr, maxY , maxX );
    mvhline( locY , locX , (char)32 , length );
    attroff(COLOR_PAIR(col));
}
