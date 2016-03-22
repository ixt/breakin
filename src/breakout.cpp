#include "breakout.h"

static int frameY = 30;
static int frameX = 60;

BreakOut::BreakOut(){
    
    // Init ncurses + some cleaning of cursors

    initscr();
    noecho();
    cbreak();
    timeout(0);
    keypad(stdscr,true);
    halfdelay(1);
    start_color();

    curs_set(0);

    // color palette (if you're american), colour palette (if you're british)
    init_pair(1,COLOR_BLACK,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_CYAN);
    init_pair(3,COLOR_BLACK,COLOR_YELLOW);
    init_pair(4,COLOR_BLACK,COLOR_GREEN);
    init_pair(5,COLOR_BLACK,COLOR_BLACK);
    init_pair(6,COLOR_BLACK,COLOR_MAGENTA);
    
    panel = new Panel(true, frameY - 4, (frameX/2)-10, 4);
    ball = new Ball(frameY-5, frameX/2, 0, panel, &frameX, &frameY, 6);
    frameOut = new Brick(false,  0, 0, frameY, frameX , 2);
    frameIn = new Brick(true, 1, 1, frameY - 2 , frameX - 2 , 6);
    fileSystem = new File(".", &end);

    int count = 0;
    while (count != fileSystem->files.size() && fileSystem->files.size() != 0 && count <= 10 ){
        bool isThereEvenAFile = count >= fileSystem -> files.size() ? false : true ; 
        addTile(count++, isThereEvenAFile);
    }   
}

void BreakOut::draw(){
 
    // add time 
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    
    char buffer[25];
    strftime(buffer,25,"Current Time: %T",timeInfo);
    mvprintw(30,1,buffer);

    frameOut -> draw();
    frameIn -> draw(); 
    panel -> draw();
    if (tiles.size() != 0)
        for (int i = 0; i < tiles.size(); i++)
            tiles[i] -> draw();
    ball -> draw();
    fileSystem -> drawFiles(&frameX);
    
    if(!ball -> started())
        startScreen();

    if(end)
        endwin();
}

void BreakOut::update(){
    if (tiles.size() != 0)
    for (int i = 0; i < tiles.size(); i++){
        if (!tiles[i]-> gone ){
            if ( tiles[i] -> collision(ball -> y, ball -> x)){
                if(tiles[i]->isThereEvenAFile)
                    fileSystem->deleteFile(i);
                ball -> reflect(tiles[i] -> previousDirection);
                tiles[i] -> gone = true;
                continue;
            }
            tiles[i]->previousDirection = tiles[i] -> reflectDirection(ball -> y, ball -> x);
        }
    }
}

void BreakOut::addTile(int file, bool isThereEvenAFile){
    srand(time(NULL));
    int addX = 3 + (rand()%( frameX - 8));
    int addY = 3 + (rand()%( frameY / 2));
    int i = 0;
    while ( i < tiles.size()){
         if (!tiles.empty() && tiles[i] ->collision(addY,addX)){
            addX = 3 + (rand()%( frameX - 8));
            addY = 3 + (rand()%( frameY / 2));
            i = 0;
         }
      i++;
     }
    tiles.push_back(new Tile(addY,addX,1+rand()%4,file,isThereEvenAFile));
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
    mvprintw(12,15, " a file will be deleted for each ");
    mvprintw(13,22,       " block destroyed ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(15,19,    " space to start, arrows ");
    mvprintw(16,18,   " h & l or a & d for panel ");
    attroff(COLOR_PAIR(1));
}
