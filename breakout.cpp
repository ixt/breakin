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
    
    if(!ball -> started())
        startScreen();
}

void BreakOut::update(){
    
}

void BreakOut::addTile(){
    int maxX,maxY;
    getmaxyx(stdscr,maxY,maxX);
    maxX = 60;
    maxY = 30;
    int addX = 3 + (rand()%52);
    int addY = 3 + (rand()%15);
    int i = 0;
    while ( i < tiles.size()){
         if (!tiles.empty() && tiles[i] ->collision(addY,addX)){
            addX = 3 + (rand()%52);
            addY = 3 + (rand()%15);
            i = 0;
         }
      i++;
     }
    tiles.push_back(new Tile(addY,addX,1+rand()%4));
}

void BreakOut::startScreen(){
    Circle * circle = new Circle(false,12,30,10,4);
    circle -> draw();

    
    
    attron(COLOR_PAIR(1));
    mvprintw(5,15, "    ___               __    _     ");
    mvprintw(6,15, "   / _ )_______ ___ _/ /__ (_)__  ");
    mvprintw(7,15, "  / _  / __/ -_) _ `/  '_// / _ \\ ");
    mvprintw(8,15, " /____/_/  \\__/\\_,_/_/\\_\\/_/_//_/ ");
    mvprintw(9,15, "                                  ");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(3));
    mvprintw(10,16, " This is a version of Breakout ");
    mvprintw(11,18,  " avoid hitting the blocks ");
    mvprintw(12,18,  " until the timer runs out ");
    mvprintw(13,15, " a file will be deleted for each ");
    mvprintw(14,22,       " block destroyed ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(15,19,    " space to start, arrows ");
    mvprintw(16,18,   " h & l or a & d for panel ");
    attroff(COLOR_PAIR(1));
}
