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
    init_pair(5,COLOR_BLACK,COLOR_BLACK);
    init_pair(6,COLOR_BLACK,COLOR_MAGENTA);
    getmaxyx(stdscr, maxY, maxX);
    maxX =60;
    maxY =30;
    
    panel = new Panel(true, maxY - 4, (maxX/2)-10, 4);
    ball = new Ball(maxY-5, maxX/2, 0, panel, 6);
    frameOut = new Brick(false,  0, 0, maxY, maxX , 2);
    frameIn = new Brick(true, 1, 1, maxY - 2 , maxX - 2 , 6);

}

void BreakOut::draw(){
    if (tiles.size() != 0)
    for (int i = 0; i < tiles.size(); i++){
        if ( tiles[i] -> collision(ball -> y, ball -> x)){
            tiles.erase(tiles.begin()+i);
            continue;
        }
    }
    frameOut -> draw();
    frameIn -> draw(); 
    panel -> draw();
    if (tiles.size() != 0)
        for (int i = 0; i < tiles.size(); i++){
            tiles[i] -> draw();
        }
    ball -> draw();
}


void BreakOut::update(){
    
}

void BreakOut::addTile(){
    int maxX,maxY;
    getmaxyx(stdscr,maxY,maxX);
    maxX =60;
    maxY =30;
    int addX = 3 + (rand()%(maxX-15));
    int addY = 5 + (rand()%(maxY-20));
    int i = 0;
    while ( i < tiles.size()){
         if (!tiles.empty() && tiles[i] ->collision(addY,addX)){
            addX = 3 + (rand()%maxX-3);
            addY = 3 + (rand()%maxY-3);
            i = 0;
         }
      i++;
     }
    tiles.push_back(new Tile(addY,addX,1+rand()%4));
}
